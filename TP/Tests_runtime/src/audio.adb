------------------------------------------------------------------------------
--                                                                          --
--                             Tests Audio                                  --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Insa, Insa.Audio, Insa.Graphics,Insa.Keys;
use Insa, Insa.Audio, Insa.Graphics;

package body audio is

   AudioBuffer: AUDIO_BUFFER;
   GenererSon:Boolean:=False;
   
   Volume: Integer;
   Freq: Integer;
   Shape: Integer;
   
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
   
   -- test  StartAudio / StopAudio
   procedure TestsAudio is
      Label,Label2: Insa.Graphics.PWidget;
      
      VolumeSlider: Insa.Graphics.PWidget;
      VolumeSliderLabel: Insa.Graphics.PWidget;
      
      FreqSlider: Insa.Graphics.PWidget;
      FreqSliderLabel: Insa.Graphics.PWidget;
      
      ShapeSlider: Insa.Graphics.PWidget;
      ShapeSliderLabel: Insa.Graphics.PWidget;
      
      Button: Insa.Graphics.PWidget;
      ButtonLabel: Insa.Graphics.PWidget;
      ButtonLastState: boolean:=False;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Audio");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      VolumeSlider:=Insa.Graphics.CreateSlider(-50, 0, Insa.Graphics.SCREEN_WIDTH-150);
      VolumeSliderLabel:=Insa.Graphics.AddLabelToSlider(VolumeSlider,Insa.Graphics.SCREEN_WIDTH/2,0,-1);
      Insa.Graphics.SetLabelText(VolumeSliderLabel, "Vol: 0 %");

      FreqSlider:=Insa.Graphics.CreateSlider(-50, 30, Insa.Graphics.SCREEN_WIDTH-150);
      FreqSliderLabel:=Insa.Graphics.AddLabelToSlider(FreqSlider,Insa.Graphics.SCREEN_WIDTH/2,0,-1);
      Insa.Graphics.SetLabelText(FreqSliderLabel, "Freq: 20 Hz");
      
      ShapeSlider:=Insa.Graphics.CreateSlider(-50, 60, Insa.Graphics.SCREEN_WIDTH-150);
      ShapeSliderLabel:=Insa.Graphics.AddLabelToSlider(ShapeSlider,Insa.Graphics.SCREEN_WIDTH/2,0,-1);
      Insa.Graphics.SetLabelText(ShapeSliderLabel, "Square");
      
      Button:=Insa.Graphics.CreateButton(0, -60, 150);
      ButtonLabel:=Insa.Graphics.AddLabelToButton(Button);
      Insa.Graphics.SetLabelText(ButtonLabel, "Start");
      
      insa.Audio.StartAudio;
      insa.Audio.SetAudioCallback(AudioCallback'Access);
      insa.Audio.StartAudio;
      
      while Insa.Keys.GetKeyState(Insa.Keys.Key_A) /= Insa.Keys.Key_Pressed loop
         -- Insa.SysDelay(100);

         Volume := Integer(Insa.Graphics.GetSliderValue(VolumeSlider));
         Insa.Graphics.SetLabelText(VolumeSliderLabel, "Vol: " & Integer'Image(Volume) & " %");
         
         if Insa.Graphics.GetButtonState(Button) and 
           not ButtonLastState then
            ButtonLastState := True;
            
            if GenererSon then
               GenererSon:=false;
               Insa.Graphics.SetLabelText(ButtonLabel, "Start");
            else
               GenererSon:=true;
               Insa.Graphics.SetLabelText(ButtonLabel, "Stop");
            end if;
         else if not Insa.Graphics.GetButtonState(Button) and
              ButtonLastState then
               ButtonLastState := False;
            end if;
         end if;
      end loop;

 
      insa.audio.StopAudio;
      
      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestsAudio;
end audio;
