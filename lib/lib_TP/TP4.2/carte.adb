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
   
   -- Procedure privée, ne pas utiliser directement
   procedure TraiterPeriodique is
   begin 
      TempsEcoule := TempsEcoule + 1 ;
   end TraiterPeriodique ;
   
   -- Initialisation de l'ecran et du timer, a faire au debut du programme
   procedure InitialiserCarte is
   begin      
      TempsEcoule := 0 ;
      SetEventCallBack(TraiterPeriodique'Access);
      StartTimer;
      
      EffacerEcran;
      Label := Insa.Graphics.CreateLabel(160, -80);
      Insa.Graphics.SetLabelText(Label, "Score");
      LabelScore := Insa.Graphics.CreateLabel(160, -60);
      EcrireScore(0);
      
      LabelInformation := Insa.Graphics.CreateLabel(160, 60);
      EcrireInformation("");
   end InitialiserCarte ;
       
   -- Renvoi l'orientation de la console
   function DetecterDirection return T_Direction is            
      Resultat : T_Direction := Immobile;
      TempsEntree : constant Integer  := TempsEcoule ;
      EstOuest : Integer ;
      NordSud : Integer ;
   begin
      EstOuest := Integer(GetAccelerometerValues.X);
      NordSud := Integer(-GetAccelerometerValues.Y);

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
      
      return Resultat ;
   end DetecterDirection ;
    
   -- Efface l'ecran: attention, tous les widgets sont perdus apres ça.
   -- A faire en fin de programme
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
   
   -- Affiche une fenetre 'popup' avec un message et un bouton OK
   -- Procedure bloquante tant que l'utilisateur n'a pas appuyé sur OK
   procedure AfficheMessage(Titre: String; Message: String) is
   begin
      Insa.Graphics.CreateMessageBox(Titre & Newline & Newline& Message, "Ok");
   end AfficheMessage;
   
end Carte ;
