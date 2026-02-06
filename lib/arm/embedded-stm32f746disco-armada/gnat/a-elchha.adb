------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--    A D A . E X C E P T I O N S . L A S T _ C H A N C E _ H A N D L E R   --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--          Copyright (C) 2003-2025, Free Software Foundation, Inc.         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
--                                                                          --
-- As a special exception under Section 7 of GPL version 3, you are granted --
-- additional permissions described in the GCC Runtime Library Exception,   --
-- version 3.1, as published by the Free Software Foundation.               --
--                                                                          --
-- You should have received a copy of the GNU General Public License and    --
-- a copy of the GCC Runtime Library Exception along with this program;     --
-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
-- <http://www.gnu.org/licenses/>.                                          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

with System;
with System.Machine_Reset;

--  with System.IO;                use System.IO;
--  with GNAT.Debug_Utilities;     use GNAT.Debug_Utilities;

with Interfaces;
with Interfaces.C.Strings;

--  Default last chance handler for use with full run-time library on bare
--  board targets.

--  It dumps the exception identity and the non-symbolic traceback from the
--  point where the exception was triggered.

procedure Ada.Exceptions.Last_Chance_Handler (Except : Exception_Occurrence) is
   --  procedure Reboot;
   --  pragma Import (C, Reboot, "Reboot_System");

   --  ExceptionMessageBox
   --  Open a messagebox for information
   --  Function call is blocking until user clicks the button,
   --  then the system will reboot
   procedure ExceptionMessageBox (Msg : String; Button_Txt : String);

   procedure ExceptionMessageBox (Msg : String; Button_Txt : String) is

      type Pobj is access Integer;

      type ExceptionMessageBoxCallbackType is access
         procedure (Obj : Pobj; Event : Interfaces.Unsigned_8);
      pragma Convention (C, ExceptionMessageBoxCallbackType);

      ExceptionMessageBoxFlag : aliased Boolean := False;
      pragma Volatile (ExceptionMessageBoxFlag);

      procedure ExceptionMessageBoxCallback (Obj : Pobj;
                                          Event : Interfaces.Unsigned_8);
      pragma Convention (C, ExceptionMessageBoxCallback);

      --  Messagebox callback. Called when user clicks the button.
      --  Set the flag to true to exit the loop and reboot the system
      procedure ExceptionMessageBoxCallback (Obj : Pobj;
                                          Event : Interfaces.Unsigned_8) is

         pragma Unreferenced (Obj, Event);
      begin
         ExceptionMessageBoxFlag := True;
      end ExceptionMessageBoxCallback;

      function Wrp_UI_MESSAGEBOX_Create
        (Msg : Interfaces.C.Strings.chars_ptr;
         Button_Txt : Interfaces.C.Strings.chars_ptr_array;
         Callback : ExceptionMessageBoxCallbackType) return Pobj;
      pragma Import (C, Wrp_UI_MESSAGEBOX_Create, "UI_MESSAGEBOX_Create");

      Mbx : Pobj;
      pragma Volatile (Mbx);

      Msg_C : constant Interfaces.C.Strings.chars_ptr :=
        Interfaces.C.Strings.New_String (Msg);
      Button_Txt_Array : constant Interfaces.C.Strings.chars_ptr_array (0 .. 1)
        := (Interfaces.C.Strings.New_String (Button_Txt),
            Interfaces.C.Strings.New_String (""));
   begin
      ExceptionMessageBoxFlag := False;

      --  Create and show the messagebox
      Mbx := Wrp_UI_MESSAGEBOX_Create (Msg_C, Button_Txt_Array,
                                       ExceptionMessageBoxCallback'Access);

      --  Wait until user clicks the button
      while ExceptionMessageBoxFlag = False loop
         null;
      end loop;
   end ExceptionMessageBox;

begin
   ExceptionMessageBox ("Unhandled Ada Exception: " & ASCII.LF &
                                Exception_Name (Except) &
                                ASCII.LF & ASCII.LF &
                                Exception_Message (Except),
                              "Reboot");

   --  Put_Line ("In last chance handler");
   --  Put_Line ("Unhandled Ada Exception: " & Exception_Name (Except));
   --  Put_Line ("Message: " & Exception_Message (Except));
   --  Put_Line ("Call stack traceback locations:");

   --  Dump backtrace PC values

   --  for J in 1 .. Except.Num_Tracebacks loop
   --    Put (Image_C (Except.Tracebacks (J)));
   --    Put (" ");
   --  end loop;

   --  New_Line;

   --  Stop the machine

   System.Machine_Reset.Stop;

end Ada.Exceptions.Last_Chance_Handler;
