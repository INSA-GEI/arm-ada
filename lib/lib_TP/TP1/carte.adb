------------------------------------------------------------------------------
--                                                                          --
--                             Mission Pacman                               --
--                                                                          --
--                              Acteur Carte                                -- 
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a la gestion
-- des mouvements de pacman.
--

with Insa, Insa.Keys, Insa.Timer;
use  Insa, Insa.Keys, Insa.Timer;

package body Carte is
   
   TempsEcoule : Integer := 0;
   pragma Volatile (TempsEcoule);

   -- retourne un entier qui represente le nombre de 100ms
   -- ecoulees depuis l'appel de la procedure InitialiserCarte
   function GetTempsEcoule return Integer is
   begin
      return TempsEcoule ;
   end GetTempsEcoule ;
   
   procedure TraiterPeriodique;
   
   procedure InitialiserCarte is
   begin      
      TempsEcoule := 0 ;
      SetEventCallBack(TraiterPeriodique'Access);
      StartTimer;
   end InitialiserCarte ;
   
   -- fige le temps !!!
   procedure SuspendreTimer is
   begin
      StopTimer ;
   end SuspendreTimer ;
   
   -- "defige" le temps !!!
   procedure ReprendreTimer is
   begin
      StartTimer ;
   end ReprendreTimer ;
   
   -- redemarre le temps à partir de '0'
   procedure Mettreazerotimer is
   begin
      TempsEcoule := 0 ;
   end Mettreazerotimer ;
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA is
   begin
      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
   end AttendreToucheA;
   
    -- renvoie la derniere touche de direction appuyee de type T_Direction
   function DetecterDirection return T_Direction is
      Resultat : T_Direction := Immobile;
      Compteurtemps : Integer;
   begin
      Compteurtemps := GetTempsEcoule;

      if GetKeyState(Key_Down) = Key_Pressed then
         Resultat := Bas ;
      end if ; 
      if GetKeyState(Key_Up) = Key_Pressed then
         Resultat := Haut ;
      end if ;
      if GetKeyState(Key_Left) = Key_Pressed then
         Resultat := Gauche ;
      end if ;
      if GetKeyState(Key_Right) = Key_Pressed then
         Resultat := Droite ;
      end if ;
      
      if Resultat /= Immobile then 
	 Compteurtemps := Compteurtemps+2;
      else 
	 Compteurtemps := Compteurtemps+1;
      end if;

      while Compteurtemps > GetTempsEcoule loop
         null;
      end loop;
      
      return Resultat ;
   end DetecterDirection ;
   
   --
   -- Fonctions privées
   -- Ne pas appeler directement
   --
   
   procedure TraiterPeriodique is
   begin 
      TempsEcoule := TempsEcoule + 1 ;
   end TraiterPeriodique ;
begin
   InitialiserCarte ;
   
end Carte ;
