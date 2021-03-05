-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;
with Ada.Finalization;

package Insa.Simulator is
   
   SocketException           : exception;
   type FinalizeObject is new Ada.Finalization.Controlled with private;
   
   procedure Open;
   procedure Close;
   function IsSocketOpen return Boolean;
   
   procedure SendMessage(Msg : String);
   function ReceiveMessage return String;
   function GetListenerBuffer return String;
   
private
   type FinalizeObject is new Ada.Finalization.Controlled with
      record
         Flag                : Boolean  := False;
      end record;
   
   -- override operation, used to execute code when program end
   procedure Finalize  (E    : in out FinalizeObject);  
end Insa.Simulator;
