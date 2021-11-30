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

with Ada.Characters.Latin_1;

package Ecran is
   
   -- Utiliser newline pour faire un retour à la ligne (dans EcrireInfos)
   --
   -- Exemple:
   -- EcrireInfos("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
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
