------------------------------------------------------------------------------
--                                                                          --
--                             Tests insa.graphics                          --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------
with Insa;
with Insa.Graphics;
with Insa.Keys;
with Insa.Graphics.Images;

with Sprites;

with Ada.Exceptions;  use Ada.Exceptions;

procedure Main is

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

   -- Test createImage / DrawImage
   procedure TestImage is
      Label, Label2: Insa.Graphics.PWidget;
      Image: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test DrawImage");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Image:=Insa.Graphics.Images.CreateImage(0,0,Insa.Graphics.ALIGNEMENT_CENTER);
      Insa.Graphics.Images.DrawImage(Image, Sprites.Cerise'Access);
      Insa.Graphics.RealignWidget(Image);

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestImage;

   -- Test declare bloc
   procedure TestDeclare is
      Label, Label2: Insa.Graphics.PWidget;
      LabelArr: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Declare bloc");

      declare
         A: Integer;
         Arr: array (1..10) of Integer;
      begin
         A:=0;

         for I in Arr'Range loop
            Arr(I):=A;
            A:=A+1;
         end loop;

         LabelArr:=Insa.Graphics.CreateLabel(0,0);
         Insa.Graphics.SetLabelText(LabelArr,
                                    "A=" & Integer'Image(A) &
                                      ", arr(1)=" & Integer'Image(Arr(1)) &
                                      ", arr(10)=" & Integer'Image(Arr(10)));
      end;

      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestDeclare;

   -- Test Exception handling
   procedure TestException is
      Label, Label2, LabelException: Insa.Graphics.PWidget;

      ButtonRecursivity: Insa.Graphics.PWidget;
      ButtonRange: Insa.Graphics.PWidget;
      ButtonCatch:Insa.Graphics.PWidget;

      ButtonRecursivityLabel: Insa.Graphics.PWidget;
      ButtonRangeLabel: Insa.Graphics.PWidget;
      ButtonCatchLabel: Insa.Graphics.PWidget;

      MyException : exception;

      function RecursiveError(Val: Integer) return Integer is
      begin
         if Val>10 then
            return 1;
         else
            return RecursiveError(Val);
         end if;
      end RecursiveError;

      procedure RangeError is
         Val: Positive;
      begin
         Val := 5;

         loop
            Val:=Val-1;
         end loop;
      end RangeError;

      procedure RaiseException is
         Val: Integer;
      begin
         Val := 5;

         loop
            Val:=Val-1;
            if Val = 0 then
               raise MyException;
            end if;
         end loop;
      end RaiseException;

      Tmp: Integer;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Exception handling");

      ButtonRecursivity:=Insa.Graphics.CreateButton(-100, -30, 150);
      ButtonRecursivityLabel:=Insa.Graphics.AddLabelToButton(ButtonRecursivity);
      Insa.Graphics.SetLabelText(ButtonRecursivityLabel, "Recursivity");
      Insa.Graphics.RealignWidget(ButtonRecursivity);

      ButtonRange:=Insa.Graphics.CreateButton(100, -30, 150);
      ButtonRangeLabel:=Insa.Graphics.AddLabelToButton(ButtonRange);
      Insa.Graphics.SetLabelText(ButtonRangeLabel, "Range");
      Insa.Graphics.RealignWidget(ButtonRange);

      ButtonCatch:=Insa.Graphics.CreateButton(0, 30, 150);
      ButtonCatchLabel:=Insa.Graphics.AddLabelToButton(ButtonCatch);
      Insa.Graphics.SetLabelText(ButtonCatchLabel, "Catch exception");
      Insa.Graphics.RealignWidget(ButtonCatch);

      while
        Insa.Graphics.GetButtonState(ButtonRecursivity) /= True and
        Insa.Graphics.GetButtonState(ButtonRange) /= True and
        Insa.Graphics.GetButtonState(ButtonCatch) /= True
      loop
         null;
      end loop;

      if Insa.Graphics.GetButtonState(ButtonRecursivity) then
         Insa.Graphics.WaitForButton(ButtonRecursivity);

         Tmp:=RecursiveError(5); -- Should raise STORAGE ERROR Exception
      elsif Insa.Graphics.GetButtonState(ButtonRange) then
         Insa.Graphics.WaitForButton(ButtonRange);

         RangeError;             -- Should raise CONSTRAINT ERROR exception
      elsif Insa.Graphics.GetButtonState(ButtonCatch) then
         Insa.Graphics.WaitForButton(ButtonCatch);

         begin
            RaiseException;         -- Should raise MyException exception
         exception
            when E : MyException =>
               --       ^ Exception to be handled
               LabelException:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-50);
               Insa.Graphics.SetLabelText(LabelException, "Exception " &  Ada.Exceptions.Exception_Name(E) & " caught");
         end;
      else
         null;
      end if;

      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestException;

   Label1, Label2: Insa.Graphics.PWidget;
begin
   -- Val:=Recursive(1);
   Label1:=Insa.Graphics.CreateLabel(0,-10);
   Insa.Graphics.SetLabelText(Label1, "Tests of insa.graphics");
   Label2:=Insa.Graphics.CreateLabel(0,10);
   Insa.Graphics.SetLabelText(Label2, "Press A to start");

   Insa.Keys.WaitForKey(Insa.Keys.Key_A);
   Insa.Graphics.ClearScreen;

   -- Test createImage / DrawImage
   TestImage;

   -- Test CreateButton / GetButtonState
   TestButton;

   TestSlider;

   TestMultipleSlider;

   TestProgressbar;

   TestMessagebox;

   TestDeclare;

   TestException;

   Label1:=Insa.Graphics.CreateLabel(0,0);
   Insa.Graphics.SetLabelText(Label1, "That's all, folks !");

   loop
      null;
   end loop;

end Main;
