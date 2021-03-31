pragma Ada_95;
pragma Warnings (Off);
with System;
package ada_main is

   gnat_argc : Integer;
   gnat_argv : System.Address;
   gnat_envp : System.Address;

   pragma Import (C, gnat_argc);
   pragma Import (C, gnat_argv);
   pragma Import (C, gnat_envp);

   gnat_exit_status : Integer;
   pragma Import (C, gnat_exit_status);

   GNAT_Version : constant String :=
                    "GNAT Version: 6.3.1 20170620 (release) [ARM/embedded-6-branch revision 249437]" & ASCII.NUL;
   pragma Export (C, GNAT_Version, "__gnat_version");

   Ada_Main_Program_Name : constant String := "_ada_missionsimon" & ASCII.NUL;
   pragma Export (C, Ada_Main_Program_Name, "__gnat_ada_main_program_name");

   procedure adainit;
   pragma Export (C, adainit, "adainit");

   procedure adafinal;
   pragma Export (C, adafinal, "adafinal");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer;
   pragma Export (C, main, "main");

   type Version_32 is mod 2 ** 32;
   u00001 : constant Version_32 := 16#2c4b673c#;
   pragma Export (C, u00001, "missionsimonB");
   u00002 : constant Version_32 := 16#b6df930e#;
   pragma Export (C, u00002, "system__standard_libraryB");
   u00003 : constant Version_32 := 16#f90293f2#;
   pragma Export (C, u00003, "system__standard_libraryS");
   u00004 : constant Version_32 := 16#4be8ce1b#;
   pragma Export (C, u00004, "interfacesS");
   u00005 : constant Version_32 := 16#491b1a63#;
   pragma Export (C, u00005, "simonB");
   u00006 : constant Version_32 := 16#0219b843#;
   pragma Export (C, u00006, "simonS");
   u00007 : constant Version_32 := 16#3ffc8e18#;
   pragma Export (C, u00007, "adaS");
   u00008 : constant Version_32 := 16#920eada5#;
   pragma Export (C, u00008, "ada__tagsB");
   u00009 : constant Version_32 := 16#13ca27f3#;
   pragma Export (C, u00009, "ada__tagsS");
   u00010 : constant Version_32 := 16#d90b9106#;
   pragma Export (C, u00010, "ada__exceptionsB");
   u00011 : constant Version_32 := 16#687d7b36#;
   pragma Export (C, u00011, "ada__exceptionsS");
   u00012 : constant Version_32 := 16#e947e6a9#;
   pragma Export (C, u00012, "ada__exceptions__last_chance_handlerB");
   u00013 : constant Version_32 := 16#41e5552e#;
   pragma Export (C, u00013, "ada__exceptions__last_chance_handlerS");
   u00014 : constant Version_32 := 16#095425b4#;
   pragma Export (C, u00014, "systemS");
   u00015 : constant Version_32 := 16#465d427a#;
   pragma Export (C, u00015, "system__soft_linksB");
   u00016 : constant Version_32 := 16#97d0fde1#;
   pragma Export (C, u00016, "system__soft_linksS");
   u00017 : constant Version_32 := 16#b01dad17#;
   pragma Export (C, u00017, "system__parametersB");
   u00018 : constant Version_32 := 16#777e28cb#;
   pragma Export (C, u00018, "system__parametersS");
   u00019 : constant Version_32 := 16#0f0cb66d#;
   pragma Export (C, u00019, "system__secondary_stackB");
   u00020 : constant Version_32 := 16#a235eadd#;
   pragma Export (C, u00020, "system__secondary_stackS");
   u00021 : constant Version_32 := 16#39a03df9#;
   pragma Export (C, u00021, "system__storage_elementsB");
   u00022 : constant Version_32 := 16#24976fb0#;
   pragma Export (C, u00022, "system__storage_elementsS");
   u00023 : constant Version_32 := 16#41837d1e#;
   pragma Export (C, u00023, "system__stack_checkingB");
   u00024 : constant Version_32 := 16#87eb4e5c#;
   pragma Export (C, u00024, "system__stack_checkingS");
   u00025 : constant Version_32 := 16#87a448ff#;
   pragma Export (C, u00025, "system__exception_tableB");
   u00026 : constant Version_32 := 16#54fa4cf6#;
   pragma Export (C, u00026, "system__exception_tableS");
   u00027 : constant Version_32 := 16#ce4af020#;
   pragma Export (C, u00027, "system__exceptionsB");
   u00028 : constant Version_32 := 16#61374842#;
   pragma Export (C, u00028, "system__exceptionsS");
   u00029 : constant Version_32 := 16#aa0563fc#;
   pragma Export (C, u00029, "system__exceptions_debugB");
   u00030 : constant Version_32 := 16#77dedc70#;
   pragma Export (C, u00030, "system__exceptions_debugS");
   u00031 : constant Version_32 := 16#570325c8#;
   pragma Export (C, u00031, "system__img_intB");
   u00032 : constant Version_32 := 16#0b8fc576#;
   pragma Export (C, u00032, "system__img_intS");
   u00033 : constant Version_32 := 16#39df8c17#;
   pragma Export (C, u00033, "system__tracebackB");
   u00034 : constant Version_32 := 16#5776fb70#;
   pragma Export (C, u00034, "system__tracebackS");
   u00035 : constant Version_32 := 16#9ed49525#;
   pragma Export (C, u00035, "system__traceback_entriesB");
   u00036 : constant Version_32 := 16#090fd3c4#;
   pragma Export (C, u00036, "system__traceback_entriesS");
   u00037 : constant Version_32 := 16#6fd210f2#;
   pragma Export (C, u00037, "system__traceback__symbolicB");
   u00038 : constant Version_32 := 16#dd19f67a#;
   pragma Export (C, u00038, "system__traceback__symbolicS");
   u00039 : constant Version_32 := 16#701f9d88#;
   pragma Export (C, u00039, "ada__exceptions__tracebackB");
   u00040 : constant Version_32 := 16#20245e75#;
   pragma Export (C, u00040, "ada__exceptions__tracebackS");
   u00041 : constant Version_32 := 16#57a37a42#;
   pragma Export (C, u00041, "system__address_imageB");
   u00042 : constant Version_32 := 16#a8b8b88e#;
   pragma Export (C, u00042, "system__address_imageS");
   u00043 : constant Version_32 := 16#8c33a517#;
   pragma Export (C, u00043, "system__wch_conB");
   u00044 : constant Version_32 := 16#12290766#;
   pragma Export (C, u00044, "system__wch_conS");
   u00045 : constant Version_32 := 16#9721e840#;
   pragma Export (C, u00045, "system__wch_stwB");
   u00046 : constant Version_32 := 16#3f382b67#;
   pragma Export (C, u00046, "system__wch_stwS");
   u00047 : constant Version_32 := 16#b96cfbef#;
   pragma Export (C, u00047, "system__wch_cnvB");
   u00048 : constant Version_32 := 16#1d9ebd95#;
   pragma Export (C, u00048, "system__wch_cnvS");
   u00049 : constant Version_32 := 16#ece6fdb6#;
   pragma Export (C, u00049, "system__wch_jisB");
   u00050 : constant Version_32 := 16#9deea4b4#;
   pragma Export (C, u00050, "system__wch_jisS");
   u00051 : constant Version_32 := 16#c3335bfd#;
   pragma Export (C, u00051, "system__htableB");
   u00052 : constant Version_32 := 16#8d96965e#;
   pragma Export (C, u00052, "system__htableS");
   u00053 : constant Version_32 := 16#089f5cd0#;
   pragma Export (C, u00053, "system__string_hashB");
   u00054 : constant Version_32 := 16#2fc8fd20#;
   pragma Export (C, u00054, "system__string_hashS");
   u00055 : constant Version_32 := 16#940c8174#;
   pragma Export (C, u00055, "system__unsigned_typesS");
   u00056 : constant Version_32 := 16#b44f9ae7#;
   pragma Export (C, u00056, "system__val_unsB");
   u00057 : constant Version_32 := 16#84a46c4f#;
   pragma Export (C, u00057, "system__val_unsS");
   u00058 : constant Version_32 := 16#27b600b2#;
   pragma Export (C, u00058, "system__val_utilB");
   u00059 : constant Version_32 := 16#a5f4934a#;
   pragma Export (C, u00059, "system__val_utilS");
   u00060 : constant Version_32 := 16#d1060688#;
   pragma Export (C, u00060, "system__case_utilB");
   u00061 : constant Version_32 := 16#2d5d4c63#;
   pragma Export (C, u00061, "system__case_utilS");
   u00062 : constant Version_32 := 16#c1a106e2#;
   pragma Export (C, u00062, "ada__text_ioB");
   u00063 : constant Version_32 := 16#e701a999#;
   pragma Export (C, u00063, "ada__text_ioS");
   u00064 : constant Version_32 := 16#10558b11#;
   pragma Export (C, u00064, "ada__streamsB");
   u00065 : constant Version_32 := 16#2e6701ab#;
   pragma Export (C, u00065, "ada__streamsS");
   u00066 : constant Version_32 := 16#db5c917c#;
   pragma Export (C, u00066, "ada__io_exceptionsS");
   u00067 : constant Version_32 := 16#84a27f0d#;
   pragma Export (C, u00067, "interfaces__c_streamsB");
   u00068 : constant Version_32 := 16#a06e9ee4#;
   pragma Export (C, u00068, "interfaces__c_streamsS");
   u00069 : constant Version_32 := 16#79c5f3ba#;
   pragma Export (C, u00069, "system__crtlS");
   u00070 : constant Version_32 := 16#f1dc49a7#;
   pragma Export (C, u00070, "system__file_ioB");
   u00071 : constant Version_32 := 16#ae25c4d1#;
   pragma Export (C, u00071, "system__file_ioS");
   u00072 : constant Version_32 := 16#cf417de3#;
   pragma Export (C, u00072, "ada__finalizationS");
   u00073 : constant Version_32 := 16#95817ed8#;
   pragma Export (C, u00073, "system__finalization_rootB");
   u00074 : constant Version_32 := 16#46a65624#;
   pragma Export (C, u00074, "system__finalization_rootS");
   u00075 : constant Version_32 := 16#769e25e6#;
   pragma Export (C, u00075, "interfaces__cB");
   u00076 : constant Version_32 := 16#61e3d2ff#;
   pragma Export (C, u00076, "interfaces__cS");
   u00077 : constant Version_32 := 16#d301c7de#;
   pragma Export (C, u00077, "system__os_libB");
   u00078 : constant Version_32 := 16#dc0cac3f#;
   pragma Export (C, u00078, "system__os_libS");
   u00079 : constant Version_32 := 16#1a817b8e#;
   pragma Export (C, u00079, "system__stringsB");
   u00080 : constant Version_32 := 16#77eb34d2#;
   pragma Export (C, u00080, "system__stringsS");
   u00081 : constant Version_32 := 16#f4cbbf1c#;
   pragma Export (C, u00081, "system__file_control_blockS");
   u00082 : constant Version_32 := 16#b0988e58#;
   pragma Export (C, u00082, "insaB");
   u00083 : constant Version_32 := 16#34488d3d#;
   pragma Export (C, u00083, "insaS");
   u00084 : constant Version_32 := 16#11382f47#;
   pragma Export (C, u00084, "insa__audioB");
   u00085 : constant Version_32 := 16#59afd83b#;
   pragma Export (C, u00085, "insa__audioS");
   u00086 : constant Version_32 := 16#c1a34cbf#;
   pragma Export (C, u00086, "insa__audio__synthesizerB");
   u00087 : constant Version_32 := 16#3176dd7a#;
   pragma Export (C, u00087, "insa__audio__synthesizerS");
   u00088 : constant Version_32 := 16#63b70ccf#;
   pragma Export (C, u00088, "insa__graphicsB");
   u00089 : constant Version_32 := 16#5c6222d3#;
   pragma Export (C, u00089, "insa__graphicsS");
   u00090 : constant Version_32 := 16#afa472ec#;
   pragma Export (C, u00090, "insa__graphics__advancedB");
   u00091 : constant Version_32 := 16#0553dd5b#;
   pragma Export (C, u00091, "insa__graphics__advancedS");
   u00092 : constant Version_32 := 16#783477d2#;
   pragma Export (C, u00092, "insa__memoryB");
   u00093 : constant Version_32 := 16#e429f208#;
   pragma Export (C, u00093, "insa__memoryS");
   u00094 : constant Version_32 := 16#eacbfa68#;
   pragma Export (C, u00094, "insa__graphics__imagesB");
   u00095 : constant Version_32 := 16#4f117988#;
   pragma Export (C, u00095, "insa__graphics__imagesS");
   u00096 : constant Version_32 := 16#dba6bfea#;
   pragma Export (C, u00096, "insa__graphics__uiB");
   u00097 : constant Version_32 := 16#5d46fcf6#;
   pragma Export (C, u00097, "insa__graphics__uiS");
   u00098 : constant Version_32 := 16#f9ad2a59#;
   pragma Export (C, u00098, "insa__keysB");
   u00099 : constant Version_32 := 16#07fddcb9#;
   pragma Export (C, u00099, "insa__keysS");
   u00100 : constant Version_32 := 16#4a9efeb7#;
   pragma Export (C, u00100, "insa__random_numberB");
   u00101 : constant Version_32 := 16#f33621ae#;
   pragma Export (C, u00101, "insa__random_numberS");
   u00102 : constant Version_32 := 16#14eb63fd#;
   pragma Export (C, u00102, "insa__timerB");
   u00103 : constant Version_32 := 16#973ffe06#;
   pragma Export (C, u00103, "insa__timerS");
   u00104 : constant Version_32 := 16#de8e8b25#;
   pragma Export (C, u00104, "ressourcesS");
   u00105 : constant Version_32 := 16#fd83e873#;
   pragma Export (C, u00105, "system__concat_2B");
   u00106 : constant Version_32 := 16#0bf4f264#;
   pragma Export (C, u00106, "system__concat_2S");
   u00107 : constant Version_32 := 16#58e7cff7#;
   pragma Export (C, u00107, "system__memoryB");
   u00108 : constant Version_32 := 16#50294380#;
   pragma Export (C, u00108, "system__memoryS");
   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  interfaces%s
   --  system%s
   --  system.case_util%s
   --  system.case_util%b
   --  system.htable%s
   --  system.img_int%s
   --  system.img_int%b
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  interfaces.c_streams%s
   --  interfaces.c_streams%b
   --  system.standard_library%s
   --  system.exceptions_debug%s
   --  system.exceptions_debug%b
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.string_hash%s
   --  system.string_hash%b
   --  system.htable%b
   --  system.strings%s
   --  system.strings%b
   --  system.os_lib%s
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  ada.exceptions%s
   --  system.soft_links%s
   --  system.unsigned_types%s
   --  system.val_uns%s
   --  system.val_util%s
   --  system.val_util%b
   --  system.val_uns%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_cnv%s
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%b
   --  system.wch_stw%s
   --  system.wch_stw%b
   --  ada.exceptions.last_chance_handler%s
   --  ada.exceptions.last_chance_handler%b
   --  ada.exceptions.traceback%s
   --  system.address_image%s
   --  system.concat_2%s
   --  system.concat_2%b
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.io_exceptions%s
   --  ada.tags%s
   --  ada.streams%s
   --  ada.streams%b
   --  interfaces.c%s
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.file_control_block%s
   --  system.file_io%s
   --  system.finalization_root%s
   --  system.finalization_root%b
   --  ada.finalization%s
   --  system.memory%s
   --  system.memory%b
   --  system.standard_library%b
   --  system.secondary_stack%s
   --  system.file_io%b
   --  interfaces.c%b
   --  ada.tags%b
   --  system.soft_links%b
   --  system.os_lib%b
   --  system.secondary_stack%b
   --  system.address_image%b
   --  ada.exceptions.traceback%b
   --  system.traceback%s
   --  system.traceback%b
   --  system.traceback.symbolic%s
   --  system.traceback.symbolic%b
   --  ada.exceptions%b
   --  ada.text_io%s
   --  ada.text_io%b
   --  insa%s
   --  insa%b
   --  insa.audio%s
   --  insa.audio%b
   --  insa.audio.synthesizer%s
   --  insa.audio.synthesizer%b
   --  insa.graphics%s
   --  insa.graphics%b
   --  insa.graphics.ui%s
   --  insa.graphics.ui%b
   --  insa.keys%s
   --  insa.keys%b
   --  insa.memory%s
   --  insa.memory%b
   --  insa.graphics.advanced%s
   --  insa.graphics.advanced%b
   --  insa.graphics.images%s
   --  insa.graphics.images%b
   --  insa.random_number%s
   --  insa.random_number%b
   --  insa.timer%s
   --  insa.timer%b
   --  ressources%s
   --  simon%s
   --  simon%b
   --  missionsimon%b
   --  END ELABORATION ORDER


end ada_main;
