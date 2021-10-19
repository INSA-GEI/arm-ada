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
   -- soit que 2 secondes se soient ecoulees
   -- soit que l'utilisateur ait appuye sur la touche B
   -- un message s'affiche sur la ligne 10
   -- le boolean est vrai si la touche B a ete appuyee
   function Attendre2secondesOuB return Boolean ;
   
   --  -- efface l'ecran
   --  procedure EffacerEcran ;
   --  
   --  -- ecris sur l'ecran la chaine de caractere S a la ligne L, colonne C
   --  procedure EcrireEcran(C : in Integer;L : in Integer;S : in String) ;
   --  
   --  -- dessine un rectangle plein de taille d'un caractere de couleur Col
   --  -- a la ligne L, colonne C
   --  procedure DessinerEcran (C : in Integer;L : in Integer;Coul : in Integer ) ;
   
   -- affiche a l'ecran un message d'attente
   -- blocante jusqu'a l'appui de la touche A
   procedure AttendreToucheA ;
   
   -- affiche a l'ecran un message d'attente
   -- blocante jusqu'a l'appui de la touche B
   procedure AttendreToucheB;
   
   procedure AfficherEcranEnregistrement;
   
   procedure EffacerEcran;
   
   procedure AfficheMessage(Titre: String; Message: String);
end Sensors;
