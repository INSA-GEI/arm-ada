------------------------------------------------------------------------------
--                                                                          --
--                             Mission Dicho                                --
--                                                                          --
--                             Acteur Nombre                                -- 
--                                 Spec                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires à l'interface utilisateur
-- du TP sur la dichotomie
--

with Ada.Characters.Latin_1;

package Nombre is
   
   -- Utiliser newline pour faire un retour à la ligne (dans AjouterTexteResultats)
   --
   -- Exemple:
   -- AjouterTexteResultats("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA;
   
   -- Affiche le titre "Tests Unitaires" en haut de l'ecran
   procedure AfficherEcranTestsUnitaires;
   
   -- Affiche le titre "Tests Libres" en haut de l'ecran
   procedure AfficherEcranTestsLibres;
   
   -- Efface la zone de resultats (centre de l'ecran)
   procedure EffacerResultats; 
   
   -- Ajoute du texte à la zone de resultats
   procedure AjouterTexteResultats(S: String);
   
   -- Attend jusqu'a l'appui de la touche A
   -- que l'utilisateur saisisse la taille du vecteur
   -- a l'aide du slider
   function SaisirTailleVecteur return Integer;
   
   -- Fonction identique a SaisirTailleVecteur
   -- seul le message d'invite change
   function SaisirValeurRecherchee return Integer; 
     
   -- Attend jusqu'a l'appui de la touche A
   -- que l'utilisateur saisisse une valeur 
   -- mais dont la plus petite valeur retournee est fixee par 
   -- PlusPetiteValeur 
   -- A vous de l'appeler intelligemment pour s'assurer que
   -- toutes les valeurs du vecteur sont croissantes
   function SaisirNombreCroissant (PlusPetiteValeur : Integer ) return Integer;
     
end Nombre;
