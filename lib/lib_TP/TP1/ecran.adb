------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                              Acteur Ecran                                -- 
--                                 Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines pour afficher du texte
--

with Insa, Insa.Graphics;
use  Insa, Insa.Graphics;

package body Ecran is
   LabelCerise: Pwidget;
   LabelTemps: Pwidget;
   LabelInformation: Pwidget;
   
   --  Cree une zone pour ecrire du texte
   --  X=0 completement à gauche de l'ecran; x = SCREEN_WIDTH: completement à droite
   --  Y=0 Completement en HAUT de l'ecran, y= SCREEn_HEIGHT: completement en BAS
   --  function CreerZonedeTexte(X: Integer; Y: Integer) return Pwidget;
  
   --  Ecrit du texte dans une zone de texte DEJA CREE
   --  procedure Ecriretexte(ZonedeTexte: not null PWidget; Texte: String);
   
   --  function CreerZonedeTexte(X: Integer; Y: Integer) return Pwidget is
   --  begin
   --     return Insa.Graphics.CreateLabel((SCREEN_WIDTH/2)+X, (SCREEN_HEIGHT/2)+Y);
   --  end CreerZonedeTexte;
   --  
   --  procedure Ecriretexte(ZonedeTexte: not null Pwidget; Texte: String) is
   --  begin
   --     Insa.Graphics.SetLabelText(ZonedeTexte, Texte);
   --  end Ecriretexte;
   
   -- Ecrit le nombre de cerises restant dans la zone prevue 
   procedure EcrireNbCerises(Cerises: Integer) is
   begin
      Insa.Graphics.SetLabelText(LabelCerise, Integer'Image(Cerises));
   end EcrireNbCerises;
   
   -- Ecrit le temps restant dans la zone prevue
   procedure EcrireTempsRestant(Temps: Integer) is
   begin
      Insa.Graphics.SetLabelText(LabelTemps, Integer'Image(Temps));
   end EcrireTempsRestant;
   
   -- Ecrit un message dans la zone d'information
   procedure EcrireInformation(Info: String) is
   begin
      Insa.Graphics.SetLabelText(LabelInformation, Info);
   end EcrireInformation;
      
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String) is
   begin
      Insa.Graphics.CreateMessageBox(Titre & Newline & Newline& Message, "Ok");
   end AfficheMessage;
   
   Label: Pwidget;
begin
   
   Label := Insa.Graphics.CreateLabel(130, -80);
   Insa.Graphics.SetLabelText(Label, "Cerises restantes");
   LabelCerise := Insa.Graphics.CreateLabel(130, -60);
   EcrireNbCerises(0);
   
   Label := Insa.Graphics.CreateLabel(130, -20);
   Insa.Graphics.SetLabelText(Label, "Temps restant");
   LabelTemps := Insa.Graphics.CreateLabel(130, 0);
   EcrireTempsRestant(0);
   
   LabelInformation := Insa.Graphics.CreateLabel(130, 60);
   EcrireInformation("");
end Ecran;
