------------------------------------------------------------------------------
--                                                                          --
--                             Tests Graphics                               --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with insa.Graphics;
with Insa.Keys;

package body graphics is

   -- Test CreateButton / GetButtonState
   procedure TestButton is
      Label,Label2: Insa.Graphics.PWidget;
      Button: Insa.Graphics.PWidget;
      ButtonLabel: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Button");

      Button:=Insa.Graphics.CreateButton(0, 0, 150);
      ButtonLabel:=Insa.Graphics.AddLabelToButton(Button);
      Insa.Graphics.SetLabelText(ButtonLabel, "Press");

      while Insa.Graphics.GetButtonState(Button) /= True loop
         null;
      end loop;

      Insa.Graphics.SetLabelText(ButtonLabel, "Bye Bye");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestButton;

   -- Test CreateMessageBox
   procedure TestMessagebox is
      Label,Label2: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Messagebox");

      Insa.Graphics.CreateMessageBox("Hello", "Ok");

      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");
      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestMessagebox;

   -- test CreateSlider / GetSliderValue
   procedure TestSlider is
      Label,Label2: Insa.Graphics.PWidget;
      Slider: Insa.Graphics.PWidget;
      SliderLabel: Insa.Graphics.PWidget;
      Val: Integer;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Slider");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Slider:=Insa.Graphics.CreateSlider(0, 0, Insa.Graphics.SCREEN_WIDTH-100);
      SliderLabel:=Insa.Graphics.AddLabelToSlider(Slider,0,30,-1);
      Insa.Graphics.SetLabelText(SliderLabel, "0 %");

      while Insa.Keys.GetKeyState(Insa.Keys.Key_A) /= Insa.Keys.Key_Pressed loop
         Insa.SysDelay(100);

         Val := Integer(Insa.Graphics.GetSliderValue(Slider));
         Insa.Graphics.SetLabelText(SliderLabel, Integer'Image(Val) & " %");
      end loop;

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestSlider;

   -- test CreateSlider / GetSliderValue
   procedure TestMultipleSlider is
      Label,Label2: Insa.Graphics.PWidget;
      Slider1: Insa.Graphics.PWidget;
      Slider2: Insa.Graphics.PWidget;
      Slider3: Insa.Graphics.PWidget;
      Slider4: Insa.Graphics.PWidget;
      Slider5: Insa.Graphics.PWidget;

      SliderLabel1: Insa.Graphics.PWidget;
      SliderLabel2: Insa.Graphics.PWidget;
      SliderLabel3: Insa.Graphics.PWidget;
      SliderLabel4: Insa.Graphics.PWidget;
      SliderLabel5: Insa.Graphics.PWidget;

      Val: Integer;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Multiple sliders");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Slider1:=Insa.Graphics.CreateSlider(0, -100, Insa.Graphics.SCREEN_WIDTH-100);
      Slider2:=Insa.Graphics.CreateSlider(0, -60, Insa.Graphics.SCREEN_WIDTH-150);
      Slider3:=Insa.Graphics.CreateSlider(0, -20, Insa.Graphics.SCREEN_WIDTH-200);
      Slider4:=Insa.Graphics.CreateSlider(0, 20, Insa.Graphics.SCREEN_WIDTH-100);
      Slider5:=Insa.Graphics.CreateSlider(0, 60, Insa.Graphics.SCREEN_WIDTH-150);

      SliderLabel1:=Insa.Graphics.AddLabelToSlider(Slider1,0,10,-1);
      Insa.Graphics.SetLabelText(SliderLabel1, "0 %");
      SliderLabel2:=Insa.Graphics.AddLabelToSlider(Slider2,0,10,-1);
      Insa.Graphics.SetLabelText(SliderLabel2, "0 %");
      SliderLabel3:=Insa.Graphics.AddLabelToSlider(Slider3,0,10,-1);
      Insa.Graphics.SetLabelText(SliderLabel3, "0 %");
      SliderLabel4:=Insa.Graphics.AddLabelToSlider(Slider4,0,10,-1);
      Insa.Graphics.SetLabelText(SliderLabel4, "0 %");
      SliderLabel5:=Insa.Graphics.AddLabelToSlider(Slider5,0,10,-1);

      while Insa.Keys.GetKeyState(Insa.Keys.Key_A) /= Insa.Keys.Key_Pressed loop
         Insa.SysDelay(100);
         Val := Integer(Insa.Graphics.GetSliderValue(Slider1));
         Insa.Graphics.SetLabelText(SliderLabel1, Integer'Image(Val) & " %");
         Val := Integer(Insa.Graphics.GetSliderValue(Slider2));
         Insa.Graphics.SetLabelText(SliderLabel2, Integer'Image(Val) & " %");
         Val := Integer(Insa.Graphics.GetSliderValue(Slider3));
         Insa.Graphics.SetLabelText(SliderLabel3, Integer'Image(Val) & " %");
         Val := Integer(Insa.Graphics.GetSliderValue(Slider4));
         Insa.Graphics.SetLabelText(SliderLabel4, Integer'Image(Val) & " %");
         Val := Integer(Insa.Graphics.GetSliderValue(Slider5));
         Insa.Graphics.SetLabelText(SliderLabel5, Integer'Image(Val) & " %");
      end loop;

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestMultipleSlider;

   -- Test CreateProgressbar / SetProgressbarValue
   procedure TestProgressbar is
      Label,Label2: Insa.Graphics.PWidget;
      Progressbar: Insa.Graphics.PWidget;
      ProgressbarLabel: Insa.Graphics.PWidget;
      Val: Integer;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Progress Bar");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Progressbar:=Insa.Graphics.CreateProgressbar(0, 0, Insa.Graphics.SCREEN_WIDTH-100);
      ProgressbarLabel:=Insa.Graphics.AddLabelToSlider(Progressbar,0,30,-1);
      Insa.Graphics.SetLabelText(ProgressbarLabel, "0 %");

      Val:=0;

      while Insa.Keys.GetKeyState(Insa.Keys.Key_A) /= Insa.Keys.Key_Pressed loop
         Insa.SysDelay(100);

         Val := Val+1;
         if Val=100 then
            Val:=0;
         end if;

         Insa.Graphics.SetProgressbarValue(Progressbar, Val);
         Insa.Graphics.SetLabelText(ProgressbarLabel, Integer'Image(Val) & " %");
      end loop;

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestProgressbar;

end graphics;
