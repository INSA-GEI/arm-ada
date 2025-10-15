------------------------------------------------------------------------------
--                                                                          --
--                             Mission Snake                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Carte, Plateau;
use Carte, Plateau;

procedure Mission_Snake is

   PERDU : exception ;

   procedure AfficherFinPartie (L : in P_Element ) is
      function CompterElement (L : P_Element) return Integer is
         Res : Integer :=0 ;
      begin
         if L/=null then
            Res :=  1 + CompterElement(L.all.Suiv);
         end if;
         return Res ;
      end CompterElement ;

   begin
      EffacerEcran;
      AfficheMessage(" !!! PERDU !!!", "Taille du serpent" & Integer'Image(CompterElement(L)));
   end AfficherFinPartie ;

   --  procedure EffacerFinListe (L : in P_Element;T : in out T_Table ) is
   procedure EffacerFinListe (L : in P_Element) is
      Aux : P_Element := L ;
   begin
      if Aux/=null then
         while Aux.all.Suiv /= null loop
            Aux:=Aux.all.Suiv ;
         end loop;
         --  T(Aux.Serpent.PosX,Aux.Serpent.PosY):=Vide;
         DessinerBloc(Aux.Serpent.PosX,Aux.Serpent.PosY,Vide);
      end if;
   end EffacerFinListe ;

   procedure AjouterElementEnTete (L: in out P_Element;Tete : T_Pos ) is
   begin
      L := new Element'(Tete,L);
   end AjouterElementEnTete ;

   procedure SupprimerQueue (L: in P_Element) is
      Aux : P_Element := L ;
   begin
      while Aux.all.Suiv.all.Suiv /= null loop
         Aux:=Aux.all.Suiv;
      end loop;
      EffacerMemoireElement(Aux.all.Suiv);
   end SupprimerQueue ;

   function RechercherPosSerpent(L: in P_Element; Coords: in T_Pos) return Boolean is
   begin
      if L = null then
         return False;
      elsif L.all.Serpent = Coords then
         return True;
      else
         return RechercherPosSerpent(L.all.Suiv, Coords);
      end if;
   end RechercherPosSerpent;

   procedure RechercherPosCerises(L_Cerises: in out P_Element_Cerise; Coords: in T_Pos; Trouve: out Boolean) is

   begin
      if L_Cerises = null then
         Trouve:=False;
      elsif L_Cerises.all.Cerise = Coords then
         Trouve:=True;
         L_Cerises := L_Cerises.all.Suiv;
      else
         RechercherPosCerises(L_Cerises.all.Suiv, Coords, Trouve);
      end if;
   end RechercherPosCerises;

   --  procedure GererDeplacement( S : in out P_Element ; T : in out T_Table ; D : in T_Direction ) is
   procedure GererDeplacement( S : in out P_Element ; L_Cerises : in out P_Element_Cerise ; D : in T_Direction ) is
      NouvelleTete : T_Pos ;
      Trouve: Boolean := False;
   begin
      case D is
         when Droite =>
            Nouvelletete :=((S.Serpent.PosX+1) mod PLATEAU_LARGEUR, S.Serpent.PosY);
         when Gauche =>
            Nouvelletete :=((S.Serpent.PosX-1) mod PLATEAU_LARGEUR,S.Serpent.PosY);
         when Bas =>
            Nouvelletete :=(S.Serpent.PosX,(S.Serpent.PosY+1) mod PLATEAU_HAUTEUR);
         when Haut =>
            Nouvelletete :=(S.Serpent.PosX,(S.Serpent.PosY-1) mod PLATEAU_HAUTEUR);
         when others =>
            null;
      end case ;

      --  if T(Nouvelletete.PosX,Nouvelletete.PosY) = Snake then
      if RechercherPosSerpent(S, NouvelleTete) = True then
         raise PERDU ;
      else
         AjouterElementEnTete(S,Nouvelletete);
      end if;

      RechercherPosCerises(L_Cerises, NouvelleTete, Trouve);
      if Trouve = False then
         --  EffacerFinListe(S,T);
         EffacerFinListe(S);
         SupprimerQueue(S);
      end if;

      --  T(S.Serpent.PosX,S.Serpent.PosY):=Snake;
      DessinerBloc(S.Serpent.PosX,S.Serpent.PosY,Snake);

   end GererDeplacement ;

   --  Ma_Table : T_Table ;
   Mon_Serpent : P_Element ;
   Ma_Direction : T_Direction ;
   Ma_Liste_Cerises : P_Element_Cerise := null;
begin
   InitialiserCarte ;

   Mon_Serpent := new Element ;
   --  InitialiserJeu(Ma_Table,Mon_Serpent.Serpent) ;
   InitialiserJeu(Mon_Serpent.Serpent) ;

   while True loop
      Ma_Direction := Carte.DetecterDirection ;
      if Ma_Direction /= Immobile then
         --  GererDeplacement(Mon_Serpent,Ma_Table,Ma_Direction);
         GererDeplacement(Mon_Serpent,Ma_Liste_Cerises,Ma_Direction);
      end if;
      --  Placercerise(Ma_Table);
      Placercerise(Ma_Liste_Cerises);
   end loop;
exception
   when PERDU =>
      AfficherFinPartie(Mon_Serpent);
end Mission_Snake;
