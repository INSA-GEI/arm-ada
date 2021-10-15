-- Package Insa.Audio.Synthetiser
-- High level note and music generation (synthetiser)
--

-- pragma Ada_95;

-- with Insa.Audio;
-- use Insa.Audio;

package body Insa.Audio.Synthesizer is
	
   function SYNTH_Start return SYNTH_STATUS is
      --   function Wrapper_SYNTH_Start return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_Start, "SYNTH_Start");
   begin
      --   return Wrapper_SYNTH_Start;
      return SYNTH_SUCCESS;
   end Synth_Start;

   function SYNTH_Stop return SYNTH_STATUS is
      --   function Wrapper_SYNTH_Stop return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_Stop, "SYNTH_Stop");
   begin
      --   return Wrapper_SYNTH_Stop;
      return SYNTH_SUCCESS;
   end Synth_Stop;

   function SYNTH_SetMainVolume(Volume: INTEGER) return SYNTH_Status is
      --   function Wrapper_SYNTH_SetMainVolume(Volume: INTEGER) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetMainVolume, "SYNTH_SetMainVolume");
   begin
      --   return Wrapper_SYNTH_SetMainVolume(Volume);
      return SYNTH_SUCCESS;
   end SYNTH_SetMainVolume;

   function SYNTH_SetVolume(Channel: INTEGER; Volume: INTEGER) return SYNTH_Status is
      --   function Wrapper_SYNTH_SetVolume(Channel: INTEGER; Volume: INTEGER) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetVolume, "SYNTH_SetVolume");
   begin
      --   return Wrapper_SYNTH_SetVolume(Channel, Volume);
      return SYNTH_SUCCESS;
   end SYNTH_SetVolume;

   function SYNTH_SetInstrument(Channel: INTEGER; Instrument: SYNTH_INSTRUMENT_ACCESS) return SYNTH_Status is
      --   function Wrapper_SYNTH_SetInstrument(Channel: INTEGER; Instrument_Access: SYNTH_INSTRUMENT_ACCESS) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_SetInstrument, "SYNTH_SetInstrument");
   begin
      --   return Wrapper_SYNTH_SetInstrument(Channel, Instrument);
      return SYNTH_SUCCESS;
   end SYNTH_SetInstrument;

   function SYNTH_NoteOn(Channel: INTEGER; Note: SYNTH_NOTE) return SYNTH_STATUS is
      --   function Wrapper_SYNTH_NoteOn(Channel: INTEGER; Note: SYNTH_NOTE) return SYNTH_STATUS;
      --   pragma Import (C, Wrapper_SYNTH_NoteOn, "SYNTH_NoteOn");
   begin
      --   return Wrapper_SYNTH_NoteOn(Channel,Note);
      return SYNTH_SUCCESS;
   end SYNTH_NoteOn;
	
   function SYNTH_NoteOff(Channel: INTEGER) return SYNTH_STATUS is
      --   function Wrapper_SYNTH_NoteOff(Channel: INTEGER) return SYNTH_STATUS;
      --  pragma Import (C, Wrapper_SYNTH_NoteOff, "SYNTH_NoteOff");
   begin
      --  return Wrapper_SYNTH_NoteOff(Channel);
      return SYNTH_SUCCESS;
   end SYNTH_NoteOff;

   function MELODY_Start(Music: in MELODY_NOTES; Length: NATURAL) return MELODY_Status is
      --  function Wrapper_MELODY_Start(Music_Access: MELODY_NOTES_ACCESS; Length: NATURAL) return MELODY_Status;
      --  pragma Import (C, Wrapper_MELODY_Start, "MELODY_Start");
   begin
      --  return Wrapper_MELODY_Start(Music'Unrestricted_Access, Length);
      return MELODY_SUCCESS;
   end MELODY_Start;

   function MELODY_Stop return MELODY_Status is
      --  function Wrapper_MELODY_Stop return MELODY_Status;
      --  pragma Import (C, Wrapper_MELODY_Stop, "MELODY_Stop");
   begin
      --  return Wrapper_MELODY_Stop;
      return MELODY_SUCCESS;
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
