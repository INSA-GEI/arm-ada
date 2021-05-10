-- Package Insa.Simulator.Common
-- Common functions for various simulator specific actions
--

-- pragma Ada_95;
with Insa.Graphics; use Insa.Graphics;
with Insa.Memory; use Insa.Memory;
with Interfaces; use Interfaces;

package Insa.Simulator.Common is

   procedure ColorToRGB16(C: in COLOR; Msb: out BYTE; Lsb: out BYTE);
   procedure MemoryByteToRGB16(M: in MEMORY_BYTE; Msb: out BYTE; Lsb: out BYTE);

end Insa.Simulator.Common;
