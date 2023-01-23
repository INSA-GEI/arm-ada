------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                               Acteur Lab                                 -- 
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a la gestion
-- du labyrinthe.
--

with Insa, Insa.Graphics;
use  Insa, Insa.Graphics;

with Insa.Graphics.Images;
use Insa.Graphics.Images;

with Sprites;

with Ada.Exceptions;  use Ada.Exceptions;

package body Lab is
   
   SPRITE_WIDTH : constant Integer := 24;
   SPRITE_HEIGHT : constant Integer := 24;
   
   Lab_Image: array (1.. LAB_LIGNES, 1.. LAB_COLONNES) of PWidget;
   
   -- Efface l'ecran, genere et dessine un labyrinthe
   -- Positionne Pacman avec MaxNbreVies vies au milieu du labyrinthe
   procedure InitialiserJeu (P : out T_Pacman ; L : out T_Lab)  is
   begin
      P.PosLigne:= 5 ;
      P.PosColonne := 6 ;
      P.NbreVies := MaxNbreVies ;
      L := GenererLabyrinthe(P) ;

      DessinerLabyrinthe(L);
   end Initialiserjeu ;
   
   -- Retourne une variable de type T_Lab initialisee avec un labyrinthe
   -- dans lequel un T_Pacman P est place 
   function GenererLabyrinthe(P : T_Pacman) return T_Lab is
      L : T_Lab := (others => (others => Vide));
   begin
      L:= (1=>(Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur),
           2=>(Mur,Cerise,Cerise,Mur,Cerise,Cerise,Cerise,Cerise,Cerise,Mur),
           3=>(Mur,Mur,Cerise,Cerise,Cerise,Mur,Cerise,Mur,Cerise,Mur),
           4=>(Mur,Cerise,Cerise,Mur,Cerise,Mur,Cerise,Cerise,Cerise,Mur),
           5=>(Mur,Cerise,Mur,Cerise,Cerise,Cerise,Mur,Cerise,Cerise,Mur),
           6=>(Mur,Cerise,Mur,Cerise,Cerise,Cerise,Mur,Cerise,Cerise,Mur),
           7=>(Mur,Cerise,Cerise,Mur,Cerise,Mur,Cerise,Cerise,Cerise,Mur),
           8=>(Mur,Mur,Cerise,Cerise,Cerise,Mur,Cerise,Mur,Cerise,Mur),
           9=>(Mur,Cerise,Cerise,Mur,Cerise,Cerise,Cerise,Cerise,Cerise,Mur),
           10=>(Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur,Mur));	   
      L(P.PosLigne,P.PosColonne):=Pacman;
      return L;
   end GenererLabyrinthe ;
   
   -- Dessine a la Leme ligne Ceme colonne du labyrinthe un T_Bloc defini par TypeBloc
   procedure DessinerBloc (L,C : Integer ; TypeBloc : T_Bloc) is
   begin
      case TypeBloc is
      when Mur    => 
         DrawImage(Lab_Image(L,C), Sprites.Mur2'Access);
      when Vide   => 
         DrawImage(Lab_Image(L,C), Sprites.Vide'Access);
      when Cerise => DrawImage(Lab_Image(L,C), Sprites.Cerise'Access);
      when Pacman => DrawImage(Lab_Image(L,C), Sprites.Pacman_Droit'Access); 
      end case;
   end DessinerBloc;
   
   -- Dessine a la Leme ligne Ceme colonne du labyrinthe un bloc pacman (Pacman_Haut, Pacman_Droit, Pacman_Gauche, Pacman_Bas) 
   -- en fonction de la direction.
   -- Si le bloc n'est pas un bloc pacman, une exception Invalid_Bloc est levée
   procedure DessinerBloc (L,C : Integer ; TypeBloc : T_Bloc; Direction: T_Direction ) is
   begin
      case TypeBloc is
      when Mur    => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Mur')");
      when Vide   => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Vide')");
      when Cerise => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Cerise')");
      when Pacman =>
         case Direction is
         when Haut => DrawImage(Lab_Image(L,C), Sprites.Pacman_Haut'Access);
         when Bas => DrawImage(Lab_Image(L,C), Sprites.Pacman_Bas'Access);
         when Droite => DrawImage(Lab_Image(L,C), Sprites.Pacman_Droit'Access);
         when Gauche => DrawImage(Lab_Image(L,C), Sprites.Pacman_Gauche'Access);
         when others => null;
         end case;
      end case;
   end DessinerBloc;

   -- Dessine un labyrinthe T_Lab defini par L
   procedure DessinerLabyrinthe (L : T_Lab) is
   begin
      for Lig in L'Range(1) loop
         for Col in L'Range(2) loop
            DessinerBloc(Lig,Col,L(Lig,Col)) ; 
         end loop;
      end loop;
   end DessinerLabyrinthe ;

begin
   -- attention le tableau est en (ligne,colonne),donc (Y,X) mais 
   -- CreateImage est en X,Y, d'où l'inversion des indices col et lig
   for Lig in Lab_Image'Range(1) loop
      for Col in Lab_Image'Range(1) loop
         Lab_Image(Lig,Col):= CreateImage(-200+(Col*SPRITE_WIDTH), -120+(Lig*SPRITE_HEIGHT), ALIGNEMENT_CENTER);
         DrawImage(Lab_Image(Lig,Col),Sprites.Vide'Access);
      end loop;
   end loop;
end Lab;  
