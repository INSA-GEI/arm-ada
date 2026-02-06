------------------------------------------------------------------------------
--                                                                          --
--                             Tests                                        --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------
with Insa;
with Insa.Graphics;
with Insa.Keys;

with graphics;
with audio;
with synth;
with images;
with runtime;

procedure Main is

   Label1, Label2: Insa.Graphics.PWidget;
begin
   --  Val:=Recursive(1);
   Label1:=Insa.Graphics.CreateLabel(0,-10);
   Insa.Graphics.SetLabelText(Label1, "Tests of insa.graphics");
   Label2:=Insa.Graphics.CreateLabel(0,10);
   Insa.Graphics.SetLabelText(Label2, "Press A to start");

   Insa.Keys.WaitForKey(Insa.Keys.Key_A);
   Insa.Graphics.ClearScreen;

   --  Test CreateButton / GetButtonState
   Graphics.TestButton;

   --  test CreateSlider / GetSliderValue
   Graphics.TestSlider;

   --  test CreateSlider / GetSliderValue
   Graphics.TestMultipleSlider;

   --  Test CreateProgressbar / SetProgressbarValue
   Graphics.TestProgressbar;

   --  Test CreateMessageBox
   Graphics.TestMessagebox;

   --  Test createImage / DrawImage
   Images.TestImage;

   --  Test declare bloc
   runtime.TestDeclare;

   --  Test Exception handling
   runtime.TestException;

   --  Test StartAudio/SetAudioCallback/StartAudio
   audio.TestsAudio;

   --  Test synth
   synth.TestsSynth;

   Label1:=Insa.Graphics.CreateLabel(0,0);
   Insa.Graphics.SetLabelText(Label1, "That's all, folks !");

   loop
      null;
   end loop;

end Main;
