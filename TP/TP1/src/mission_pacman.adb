------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Ecran, Lab, Carte;
use Ecran, Lab, Carte;

procedure mission_pacman is
  
   DureeJeu : constant Integer := 600 ;
   
   procedure CalculerPFutur(P : T_Pacman ; D : T_Direction ; PFutur : out T_Pacman) is
   begin
      PFutur := P ;
      case D is
         when Haut   => PFutur.PosLigne := PFutur.PosLigne - 1 ;
         when Bas    => PFutur.PosLigne := PFutur.PosLigne + 1 ;
         when Droite => PFutur.PosColonne := PFutur.PosColonne + 1 ;
         when Gauche => PFutur.PosColonne := PFutur.PosColonne - 1 ;
         when Immobile => null;
      end case ;
   end CalculerPFutur ;
   
   function estMur (L : T_Lab ; P : T_Pacman) return Boolean is
   begin
      return (L(P.PosLigne,P.PosColonne) = Mur) ;
   end estMur ;
   
   
   function nombreCerises(lab : T_Lab) return Integer is
      res : integer := 0 ;
   begin
      for Lig in lab'range(1) loop
         for Col in lab'range(2) loop
            if lab(lig,col)=Cerise then
               res := res + 1;
            end if ;
         end loop;
      end loop;
      return res ;
   end nombreCerises ;
   
   procedure DeplacerPac(Lab : in out T_Lab ; p : in out T_Pacman ; pf : in T_Pacman ; NCerises : in out integer ; D : in T_Direction) is
   begin
      -- voir s'il y a une cerise sur la prochaine position
      if Lab(pf.PosLigne,pf.PosColonne) = Cerise then
         NCerises := NCerises - 1 ;
      end if;
      -- mettre a jour l'ecran et la lab a l'ancienne position 
      DessinerBloc(p.PosLigne,p.PosColonne,Vide);
      Lab(p.PosLigne,p.PosColonne) := Vide ;
      -- remplace la position
      p:=pf ;
      -- mettre a jour l'ecran et la lab a la prochaine position 
      DessinerBloc(p.PosLigne,p.PosColonne,Pacman,D);
      Lab(p.PosLigne,p.PosColonne) := Pacman ;
      
   end DeplacerPac ;
   
   MonP,MonPFutur : T_Pacman ;
   MonLab : T_Lab ;
   termine : Boolean := false ;
   dir : T_Direction ;
   NbreCerises : Integer ;
   
begin
   InitialiserJeu(MonP,MonLab);
   NbreCerises := nombreCerises(MonLab);
   while not termine loop      
      EcrireTempsRestant(DureeJeu-GetTempsEcoule);
      dir := DetecterDirection ;
      if dir /= Immobile then
         CalculerPFutur(MonP,dir,MonPFutur);
         if not estMur(MonLab,MonPFutur) then
            DeplacerPac(MonLab,MonP,MonPFutur,NbreCerises,dir);
         else
            MonP.NbreVies := MonP.NbreVies -1 ;
            AfficheMessage("Bing le mur","reste "&integer'image(MonP.NbreVies)&" vie(s)");
         end if;
         if ((DureeJeu-GetTempsEcoule)<=0) or (MonP.NbreVies <= 0) then
            termine := true ;
            AfficheMessage("Perdu"," essaye encore");
         elsif NbreCerises <=0 then
            termine := true ;
            AfficheMessage("Victoire"," score :"&integer'image((DureeJeu-GetTempsEcoule)*10));         
         end if ;
      end if;
      EcrireNbCerises(NbreCerises);
   end loop;
end mission_pacman;
