------------------------------------------------------------------------------
--                                                                          --
--                             Mission Koch                                 --
--                                                                          --
--                             Acteur Tortue                                -- 
--                                 Body                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires au tracé de lignes pour le
-- TP sur le flocon de Koch
--

with Insa;
with Insa.Graphics, Insa.Graphics.Images;
with Ada.Numerics.Elementary_Functions;

use Insa.Graphics, Insa.Graphics.Images;
use Ada.Numerics.Elementary_Functions;

with Interfaces, Interfaces.C;

package body Tortue is

   X_Pos   : 	Float:=0.0;
   Y_Pos   : 	Float:=0.0;

   Direction:	Float:=180.0;
   Plume   : 	Boolean:=True; --baisser = true
   
   -- Configuration de la ligne pour le tracage
   -- Couleur: Noir
   -- Epaisseur: 1 px
   -- Transparence: 0%
   Line_Cfg : aliased T_Line := 
     (Color=>Black,
      Width=>1,
      Dash_Width=>1,
      Dash_Gap=>0,
      Opa=>255,
      Other=>0);
   
   Canvas: Pwidget;
   
   CANVAS_WIDTH: constant Integer := 250;
   CANVAS_HEIGHT: constant Integer := 250;
   
   CANVAS_X: constant Integer := -105;
   CANVAS_Y: constant Integer := 0;
   
   procedure Ouvrir_Page is
   begin
      -- Ext_Create_Graph_Window(Integer(X_Max),Integer(Y_Max),Integer(X_Char), Integer(Y_Char));
      X_Pos := 0.0;
      X_Pos := 0.0;
      -- Put_Line("Set Pixel: (" & Integer'Image(Current_Pixel.x)& ";" & Integer'Image(Current_Pixel.y) &")");
      -- ClearScreen(White);
      
      Canvas:=CreateCanvas(CANVAS_X, CANVAS_Y);
      AddBufferToCanvas(Canvas, CANVAS_WIDTH, CANVAS_HEIGHT, White);
      
      Baisser_Plume;
   end Ouvrir_Page;

   procedure Fermer_Page is
   begin
      X_Pos := 0.0;
      X_Pos := 0.0;
      Lever_Plume;
   end Fermer_Page;

   procedure Lever_Plume is
   begin
      Plume:=False;
   end Lever_Plume;

   procedure Baisser_Plume is
   begin
      Plume:=True;
   end Baisser_Plume;

   function Coordonnee_X return Float is
   begin
      return X_Pos;
   end Coordonnee_X;

   function Coordonnee_Y return Float is
   begin
      return Y_Pos;
   end Coordonnee_Y;

   function Coordonnee_Direction return Float is
   begin
      return Direction;
   end Coordonnee_Direction;

   procedure Orienter(X: in Float) is
   begin
      Direction:=X;
   end Orienter;

   procedure Choix_Couleur(Pen_Color: in Insa.Graphics.COLOR)is
   begin
      Line_Cfg.Color := Pen_Color;
   end Choix_Couleur;

   procedure Tourner_Droite(X: in Float) is
   begin
      Direction:=Direction+X;
   end Tourner_Droite;

   procedure Tourner_Gauche(X: in Float) is
   begin
      Direction:=Direction-X;
   end Tourner_Gauche;

   procedure Absolue(X: in PIXEl_X; Y: in PIXEL_Y) is
   begin
      X_Pos:=Float(X);
      Y_Pos:=Float(Y);
   end Absolue;

   function Hauteur_Page return Float is
   begin
      return Float(CANVAS_HEIGHT);
   end Hauteur_Page;

   function Largeur_Page return Float is
   begin
      return Float(CANVAS_WIDTH);
   end Largeur_Page;
	
   procedure Deplacement(X: in Float; Y: in Float) is
      Points: T_PointArray(0..1);
   begin
      if (X+X_Pos<0.0) or 
        (X+X_Pos>Largeur_Page) or 
        (Y_Pos+Y<0.0) or 
        (Y_Pos+Y>Hauteur_Page) 
      then
         raise Liberte;
      end if;

      Points(0):=(Interfaces.C.Short(X_Pos),Interfaces.C.Short(Y_Pos));
      Points(1):=(Interfaces.C.Short(X_Pos+X),Interfaces.C.Short(Y_Pos+Y));
      
      if Plume then
         DrawLine(Canvas, Points, 2, Line_Cfg'Access);
      end if;

      X_Pos:=X_Pos+X;
      Y_Pos:=Y_Pos+Y;
   end Deplacement;

   procedure Avancer(X : in Float) is
      X_Aux: Float;
      Y_Aux: Float;
      Points: T_PointArray(0..1);
   begin
      X_Aux := X_Pos+((Sin(Direction,360.0))*X);
      Y_Aux := Y_Pos-((Cos(Direction,360.0))*X);

      --Put_Line("X_aux = "&Float'Image(X_Aux)&" Y_aux = "&Float'Image(Y_Aux));
      if (X_Aux<0.0) or 
        (X_Aux>Largeur_Page) or 
        (Y_Aux<0.0) or 
        (Y_Aux>Hauteur_Page) then
         raise Liberte;
      end if;
		
      Points(0):=(Interfaces.C.Short(X_Pos),Interfaces.C.Short(Y_Pos));
      Points(1):=(Interfaces.C.Short(X_Aux),Interfaces.C.Short(Y_Aux));
      
      if Plume then
         --DrawLine(Integer(X_Pos),Integer(Y_Pos),Integer(X_Aux),Integer(Y_Aux));
         DrawLine(Canvas, Points, 2, Line_Cfg'Access);
      end if;
	  
      X_Pos := X_Aux;
      Y_Pos := Y_Aux;
   end Avancer;

   procedure Reculer(X: in Float) is
      X_Aux: Float;
      Y_Aux: Float;
      Points: T_PointArray(0..1);
   begin
      X_Aux := X_Pos-((Sin(Direction,360.0))*X);
      Y_Aux := Y_Pos+((Cos(Direction,360.0))*X);
	  
      if (X_Aux<0.0) or 
        (X_Aux>Largeur_Page) or 
        (Y_Aux<0.0) or 
        (Y_Aux>Hauteur_Page) then
         raise Liberte;
      end if;
		
      Points(0):=(Interfaces.C.Short(X_Pos),Interfaces.C.Short(Y_Pos));
      Points(1):=(Interfaces.C.Short(X_Aux),Interfaces.C.Short(Y_Aux));
      
      if Plume then
         -- DrawLine(Integer(X_Pos),Integer(Y_Pos),Integer(X_Aux),Integer(Y_Aux));
         DrawLine(Canvas, Points, 2, Line_Cfg'Access);
      end if;
	  
      X_Pos := X_Aux;
      Y_Pos := Y_Aux;
   end Reculer;

end Tortue;




