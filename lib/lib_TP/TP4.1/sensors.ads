------------------------------------------------------------------------------
--                                                                          --
--                             Mission Capteurs                             --
--                                  Specs                                   --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur defini les routines necessaires au TP mission capteurs

with Ada.Characters.Latin_1;

package Sensors is
   
   -- Utiliser newline pour faire un retour à la ligne (dans EcrireInfos)
   --
   -- Exemple:
   -- EcrireInfos("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   type COULEUR is range 0 .. 255;
   for COULEUR'Size use 8; 
   
   -- type T_Valeurs_Capteurs is array (1..3) of Integer ;
   type T_Valeurs_Capteur is record
      X: Integer;
      Y: Integer;
      Z: Integer;
   end record;
      
   -- Retourne les valeurs des 3 axes de l'accelerometre
   function ObtenirValeursCapteur return T_Valeurs_Capteur ;
   
   -- Retourne la partie entiere de la racine carree de N
   function CalculerRacineCarre (N: Integer) return Integer ;
   
   -- fonction bloquante qui attend le 1er evenement entre
   -- soit que 1 seconde se soient ecoulees
   -- soit que l'utilisateur ait appuye sur la touche B
   -- le boolean est vrai si la touche B a ete appuyee
   function Attendre1secondesOuB return Boolean ;
   
   -- affiche a l'ecran un message d'attente
   -- blocante jusqu'a l'appui de la touche A
   procedure AttendreToucheA ;
   
   -- affiche a l'ecran un message d'attente
   -- blocante jusqu'a l'appui de la touche B
   procedure AttendreToucheB;
   
   --
   -- Routines pour l'ecran d'enregistrement
   --
   
   -- Affiche la fenetre d'enregistrement
   procedure AfficherEcranEnregistrement;
   
   -- Ajoute une valeur sur le graphique de l'enregistreur (à droite, scroll vers la gauche)
   procedure AjouterEcranEnregistrement(Val:Integer);
      
   --
   -- Routines pour l'affichage des resultats
   --
    
   -- Affiche la fenetre des resultats non filtrés
   procedure AfficherEcranResultatsBruts(N:Integer);
   
   -- Affiche la fenetre des resultats filtrés
   procedure AfficherEcranResultatsFiltre(N:Integer; Nb_Supprime: Integer);
   
   -- ajoute une valeur sur le graphique des premieres valeurs
   procedure AjouterPremier(Val:Integer);
   
   -- ajoute une valeur sur le graphique des dernieres valeurs
   procedure AjouterDernier(Val:Integer);
   
   --
   -- Fonctions diverses
   --
  
   -- Efface l'ecran
   procedure EffacerEcran;
   
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String);
end Sensors;
