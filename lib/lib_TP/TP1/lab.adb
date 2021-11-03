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
   
   Lab_Image: array (1.. LAB_WIDTH, 1.. LAB_HEIGHT) of PWidget;
   
   -- Efface l'ecran, genere et dessine un labyrinthe
   -- Positionne Pacman avec MaxNbreVies vies au milieu du labyrinthe
   procedure InitialiserJeu (P : out T_Pacman ; L : out T_Lab)  is
   begin
      P.PosX := 5 ;
      P.PosY := 6 ;
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
      L(P.PosX,P.PosY):=Pacman;
      return L;
   end GenererLabyrinthe ;
   
   -- Dessine a la Ieme ligne Jeme colonne du labyrinthe un T_Bloc defini par TypeBloc
   procedure DessinerBloc (I,J : Integer ; TypeBloc : T_Bloc) is
   begin
      case TypeBloc is
      when Mur    => 
         DrawImage(Lab_Image(I,J), Sprites.Mur2'Access);
      when Vide   => 
         DrawImage(Lab_Image(I,J), Sprites.Vide'Access);
      when Cerise => DrawImage(Lab_Image(I,J), Sprites.Cerise'Access);
      when Pacman => DrawImage(Lab_Image(I,J), Sprites.Pacman_Droit'Access); 
      end case;
   end DessinerBloc;
   
   -- Dessine a la Ieme ligne Jeme colonne du labyrinthe un bloc pacman (Pacman_Haut, Pacman_Droit, Pacman_Gauche, Pacman_Bas) 
   -- en fonction de la direction.
   -- Si le bloc n'est pas un bloc pacman, une exception Invalid_Bloc est levée
   procedure DessinerBloc (I,J : Integer ; TypeBloc : T_Bloc; Direction: T_Direction ) is
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
         when Nord => DrawImage(Lab_Image(I,J), Sprites.Pacman_Haut'Access);
         when Sud => DrawImage(Lab_Image(I,J), Sprites.Pacman_Bas'Access);
         when Est => DrawImage(Lab_Image(I,J), Sprites.Pacman_Droit'Access);
         when Ouest => DrawImage(Lab_Image(I,J), Sprites.Pacman_Gauche'Access);
         when others => null;
         end case;
      end case;
   end DessinerBloc;

   -- Dessine un labyrinthe T_Lab defini par L
   procedure DessinerLabyrinthe (L : T_Lab) is
   begin
      for I in L'Range(1) loop
         for J in L'Range(2) loop
            DessinerBloc(I,J,L(I,J)) ; 
         end loop;
      end loop;
   end DessinerLabyrinthe ;

begin
   for Y in Lab_Image'Range(2) loop
      for X in Lab_Image'Range(1) loop
         Lab_Image(X,Y):= CreateImage(-200+(X*SPRITE_WIDTH), -120 +(Y*SPRITE_HEIGHT), ALIGNEMENT_CENTER);
         DrawImage(Lab_Image(X,Y),Sprites.Vide'Access);
      end loop;
   end loop;
end Lab;  
