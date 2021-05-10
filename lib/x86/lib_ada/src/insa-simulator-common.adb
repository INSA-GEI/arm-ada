-- Package Insa.Simulator.Common
-- Common functions for various simulator specific actions
--

-- pragma Ada_95;
package body Insa.Simulator.Common is

   procedure ColorToRGB16(C: in COLOR; Msb: out BYTE; Lsb: out BYTE) is
      R,G,B: WORD;
   begin
      R:= WORD(Shift_Right((C and 16#E0#),5));
      G:= WORD(Shift_Right((C and 16#1C#),2));
      B:= WORD(C and 16#03#);

      R:= (R*31)/7;
      G:= (G*63)/7;
      B:= (B*31)/3;
         
      Msb := BYTE(Shift_Left(R,3) or Shift_Right(G,3));
      Lsb := BYTE((Shift_Left(G,5) and 16#E0#) or B);

   end ColorToRGB16;
   
   procedure MemoryByteToRGB16(M: in MEMORY_BYTE; Msb: out BYTE; Lsb: out BYTE) is
      C: COLOR:=COLOR(M);
      R,G,B: WORD;
   begin
      R:= WORD(Shift_Right((C and 16#E0#),5));
      G:= WORD(Shift_Right((C and 16#1C#),2));
      B:= WORD(C and 16#03#);

      R:= (R*31)/7;
      G:= (G*63)/7;
      B:= (B*31)/3;
         
      Msb := BYTE(Shift_Left(R,3) or Shift_Right(G,3));
      Lsb := BYTE((Shift_Left(G,5) and 16#E0#) or B);

   end MemoryByteToRGB16;

end Insa.Simulator.Common;
