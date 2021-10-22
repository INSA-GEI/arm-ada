------------------------------------------------------------------------------
--                                                                          --
--                             Mission Snake                                --
--                                                                          --
--                              Acteur Carte                                -- 
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a la gestion
-- des mouvements du serpent.
--

with Insa, Insa.Timer, Insa.Graphics, Insa.Sensors ;
use  Insa, Insa.Timer, Insa.Graphics, Insa.Sensors ;

package body Carte is
   
   SeuilEstOuest : constant Integer := 30 ;
   SeuilNordSud : constant Integer := 30 ;
   
   LabelInformation: PWidget;
   LabelScore:PWidget;
   Label: PWidget;
   
   procedure TraiterPeriodique is
   begin 
      TempsEcoule := TempsEcoule + 1 ;
   end TraiterPeriodique ;
   
   procedure InitialiserCarte is
   begin      
      TempsEcoule := 0 ;
      SetEventCallBack(TraiterPeriodique'Access);
      StartTimer;
      
      EffacerEcran;
      Label := Insa.Graphics.CreateLabel(130, -80);
      Insa.Graphics.SetLabelText(Label, "Score");
      LabelScore := Insa.Graphics.CreateLabel(130, -60);
      EcrireScore(0);
      
      LabelInformation := Insa.Graphics.CreateLabel(130, 60);
      EcrireInformation("");
   end InitialiserCarte ;
   
   -- type T_Valeur_Accelero is array (1..3) of Integer ;
   
   -- Retourne les valeurs des 3 axes de=u magnetometre
   -- function ObtenirValeursAccelero return SENSOR_VALUES ;
    
   --  function ObtenirValeursAccelero return SENSOR_VALUES is
   --      Valeurs_Accelero: SENSOR_VALUES;
   --      Resultat : SENSOR_VALUES ;
   --   begin
   --      Valeurs_Accelero := GetAccelerometerValues;
   --      REsultat(1):= Integer(Valeurs_Accelero(1));
   --      REsultat(2):= Integer(Valeurs_Accelero(2));
   --      REsultat(3):= Integer(Valeurs_Accelero(3));
   --      return Resultat ;
   --   end ObtenirValeursaccelero;
    
   function DetecterDirection return T_Direction is            
      Resultat : T_Direction := Immobile;
      TempsEntree : constant Integer  := TempsEcoule ;
      EstOuest : Integer ;
      NordSud : Integer ;
      
   begin
      EstOuest := Integer(GetAccelerometerValues.X);
      NordSud := Integer(GetAccelerometerValues.Y);
	
      --EcrireEcran(1,1,"X: " & Integer'Image(EstOuest) & "  ");
      --EcrireEcran(1,2,"Y: " & Integer'Image(NordSud) & "  ");

      if abs(EstOuest) > abs(NordSud) then
         if EstOuest > SeuilEstOuest then
            Resultat := Ouest ;
         elsif EstOuest < -SeuilEstOuest then
            Resultat := Est ;
         end if;
      else
         if NordSuD > SeuilNordSud then
            Resultat := Nord ;
         elsif NordSuD < -SeuilNordSud then
            Resultat := Sud ;
         end if;
      end if;
	 
      while  TempsEcoule - TempsEntree < 1 loop
         null ;
      end loop ;

      --EcrireEcran(1,3,"R: " & T_Direction'Image(Resultat) & "     ");
      return Resultat ;
   end DetecterDirection ;
    
   procedure EffacerEcran is
   begin
      ClearScreen;
   end EffacerEcran;
   
   -- Ecrit un message dans la zone d'information
   procedure EcrireInformation(Info: String) is
   begin
      Insa.Graphics.SetLabelText(LabelInformation, Info);
   end EcrireInformation;
   
   -- Ecrit le score
   procedure EcrireScore(Score: Natural) is
   begin
      Insa.Graphics.SetLabelText(LabelScore, Natural'Image(Score));
   end EcrireScore;
   
end Carte ;
