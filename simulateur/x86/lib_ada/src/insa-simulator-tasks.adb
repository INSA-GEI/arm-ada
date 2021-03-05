-- Package Insa.Simulator.Tasks
-- Functions for doing background task with simulator
--

-- pragma Ada_95;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Exceptions;  use Ada.Exceptions;
with Ada.Strings;
with GNAT.Source_Info;

with Insa.Simulator;
  
package body Insa.Simulator.Tasks is

   type TASK_CALLBACK is access procedure;
   pragma Convention(C, TASK_CALLBACK);
   
   procedure SocketListenerCallback;
   pragma Convention(C, SocketListenerCallback);
 
   -----------------------------------------------------------------------------
   -- SocketListener task related function and procedure
   -----------------------------------------------------------------------------
   
   procedure SocketListenerCallback is
   begin
      -- Ada.Text_IO.Put_Line("[task receiver] Task handler called");
      
      declare
         -- Msg : String := ReceiveMessage;
         Msg : String := GetListenerBuffer;
      begin
         if Msg'Length /= 0 then
            Ada.Text_IO.Put_Line ("[receiver task] Message received (length=" & Integer'Image(Msg'Length) & ") = " & Msg);
         else
            Ada.Text_IO.Put_Line ("[receiver task] No message");
         end if;
      end;
   end SocketListenerCallback;
   
   procedure SetSocketListenerCallback is
      procedure SetSocketListenerCallback_Wrp(SysCallback: TASK_CALLBACK);
      pragma Import (C, SetSocketListenerCallback_Wrp, "socket_setcallback");
   begin
      SetSocketListenerCallback_Wrp(SocketListenerCallback'Access);
   end SetSocketListenerCallback;
   
   procedure ClearSocketListenerCallback is
      procedure ClearSocketListenerCallback_Wrp;
      pragma Import (C, ClearSocketListenerCallback_Wrp, "socket_clearcallback");
   begin
      ClearSocketListenerCallback_Wrp;
   end ClearSocketListenerCallback;
   
   procedure StartSocketListenerTask is
      function StartSocketListenerTask_Wrp return Integer;
      pragma Import (C, StartSocketListenerTask_Wrp, "socket_startthread");
      
      RetVal : Integer;
   begin
      SetSocketListenerCallback;
      RetVal := StartSocketListenerTask_Wrp;
      
      if RetVal /= 0 then
         raise SocketTaskException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket task listener creation failed. Code (" & Integer'Image(RetVal) & ")";
      else
         Ada.Text_IO.Put_Line("[receiver task] Task handler started");
      end if;
   end StartSocketListenerTask;
   
   procedure StopSocketListenerTask is
      function StopSocketListenerTask_Wrp return Integer;
      pragma Import (C, StopSocketListenerTask_Wrp, "socket_stopthread");
      
      RetVal : Integer;
   begin 
      RetVal := StopSocketListenerTask_Wrp;
      
      if RetVal /= 0 then
         raise SocketTaskException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Socket task listener cancelation failed. Code (" & Integer'Image(RetVal) & ")";
      else
         Ada.Text_IO.Put_Line("[receiver task] Task handler canceled");
      end if;
      
      ClearSocketListenerCallback;
   end StopSocketListenerTask;
   
   
   -----------------------------------------------------------------------------
   -- Timer task related function and procedure
   -----------------------------------------------------------------------------
   
   procedure TimerCallback is
   begin
      Ada.Text_IO.Put_Line("[timer task] Task handler called");
   end TimerCallback;
   
   procedure SetTimerCallback is
      procedure SetTimerCallback_Wrp(SysCallback: TASK_CALLBACK);
      pragma Import (C, SetTimerCallback_Wrp, "timer_setcallback");
   begin
      SetTimerCallback_Wrp(SocketListenerCallback'Access);
   end SetTimerCallback;
   
   procedure ClearTimerCallback is
      procedure ClearTimerCallback_Wrp;
      pragma Import (C, ClearTimerCallback_Wrp, "timer_clearcallback");
   begin
      ClearTimerCallback_Wrp;
   end ClearTimerCallback;
   
   procedure StartTimerTask is
      function StartTimerTask_Wrp return Integer;
      pragma Import (C, StartTimerTask_Wrp, "timer_startthread");
      
      RetVal : Integer;
   begin
      SetTimerCallback;
      RetVal := StartTimerTask_Wrp;
      
      if RetVal /= 0 then
         raise SocketTaskException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Timer task listener creation failed. Code (" & Integer'Image(RetVal) & ")";
      else
         Ada.Text_IO.Put_Line("[timer task] Task handler started");
      end if;
   end StartTimerTask;
   
   procedure StopTimerTask is
      function StopTimerTask_Wrp return Integer;
      pragma Import (C, StopTimerTask_Wrp, "timer_stopthread");
      
      RetVal : Integer;
   begin 
      RetVal := StopTimerTask_Wrp;
      
      if RetVal /= 0 then
         raise SocketTaskException with GNAT.Source_Info.File & " : " & Integer'Image(GNAT.Source_Info.Line) & " Timer task listener cancelation failed. Code (" & Integer'Image(RetVal) & ")";
      else
         Ada.Text_IO.Put_Line("[timer task] Task handler canceled");
      end if;
      
      ClearTimerCallback;
   end StopTimerTask;
     
end Insa.Simulator.Tasks;
