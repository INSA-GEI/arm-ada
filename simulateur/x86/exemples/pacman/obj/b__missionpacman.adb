pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__missionpacman.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__missionpacman.adb");
pragma Suppress (Overflow_Check);
with Ada.Exceptions;

package body ada_main is

   E077 : Short_Integer; pragma Import (Ada, E077, "system__os_lib_E");
   E010 : Short_Integer; pragma Import (Ada, E010, "ada__exceptions_E");
   E015 : Short_Integer; pragma Import (Ada, E015, "system__soft_links_E");
   E027 : Short_Integer; pragma Import (Ada, E027, "system__exception_table_E");
   E042 : Short_Integer; pragma Import (Ada, E042, "ada__containers_E");
   E072 : Short_Integer; pragma Import (Ada, E072, "ada__io_exceptions_E");
   E057 : Short_Integer; pragma Import (Ada, E057, "ada__strings_E");
   E059 : Short_Integer; pragma Import (Ada, E059, "ada__strings__maps_E");
   E063 : Short_Integer; pragma Import (Ada, E063, "ada__strings__maps__constants_E");
   E047 : Short_Integer; pragma Import (Ada, E047, "interfaces__c_E");
   E029 : Short_Integer; pragma Import (Ada, E029, "system__exceptions_E");
   E083 : Short_Integer; pragma Import (Ada, E083, "system__object_reader_E");
   E052 : Short_Integer; pragma Import (Ada, E052, "system__dwarf_lines_E");
   E023 : Short_Integer; pragma Import (Ada, E023, "system__soft_links__initialize_E");
   E041 : Short_Integer; pragma Import (Ada, E041, "system__traceback__symbolic_E");
   E103 : Short_Integer; pragma Import (Ada, E103, "ada__tags_E");
   E101 : Short_Integer; pragma Import (Ada, E101, "ada__streams_E");
   E134 : Short_Integer; pragma Import (Ada, E134, "gnat_E");
   E115 : Short_Integer; pragma Import (Ada, E115, "system__file_control_block_E");
   E114 : Short_Integer; pragma Import (Ada, E114, "system__finalization_root_E");
   E112 : Short_Integer; pragma Import (Ada, E112, "ada__finalization_E");
   E111 : Short_Integer; pragma Import (Ada, E111, "system__file_io_E");
   E154 : Short_Integer; pragma Import (Ada, E154, "system__storage_pools_E");
   E150 : Short_Integer; pragma Import (Ada, E150, "system__finalization_masters_E");
   E160 : Short_Integer; pragma Import (Ada, E160, "system__storage_pools__subpools_E");
   E121 : Short_Integer; pragma Import (Ada, E121, "ada__calendar_E");
   E119 : Short_Integer; pragma Import (Ada, E119, "ada__calendar__delays_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "ada__text_io_E");
   E156 : Short_Integer; pragma Import (Ada, E156, "system__pool_global_E");
   E117 : Short_Integer; pragma Import (Ada, E117, "insa_E");
   E211 : Short_Integer; pragma Import (Ada, E211, "insa__audio_E");
   E213 : Short_Integer; pragma Import (Ada, E213, "insa__audio__synthesizer_E");
   E206 : Short_Integer; pragma Import (Ada, E206, "insa__base64_E");
   E127 : Short_Integer; pragma Import (Ada, E127, "insa__keys_E");
   E129 : Short_Integer; pragma Import (Ada, E129, "insa__simulator_E");
   E140 : Short_Integer; pragma Import (Ada, E140, "insa__timer_E");
   E138 : Short_Integer; pragma Import (Ada, E138, "insa__simulator__tasks_E");
   E005 : Short_Integer; pragma Import (Ada, E005, "carte_E");
   E174 : Short_Integer; pragma Import (Ada, E174, "insa__graphics_E");
   E172 : Short_Integer; pragma Import (Ada, E172, "ecran_E");
   E208 : Short_Integer; pragma Import (Ada, E208, "insa__memory_E");
   E184 : Short_Integer; pragma Import (Ada, E184, "insa__graphics__images_E");
   E209 : Short_Integer; pragma Import (Ada, E209, "sprites_E");
   E182 : Short_Integer; pragma Import (Ada, E182, "lab_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      declare
         procedure F1;
         pragma Import (Ada, F1, "insa__simulator__finalize_body");
      begin
         E129 := E129 - 1;
         F1;
      end;
      declare
         procedure F2;
         pragma Import (Ada, F2, "insa__simulator__finalize_spec");
      begin
         F2;
      end;
      E156 := E156 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "system__pool_global__finalize_spec");
      begin
         F3;
      end;
      E008 := E008 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "ada__text_io__finalize_spec");
      begin
         F4;
      end;
      E160 := E160 - 1;
      declare
         procedure F5;
         pragma Import (Ada, F5, "system__storage_pools__subpools__finalize_spec");
      begin
         F5;
      end;
      E150 := E150 - 1;
      declare
         procedure F6;
         pragma Import (Ada, F6, "system__finalization_masters__finalize_spec");
      begin
         F6;
      end;
      declare
         procedure F7;
         pragma Import (Ada, F7, "system__file_io__finalize_body");
      begin
         E111 := E111 - 1;
         F7;
      end;
      declare
         procedure Reraise_Library_Exception_If_Any;
            pragma Import (Ada, Reraise_Library_Exception_If_Any, "__gnat_reraise_library_exception_if_any");
      begin
         Reraise_Library_Exception_If_Any;
      end;
   end finalize_library;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (Ada, s_stalib_adafinal, "system__standard_library__adafinal");

      procedure Runtime_Finalize;
      pragma Import (C, Runtime_Finalize, "__gnat_runtime_finalize");

   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      Runtime_Finalize;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;
   pragma Favor_Top_Level (No_Param_Proc);

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Default_Secondary_Stack_Size : System.Parameters.Size_Type;
      pragma Import (C, Default_Secondary_Stack_Size, "__gnat_default_ss_size");
      Bind_Env_Addr : System.Address;
      pragma Import (C, Bind_Env_Addr, "__gl_bind_env_addr");

      procedure Runtime_Initialize (Install_Handler : Integer);
      pragma Import (C, Runtime_Initialize, "__gnat_runtime_initialize");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
      Binder_Sec_Stacks_Count : Natural;
      pragma Import (Ada, Binder_Sec_Stacks_Count, "__gnat_binder_ss_count");
      Default_Sized_SS_Pool : System.Address;
      pragma Import (Ada, Default_Sized_SS_Pool, "__gnat_default_ss_pool");

   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;

      ada_main'Elab_Body;
      Default_Secondary_Stack_Size := System.Parameters.Runtime_Default_Sec_Stack_Size;
      Binder_Sec_Stacks_Count := 1;
      Default_Sized_SS_Pool := Sec_Default_Sized_Stacks'Address;

      Runtime_Initialize (1);

      Finalize_Library_Objects := finalize_library'access;

      Ada.Exceptions'Elab_Spec;
      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E027 := E027 + 1;
      Ada.Containers'Elab_Spec;
      E042 := E042 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E072 := E072 + 1;
      Ada.Strings'Elab_Spec;
      E057 := E057 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E059 := E059 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E063 := E063 + 1;
      Interfaces.C'Elab_Spec;
      E047 := E047 + 1;
      System.Exceptions'Elab_Spec;
      E029 := E029 + 1;
      System.Object_Reader'Elab_Spec;
      E083 := E083 + 1;
      System.Dwarf_Lines'Elab_Spec;
      E052 := E052 + 1;
      System.Os_Lib'Elab_Body;
      E077 := E077 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E023 := E023 + 1;
      E015 := E015 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E041 := E041 + 1;
      E010 := E010 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Tags'Elab_Body;
      E103 := E103 + 1;
      Ada.Streams'Elab_Spec;
      E101 := E101 + 1;
      Gnat'Elab_Spec;
      E134 := E134 + 1;
      System.File_Control_Block'Elab_Spec;
      E115 := E115 + 1;
      System.Finalization_Root'Elab_Spec;
      E114 := E114 + 1;
      Ada.Finalization'Elab_Spec;
      E112 := E112 + 1;
      System.File_Io'Elab_Body;
      E111 := E111 + 1;
      System.Storage_Pools'Elab_Spec;
      E154 := E154 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Finalization_Masters'Elab_Body;
      E150 := E150 + 1;
      System.Storage_Pools.Subpools'Elab_Spec;
      E160 := E160 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E121 := E121 + 1;
      Ada.Calendar.Delays'Elab_Body;
      E119 := E119 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E008 := E008 + 1;
      System.Pool_Global'Elab_Spec;
      E156 := E156 + 1;
      E117 := E117 + 1;
      E211 := E211 + 1;
      E213 := E213 + 1;
      E206 := E206 + 1;
      Insa.Simulator'Elab_Spec;
      E127 := E127 + 1;
      Insa.Timer'Elab_Spec;
      Insa.Simulator.Tasks'Elab_Spec;
      E138 := E138 + 1;
      Insa.Simulator'Elab_Body;
      E129 := E129 + 1;
      E140 := E140 + 1;
      E005 := E005 + 1;
      E174 := E174 + 1;
      E172 := E172 + 1;
      E208 := E208 + 1;
      E184 := E184 + 1;
      sprites'elab_spec;
      E209 := E209 + 1;
      Lab'Elab_Spec;
      Lab'Elab_Body;
      E182 := E182 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_missionpacman");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      if gnat_argc = 0 then
         gnat_argc := argc;
         gnat_argv := argv;
      end if;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   /home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/carte.o
   --   /home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/ecran.o
   --   /home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/sprites.o
   --   /home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/lab.o
   --   /home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/missionpacman.o
   --   -L/home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/
   --   -L/home/dimercur/arm-ada/simulateur/x86/exemples/pacman/obj/
   --   -L/home/dimercur/Travail/git/arm-ada/simulateur/x86/lib_ada/
   --   -L/home/dimercur/opt/GNAT/2020-x86/lib/gcc/x86_64-pc-linux-gnu/9.3.1/adalib/
   --   -static
   --   -lgnat
   --   -ldl
--  END Object file/option list   

end ada_main;