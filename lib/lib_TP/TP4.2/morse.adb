----------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                             Acteur Morse                                 -- 
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires à la saisie
-- et l'affichage des elements de morse.
--

with Insa, Insa.Graphics, Insa.Audio;
use Insa, Insa.Graphics, Insa.Audio;

with Ada.Characters.Latin_1;

package body Morse is
   
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   TextAreaSymboleSaisie,TextAreaCaractereSaisie : PWidget;
   BoutonCourt, BoutonLong, BoutonFinLettre, BoutonFinMot: Pwidget;
   LabelBouton:Pwidget;
   
   LabelCaractere, LabelSymbole: Pwidget;
   TextAreaCaractere, TextAreaSymbole: Pwidget;
   BoutonResultat: Pwidget;
   LabelBoutonResultat: Pwidget;
   WindowResultat: PWidget;
   
   AudioBuffer: AUDIO_BUFFER;
   GenererSon:Boolean:=False;
   
   procedure AfficherSymboleSaisi (S: T_Symbole) is
   begin
      case S is 
         when Court => AddCharinTextArea(TextAreaSymboleSaisie,'*');  --Put("Court");
         when Long => AddCharinTextArea(TextAreaSymboleSaisie,'-'); --Put("Long");
         when FinLettre => AddCharinTextArea(TextAreaSymboleSaisie,Newline);
         when FinMot => AddCharinTextArea(TextAreaSymboleSaisie,Newline);
            AddTextinTextArea(TextAreaSymboleSaisie,"Fin de saisie");
      end case ;
   end AfficherSymboleSaisi;
           
   procedure AfficherCaractereSaisi (C: Character) is
   begin
      AddCharinTextArea(TextAreaCaractereSaisie,C);
      AddCharinTextArea(TextAreaCaractereSaisie,Newline);
   end AfficherCaractereSaisi;
   
   function AttendreSymbole return T_Symbole is
      Symbole: T_Symbole := FinMot;
   begin 
      while not GetButtonState(BoutonCourt) 
        and not GetButtonState(BoutonLong) 
        and not GetButtonState(BoutonFinLettre)
        and not GetButtonState(BoutonFinMot) loop
         null; -- Attente de l'appui sur un bouton
      end loop;
      
      if GetButtonState(BoutonCourt) then
         Symbole:=Court;
      elsif GetButtonState(BoutonLong) then
         Symbole:=Long;
      elsif GetButtonState(BoutonFinLettre) then
         Symbole:=FinLettre;
      end if; -- Si ce n'est aucun de ces 3 cas, c'est donc le bouton finmot, déja selectionné dans Symbole
      
      while GetButtonState(BoutonCourt) 
        or GetButtonState(BoutonLong) 
        or GetButtonState(BoutonFinLettre)
        or GetButtonState(BoutonFinMot) loop
         null; -- Attente que tous les boutons soient relachés
      end loop;
            
      return Symbole;
   end AttendreSymbole;
   
   procedure OuvrirFenetreResultat is
   begin
      WindowResultat:=CreateModalWindow(SCREEN_WIDTH-50, SCREEN_HEIGHT-40);
      
      BoutonResultat:=CreateButton(WindowResultat, 0,80);
      LabelBoutonResultat:=AddLabelToButton(BoutonResultat);
      SetLabelText(LabelBoutonResultat, "Fermer");
      
      LabelSymbole:=CreateLabel(WindowResultat,0,-90);
      SetLabelText(LabelSymbole, "Message Morse");
      
      TextAreaSymbole:=CreateTextArea(WindowResultat, 0,-60);
      SetWidgetSize(TextAreaSymbole, 350, 30);
      RealignWidget(TextAreaSymbole);
      
      LabelCaractere:=CreateLabel(WindowResultat,0,-10);
      SetLabelText(LabelCaractere, "Texte");
      
      TextAreaCaractere:=CreateTextArea(WindowResultat, 0,20);
      SetWidgetSize(TextAreaCaractere, 200, 30);
      RealignWidget(TextAreaCaractere);
      
      ClearTextinTextArea(TextAreaSymbole);
      ClearTextinTextArea(TextAreaCaractere);
   end OuvrirFenetreResultat;
   
   procedure FermerFenetreResultat is
   begin
      DestroyWidget(TextAreaCaractere);
      DestroyWidget(TextAreaSymbole);
      DestroyWidget(LabelSymbole);
      DestroyWidget(LabelCaractere);
      DestroyWidget(BoutonResultat);
      DestroyWidget(LabelBoutonResultat);
      DestroyWidget(WindowResultat);
   end FermerFenetreResultat; 
   
   procedure AttendreBoutonFermer is
   begin
      while GetButtonState(BoutonResultat) = False loop
         null; -- attendre que l'on appui sur le bouton fermer
      end loop;
   
      while GetButtonState(BoutonResultat) = True loop
         null; -- attendre que l'on relache le bouton fermer
      end loop;
   end AttendreBoutonFermer;
   
   procedure AfficherCaractereResultat(C:Character) is
   begin
      AddCharinTextArea(TextAreaCaractere,C);
   end AfficherCaractereResultat;
   
   procedure AfficherSymboleResultat(S:T_Symbole) is
   begin
      case S is
         when Court => AddCharinTextArea(TextAreaSymbole,'*');
         when Long => AddCharinTextArea(TextAreaSymbole,'-');
         when FinLettre => AddCharinTextArea(TextAreaSymbole,' ');
         when others => null;
      end case;
   end AfficherSymboleResultat ;
   
   procedure AudioCallback (Buffer_Nbr: BUFFER_NUMBER) is
   begin
      for I in AudioBuffer'Range loop
         if not GenererSon then
            AudioBuffer(I).Left:= 0;
            AudioBuffer(I).Right:= 0;
         elsif I<AudioBuffer'Last/2 then
            AudioBuffer(I).Left:= SIGNED_WORD'First;
            AudioBuffer(I).Right:= SIGNED_WORD'First;
         else
            AudioBuffer(I).Left:= SIGNED_WORD'Last;
            AudioBuffer(I).Right:= SIGNED_WORD'Last;
         end if;
      end loop;
      
      if Buffer_Nbr =2 then
         FillAudioBuffer(1,AudioBuffer);
      else 
         FillAudioBuffer(2,AudioBuffer);
      end if;
   end AudioCallback;
   
   procedure JouerBruitSymbole(S:T_Symbole) is
      DUREE_TI: constant Integer:= 100;
      DUREE_TA: constant Integer:= 3*DUREE_TI;
      
      DUREE_APRES_SYMBOLE: constant Integer:= DUREE_TI;
      
      DUREE_ENTRE_LETTRE: constant Integer:= DUREE_TA;
   begin
      case S is
         when Court => 
            GenererSon:=True;
            Insa.SysDelay(DUREE_TI);
            GenererSon:=False;
            Insa.SysDelay(DUREE_APRES_SYMBOLE);
         when Long => 
            GenererSon:=True;
            Insa.SysDelay(DUREE_TA);
            GenererSon:=False;
            Insa.SysDelay(DUREE_APRES_SYMBOLE);
         when FinLettre => Insa.SysDelay(DUREE_ENTRE_LETTRE);
         when others => null;
      end case;
      
   end JouerBruitSymbole;
      
   procedure InitialiseEcran is
   begin
      if TextAreaSymboleSaisie = null then
         TextAreaSymboleSaisie:=CreateTextArea(0,0);
         SetWidgetSize(TextAreaSymboleSaisie, 300, 120);
         SetWidgetPosition(TextAreaSymboleSaisie, -70,-60);
         
         TextAreaCaractereSaisie:=CreateTextArea(0,0);
         SetWidgetSize(TextAreaCaractereSaisie, 100, 120);
         SetWidgetPosition(TextAreaCaractereSaisie, 170,-60);
      
         BoutonCourt:= CreateButton(-100,35, 50);
         LabelBouton:=AddLabelToButton(BoutonCourt);
         SetLabelText(LabelBouton, "Court");
      
         BoutonLong:= CreateButton(100,35, 180);
         LabelBouton:=AddLabelToButton(BoutonLong);
         SetLabelText(LabelBouton, "Long");
      
         BoutonFinLettre:= CreateButton(-100,90, 100);
         LabelBouton:=AddLabelToButton(BoutonFinLettre);
         SetLabelText(LabelBouton, "Fin lettre");
      
         BoutonFinMot:= CreateButton(100,90, 100);
         LabelBouton:=AddLabelToButton(BoutonFinMot);
         SetLabelText(LabelBouton, "Fin Mot");
         
         ClearTextinTextArea(TextAreaSymboleSaisie);
         ClearTextinTextArea(TextAreaCaractereSaisie);
      else
         ClearTextinTextArea(TextAreaSymboleSaisie);
         ClearTextinTextArea(TextAreaCaractereSaisie);
      end if;
   end InitialiseEcran;
   
begin
   
   TextAreaSymboleSaisie := null;
   TextAreaCaractereSaisie := null;
   BoutonCourt:= null;
   BoutonLong:= null;
   BoutonFinLettre:= null; 
   BoutonFinMot:= null;
   LabelBouton:= null;
   
   StopAudio;
   SetAudioCallback(AudioCallback'Access);
   
   GenererSon:=False;
   
   StartAudio;
end Morse;
