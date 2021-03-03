-- Package Insa.Simulator
-- Functions for communicating with simulator
--

-- pragma Ada_95;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Exceptions;  use Ada.Exceptions;
with Ada.Strings;
with GNAT.Source_Info;
with Ada.Real_Time; use Ada.Real_Time;

package body Insa.Simulator is

   SocketNotInitialized                                          : Boolean := True;
   
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
   ReceiverTaskRun                                               : Boolean:=False;
   
   task ReceiverTask is
      pragma Priority (-1);
      entry Start;
   end ReceiverTask;
   
   procedure Test is
      procedure Test_Wrp;
      pragma Import (C, Test_Wrp, "test");
   begin
      Test_Wrp;
   end Test;
   
   procedure Init is
      function Init_Wrp return Integer;
      pragma Import (C, Init_Wrp, "socket_init");
      
      RetVal                                                     : Integer;
   begin
      RetVal := Init_Wrp;
      
      if RetVal /= STATUS_NO_ERROR then
         SocketNotInitialized := True;
         
         if RetVal = STATUS_SOCKET_CREATION_ERROR then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket creation failed. Code (" & Integer'Image(RetVal) & ")";
         elsif RetVal = STATUS_CONNECTION_ERROR then
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket connection refused. Code (" & Integer'Image(RetVal) & ")";
         else
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Unknown error during socket intialization. Code (" & Integer'Image(RetVal) & ")";
         end if;
      else
         SocketNotInitialized := False;
      end if;
      
      Ada.Text_IO.Put_Line("Launch ReceiverTask");
      ReceiverTask.Start;
      Ada.Text_IO.Put_Line("ReceiverTask launched");
   end Init;
   
   procedure Close is
      function Close_Wrp return Integer;
      pragma Import (C, Close_Wrp, "socket_close");
      
      RetVal                                                     : Integer;
   begin
      RetVal := Close_Wrp;
      
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
      if SocketNotInitialized then
         Init;
         SocketNotInitialized := False;
      end if;
      
      RetVal := SendMessage_Wrp (Msg & ASCII.LF, Msg'Length+1);
      if RetVal /= STATUS_NO_ERROR then
         if RetVal = STATUS_WRITE_ERROR then 
            raise SocketException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket write failed. Code (" & Integer'Image(RetVal) & ")";
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
      if SocketNotInitialized then
         Init;
         SocketNotInitialized := False;
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

   task body ReceiverTask is
      Next_Time : Ada.Real_Time.Time;
      Period : constant Time_Span := Milliseconds (250);
   begin
      loop
         select
            accept Start do -- Waiting for somebody to call the entry
               ReceiverTaskRun:=True;
               Ada.Text_IO.Put_Line ("Receiver task started");
      
               while ReceiverTaskRun loop
                  Next_Time := Clock + Period;
                  delay until Next_Time;
                  
                  declare
                     Msg                                         : String := ReceiveMessage;
                  begin
                     Ada.Text_IO.Put_Line ("Message received (length=" & Integer'Image(Msg'Length) & ") = " & Msg);
                  end;
               end loop;
            end Start;
         or 
            terminate;
         end select;
      end loop;
   end ReceiverTask;
   
end Insa.Simulator;
