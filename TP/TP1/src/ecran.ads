------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                              Acteur Ecran                                -- 
--                                 Specs                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines pour afficher du texte
--

with Insa, Insa.Graphics;
use  Insa, Insa.Graphics;

with Ada.Characters.Latin_1;

package Ecran is
   
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   -- Efface un ecran et fixe un fond bleu fonce
   procedure EffacerEcran ;
   
   -- Cree une zone pour ecrire du texte
   -- X=0 completement à gauche de l'ecran; x = SCREEN_WIDTH: completement à droite
   -- Y=0 Completement en HAUT de l'ecran, y= SCREEn_HEIGHT: completement en BAS
   function CreerZonedeTexte(X: Integer; Y: Integer) return Pwidget;
  
   -- Ecrit du texte dans une zone de texte DEJA CREE
   procedure Ecriretexte(ZonedeTexte: not null PWidget; Texte: String);
   
   -- Ecrit le nombre de cerises restant dans la zone prevue 
   procedure EcrireNbCerises(Cerises: Integer);
   
   -- Ecrit le temps restant dans la zone prevue
   procedure EcrireTempsRestant(Temps: Integer);
   
   -- Ecrit un message dans la zone d'information
   procedure EcrireInformation(Info: String);
      
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String);
end Ecran;
