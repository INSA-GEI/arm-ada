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
   
   -- procédure permettant l'ouverture d'une fenêtre graphique
   -- => PREMIERE PROCEDURE A UTILISER AVANT DE FAIRE APPEL AUX SUIVANTES DANS LE PROGRAMME DE DESSIN
   -- La tortue est positionnée en haut à gauche, coordonnées (0, 0), la tête vers le bas (orientation = 180°),
   -- plume baissée et prête à dessiner en noir
   procedure Ouvrir_Page is
   begin
      X_Pos := 0.0;
      X_Pos := 0.0;
           
      Canvas:=CreateCanvas(CANVAS_X, CANVAS_Y);
      AddBufferToCanvas(Canvas, CANVAS_WIDTH, CANVAS_HEIGHT, White);
      
      Baisser_Plume;
   end Ouvrir_Page;

   -- procédure permettant la fermeture d'une fenêtre graphique
   -- => DERNIERE PROCEDURE A APPELER AVANT DE QUITTER LE PROGRAMME DE DESSINx
   procedure Fermer_Page is
   begin
      X_Pos := 0.0;
      X_Pos := 0.0;
      Lever_Plume;
   end Fermer_Page;

   -- procédure permettant de lever la plume de la tortue
   -- => DANS CETTE ETAT AUCUN DEPLACEMENT NE SERA VISIBLE A L'ECRAN
   procedure Lever_Plume is
   begin
      Plume:=False;
   end Lever_Plume;

   -- procédure permettant de lever la plume de la tortue
   -- => DANS CETTE ETAT TOUT DEPLACEMENT LAISSERA UNE TRACE A L'ECRAN
   procedure Baisser_Plume is
   begin
      Plume:=True;
   end Baisser_Plume;

   -- function retournant l'abscisse (= le numéro de colonne) de la position courante de la tortue
   function Coordonnee_X return Float is
   begin
      return X_Pos;
   end Coordonnee_X;

   -- function retournant l'ordonnee (= le numéro de ligne) de la position courante de la tortue
   function Coordonnee_Y return Float is
   begin
      return Y_Pos;
   end Coordonnee_Y;

   -- function retournant la valeur de la position angulaire courante de la tortue
   function Coordonnee_Direction return Float is
   begin
      return Direction;
   end Coordonnee_Direction;

    -- procédure permettant de positionner la tortue sur une position angulaire spécifique (valeur X)
   -- X=0 : la tortue est orientée vers le haut
   -- X=90 : la tortue est orientée vers la droite
   -- X=180 : la tortue est orientée vers le bas
   -- X=270 : la tortue est orientée vers la gauche
   procedure Orienter(X: in Float) is
   begin
      Direction:=X;
   end Orienter;

   -- procédure permettant de choisir la couleur du tracé
   procedure Choix_Couleur(Pen_Color: in Insa.Graphics.COLOR)is
   begin
      Line_Cfg.Color := Pen_Color;
   end Choix_Couleur;

   -- procédure permettant de faire pivoter la position angulaire de la tortue de X degré dans le sens des aiguilles d'une montre
   procedure Tourner_Droite(X: in Float) is
   begin
      Direction:=Direction+X;
   end Tourner_Droite;

   -- procédure permettant de faire pivoter la position angulaire de la tortue de X degré dans le sens inverse des aiguilles d'une montre
   procedure Tourner_Gauche(X: in Float) is
   begin
      Direction:=Direction-X;
   end Tourner_Gauche;

   -- procédure permettant un déplacement de la position courante vers le point (X, Y)
   procedure Absolue(X: in PIXEl_X; Y: in PIXEL_Y) is
   begin
      X_Pos:=Float(X);
      Y_Pos:=Float(Y);
   end Absolue;

   -- function retournant le nombre maximum de lignes qui peut être affiché dans la fenêtre
   function Hauteur_Page return Float is
   begin
      return Float(CANVAS_HEIGHT);
   end Hauteur_Page;

   -- function retournant le nombre maximum de colonnes qui peut être affiché dans la fenêtre
   function Largeur_Page return Float is
   begin
      return Float(CANVAS_WIDTH);
   end Largeur_Page;
	
   -- procédure permettant un déplacement depuis la position courante (point A) vers un point B tel que abscisse(B)-abscisse(A) = X et ordonnee(B)-ordonnee(A) = Y
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

   -- procédure permettant d'avancer de X unités dans la direction courante et depuis la position actuelle de la tortue
   procedure Avancer(X : in Float) is
      X_Aux: Float;
      Y_Aux: Float;
      Points: T_PointArray(0..1);
   begin
      X_Aux := X_Pos+((Sin(Direction,360.0))*X);
      Y_Aux := Y_Pos-((Cos(Direction,360.0))*X);

      if (X_Aux<0.0) or 
        (X_Aux>Largeur_Page) or 
        (Y_Aux<0.0) or 
        (Y_Aux>Hauteur_Page) then
         raise Liberte;
      end if;
		
      Points(0):=(Interfaces.C.Short(X_Pos),Interfaces.C.Short(Y_Pos));
      Points(1):=(Interfaces.C.Short(X_Aux),Interfaces.C.Short(Y_Aux));
      
      if Plume then
         DrawLine(Canvas, Points, 2, Line_Cfg'Access);
      end if;
	  
      X_Pos := X_Aux;
      Y_Pos := Y_Aux;
   end Avancer;

   -- procédure permettant de reculer de X unités dans la direction courante et depuis la position actuelle de la tortue
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
         DrawLine(Canvas, Points, 2, Line_Cfg'Access);
      end if;
	  
      X_Pos := X_Aux;
      Y_Pos := Y_Aux;
   end Reculer;

end Tortue;




