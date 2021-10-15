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
   
   -- TailleSymbole : constant Integer := 20 ;

  -- X_Origine_Lab : constant Integer := 20 ;
   -- Y_Origine_Lab : constant Integer := 20 ;
   
   SPRITE_WIDTH : constant Integer := 24;
   SPRITE_HEIGHT : constant Integer := 24;
   
   --  CouleurMur : constant COLOR     := White;
   --  CouleurVide : constant COLOR    := Black ;
   --  CouleurCerise : constant COLOR  := Red ;
   --  CouleurPacMan : constant COLOR  := Yellow ;
   --  
   --  Pacman_Gauche_Sprite: Image;
   --  Pacman_Droit_Sprite: Image;
   --  Pacman_Haut_Sprite: Image;
   --  Pacman_Bas_Sprite: Image;
   --  Cerise_Sprite: Image;
   --  Mur_Sprite: Image;
   Lab_Image: array (1.. LAB_WIDTH, 1.. LAB_HEIGHT) of PWidget;
   
   procedure InitialiserJeu (P : out T_Pacman ; L : out T_Lab)  is
   begin
      --ClearScreen;
      P.PosX := 5 ;
      P.PosY := 6 ;
      P.NbreVies := MaxNbreVies ;
      L := GenererLabyrinthe(P) ;
      
      -- Decompression des sprites
      --  Pacman_Gauche_Sprite := Unpackimage(Sprites.Pacman_Gauche);
      --  Pacman_Droit_Sprite := Unpackimage(Sprites.Pacman_Droit);
      --  Pacman_Haut_Sprite := Unpackimage(Sprites.Pacman_Haut);
      --  Pacman_Bas_Sprite := Unpackimage(Sprites.Pacman_Bas);
      --  Cerise_Sprite := Unpackimage(Sprites.Cerise);
      --  Mur_Sprite := Unpackimage(Sprites.Mur);
      
      DessinerLabyrinthe(L);
   end Initialiserjeu ;
   
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
   
   procedure DessinerBloc (I,J : Integer ; TypeBloc : T_Bloc) is
      --X,Y : Integer ;
   begin
      -- X:= X_Origine_Lab+(I-1)*TailleSymbole ;
      -- Y:= Y_Origine_Lab+(J-1)*TailleSymbole ;
      case TypeBloc is
      when Mur    => 
         --SetPenColor(CouleurMur) ; 
         --DrawFillRectangle(X,Y,X+Taillesymbole-1,Y+Taillesymbole-1);
         -- TODO: Dessiner un mur [DrawImage(X, Y, Mur_Sprite);]
         DrawImage(Lab_Image(I,J), Sprites.Mur2'Access);
      when Vide   => 
         -- SetPenColor(CouleurVide) ;
         -- TODO: dessiner un bloc vide [DrawFillRectangle(X,Y,X+Taillesymbole-1,Y+Taillesymbole-1);]
         DrawImage(Lab_Image(I,J), Sprites.Vide'Access);
      when Cerise => DrawImage(Lab_Image(I,J), Sprites.Cerise'Access); --  TODO: dessiner une cerise [DrawImage(X, Y, Cerise_Sprite);]
      when Pacman => DrawImage(Lab_Image(I,J), Sprites.Pacman_Droit'Access); --  TODO: dessiner un pacman [DrawImage(X, Y, Pacman_Droit_Sprite);]
         --  when others => null;
      end case;
   end DessinerBloc;
   
   procedure DessinerBloc (I,J : Integer ; TypeBloc : T_Bloc; Direction: T_Direction ) is
     -- X,Y : Integer ;
   begin
      -- X:= X_Origine_Lab+(I-1)*TailleSymbole ;
      -- Y:= Y_Origine_Lab+(J-1)*TailleSymbole ;
      
      case TypeBloc is
      when Mur    => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Mur')");
      when Vide   => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Vide')");
      when Cerise => 
         Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'Cerise')");
      when Pacman =>
         case Direction is
         when Nord => DrawImage(Lab_Image(I,J), Sprites.Pacman_Haut'Access);-- DrawImage(X, Y, Pacman_Haut_Sprite);
         when Sud => DrawImage(Lab_Image(I,J), Sprites.Pacman_Bas'Access);-- DrawImage(X, Y, Pacman_Bas_Sprite);
         when Est => DrawImage(Lab_Image(I,J), Sprites.Pacman_Droit'Access);-- DrawImage(X, Y, Pacman_Droit_Sprite);
         when Ouest => DrawImage(Lab_Image(I,J), Sprites.Pacman_Gauche'Access);-- DrawImage(X, Y, Pacman_Gauche_Sprite);
         when others => null;
         end case;
         --  when others =>
         --   Raise_Exception (Invalid_Bloc'Identity, "La procedure DessineBloc avec parametre de direction n'accepte que des blocs PACMAN (appel avec bloc 'WTF')");
      end case;
   end DessinerBloc;

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
