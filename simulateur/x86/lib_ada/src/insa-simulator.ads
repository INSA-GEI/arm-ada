-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;

package Insa.Simulator is
   
   SocketException              : exception;
   
   procedure Test;
   procedure Init;
   procedure Close;
   procedure SendMessage(Msg    : String);
   function ReceiveMessage return String;
   
end Insa.Simulator;
