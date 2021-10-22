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
   
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   type T_Direction is (Nord,Sud,Est,Ouest,Immobile) ;
   
   -- fonction devant etre appelee imperativement 
   -- au debut de votre programme
   procedure InitialiserCarte ;
   
   -- renvoie la derniere  direction observee par les accelerometres
   function  DetecterDirection return T_Direction ;         
   
   -- Efface un ecran et fixe un fond bleu fonce
   procedure EffacerEcran ;
   
   -- Ecrit un message dans la zone d'information
   procedure EcrireInformation(Info: String);
   
   -- Ecrit le score
   procedure EcrireScore(Score: Natural);
   TempsEcoule : Integer ;
end Carte ;
