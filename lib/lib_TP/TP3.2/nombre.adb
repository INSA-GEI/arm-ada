------------------------------------------------------------------------------
--                                                                          --
--                             Mission Koch                                 --
--                                                                          --
--                             Acteur Nombre                                -- 
--                                 Body                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires à l'interface utilisateur
-- du TP sur le flocon de Koch
--

with Insa, Insa.Graphics, Insa.Keys;
use Insa, Insa.Graphics, Insa.Keys; 

package body Nombre is
   
   LabelInfo: PWidget;
   
   procedure EffacerEcran is
   begin
      ClearScreen;
   end EffacerEcran;
   
   procedure EcrireInfos(S: String) is
   begin
      SetLabelText(LabelInfo, S);
   end EcrireInfos;  
   
   procedure AttendreToucheA is
   begin
      WaitForKey(Key_A);
   end AttendreToucheA;
      
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- la finesse du flocon
   function SaisirFinesse return Integer  is
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
      SetLabelText(Label, "Saisir finesse du flocon");
      
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
   end SaisirFinesse ;
   
   Label: Pwidget;
begin
   Label:=CreateLabel(130,-150);
   SetLabelText(Label, "Infos");
   LabelInfo:=CreateLabel(130,0);
   SetLabelText(LabelInfo, "");
end Nombre;
