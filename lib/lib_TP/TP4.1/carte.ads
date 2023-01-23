------------------------------------------------------------------------------
--                                                                          --
--                             Mission Snake                                --
--                                                                          --
--                              Acteur Carte                                -- 
--                                  Specs                                   --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a la gestion
-- des mouvements du serpent.
--

with Ada.Characters.Latin_1;

package Carte is
   
   -- Utiliser newline pour faire un retour à la ligne (dans EcrireInformation)
   --
   -- Exemple:
   -- EcrireInformation("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   type T_Direction is (Haut,Bas,Gauche,Droite,Immobile) ;
   
   -- fonction devant etre appelee imperativement 
   -- au debut de votre programme
   procedure InitialiserCarte ;
   
   -- renvoie la derniere  direction observee par les accelerometres
   function DetecterDirection return T_Direction ;         
   
   -- Efface l'ecran: attention, tous les widgets sont perdus apres ça.
   -- A faire en fin de programme
   procedure EffacerEcran ;
   
   -- Ecrit un message dans la zone d'information
   procedure EcrireInformation(Info: String);
   
   -- Ecrit le score
   procedure EcrireScore(Score: Natural);
   
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String);
   
   TempsEcoule: Integer ;
end Carte ;
