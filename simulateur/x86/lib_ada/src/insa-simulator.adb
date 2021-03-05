-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Exceptions;  use Ada.Exceptions;
with Ada.Strings;
with GNAT.Source_Info;
with GNAT.Exception_Traces;

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
   
begin
   GNAT.Exception_Traces.Trace_On (GNAT.Exception_Traces.Every_Raise); 
   Ada.Text_IO.Put_Line ("[sim] Initialize socket");
      
   Open;
   Tasks.StartSocketListenerTask;
   
   FinalizeFlagPtr := new FinalizeObject;
   FinalizeFlagPtr.Flag:=True;
end Insa.Simulator;
