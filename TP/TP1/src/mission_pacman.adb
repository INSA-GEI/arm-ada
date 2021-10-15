------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
------------------------------------------------------------------------------

with Carte,Lab,Ecran;
use Carte,Lab,Ecran;

procedure Mission_Pacman is
   DureeJeu : constant Integer := 600;

   procedure AfficherCerisesRestantes(Cerises: Integer);

   procedure AfficherGameOver is
   begin
      AfficheMessage("GAME OVER","Appuyez sur OK pour recommencer");
   end AfficherGameOver ;

   procedure AfficherVictoire (S : in Integer ) is
   begin
      AfficheMessage("VICTOIRE","Score : " & Integer'Image(S*4) & Newline & "Appuyez sur OK pour recommencer");
   end AfficherVictoire ;

   procedure AfficherNombreVies (P : in T_Pacman ; L : in T_Lab) is
   begin
      SuspendreTimer ;
      AfficheMessage("PERDU","Plus que " & Integer'Image(P.Nbrevies)&" vie(s)" & Newline & "Appuyez sur OK pour recommencer");
      DessinerLabyrinthe(L);
      ReprendreTimer ;
   end AfficherNombreVies ;

   function CompterCerise (L : in T_Lab) return Integer is
      Resultat : Integer := 0 ;
   begin
      for I in L'Range(1) loop
         for J in L'Range(2) loop
            if L(I,J) = Cerise then
               Resultat := Resultat +1 ;
            end if;
         end loop ;
      end loop ;
      return Resultat ;
   end CompterCerise ;

   procedure GererFinPartie (P : out T_Pacman ; L : out T_Lab) is
   begin
      InitialiserJeu(P,L);
      Mettreazerotimer ;
   end GererFinPartie ;

   procedure GererContactMur (P : in out T_Pacman ; L : in out T_Lab ) is
   begin
      P.NbreVies := P.NbreVies -1 ;
      if P.NbreVies > 0 then
         AfficherNombreVies(P,L);
      end if ;
   end GererContactMur ;

   procedure GererDeplacement( P : in out T_Pacman ; L : in out T_Lab ; D : in T_Direction ; NbrC : in out Integer ) is
   begin
      DessinerBloc(P.PosX,P.PosY,Vide);
      L(P.PosX,P.PosY):=Vide;
      case D is
      when Sud =>
         P := (P.PosX,P.PosY+1,P.NbreVies);
      when Nord =>
         P := (P.PosX,P.PosY-1,P.NbreVies);
      when Est =>
         P := (P.PosX+1,P.PosY,P.NbreVies);
      when Ouest =>
         P := (P.PosX-1,P.PosY,P.NbreVies);
      when others =>
         null;
      end case ;
      if  L(P.PosX,P.PosY) = Cerise then
         NbrC := NbrC +1 ;
         AfficherCerisesRestantes(NbrC);
      end if;
      L(P.PosX,P.PosY):=Pacman;
      DessinerBloc(P.PosX,P.PosY,Pacman, D);
   end GererDeplacement ;

   procedure AfficherTemps is
   begin
      EcrireTempsRestant(DureeJeu-GetTempsEcoule);
   end AfficherTemps;

   procedure AfficherCerisesRestantes(Cerises: Integer) is
   begin
      EcrireNbCerises(Cerises);
   end AfficherCerisesRestantes;

   function TesterMur (D: T_Direction ; L : T_Lab ; P : T_Pacman ) return Boolean is
      CestMur : Boolean := False ;
   begin
      if (D = Sud and L(P.PosX,P.PosY+1) = Mur) or
        (D = Nord and L(P.PosX,P.PosY-1) = Mur) or
        (D = Ouest and L(P.PosX-1,P.PosY) = Mur) or
        (D = Est and  L(P.PosX+1,P.PosY) = Mur) then
         CestMur := True ;
      end if;
      return CestMur ;
   end TesterMur ;

   Mon_Lab : T_Lab ;
   Mon_PacMan : T_Pacman ;
   Ma_Direction : T_Direction ;
   Mon_Nbre_Cerises_Mangees,Mon_Nbre_Cerises_Depart : Integer := 0 ;

begin
   Lab.InitialiserJeu(Mon_PacMan,Mon_Lab);
   Carte.InitialiserCarte ;
   Mon_Nbre_Cerises_Depart := CompterCerise(Mon_Lab);
   EcrireInformation("Appuyez sur A" & Newline & "pour commencer");

   AttendreToucheA;
   EcrireInformation("");

   while True loop
      while (GetTempsEcoule <= DureeJeu) and (Mon_Nbre_Cerises_Mangees < Mon_Nbre_Cerises_Depart) and  (Mon_PacMan.NbreVies > 0) loop
         AfficherTemps ;
         Ma_Direction := Carte.DetecterDirection ;
         if TesterMur(Ma_Direction,Mon_Lab,Mon_PacMan) then
            GererContactMur(Mon_PacMan,Mon_Lab);
         elsif Ma_Direction /= Immobile then
            GererDeplacement(Mon_PacMan,Mon_Lab,Ma_Direction,Mon_Nbre_Cerises_Mangees);
         end if;
      end loop;
      if (GetTempsEcoule > DureeJeu) or (Mon_PacMan.NbreVies <= 0) then
         AfficherGameOver ;
      else
         AfficherVictoire(DureeJeu - GetTempsEcoule) ;
      end if;

      GererFinPartie(Mon_PacMan,Mon_Lab);
      Mon_Nbre_Cerises_Depart := CompterCerise(Mon_Lab);
      Mon_Nbre_Cerises_Mangees := 0 ;

   end loop ;
end Mission_Pacman;
