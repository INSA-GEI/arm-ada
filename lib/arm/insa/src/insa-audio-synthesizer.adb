-- Package Insa.Audio.Synthetiser
-- High level note and music generation (synthetiser)
--

-- pragma Ada_95;

-- with Insa.Audio;
-- use Insa.Audio;

package body Insa.Audio.Synthesizer is
	
   procedure SYNTH_Start is
      --   function Wrapper_SYNTH_Start return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_Start, "SYNTH_Start");
   begin
      --   return Wrapper_SYNTH_Start;
      null;
   end Synth_Start;

   procedure SYNTH_Stop is
      --   function Wrapper_SYNTH_Stop return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_Stop, "SYNTH_Stop");
   begin
      --   return Wrapper_SYNTH_Stop;
      null;
   end Synth_Stop;

   procedure SYNTH_SetMainVolume(Volume: INTEGER) is
      --   function Wrapper_SYNTH_SetMainVolume(Volume: INTEGER) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetMainVolume, "SYNTH_SetMainVolume");
   begin
      --   return Wrapper_SYNTH_SetMainVolume(Volume);
      null;
   end SYNTH_SetMainVolume;

   procedure SYNTH_SetVolume(Channel: INTEGER; Volume: INTEGER) is
      --   function Wrapper_SYNTH_SetVolume(Channel: INTEGER; Volume: INTEGER) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetVolume, "SYNTH_SetVolume");
   begin
      --   return Wrapper_SYNTH_SetVolume(Channel, Volume);
      null;
   end SYNTH_SetVolume;

   procedure SYNTH_SetInstrument(Channel: INTEGER; Instrument: SYNTH_INSTRUMENT_ACCESS) is
      --   function Wrapper_SYNTH_SetInstrument(Channel: INTEGER; Instrument_Access: SYNTH_INSTRUMENT_ACCESS) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetInstrument, "SYNTH_SetInstrument");
   begin
      --   return Wrapper_SYNTH_SetInstrument(Channel, Instrument);
      null;
   end SYNTH_SetInstrument;

   procedure SYNTH_NoteOn(Channel: INTEGER; Note: SYNTH_NOTE) is
      --   function Wrapper_SYNTH_NoteOn(Channel: INTEGER; Note: SYNTH_NOTE) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_NoteOn, "SYNTH_NoteOn");
   begin
      --   return Wrapper_SYNTH_NoteOn(Channel,Note);
      null;
   end SYNTH_NoteOn;
	
   procedure SYNTH_NoteOff(Channel: INTEGER) is
      --   function Wrapper_SYNTH_NoteOff(Channel: INTEGER) return SYNTH_STATUS;
      --  pragma Import (C, Wrapper_SYNTH_NoteOff, "SYNTH_NoteOff");
   begin
      --  return Wrapper_SYNTH_NoteOff(Channel);
      null;
   end SYNTH_NoteOff;

   procedure MELODY_Start(Music: in MELODY_NOTES; Length: NATURAL) is
      --  function Wrapper_MELODY_Start(Music_Access: MELODY_NOTES_ACCESS; Length: NATURAL) return MELODY_Status;
      --  pragma Import (C, Wrapper_MELODY_Start, "MELODY_Start");
   begin
      --  return Wrapper_MELODY_Start(Music'Unrestricted_Access, Length);
      null;
   end MELODY_Start;

   procedure MELODY_Stop is
      --  function Wrapper_MELODY_Stop return MELODY_Status;
      --  pragma Import (C, Wrapper_MELODY_Stop, "MELODY_Stop");
   begin
      --  return Wrapper_MELODY_Stop;
      null;
   end MELODY_Stop;

   function MELODY_GetPosition return BYTE is
      -- function Wrapper_MELODY_GetPosition(Position: MELODY_POSITION_ACCESS) return MELODY_Status;
      -- pragma Import (C, Wrapper_MELODY_GetPosition, "MELODY_GetPosition");

      Pos: BYTE;
      -- Status: MELODY_Status;
   begin
      -- Status:= Wrapper_MELODY_GetPosition(Pos'Unrestricted_Access);

      -- if (Status /= MELODY_SUCCESS) then
         Pos:=0;
      -- end if;

      return Pos;
   end MELODY_GetPosition;

end Insa.Audio.Synthesizer;
