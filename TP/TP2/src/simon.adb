------------------------------------------------------------------------------
--                                                                          --
--                             Mission Simon                                --
--                                                                          --
--                              Acteur Simon                                -- 
--                                 Body                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires pour le TP sur Simon
--

with Insa, Insa.Graphics, Insa.Keys,Insa.Timer ,Insa.Random_Number; 
use Insa, Insa.Graphics, Insa.Keys, Insa.Timer ,Insa.Random_Number; 

with Insa.Graphics.Images;
use Insa.Graphics.Images;

--with Insa.Audio.Synthesizer;
--use Insa.Audio.Synthesizer;

with Sprites_Firework, Sprites_Graveyard, Sprites_Simon, Music;
use Sprites_Firework, Sprites_Graveyard, Sprites_Simon, Music;

package body Simon is
   
   TaillePave : constant Integer := 40 ;
   type T_Coord is record
      X : Integer ;
      Y : Integer ;
   end record;
   
   --  CouleurFond     : constant COLOR := White   ;
   --  CouleurHaut     : constant COLOR := Blue  ;
   --  CouleurBas      : constant COLOR := Green  ;
   --  CouleurDroite   : constant COLOR := Red    ;
   --  CouleurGauche   : constant COLOR := Yellow ;
   --  
   --  PositionCentre  : constant T_Coord := (PIXEL_X'Last/2,PIXEL_Y'Last/2) ;
   --  PositionHaut    : constant T_Coord := (PositionCentre.X + TaillePave,PositionCentre.Y) ;
   --  PositionBas     : constant T_Coord := (PositionCentre.X - TaillePave,PositionCentre.Y) ;
   --  PositionDroite  : constant T_Coord := (PositionCentre.X,PositionCentre.Y + TaillePave) ;
   --  PositionGauche  : constant T_Coord := (PositionCentre.X,PositionCentre.Y - TaillePave) ;

   T_Bleue : constant INTEGER :=1;
   T_Rouge : constant INTEGER :=2;
   T_Verte : constant INTEGER :=3;
   T_Jaune : constant INTEGER :=4;
   
   SpritesTouches: array (1..4) of PWidget :=
     (null, null, null, null);

   procedure DessinerBlocBleu (Efface : Boolean) is
      Status: SYNTH_STATUS;
   begin
      if Efface then
         --SetPenColor(White);
         --DrawFillRectangle(0, 0, 
         --		   319,239);
         --  DrawimagefromSRAM((320-SimonBg.Width)/2,
         --                    (240-SimonBg.Height)/2,
         --                    SimonBg.Width,
         --                    SimonBg.Height,
         --                    0);
         if SpritesTouches(T_Bleue)/=null then
            DestroyWidget(SpritesTouches(T_Bleue));
            SpritesTouches(T_Bleue):=null;
         end if;
      else	 
         Status:= SYNTH_SetInstrument(0, Guitar_Access);
         Status:= SYNTH_NoteOn(0, C3);
         --  DrawimagefromSRAM(165, 35,
         --                    Touche_Bleue.Width,
         --                    Touche_Bleue.Height,
         --                    Sprites(T_Bleue));
         SpritesTouches(T_Bleue):=CreateImage(100,100,ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
         DrawImage(SpritesTouches(T_Bleue),Sprites_Simon.Touche_Bleue'Access);
      end if;
   end DessinerBlocBleu ;
   
   procedure DessinerBlocRouge (Efface : Boolean) is
      Status: SYNTH_STATUS;
   begin
      if Efface then
         --SetPenColor(White);
         --DrawFillRectangle(0, 0, 
         --		   319,239);
         --  DrawimagefromSRAM((320-SimonBg.Width)/2,
         --                    (240-SimonBg.Height)/2,
         --                    SimonBg.Width,
         --                    SimonBg.Height,
         --                    0);
         if SpritesTouches(T_Rouge)/=null then
            DestroyWidget(SpritesTouches(T_Rouge));
            SpritesTouches(T_Rouge):=null;
         end if;
      else	 
         Status:= SYNTH_SetInstrument(0, Guitar_Access);
         Status:= SYNTH_NoteOn(0, A3);
         --  DrawimagefromSRAM(72, 127,
         --                    Touche_Rouge.Width,
         --                    Touche_Rouge.Height,
         --                    Sprites(T_Rouge));
         SpritesTouches(T_Rouge):=CreateImage(100,100,ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
         DrawImage(SpritesTouches(T_Rouge),Sprites_Simon.Touche_Rouge'Access);
      end if;
   end DessinerBlocRouge ;
   
   procedure DessinerBlocVert (Efface : Boolean) is
      Status: SYNTH_STATUS;
   begin
      if Efface then
         --SetPenColor(White);
         --DrawFillRectangle(0, 0, 
         --		   319,239);
         --  DrawimagefromSRAM((320-SimonBg.Width)/2,
         --                    (240-SimonBg.Height)/2,
         --                    SimonBg.Width,
         --                    SimonBg.Height,
         --                    0);
         if SpritesTouches(T_Verte)/=null then
            DestroyWidget(SpritesTouches(T_Verte));
            SpritesTouches(T_Verte):=null;
         end if;
      else	 
         Status:= SYNTH_SetInstrument(0, Guitar_Access);
         Status:= SYNTH_NoteOn(0, C4);
         --  DrawimagefromSRAM(165, 127,
         --                    Touche_Verte.Width,
         --                    Touche_Verte.Height,
         --                    Sprites(T_Verte));
         SpritesTouches(T_Verte):=CreateImage(100,100,ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
         DrawImage(SpritesTouches(T_Verte),Sprites_Simon.Touche_Verte'Access);
      end if;
   end DessinerBlocVert ;
   
   procedure DessinerBlocJaune (Efface : Boolean) is
      Status: SYNTH_STATUS;
   begin
      if Efface then
         --SetPenColor(White);
         --DrawFillRectangle(0, 0, 
         --		   319,239);
         --  DrawimagefromSRAM((320-SimonBg.Width)/2,
         --                    (240-SimonBg.Height)/2,
         --                    SimonBg.Width,
         --                    SimonBg.Height,
         --                    0);
         if SpritesTouches(T_Jaune)/=null then
            DestroyWidget(SpritesTouches(T_Jaune));
            SpritesTouches(T_Jaune):=null;
         end if;
      else	 
         Status:= SYNTH_SetInstrument(0, Guitar_Access);
         Status:= SYNTH_NoteOn(0, A4);
         --  DrawimagefromSRAM(74, 35,
         --                    Touche_Jaune.Width,
         --                    Touche_Jaune.Height,
         --                    Sprites(T_Jaune));
         SpritesTouches(T_Jaune):=CreateImage(100,100,ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
         DrawImage(SpritesTouches(T_Jaune),Sprites_Simon.Touche_Jaune'Access);
      end if;
   end DessinerBlocJaune ;
   
   --  procedure EffacerEcran is
   --  begin
   --     ClearScreen(White);
   --  end EffacerEcran;
   
   --  procedure EcrireEcran (C : in Integer; L : in Integer; S : in String) is
   --  begin
   --     SetTextColor(BLack);
   --     SetBackColor(White);
   --     DrawString(C,L,S);
   --  end EcrireEcran;
   --  
   --  procedure EffacerLigne (L : in Integer) is
   --  begin
   --     for I in 0..Text_X'Last loop
   --        EcrireEcran(I,L," ");
   --     end loop;
   --  end EffacerLigne ;
   
   procedure AttendreToucheA is
   begin
      CreateMessageBox("Appuyer sur OK pour continuer","OK");
      --  EcrireEcran(2,Text_Y'LAST,"Appuyer sur A pour continuer");
      --  WaitForKey(Key_A);
   end AttendreToucheA;
   
   function SaisirLongueurSequence return Integer  is
      --  MyProgressBar : ProgressBar ;
      --  PotValue: POTENTIOMETER_VALUE;
      Depth: Natural:=1;
      
   begin
      --  EcrireEcran (2, 4, "Saisissez la taille de la sequence");
      --  EcrireEcran (2, 11, "Appuyer sur A pour valider");
      --  CreateProgressBar(MyProgressBar, 50, 100, PIXEL_X'Last-100, 26);
      --  ProgressBarSetMaximum(MyProgressBar,15);
      --  
      --  while GetKeyState(Key_A) /= Key_Pressed loop
      --     PotValue:=GetPotentiometerValue(Potentiometer_Left);
      --     Depth := (Integer(PotValue)*15/255);
      --     ProgressBarChangeValue(MyProgressBar, Depth);
      --     EcrireEcran (2, 9, Positive'Image(Depth)&"  ");
      --     Insa.SysDelay(50);
      --  end loop;
      --  
      --  while GetKeyState(Key_A) = Key_Pressed loop
      --     null ;
      --  end loop ;
      --  
      -- EffacerEcran;
      return Depth ;
   end SaisirLongueurSequence ;
   
   procedure GenererSequence(S : in out T_Sequence) is
      Pave : Integer ;
   begin 
      for I in S'Range loop
         Pave := GetValue;
	 
         if Pave < Random_Value'Last / 4 then 
            S(I):= Bleu;
         elsif Pave < Random_Value'Last / 2 then
            S(I):= Jaune;   
         elsif Pave < Random_Value'Last * 3 / 4  then
            S(I):= Vert; 
         else
            S(I):= Rouge;    
         end if ;
      end loop;
   end GenererSequence ;
   
   TempsEcoule : Integer := 0;
   AttenteAffichage : constant Integer := 5 ;
   
   function GetTempsEcoule return Integer is
   begin
      return TempsEcoule ;
   end GetTempsEcoule ;
   
   procedure TraiterPeriodique is
   begin 
      TempsEcoule := TempsEcoule + 1 ;
   end TraiterPeriodique ;
   
   procedure InitialiserCarte is
   begin      
      TempsEcoule := 0 ;
      SetEventCallBack(TraiterPeriodique'Access);
      StartTimer;
   end InitialiserCarte ;
   
   procedure SuspendreTimer is
   begin
      StopTimer;
   end SuspendreTimer ;
   
   procedure ReprendreTimer is
   begin
      StartTimer;
   end ReprendreTimer ;
   
   procedure Mettreazerotimer is
   begin
      TempsEcoule := 0;
   end Mettreazerotimer ;
   
   function DetecterDirection return T_Direction is
      Resultat : T_Direction ;
      TempsEntree : Integer  := TempsEcoule ;
      Valide : Boolean := False ;
      
   begin
      while not Valide loop
         if GetKeyState(Key_Y) = Key_Pressed then
            Resultat := Bleu ;
            Valide := True ;
         end if; 
	 
         if GetKeyState(Key_X) = Key_Pressed then
            Resultat := Jaune ;
            Valide := True ;
         end if;
	 
         if GetKeyState(Key_B) = Key_Pressed then
            Resultat := Vert ;
            Valide := True ;
         end if;
	 
         if GetKeyState(Key_A) = Key_Pressed then
            Resultat := Rouge ;
            Valide := True ;
         end if;
	 
         if GetKeyState(Key_A) /= Key_Pressed and GetKeyState(Key_B) /= Key_Pressed and
           GetKeyState(Key_X) /= Key_Pressed and GetKeyState(Key_Y) /= Key_Pressed then
            Resultat := Immobile;
            Valide := True ;
         end if;
      end loop;
      
      Mettreazerotimer;
      
      while GetTempsEcoule /= 1 loop
         null;
      end loop;
      
      return Resultat ;
   end DetecterDirection ;
      
   procedure DessinerPave (P: T_Direction; Efface : Boolean) is
   begin
      case P is
      when Bleu   => DessinerBlocBleu(Efface);	    
      when Jaune  => DessinerBlocJaune(Efface);
      when Vert    => DessinerBlocVert(Efface) ;
      when Rouge   => DessinerBlocRouge(Efface) ;
      when others  => null;
      end case;  
   end DessinerPave;   
   
   
   procedure EffaceTout is
   begin
      DessinerPave (Jaune, True) ;
      DessinerPave (Rouge, True) ;
      DessinerPave (Bleu, True) ;
      DessinerPave (Vert, True) ;
   end EffaceTout;
   
   procedure AfficherSequence (S : T_Sequence) is
   begin    
      for I in S'Range loop 
         DessinerPave (S(I),False);
         Mettreazerotimer;
	 
         while TempsEcoule < AttenteAffichage loop
            null;
         end loop;
	 
         DessinerPave (S(I),True);
         Mettreazerotimer;
	 
         while  TempsEcoule < AttenteAffichage loop
            null;
         end loop;	 
      end loop;
   end AfficherSequence ;
   
   procedure PetitePause is
   begin
      Mettreazerotimer;
      while  TempsEcoule < 2*AttenteAffichage loop
         null ;
      end loop ;
   end PetitePause ;
   
   procedure InitialiserSonetImage is
      Status: SYNTH_Status;
      I: INTEGER;
   begin 
      -- Demarrage du synthe
      if SYNTH_Start /=SYNTH_SUCCESS then
         raise CONSTRAINT_ERROR;
      end if;

      Status:=SYNTH_SetMainVolume(200);
      I:=0;

      while I<4 loop
         Status:=SYNTH_SetVolume(I, 255);
         Status:=SYNTH_SetInstrument(I, Guitar_Access);
         I:=I+1;
      end loop;
   end InitialiserSonetImage;

   procedure AfficherSimon is
      Bgsimon:PWidget;
      Label, Labelsequence: Pwidget;
      LabelInfo: PWidget;
   begin     
      Bgsimon:=CreateImage(-100,0);
      DrawImage(Bgsimon, Sprites_Simon.SimonBg'Access);
      RealignWidget(Bgsimon);
      
      Label:=CreateLabel(130,-80);
      SetLabelText(Label, "Taille sequence");
      Labelsequence:=CreateLabel(130,-60);
      SetLabelText(Labelsequence, "0");
      
      Label:=CreateLabel(130,-20);
      SetLabelText(Label, "Infos");
      LabelInfo:=CreateLabel(130,50);
      SetLabelText(LabelInfo, "blablablablbalk" & Newline & Newline & Newline & Newline & Newline & Newline & Newline & "blobloblobloblo");
      
      --SetLayerDisplayMode(Display_Mode_Transparency);
      --SetLayer(Layer_2);
      
      --ClearScreen(White);

      --  UnpackimagetoSRAM(SimonBg,0);
      --  DrawimagefromSRAM((320-SimonBg.Width)/2,
      --                    (240-SimonBg.Height)/2,
      --                    SimonBg.Width,
      --                    SimonBg.Height,
      --                    0);

      --SetLayer(Layer_1);
      --SetLayerTransparency(Transparency_100,Transparency_100);
      --SetTransparentColorforBTE(White);
      --ClearScreen (White);

      --  Sprites(T_Bleue):=(SimonBg.Width*SimonBg.Height);
      --  UnpackimagetoSRAM(Touche_Bleue,Sprites(T_Bleue));
      --  Sprites(T_Rouge):=Sprites(T_Bleue)+(Touche_Bleue.Width*Touche_Bleue.Height);
      --  UnpackimagetoSRAM(Touche_Rouge,Sprites(T_Rouge));
      --  Sprites(T_Verte):=Sprites(T_Rouge)+(Touche_Rouge.Width*Touche_Rouge.Height);
      --  UnpackimagetoSRAM(Touche_Verte,Sprites(T_Verte));
      --  Sprites(T_Jaune):=Sprites(T_Verte)+(Touche_Verte.Width*Touche_Verte.Height);
      --  UnpackimagetoSRAM(Touche_Jaune,Sprites(T_Jaune));

   end AfficherSimon;

   procedure EffaceEcranFinDuJeu is
   begin
      --SetLayer(Layer_2);
      --ClearScreen(White);
      --SetLayer(Layer_1);
      --ClearScreen(White);
      null;
   end EffaceEcranFinDuJeu;

   procedure AfficherGameOver is
      Status: SYNTH_STATUS;
      Stat_MELODY: MELODY_STATUS;

      I: INTEGER;
   begin
      --SetLayer(Layer_1);
      --ClearScreen(Black);

      --  UnpackimagetoSRAM(GameOver,0);
      --  DrawimagefromSRAM((320-GameOver.Width)/2,
      --                    (240-GameOver.Height)/2,
      --                    GameOver.Width,
      --                    GameOver.Height,
      --                    0);

      if SYNTH_Start =SYNTH_SUCCESS then
         Status:=SYNTH_SetMainVolume(200);

         I:=0;
         while (I<4) loop
            Status:= SYNTH_SetVolume(I, 255);               -- Reglage du volume par canal
            Status:= SYNTH_SetInstrument(I, Guitar_Access);	-- Parametrage de l'instrument Ã  utiliser par canal

            I:=I+1;
         end loop;

         Stat_MELODY:=MELODY_Start(Rip_Melody,Rip.Music_Length);   -- Demarrage de la musique

         while GetKeyState(Key_A) /= Key_Pressed loop
            null ;
         end loop ;
	 
         while GetKeyState(Key_A) = Key_Pressed loop
            null ;
         end loop;

         Stat_MELODY:=MELODY_Stop;
      end if;
   end  AfficherGameOver;

   procedure AfficherGagne is
      I: Natural;
      Temps: Integer;

      Status: SYNTH_STATUS;
      Stat_MELODY: MELODY_STATUS;

      Firework: Pwidget;
      Label, ButtonLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      --SetLayer(Layer_1);
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      Firework:=CreateImage(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "!! YOU WIN !!");
      
      --  Sprites(1):=0;
      --  UnpackimagetoSRAM(Fire1,Sprites(1));
      --  Sprites(2):=Sprites(1)+(Fire1.Width*Fire1.Height);
      --  UnpackimagetoSRAM(Fire2,Sprites(2));
      --  Sprites(3):=Sprites(2)+(Fire2.Width*Fire2.Height);
      --  UnpackimagetoSRAM(Fire3,Sprites(3));
      --  Sprites(4):=Sprites(3)+(Fire3.Width*Fire3.Height);
      --  UnpackimagetoSRAM(Fire4,Sprites(4));

      Mettreazerotimer;
      ReprendreTimer;

      --  if SYNTH_Start =SYNTH_SUCCESS then
      --     Status:=SYNTH_SetMainVolume(200);
      --  
      --     I:=0;
      --     while (I<4) loop
      --        Status:= SYNTH_SetVolume(I, 255);               -- Reglage du volume par canal
      --        Status:= SYNTH_SetInstrument(I, Sinus_Instr_Access);	-- Parametrage de l'instrument Ã  utiliser par canal
      --  
      --        I:=I+1;
      --     end loop;
      --  
      --     Stat_MELODY:=MELODY_Start(Ymca_Melody,Ymca.Music_Length);   -- Demarrage de la musique
      --  end if;

      I:=1;
      while (GetKeyState(Key_A) /= Key_Pressed) and GetButtonState(Button) = False loop
         -- ClearScreen(Black);

         Temps:= GetTempsEcoule;

         case I is
         when 1 => DrawImage(Firework, Fire1'Access);
         when 2 => DrawImage(Firework, Fire2'Access);
         when 3 => DrawImage(Firework, Fire3'Access);
         when others => DrawImage(Firework, Fire4'Access);
         end case;
         
         RealignWidget(Firework);

         if Temps+GetTempsEcoule>=Temps+6 then
            
            I:= I+1;
            if I>=5 then
               I:=1;
            end if;
            
            Mettreazerotimer;
            ReprendreTimer;
            
            Temps:= GetTempsEcoule;
         end if;
         
         --  while Temps+GetTempsEcoule<Temps+6 loop
         --     null;
         --  end loop;
         --  
         --  Mettreazerotimer;
         --  ReprendreTimer;
      end loop;

      SuspendreTimer;
      Mettreazerotimer;
      ReprendreTimer;

      -- EffaceEcranFinDuJeu;

      -- Stat_MELODY:=MELODY_Stop;
      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);

      while GetKeyState(Key_A) = Key_Pressed loop
         null ;
      end loop;

   end AfficherGagne;

begin
   InitialiserCarte ;
   InitialiserSonetImage;
   
   AfficherSimon;
end Simon;
