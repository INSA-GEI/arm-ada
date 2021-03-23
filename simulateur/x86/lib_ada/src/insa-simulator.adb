-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Exceptions;  use Ada.Exceptions;
with Ada.Strings;
with Ada.Strings.Fixed;

with GNAT.Source_Info;
with GNAT.Exception_Traces;

with Insa.Keys;
with Ada.Finalization;

with INSA.Simulator.Tasks;
--  with System.Task_Primitives.Operations;

package body Insa.Simulator is
   
   SocketOpenFlag                                                : Boolean := False;
   
   STATUS_NO_ERROR                                               : constant Integer := 0;
   STATUS_SOCKET_CREATION_ERROR                                  : constant Integer := -1;
   STATUS_CONNECTION_ERROR                                       : constant Integer := -2;
   STATUS_WRITE_ERROR                                            : constant Integer := -3;
   STATUS_CLOSE_ERROR                                            : constant Integer := -4;
   STATUS_READ_ERROR                                             : constant Integer := -5;
   
   RECEIVE_BUFFER_LENGTH                                         : constant Integer := 65535;
   
   type ReceiveBufferType is array (0..RECEIVE_BUFFER_LENGTH) of Character;
   type ReceiveBufferAccess is access all ReceiveBufferType;
   
   ReceiveBuffer                                                 : ReceiveBufferType;
      
   type PtrFinalizeObject_Type is access all FinalizeObject;      -- global access type
   FinalizeFlagPtr                                               : PtrFinalizeObject_Type;
   
   procedure Finalize  (E                                        : in out FinalizeObject) is  -- override operation
   begin
            
      Ada.Text_IO.Put_Line ("[sim] Close socket");
      Close;
      
      Tasks.StopSocketListenerTask;
      E.Flag:=False;
   end Finalize;
   
   procedure Open is
      function Open_Wrp return Integer;
      pragma Import (C, Open_Wrp, "socket_init");
      
      RetVal                                                     : Integer;
   begin
      if SocketOpenFlag = False then
         RetVal := Open_Wrp;
      end if;
      
      if RetVal /= STATUS_NO_ERROR then
         SocketOpenFlag := False;
         
         if RetVal = STATUS_SOCKET_CREATION_ERROR then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket creation failed. Code (" & Integer'Image(RetVal) & ")";
         elsif RetVal = STATUS_CONNECTION_ERROR then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket connection refused. Code (" & Integer'Image(RetVal) & ")";
         else
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Unknown error during socket intialization. Code (" & Integer'Image(RetVal) & ")";
         end if;
      else
         SocketOpenFlag := True;
      end if;
    
   end Open;
   
   function IsSocketOpen return Boolean is
   begin
      return SocketOpenFlag;
   end IsSocketOpen;
   
   procedure Close is
      function Close_Wrp return Integer;
      pragma Import (C, Close_Wrp, "socket_close");
      
      RetVal                                                     : Integer;
   begin
      if SocketOpenFlag then
         RetVal := Close_Wrp;
         SocketOpenFlag := False;
      end if;
      
      if RetVal /= STATUS_NO_ERROR then
         if RetVal = STATUS_CLOSE_ERROR then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket close failed. Code (" & Integer'Image(RetVal) & ")";
         else
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Unknown error during socket closure. Code (" & Integer'Image(RetVal) & ")";
         end if;
      end if;
   end Close;
   
   procedure SendMessage(Msg                                     : String) is
      function SendMessage_Wrp(Msg                               : String; MsgLen: Integer) return Integer;
      pragma Import (C, SendMessage_Wrp, "socket_write");
      
      RetVal                                                     : Integer;
   begin
      if SocketOpenFlag = False then
         Open;
         SocketOpenFlag := True;
      end if;
      
      --Ada.Text_IO.Put_Line("sendMessage => " & Msg);
      --Ada.Text_IO.Put_Line("Msg'length = " & Integer'Image(Msg'Length));
        
      RetVal := SendMessage_Wrp (Msg & ASCII.LF, Msg'Length+1);
      if RetVal /= STATUS_NO_ERROR then
         if RetVal = STATUS_WRITE_ERROR then 
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket write failed. Code (" & Integer'Image(RetVal) & ")";
         elsif RetVal > 0 then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket write failed (partial write). Code (" & Integer'Image(RetVal) & ")";
         else
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Unknown error during socket write. Code (" & Integer'Image(RetVal) & ")";
         end if;
         
      end if;
   end SendMessage;
   
   function ReceiveMessage return String is
      
      function ReceiveMessage_Wrp(Buffer                         : ReceiveBufferAccess; BufferLen: Integer) return Integer;
      pragma Import (C, ReceiveMessage_Wrp, "socket_read");
      
      RetVal                                                     : Integer;
   begin
      if SocketOpenFlag = False then
         Open;
         SocketOpenFlag := True;
      end if;
      
      RetVal := ReceiveMessage_Wrp (ReceiveBuffer'Unrestricted_Access, RECEIVE_BUFFER_LENGTH);
      
      if RetVal < 0 then
         if RetVal = STATUS_READ_ERROR then 
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket read failed. Code (" & Integer'Image(RetVal) & ")";
         else
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Unknown error during socket read. Code (" & Integer'Image(RetVal) & ")";
         end if;
      end if;
      
      declare
         Msg                                                     : String (1..RetVal);
      begin
         for I in 1..RetVal loop
            Msg(I):=ReceiveBuffer(I-1);
         end loop;
        
         return Msg;
      end;
      
   end ReceiveMessage;
   
   function GetListenerBuffer return String is
      
      function GetListenerBuffer_Wrp(Buffer                         : ReceiveBufferAccess; BufferLen: Integer) return Integer;
      pragma Import (C, GetListenerBuffer_Wrp, "socket_getlistenermessage");
      
      RetVal                                                     : Integer;
   begin
      if SocketOpenFlag = False then
         Open;
         SocketOpenFlag := True;
      end if;
      
      RetVal := GetListenerBuffer_Wrp (ReceiveBuffer'Unrestricted_Access, RECEIVE_BUFFER_LENGTH);
      
      declare
         Msg                                                     : String (1..RetVal);
      begin
         for I in 1..RetVal loop
            Msg(I):=ReceiveBuffer(I-1);
         end loop;
        
         return Msg;
      end;
      
   end GetListenerBuffer;
   
   KeyStates : Keys.KEY_LIST;
   
   procedure KeyPressedEventReceived(Msg: String) is
   begin
      if Ada.Strings.Fixed.Index (Msg, "=A") > 0 then
         KeyStates.A := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=B") > 0 then
         KeyStates.B := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=X") > 0 then
         KeyStates.X := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=Y") > 0 then
         KeyStates.Y := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=UP") > 0 then
         KeyStates.Up := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=DOWN") > 0 then
         KeyStates.Down := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=LEFT") > 0 then
         KeyStates.Left := Keys.Key_Pressed;
      elsif Ada.Strings.Fixed.Index (Msg, "=RIGHT") > 0 then
         KeyStates.Right := Keys.Key_Pressed;
      else
         -- Unknown key
         null;
      end if;
   end KeyPressedEventReceived;
   
   procedure KeyReleasedEventReceived(Msg: String) is
   begin
      if Ada.Strings.Fixed.Index (Msg, "=A") > 0 then
         KeyStates.A := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=B") > 0 then
         KeyStates.B := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=X") > 0 then
         KeyStates.X := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=Y") > 0 then
         KeyStates.Y := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=UP") > 0 then
         KeyStates.Up := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=DOWN") > 0 then
         KeyStates.Down := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=LEFT") > 0 then
         KeyStates.Left := Keys.Key_Released;
      elsif Ada.Strings.Fixed.Index (Msg, "=RIGHT") > 0 then
         KeyStates.Right := Keys.Key_Released;
      else
         -- Unknown key
         null;
      end if;
   end KeyReleasedEventReceived;
   
   function GetSimulatorKeyState (Key: Keys.KEY_ID) return Keys.KEY_STATE is
      State : Keys.KEY_STATE;
   begin
      if Key = Keys.Key_A then
         State := KeyStates.A;
      elsif Key = Keys.Key_B then
         State := KeyStates.B;
      elsif Key = Keys.Key_X then
         State := KeyStates.X;
      elsif Key = Keys.Key_Y then
         State := KeyStates.Y;
      elsif Key = Keys.Key_Up then
         State := KeyStates.Up;
      elsif Key = Keys.Key_Down then
         State := KeyStates.Down;
      elsif Key = Keys.Key_Left then
         State := KeyStates.Left;
      elsif Key = Keys.Key_Right then
         State := KeyStates.Right;
      else
         null;
      end if;
      
      return State;
   end GetSimulatorKeyState;
   
   LeftKnob: Keys.POTENTIOMETER_VALUE:=0;
   RightKnob: Keys.POTENTIOMETER_VALUE:=0;
   
   procedure KnobsEventReceived(Msg: String) is
   begin
      if Ada.Strings.Fixed.Index (Msg, "=") > 0 then
         KeyStates.A := Keys.Key_Released;
      end if;
   end KnobsEventReceived;
   
   function GetKnobsState (Knob: Keys.POTENTIOMETER_ID) return Keys.POTENTIOMETER_VALUE is
      Val: Keys.POTENTIOMETER_VALUE;
   begin
      Val:=RightKnob;
      
      if Knob = Keys.Potentiometer_Left then
         Val:= LeftKnob;   
      end if;
      
      return Val;
   end GetKnobsState;
     
   AccelerometerValues: Sensors.SENSOR_VALUES := (0.0,0.0,0.0);
   procedure AccelerometerEventReceived(Msg: String) is
   begin
      null;
   end AccelerometerEventReceived;
   
   function GetSimAccelerometerValues return Sensors.SENSOR_VALUES is
   begin
      return AccelerometerValues;
   end GetSimAccelerometerValues;
      
   GyroscopeValues: Sensors.SENSOR_VALUES := (0.0,0.0,0.0);
   procedure GyroscopeEventReceived(Msg: String) is
   begin
      null;
   end GyroscopeEventReceived;
   
   function GetSimGyrosocopeValues return Sensors.SENSOR_VALUES is
   begin
      return GyroscopeValues;
   end GetSimGyrosocopeValues; 
   
   MagnetometerValues: Sensors.SENSOR_VALUES := (0.0,0.0,0.0);
   procedure MagnetometerEventReceived(Msg: String) is
   begin
      null;
   end MagnetometerEventReceived;
   
   function GetSimMagnetometerValues return Sensors.SENSOR_VALUES is
   begin
      return MagnetometerValues;
   end GetSimMagnetometerValues; 
   
begin
   GNAT.Exception_Traces.Trace_On (GNAT.Exception_Traces.Every_Raise); 
   Ada.Text_IO.Put_Line ("[sim] Initialize socket");
      
   Open;
   Tasks.StartSocketListenerTask;
   
   FinalizeFlagPtr := new FinalizeObject;
   FinalizeFlagPtr.Flag:=True;
   
   KeyStates.A:= Keys.Key_Released;
   KeyStates.B:= Keys.Key_Released;
   KeyStates.X:= Keys.Key_Released;
   KeyStates.Y:= Keys.Key_Released;
   KeyStates.Up:= Keys.Key_Released;
   KeyStates.Down:= Keys.Key_Released;
   KeyStates.Left:= Keys.Key_Released;
   KeyStates.Right:= Keys.Key_Released;
   KeyStates.Center:= Keys.Key_Released;
   
end Insa.Simulator;
