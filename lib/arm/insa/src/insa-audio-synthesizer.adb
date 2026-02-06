-- Package Insa.Audio.Synthetiser
-- High level note and music generation (synthetiser)
--

package body Insa.Audio.Synthesizer is
	
   procedure SYNTH_Start is
      
   begin
      null;
   end Synth_Start;

   procedure SYNTH_Stop is
      
   begin
      null;
   end Synth_Stop;

   procedure SYNTH_SetMainVolume(Volume: INTEGER) is
      
   begin
      null;
   end SYNTH_SetMainVolume;

   procedure SYNTH_SetVolume(Channel: INTEGER; Volume: INTEGER) is
      
   begin
      null;
   end SYNTH_SetVolume;

   procedure SYNTH_SetInstrument(Channel: INTEGER; Instrument: SYNTH_INSTRUMENT_ACCESS) is
      
   begin
      null;
   end SYNTH_SetInstrument;

   procedure SYNTH_NoteOn(Channel: INTEGER; Note: SYNTH_NOTE) is
      
   begin
      null;
   end SYNTH_NoteOn;
	
   procedure SYNTH_NoteOff(Channel: INTEGER) is
      
   begin
      null;
   end SYNTH_NoteOff;

   procedure MELODY_Start(Music: in MELODY_NOTES; Length: NATURAL) is
      
   begin
      null;
   end MELODY_Start;

   procedure MELODY_Stop is
      
   begin
      null;
   end MELODY_Stop;

   function MELODY_GetPosition return BYTE is

      Pos: BYTE;
   begin
      Pos:=0;
      
      return Pos;
   end MELODY_GetPosition;

end Insa.Audio.Synthesizer;
