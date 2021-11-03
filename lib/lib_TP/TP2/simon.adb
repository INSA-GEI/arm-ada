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

with Insa.Audio.Synthesizer;
use Insa.Audio.Synthesizer;

with Sprites_Firework, Sprites_Graveyard, Sprites_Simon, Music;
use Sprites_Firework, Sprites_Graveyard, Sprites_Simon, Music;

package body Simon is
   
   type T_Coord is record
      X : Integer ;
      Y : Integer ;
   end record;
   
   LabelInfo: PWidget;
   Labelsequence: Pwidget;
   
   TempsEcoule : Integer := 0;
   AttenteAffichage : constant Integer := 5 ;
   
   SpritesTouches: array (T_Direction) of PWidget :=
     (null, null, null, null, null);

   SpritesTouchesCoord: constant array (T_Direction) of T_Coord :=
     (Jaune=>(-148,-43),
      Bleu=>(-55,-45),
      Rouge=>(-145,50),
      Vert=>(-55,47),
      Immobile=>(0,0));
   
   procedure AfficherSimon;
   procedure InitialiserSon;
   procedure DessinerBlocBleu (Efface : Boolean);
   procedure DessinerBlocRouge (Efface : Boolean);
   procedure DessinerBlocVert (Efface : Boolean);
   procedure DessinerBlocJaune (Efface : Boolean);
   function GetTempsEcoule return Integer;
   procedure TraiterPeriodique;
   procedure InitialiserTimer;
   procedure SuspendreTimer;
   procedure ReprendreTimer;
   procedure Mettreazerotimer;
   
   -- Ecrit la chaine S dans le champ "Information"
   -- Pensez à inserer des newline pour eviter que les chaines soient trop longues
   procedure EcrireInfos(S: String) is
   begin
      SetLabelText(LabelInfo, S);
   end EcrireInfos;
   
   -- Ecrit la valeur V dans le champ "longueur sequence"
   procedure EcrireLongueurSequence(V: Integer) is
   begin
      SetLabelText(Labelsequence, Integer'Image(V));
   end EcrireLongueurSequence;
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA is
   begin
      EcrireInfos("Appuyez sur A");
      WaitForKey(Key_A);
      EcrireInfos("");
   end AttendreToucheA;
   
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- la taille du vecteur
   function SaisirLongueurSequence return Integer  is
      Depth: Natural:=1;
      NewDepth:Natural:=1;
      
      Slider: Pwidget;
      Label, ButtonLabel,SliderLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      Slider:=CreateSlider(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "Saisir longueur sequence");
      
      SliderLabel:=AddLabelToSlider(Slider,0,30);
      SetLabelText(SliderLabel, Natural'Image(Depth));
      
      NewDepth:=Depth;
      
      while GetKeyState(Key_A) /= Key_Pressed and GetButtonState(Button) = False loop
         NewDepth:= Natural((11*GetSliderValue(Slider)/100)+1);
         
         if NewDepth /= Depth then
            Depth:=NewDepth;
            SetLabelText(SliderLabel, Natural'Image(Depth));
         end if;
         
         Insa.SysDelay(50);
      end loop;
      
      while GetKeyState(Key_A) = Key_Pressed loop
         null ;
      end loop ;
      
      DestroyWidget(SliderLabel);
      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      return Depth ;
   end SaisirLongueurSequence ;
   
   -- Genere une sequence aleatoire de la taille de S'Length
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
   
   function DetecterDirection return T_Direction is
      Resultat : T_Direction ;
      -- TempsEntree : Integer  := TempsEcoule ;
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
            Valide := True;
         end if;
      end loop;
      
      Mettreazerotimer;
      
      while GetTempsEcoule /= 1 loop
         null;
      end loop;
      
      return Resultat ;
   end DetecterDirection ;
      
   -- Dessine ou Efface un pave 
   procedure DessinerPave (P: T_Direction; Efface : Boolean) is
   begin
      case P is
      when Bleu   => DessinerBlocBleu(Efface);	    
      when Jaune  => DessinerBlocJaune(Efface);
      when Vert   => DessinerBlocVert(Efface) ;
      when Rouge  => DessinerBlocRouge(Efface) ;
      when others => null;
      end case;  
   end DessinerPave;   
   
   -- Efface tous les paves
   procedure EffaceTout is
   begin
      DessinerPave (Jaune, True) ;
      DessinerPave (Rouge, True) ;
      DessinerPave (Bleu, True) ;
      DessinerPave (Vert, True) ;
   end EffaceTout;
   
   -- Affiche la sequence S
   procedure AfficherSequence (S : T_Sequence) is
   begin    
      -- Ajout d'une petite pause pour avoir le temps de voir la premiere
      -- touche
      PetitePause;
      
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
   
   -- Faire une petite pause entre 2 séquences (par ex.)
   procedure PetitePause is
   begin
      Mettreazerotimer;
      while  TempsEcoule < 2*AttenteAffichage loop
         null ;
      end loop ;
   end PetitePause ;
   
   -- Affiche l'ecran "perdu"
   procedure AfficherGameOver is
      I: INTEGER;
      
      GraveYard: Pwidget;
      Label, ButtonLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      GraveYard:=CreateImage(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "!! PERDU !!");
      
      DrawImage(GraveYard, Sprites_Graveyard.GameOver'Access);
      RealignWidget(GraveYard);
      
      SYNTH_Start;
      SYNTH_SetMainVolume(200);

      I:=0;
      while (I<4) loop
         SYNTH_SetVolume(I, 255);               -- Reglage du volume par canal
         SYNTH_SetInstrument(I, Guitar_Access);	-- Parametrage de l'instrument Ã  utiliser par canal

         I:=I+1;
      end loop;

      MELODY_Start(Rip_Melody,Rip.Music_Length);   -- Demarrage de la musique

      while GetKeyState(Key_A) /= Key_Pressed and GetButtonState(Button) = False loop
         null ;
      end loop ;
            
      while GetKeyState(Key_A) = Key_Pressed or GetButtonState(Button) = True loop
         null ;
      end loop;

      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      
      MELODY_Stop;
      
      -- Laisser le temps a l'oeil de voir disparaitre la fenetre
      PetitePause;
   end  AfficherGameOver;

   -- Affiche l'ecran "gagné"
   procedure AfficherGagne is
      I: Natural;
      Temps: Integer;

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
      SetLabelText(Label, "!! BRAVO !!");

      Mettreazerotimer;
      ReprendreTimer;

      SYNTH_Start;
      SYNTH_SetMainVolume(200);
      
      I:=0;
      while (I<4) loop
         SYNTH_SetVolume(I, 255);               -- Reglage du volume par canal
         SYNTH_SetInstrument(I, Guitar_Access);	-- Parametrage de l'instrument Ã  utiliser par canal
      
         I:=I+1;
      end loop;
      
      MELODY_Start(Ymca_Melody,Ymca.Music_Length);   -- Demarrage de la musique
     
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
      end loop;

      SuspendreTimer;
      Mettreazerotimer;
      ReprendreTimer;

      while GetKeyState(Key_A) = Key_Pressed or GetButtonState(Button) = True loop
         null ;
      end loop;

      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      MELODY_Stop;
      
      -- Laisser le temps a l'oeil de voir disparaitre la fenetre
      PetitePause;
   end AfficherGagne;

   --------------------------------------------------------------------
   -- Partie privée
   -- Routine de support, ne doivent pas etre appelée directement
   --------------------------------------------------------------------
   
   -- Affiche l'ecran de jeu et cree les label info et longueursequence
   procedure AfficherSimon is
      Bgsimon:PWidget;
      Label: Pwidget;
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
      SetLabelText(LabelInfo, "");
   end AfficherSimon;
   
   -- Initialise le synthetiseur
   procedure InitialiserSon is
      I: INTEGER;
   begin 
      -- Demarrage du synthe
      SYNTH_Start;

      SYNTH_SetMainVolume(200);
      I:=0;

      while I<4 loop
         SYNTH_SetVolume(I, 255);
         SYNTH_SetInstrument(I, Guitar_Access);
         I:=I+1;
      end loop;
   end InitialiserSon;
   
   -- Affiche ou efface la touche bleu eclairée
   procedure DessinerBlocBleu (Efface : Boolean) is
   begin
      if Efface then
         
         if SpritesTouches(Bleu)/=null then
            DestroyWidget(SpritesTouches(Bleu));
            SpritesTouches(Bleu):=null;
         end if;
      else	 
         if SpritesTouches(Bleu)=null then
            SYNTH_SetInstrument(0, Guitar_Access);
            SYNTH_NoteOn(0, C3);
        
            SpritesTouches(Bleu):=CreateImage(SpritesTouchesCoord(Bleu).X,
                                              SpritesTouchesCoord(Bleu).Y,
                                              ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
            DrawImage(SpritesTouches(Bleu),Sprites_Simon.Touche_Bleue'Access);
            RealignWidget(SpritesTouches(Bleu));
         end if;
         
      end if;
   end DessinerBlocBleu ;
   
   -- Affiche ou efface la touche rouge eclairée
   procedure DessinerBlocRouge (Efface : Boolean) is
   begin
      if Efface then
         if SpritesTouches(Rouge)/=null then
            DestroyWidget(SpritesTouches(Rouge));
            SpritesTouches(Rouge):=null;
         end if;
      else	 
         if SpritesTouches(Rouge)=null then
            SYNTH_SetInstrument(0, Guitar_Access);
            SYNTH_NoteOn(0, A3);
         
            SpritesTouches(Rouge):=CreateImage(SpritesTouchesCoord(Rouge).X,
                                               SpritesTouchesCoord(Rouge).Y,
                                               ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
            DrawImage(SpritesTouches(Rouge),Sprites_Simon.Touche_Rouge'Access);
            RealignWidget(SpritesTouches(Rouge)); 
         end if;
      end if;
   end DessinerBlocRouge ;
   
   -- Affiche ou efface la touche verte eclairée
   procedure DessinerBlocVert (Efface : Boolean) is
   begin
      if Efface then
         if SpritesTouches(Vert)/=null then
            DestroyWidget(SpritesTouches(Vert));
            SpritesTouches(Vert):=null;
         end if;
      else	 
         if SpritesTouches(Vert)=null then
            SYNTH_SetInstrument(0, Guitar_Access);
            SYNTH_NoteOn(0, C4);
        
            SpritesTouches(Vert):=CreateImage(SpritesTouchesCoord(Vert).X,
                                              SpritesTouchesCoord(Vert).Y,
                                              ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
            DrawImage(SpritesTouches(Vert),Sprites_Simon.Touche_Verte'Access);
            RealignWidget(SpritesTouches(Vert));  
         end if;
      end if;
   end DessinerBlocVert ;
   
   -- Affiche ou efface la touche jaune eclairée
   procedure DessinerBlocJaune (Efface : Boolean) is
   begin
      if Efface then
         if SpritesTouches(Jaune)/=null then
            DestroyWidget(SpritesTouches(Jaune));
            SpritesTouches(Jaune):=null;
         end if;
      else	 
         if SpritesTouches(Jaune)=null then
            SYNTH_SetInstrument(0, Guitar_Access);
            SYNTH_NoteOn(0, A4);
         
            SpritesTouches(Jaune):=CreateImage(SpritesTouchesCoord(Jaune).X,
                                               SpritesTouchesCoord(Jaune).Y,
                                               ALIGNEMENT_CENTER); -- TODO revoir les coordonnées
            DrawImage(SpritesTouches(Jaune),Sprites_Simon.Touche_Jaune'Access);
            RealignWidget(SpritesTouches(Jaune));
         end if;
      end if;
   end DessinerBlocJaune;
   
   -- Retourne le temps ecoulé (en 100 ms)
   function GetTempsEcoule return Integer is
   begin
      return TempsEcoule;
   end GetTempsEcoule;
   
   -- Callback pour le timer
   procedure TraiterPeriodique is
   begin 
      TempsEcoule := TempsEcoule + 1 ;
   end TraiterPeriodique;
   
   -- Initialisation diverse
   procedure InitialiserTimer is
   begin      
      TempsEcoule := 0 ;
      SetEventCallBack(TraiterPeriodique'Access);
      StartTimer;
   end InitialiserTimer;
   
   -- arrete le timer
   procedure SuspendreTimer is
   begin
      StopTimer;
   end SuspendreTimer;
   
   -- Relance le timer
   procedure ReprendreTimer is
   begin
      StartTimer;
   end ReprendreTimer;
   
   -- Reinitialise le timer
   procedure Mettreazerotimer is
   begin
      TempsEcoule := 0;
   end Mettreazerotimer;
begin
   InitialiserTimer;
   InitialiserSon;
   
   AfficherSimon;
end Simon;
