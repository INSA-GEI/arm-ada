-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;
with Ada.Finalization;
with Insa.Keys;

with Ada.Strings;

package Insa.Simulator is
   
   --pragma Elaborate_Body;
   SocketException           : exception;
   type FinalizeObject is new Ada.Finalization.Controlled with private;
   
   procedure Open;
   procedure Close;
   function IsSocketOpen return Boolean;
   
   procedure SendMessage(Msg : String);
   function ReceiveMessage return String;
   function GetListenerBuffer return String;
   
   procedure KeyPressedEventReceived(Msg: String);
   procedure KeyReleasedEventReceived(Msg:String);
   function GetSimulatorKeyState (Key: Keys.KEY_ID) return Keys.KEY_STATE;

private
   type FinalizeObject is new Ada.Finalization.Controlled with
      record
         Flag                : Boolean  := False;
      end record;
   
   -- override operation, used to execute code when program end
   procedure Finalize  (E    : in out FinalizeObject);  
end Insa.Simulator;
