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
    
   function Attendre1secondesOuB return Boolean is
      Compteur : Natural := 0;
   begin
      while (GetKeyState(KEY_B) /= Key_Pressed) and Compteur < 10 loop
         Insa.SysDelay(100);
         Compteur := Compteur +1 ;
      end loop ;

      return GetKeyState(KEY_B) = Key_Pressed ;
   end Attendre1secondesOuB ;
    
   procedure AttendreToucheA is
   begin
      -- EcrireEcran(2,Text_Y'LAST,"Appuyer sur A pour continuer");
      WaitForKey(Key_A);
   end AttendreToucheA;
   
   procedure AttendreToucheB is
   begin
      WaitForKey(Key_B);
   end AttendreToucheB;
     
   --
   -- Routines pour l'ecran d'enregistrement
   --
   
   ChartEnregistrement: PWidget;
   SeriesEnregistrement: PChart_Series;
   
   procedure AfficherEcranEnregistrement is
      Label: Pwidget;
   begin
      Label:=CreateLabel(0,-110);
      SetLabelText(Label, "Enregistrement capteur");
      
      Label:=CreateLabel(0,110);
      SetLabelText(Label, "Appuyez sur B pour quitter");
      
      ChartEnregistrement:=CreateChart(0,0);
      -- AddStyle(ChartEnregistrement,PART_CHART_BG,StyleEnregistrement'Access);
      SetWidgetSize(ChartEnregistrement, SCREEN_WIDTH-100, SCREEN_HEIGHT-100);
      RealignWidget(ChartEnregistrement);
      SetDivLineCount(ChartEnregistrement, 3, 0);
      SetPointCount(ChartEnregistrement, 10);
      SetChartType(ChartEnregistrement,CHART_TYPE_LINE);
      SetYTickLength(ChartEnregistrement,0,0);
      SetXTickLength(ChartEnregistrement,0,0);
      SetYAxisLabel(ChartEnregistrement,"2g", 0, CHART_AXIS_DRAW_LAST_TICK);
      SeriesEnregistrement:= AddChartSeries(ChartEnregistrement, Black);
   end AfficherEcranEnregistrement;
   
   procedure AjouterEcranEnregistrement(Val:Integer) is
   begin
      AddDataToSeries(ChartEnregistrement, SeriesEnregistrement, (Val*100)/2000);
   end AjouterEcranEnregistrement;
  
   --
   -- Routines pour l'affichage des resultast bruts
   --
   
   ChartAffichagePremier,ChartAffichageDernier: PWidget;
   SeriesAffichagePremier,SeriesAffichageDernier: PChart_Series;
   
   procedure AfficherEcranResultatsBruts(N:Integer) is
      Label: Pwidget;
   begin
      Label:=CreateLabel(0,-110);
      SetLabelText(Label, "Affichage des valeurs brutes");
      
      Label:=CreateLabel(0,110);
      SetLabelText(Label, "Appuyez sur A pour continuer");
      
      Label:=CreateLabel(-110,-80);
      SetLabelText(Label, "N premiers");
      
      Label:=CreateLabel(110,-80);
      SetLabelText(Label, "N derniers");
      
      ChartAffichagePremier:=CreateChart(-110,10);
      SetWidgetSize(ChartAffichagePremier, SCREEN_WIDTH/2-30, SCREEN_HEIGHT-120);
      RealignWidget(ChartAffichagePremier);
      SetDivLineCount(ChartAffichagePremier, 3, 0);
      SetPointCount(ChartAffichagePremier, N);
      SetChartType(ChartAffichagePremier,CHART_TYPE_LINE);
      SetYTickLength(ChartAffichagePremier,0,0);
      SetXTickLength(ChartAffichagePremier,0,0);
      SetYAxisLabel(ChartAffichagePremier,"2g", 0, CHART_AXIS_DRAW_LAST_TICK);
      SeriesAffichagePremier:= AddChartSeries(ChartAffichagePremier, Black);
      
      ChartAffichageDernier:=CreateChart(110,10);
      SetWidgetSize(ChartAffichageDernier, SCREEN_WIDTH/2-30, SCREEN_HEIGHT-120);
      RealignWidget(ChartAffichageDernier);
      SetDivLineCount(ChartAffichageDernier, 3, 0);
      SetPointCount(ChartAffichageDernier, N);
      SetChartType(ChartAffichageDernier,CHART_TYPE_LINE);
      SetYTickLength(ChartAffichageDernier,0,0);
      SetXTickLength(ChartAffichageDernier,0,0);
      SetYAxisLabel(ChartAffichageDernier,"2g", 0, CHART_AXIS_DRAW_LAST_TICK);
      SeriesAffichageDernier:= AddChartSeries(ChartAffichageDernier, Black);
      
      RealignWidget(ChartAffichagePremier);
      RealignWidget(ChartAffichageDernier);
      
   end AfficherEcranResultatsBruts;
   
   procedure AfficherEcranResultatsFiltre(N:Integer; Nb_Supprime: Integer) is
      Label: Pwidget;
   begin
      Label:=CreateLabel(0,-110);
      SetLabelText(Label, "Affichage des valeurs filtrees [" & Integer'Image(Nb_Supprime) & "] supprimes");
      
      Label:=CreateLabel(0,110);
      SetLabelText(Label, "Appuyez sur A pour continuer");
      
      Label:=CreateLabel(-110,-80);
      SetLabelText(Label, "N premiers");
      
      Label:=CreateLabel(110,-80);
      SetLabelText(Label, "N derniers");
      
      ChartAffichagePremier:=CreateChart(-110,10);
      SetWidgetSize(ChartAffichagePremier, SCREEN_WIDTH/2-30, SCREEN_HEIGHT-120);
      RealignWidget(ChartAffichagePremier);
      SetDivLineCount(ChartAffichagePremier, 3, 0);
      SetPointCount(ChartAffichagePremier, N);
      SetChartType(ChartAffichagePremier,CHART_TYPE_LINE);
      SetYTickLength(ChartAffichagePremier,0,0);
      SetXTickLength(ChartAffichagePremier,0,0);
      SetYAxisLabel(ChartAffichagePremier,"2g", 0, CHART_AXIS_DRAW_LAST_TICK);
      SeriesAffichagePremier:= AddChartSeries(ChartAffichagePremier, Black);
      
      ChartAffichageDernier:=CreateChart(110,10);
      SetWidgetSize(ChartAffichageDernier, SCREEN_WIDTH/2-30, SCREEN_HEIGHT-120);
      RealignWidget(ChartAffichageDernier);
      SetDivLineCount(ChartAffichageDernier, 3, 0);
      SetPointCount(ChartAffichageDernier, N);
      SetChartType(ChartAffichageDernier,CHART_TYPE_LINE);
      SetYTickLength(ChartAffichageDernier,0,0);
      SetXTickLength(ChartAffichageDernier,0,0);
      SetYAxisLabel(ChartAffichageDernier,"2g", 0, CHART_AXIS_DRAW_LAST_TICK);
      SeriesAffichageDernier:= AddChartSeries(ChartAffichageDernier, Black);
      
      RealignWidget(ChartAffichagePremier);
      RealignWidget(ChartAffichageDernier);
      
   end AfficherEcranResultatsFiltre;
   
   procedure AjouterPremier(Val:Integer) is
   begin
      AddDataToSeries(ChartAffichagePremier, SeriesAffichagePremier, (Val*100)/2000);
   end AjouterPremier;
   
   procedure AjouterDernier(Val:Integer) is
   begin
      AddDataToSeries(ChartAffichageDernier, SeriesAffichageDernier, (Val*100)/2000);
   end AjouterDernier;
   
      
   procedure EffacerEcran is
   begin
      ClearScreen;
      
      ChartEnregistrement:=null;
      SeriesEnregistrement:=null;
      ChartAffichagePremier:=null;
      ChartAffichageDernier:=null;
      SeriesAffichagePremier:=null;
      SeriesAffichageDernier:=null;
   end EffacerEcran;
   
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String) is
   begin
      Insa.Graphics.CreateMessageBox(Titre & Newline & Newline & Message, "Ok");
   end AfficheMessage;
   
end Sensors;
