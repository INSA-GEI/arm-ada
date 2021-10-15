------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                              Acteur Carte                                -- 
--                                 Specs                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a la gestion
-- des mouvements de pacman.
--

package Carte is
   
   type T_Direction is (Nord,Sud,Est,Ouest,Immobile);
   
   -- fonction devant etre appelee imperativement au debut de votre programme
   procedure InitialiserCarte ;
   
   -- retourne un entier qui represente le nombre de 100ms
   -- ecoulees depuis l'appel de la procedure InitialiserCarte
   function GetTempsEcoule return Integer ;
   
   -- fige le temps !!!
   procedure SuspendreTimer;
   
   -- "defige" le temps !!!
   procedure ReprendreTimer;
   
   -- redemarre le temps à partir de '0'
   procedure MettreAZeroTimer;
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA;
   
   -- renvoie la derniere touche de direction appuyee de type T_Direction
   function  DetecterDirection return T_Direction;
  
end Carte ;
