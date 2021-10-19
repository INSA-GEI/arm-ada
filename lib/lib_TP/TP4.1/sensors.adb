------------------------------------------------------------------------------
--                                                                          --
--                             Mission Capteurs                             --
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur defini les routines necessaires au TP mission capteurs

with Insa.Graphics;
with Insa.Sensors;
with Insa.Keys;

with Ada.Numerics.Elementary_Functions;

use Insa.Graphics;
use Insa.Sensors;
use Insa.Keys;
use Ada.Numerics.Elementary_Functions;

package body Sensors is   
   
   function ObtenirValeursCapteur return T_Valeurs_Capteur is
      Valeurs_Capteur: SENSOR_VALUES;
      Resultat : T_Valeurs_Capteur ;
   begin
      Valeurs_Capteur := GetAccelerometerValues;        
      REsultat.X:= Integer(Valeurs_Capteur.X);
      REsultat.Y:= Integer(Valeurs_Capteur.Y);
      REsultat.Z:= Integer(Valeurs_Capteur.Z);
      
      return Resultat ;
   end ObtenirValeursCapteur;
    
   function CalculerRacineCarre (N: Integer) return Integer is
   begin
      return Integer(Sqrt(Float(N)));
   end CalculerRacineCarre ;
    
   function Attendre2secondesOuB return Boolean is
      Compteur : Natural := 0;
   begin
      while (GetKeyState(KEY_B) /= Key_Pressed) and Compteur < 20 loop
         --  DrawString(10, 7, "Enregistrement -");
         --  Insa.SysDelay(100); -- Attente
         --  DrawString(10, 7, "Enregistrement \");
         --  Insa.SysDelay(100); -- Attente
         --  DrawString(10, 7, "Enregistrement |");
         --  Insa.SysDelay(100); -- Attente
         --  DrawString(10, 7, "Enregistrement /");
         --  Insa.SysDelay(100); -- Attente
         Insa.SysDelay(100);
         Compteur := Compteur +1 ;
      end loop ;

      return GetKeyState(KEY_B) = Key_Pressed ;
   end Attendre2secondesOuB ;
    
   --  procedure EffacerEcran is
   --  begin
   --     --     ClearScreen(White);
   --     null;
   --  end EffacerEcran;
   --  
   --  procedure EcrireEcran (C : in Integer;L : in Integer;S : in String) is
   --  begin
   --     --  SetTextColor(BLack);
   --     --  SetBackColor(White);
   --     --  DrawString(C,L,S);
   --     null;
   --  end EcrireEcran;
   --  
   --  procedure DessinerEcran (C : in Integer;L : in Integer;Coul : in Integer ) is
   --     -- Coul_Loc : Integer;
   --  begin
   --     --  Coul_Loc := Coul;
   --     --
   --     --  if Coul_Loc > 255 then
   --     --     Coul_Loc := 255;
   --     --  end if;
   --     --
   --     --  if Coul_Loc <0 then
   --     --     Coul_Loc := 0;
   --     --  end if;
   --     --
   --     --  SetPenColor(Color(Coul_Loc));
   --     --  DrawFillRectangle(C*8,L*16,C*8+8,L*16+16);
   --     --  SetTextColor(Black);
   --     null;
   --  end DessinerEcran ;
   
   procedure AttendreToucheA is
   begin
      -- EcrireEcran(2,Text_Y'LAST,"Appuyer sur A pour continuer");
      WaitForKey(Key_A);
   end AttendreToucheA;
   
   procedure AttendreToucheB is
   begin
      WaitForKey(Key_B);
   end AttendreToucheB;
       
   LabelHautEnregistrement, labelBasEnregistrement: Pwidget;
   
   procedure AfficherEcranEnregistrement is
   begin
      LabelHautEnregistrement:=CreateLabel(0,-110);
      labelBasEnregistrement:=CreateLabel(0,110);

      SetLabelText(LabelHautEnregistrement, "Enregistrement capteur");
      SetLabelText(LabelBasEnregistrement, "Appuyez sur B pour quitter");
   end AfficherEcranEnregistrement;
   
   procedure EffacerEcran is
   begin
      ClearScreen;
      
      LabelHautEnregistrement:=null;
      LabelBasEnregistrement:=null;
   end EffacerEcran;
   
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String) is
   begin
      Insa.Graphics.CreateMessageBox(Titre & Newline & Newline & Message, "Ok");
   end AfficheMessage;
   
end Sensors;
