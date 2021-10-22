------------------------------------------------------------------------------
--                                                                          --
--                             Mission Koch                                 --
--                                                                          --
--                             Acteur Nombre                                -- 
--                                 Spec                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires à l'interface utilisateur
-- du TP sur le flocon de Koch
--

with Ada.Characters.Latin_1;

package Nombre is
   
   -- Utiliser newline pour faire un retour à la ligne (dans EcrireInfos)
   --
   -- Exemple:
   -- EcrireInfos("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA ;
   
   -- Efface un ecran et fixe un fond bleu fonce
   procedure EffacerEcran ;
   
   -- Ecrit la chaine S dans la zone infos de l'ecran
   procedure EcrireInfos(S: String);
     
   -- Fonction identique a SaisirTailleVecteur
   -- et SaisirValeurRecherchee
   -- seul le message d'invite change
   function SaisirFinesse return Integer  ; 
   
end Nombre ;
