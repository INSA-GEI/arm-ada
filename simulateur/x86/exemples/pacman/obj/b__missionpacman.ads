pragma Warnings (Off);
pragma Ada_95;
with System;
with System.Parameters;
with System.Secondary_Stack;
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
                    "GNAT Version: Community 2020 (20200818-93)" & ASCII.NUL;
   pragma Export (C, GNAT_Version, "__gnat_version");

   Ada_Main_Program_Name : constant String := "_ada_missionpacman" & ASCII.NUL;
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
   u00001 : constant Version_32 := 16#61aba0a2#;
   pragma Export (C, u00001, "missionpacmanB");
   u00002 : constant Version_32 := 16#67c8d842#;
   pragma Export (C, u00002, "system__standard_libraryB");
   u00003 : constant Version_32 := 16#23d4d899#;
   pragma Export (C, u00003, "system__standard_libraryS");
   u00004 : constant Version_32 := 16#7b4ac787#;
   pragma Export (C, u00004, "carteB");
   u00005 : constant Version_32 := 16#e208192d#;
   pragma Export (C, u00005, "carteS");
   u00006 : constant Version_32 := 16#76789da1#;
   pragma Export (C, u00006, "adaS");
   u00007 : constant Version_32 := 16#f4e097a7#;
   pragma Export (C, u00007, "ada__text_ioB");
   u00008 : constant Version_32 := 16#777d5329#;
   pragma Export (C, u00008, "ada__text_ioS");
   u00009 : constant Version_32 := 16#f435a12e#;
   pragma Export (C, u00009, "ada__exceptionsB");
   u00010 : constant Version_32 := 16#bb2e31f9#;
   pragma Export (C, u00010, "ada__exceptionsS");
   u00011 : constant Version_32 := 16#35e1815f#;
   pragma Export (C, u00011, "ada__exceptions__last_chance_handlerB");
   u00012 : constant Version_32 := 16#cfec26ee#;
   pragma Export (C, u00012, "ada__exceptions__last_chance_handlerS");
   u00013 : constant Version_32 := 16#4635ec04#;
   pragma Export (C, u00013, "systemS");
   u00014 : constant Version_32 := 16#ae860117#;
   pragma Export (C, u00014, "system__soft_linksB");
   u00015 : constant Version_32 := 16#39005bef#;
   pragma Export (C, u00015, "system__soft_linksS");
   u00016 : constant Version_32 := 16#2d437d19#;
   pragma Export (C, u00016, "system__secondary_stackB");
   u00017 : constant Version_32 := 16#b79edb80#;
   pragma Export (C, u00017, "system__secondary_stackS");
   u00018 : constant Version_32 := 16#896564a3#;
   pragma Export (C, u00018, "system__parametersB");
   u00019 : constant Version_32 := 16#016728cf#;
   pragma Export (C, u00019, "system__parametersS");
   u00020 : constant Version_32 := 16#ced09590#;
   pragma Export (C, u00020, "system__storage_elementsB");
   u00021 : constant Version_32 := 16#6bf6a600#;
   pragma Export (C, u00021, "system__storage_elementsS");
   u00022 : constant Version_32 := 16#ce3e0e21#;
   pragma Export (C, u00022, "system__soft_links__initializeB");
   u00023 : constant Version_32 := 16#5697fc2b#;
   pragma Export (C, u00023, "system__soft_links__initializeS");
   u00024 : constant Version_32 := 16#41837d1e#;
   pragma Export (C, u00024, "system__stack_checkingB");
   u00025 : constant Version_32 := 16#c88a87ec#;
   pragma Export (C, u00025, "system__stack_checkingS");
   u00026 : constant Version_32 := 16#34742901#;
   pragma Export (C, u00026, "system__exception_tableB");
   u00027 : constant Version_32 := 16#795caff4#;
   pragma Export (C, u00027, "system__exception_tableS");
   u00028 : constant Version_32 := 16#ce4af020#;
   pragma Export (C, u00028, "system__exceptionsB");
   u00029 : constant Version_32 := 16#2e5681f2#;
   pragma Export (C, u00029, "system__exceptionsS");
   u00030 : constant Version_32 := 16#69416224#;
   pragma Export (C, u00030, "system__exceptions__machineB");
   u00031 : constant Version_32 := 16#5c74e542#;
   pragma Export (C, u00031, "system__exceptions__machineS");
   u00032 : constant Version_32 := 16#aa0563fc#;
   pragma Export (C, u00032, "system__exceptions_debugB");
   u00033 : constant Version_32 := 16#5a783f72#;
   pragma Export (C, u00033, "system__exceptions_debugS");
   u00034 : constant Version_32 := 16#6c2f8802#;
   pragma Export (C, u00034, "system__img_intB");
   u00035 : constant Version_32 := 16#44ee0cc6#;
   pragma Export (C, u00035, "system__img_intS");
   u00036 : constant Version_32 := 16#39df8c17#;
   pragma Export (C, u00036, "system__tracebackB");
   u00037 : constant Version_32 := 16#181732c0#;
   pragma Export (C, u00037, "system__tracebackS");
   u00038 : constant Version_32 := 16#9ed49525#;
   pragma Export (C, u00038, "system__traceback_entriesB");
   u00039 : constant Version_32 := 16#466e1a74#;
   pragma Export (C, u00039, "system__traceback_entriesS");
   u00040 : constant Version_32 := 16#e162df04#;
   pragma Export (C, u00040, "system__traceback__symbolicB");
   u00041 : constant Version_32 := 16#46491211#;
   pragma Export (C, u00041, "system__traceback__symbolicS");
   u00042 : constant Version_32 := 16#179d7d28#;
   pragma Export (C, u00042, "ada__containersS");
   u00043 : constant Version_32 := 16#701f9d88#;
   pragma Export (C, u00043, "ada__exceptions__tracebackB");
   u00044 : constant Version_32 := 16#ae2d2db5#;
   pragma Export (C, u00044, "ada__exceptions__tracebackS");
   u00045 : constant Version_32 := 16#5ab55268#;
   pragma Export (C, u00045, "interfacesS");
   u00046 : constant Version_32 := 16#e49bce3e#;
   pragma Export (C, u00046, "interfaces__cB");
   u00047 : constant Version_32 := 16#dbc36ce0#;
   pragma Export (C, u00047, "interfaces__cS");
   u00048 : constant Version_32 := 16#e865e681#;
   pragma Export (C, u00048, "system__bounded_stringsB");
   u00049 : constant Version_32 := 16#31c8cd1d#;
   pragma Export (C, u00049, "system__bounded_stringsS");
   u00050 : constant Version_32 := 16#0fdcf3be#;
   pragma Export (C, u00050, "system__crtlS");
   u00051 : constant Version_32 := 16#108b4f79#;
   pragma Export (C, u00051, "system__dwarf_linesB");
   u00052 : constant Version_32 := 16#345b739f#;
   pragma Export (C, u00052, "system__dwarf_linesS");
   u00053 : constant Version_32 := 16#5b4659fa#;
   pragma Export (C, u00053, "ada__charactersS");
   u00054 : constant Version_32 := 16#8f637df8#;
   pragma Export (C, u00054, "ada__characters__handlingB");
   u00055 : constant Version_32 := 16#3b3f6154#;
   pragma Export (C, u00055, "ada__characters__handlingS");
   u00056 : constant Version_32 := 16#4b7bb96a#;
   pragma Export (C, u00056, "ada__characters__latin_1S");
   u00057 : constant Version_32 := 16#e6d4fa36#;
   pragma Export (C, u00057, "ada__stringsS");
   u00058 : constant Version_32 := 16#96df1a3f#;
   pragma Export (C, u00058, "ada__strings__mapsB");
   u00059 : constant Version_32 := 16#1e526bec#;
   pragma Export (C, u00059, "ada__strings__mapsS");
   u00060 : constant Version_32 := 16#32cfc5a0#;
   pragma Export (C, u00060, "system__bit_opsB");
   u00061 : constant Version_32 := 16#0765e3a3#;
   pragma Export (C, u00061, "system__bit_opsS");
   u00062 : constant Version_32 := 16#18fa9e16#;
   pragma Export (C, u00062, "system__unsigned_typesS");
   u00063 : constant Version_32 := 16#92f05f13#;
   pragma Export (C, u00063, "ada__strings__maps__constantsS");
   u00064 : constant Version_32 := 16#a0d3d22b#;
   pragma Export (C, u00064, "system__address_imageB");
   u00065 : constant Version_32 := 16#e7d9713e#;
   pragma Export (C, u00065, "system__address_imageS");
   u00066 : constant Version_32 := 16#8631cc2e#;
   pragma Export (C, u00066, "system__img_unsB");
   u00067 : constant Version_32 := 16#870ea2e1#;
   pragma Export (C, u00067, "system__img_unsS");
   u00068 : constant Version_32 := 16#20ec7aa3#;
   pragma Export (C, u00068, "system__ioB");
   u00069 : constant Version_32 := 16#d8771b4b#;
   pragma Export (C, u00069, "system__ioS");
   u00070 : constant Version_32 := 16#f790d1ef#;
   pragma Export (C, u00070, "system__mmapB");
   u00071 : constant Version_32 := 16#ee41b8bb#;
   pragma Export (C, u00071, "system__mmapS");
   u00072 : constant Version_32 := 16#92d882c5#;
   pragma Export (C, u00072, "ada__io_exceptionsS");
   u00073 : constant Version_32 := 16#91eaca2e#;
   pragma Export (C, u00073, "system__mmap__os_interfaceB");
   u00074 : constant Version_32 := 16#1fc2f713#;
   pragma Export (C, u00074, "system__mmap__os_interfaceS");
   u00075 : constant Version_32 := 16#8c787ae2#;
   pragma Export (C, u00075, "system__mmap__unixS");
   u00076 : constant Version_32 := 16#11eb9166#;
   pragma Export (C, u00076, "system__os_libB");
   u00077 : constant Version_32 := 16#d872da39#;
   pragma Export (C, u00077, "system__os_libS");
   u00078 : constant Version_32 := 16#ec4d5631#;
   pragma Export (C, u00078, "system__case_utilB");
   u00079 : constant Version_32 := 16#79e05a50#;
   pragma Export (C, u00079, "system__case_utilS");
   u00080 : constant Version_32 := 16#2a8e89ad#;
   pragma Export (C, u00080, "system__stringsB");
   u00081 : constant Version_32 := 16#2623c091#;
   pragma Export (C, u00081, "system__stringsS");
   u00082 : constant Version_32 := 16#c83ab8ef#;
   pragma Export (C, u00082, "system__object_readerB");
   u00083 : constant Version_32 := 16#82413105#;
   pragma Export (C, u00083, "system__object_readerS");
   u00084 : constant Version_32 := 16#914b0305#;
   pragma Export (C, u00084, "system__val_lliB");
   u00085 : constant Version_32 := 16#2a5b7ef4#;
   pragma Export (C, u00085, "system__val_lliS");
   u00086 : constant Version_32 := 16#d2ae2792#;
   pragma Export (C, u00086, "system__val_lluB");
   u00087 : constant Version_32 := 16#753413f4#;
   pragma Export (C, u00087, "system__val_lluS");
   u00088 : constant Version_32 := 16#269742a9#;
   pragma Export (C, u00088, "system__val_utilB");
   u00089 : constant Version_32 := 16#ea955afa#;
   pragma Export (C, u00089, "system__val_utilS");
   u00090 : constant Version_32 := 16#b578159b#;
   pragma Export (C, u00090, "system__exception_tracesB");
   u00091 : constant Version_32 := 16#62eacc9e#;
   pragma Export (C, u00091, "system__exception_tracesS");
   u00092 : constant Version_32 := 16#8c33a517#;
   pragma Export (C, u00092, "system__wch_conB");
   u00093 : constant Version_32 := 16#5d48ced6#;
   pragma Export (C, u00093, "system__wch_conS");
   u00094 : constant Version_32 := 16#9721e840#;
   pragma Export (C, u00094, "system__wch_stwB");
   u00095 : constant Version_32 := 16#7059e2d7#;
   pragma Export (C, u00095, "system__wch_stwS");
   u00096 : constant Version_32 := 16#a831679c#;
   pragma Export (C, u00096, "system__wch_cnvB");
   u00097 : constant Version_32 := 16#52ff7425#;
   pragma Export (C, u00097, "system__wch_cnvS");
   u00098 : constant Version_32 := 16#ece6fdb6#;
   pragma Export (C, u00098, "system__wch_jisB");
   u00099 : constant Version_32 := 16#d28f6d04#;
   pragma Export (C, u00099, "system__wch_jisS");
   u00100 : constant Version_32 := 16#10558b11#;
   pragma Export (C, u00100, "ada__streamsB");
   u00101 : constant Version_32 := 16#67e31212#;
   pragma Export (C, u00101, "ada__streamsS");
   u00102 : constant Version_32 := 16#f9576a72#;
   pragma Export (C, u00102, "ada__tagsB");
   u00103 : constant Version_32 := 16#b6661f55#;
   pragma Export (C, u00103, "ada__tagsS");
   u00104 : constant Version_32 := 16#796f31f1#;
   pragma Export (C, u00104, "system__htableB");
   u00105 : constant Version_32 := 16#c2f75fee#;
   pragma Export (C, u00105, "system__htableS");
   u00106 : constant Version_32 := 16#089f5cd0#;
   pragma Export (C, u00106, "system__string_hashB");
   u00107 : constant Version_32 := 16#60a93490#;
   pragma Export (C, u00107, "system__string_hashS");
   u00108 : constant Version_32 := 16#73d2d764#;
   pragma Export (C, u00108, "interfaces__c_streamsB");
   u00109 : constant Version_32 := 16#b1330297#;
   pragma Export (C, u00109, "interfaces__c_streamsS");
   u00110 : constant Version_32 := 16#ec9c64c3#;
   pragma Export (C, u00110, "system__file_ioB");
   u00111 : constant Version_32 := 16#e1440d61#;
   pragma Export (C, u00111, "system__file_ioS");
   u00112 : constant Version_32 := 16#86c56e5a#;
   pragma Export (C, u00112, "ada__finalizationS");
   u00113 : constant Version_32 := 16#95817ed8#;
   pragma Export (C, u00113, "system__finalization_rootB");
   u00114 : constant Version_32 := 16#09c79f94#;
   pragma Export (C, u00114, "system__finalization_rootS");
   u00115 : constant Version_32 := 16#bbaa76ac#;
   pragma Export (C, u00115, "system__file_control_blockS");
   u00116 : constant Version_32 := 16#08c9efdf#;
   pragma Export (C, u00116, "insaB");
   u00117 : constant Version_32 := 16#0830a824#;
   pragma Export (C, u00117, "insaS");
   u00118 : constant Version_32 := 16#ffaa9e94#;
   pragma Export (C, u00118, "ada__calendar__delaysB");
   u00119 : constant Version_32 := 16#d86d2f1d#;
   pragma Export (C, u00119, "ada__calendar__delaysS");
   u00120 : constant Version_32 := 16#c47dab26#;
   pragma Export (C, u00120, "ada__calendarB");
   u00121 : constant Version_32 := 16#31350a81#;
   pragma Export (C, u00121, "ada__calendarS");
   u00122 : constant Version_32 := 16#51f2d040#;
   pragma Export (C, u00122, "system__os_primitivesB");
   u00123 : constant Version_32 := 16#41c889f2#;
   pragma Export (C, u00123, "system__os_primitivesS");
   u00124 : constant Version_32 := 16#eeb230e3#;
   pragma Export (C, u00124, "system__arith_64B");
   u00125 : constant Version_32 := 16#5ccd1b9e#;
   pragma Export (C, u00125, "system__arith_64S");
   u00126 : constant Version_32 := 16#158a7ea4#;
   pragma Export (C, u00126, "insa__keysB");
   u00127 : constant Version_32 := 16#9b861e2b#;
   pragma Export (C, u00127, "insa__keysS");
   u00128 : constant Version_32 := 16#ba9e17ba#;
   pragma Export (C, u00128, "insa__simulatorB");
   u00129 : constant Version_32 := 16#07607d8c#;
   pragma Export (C, u00129, "insa__simulatorS");
   u00130 : constant Version_32 := 16#97ae1e3d#;
   pragma Export (C, u00130, "ada__strings__fixedB");
   u00131 : constant Version_32 := 16#fec1aafc#;
   pragma Export (C, u00131, "ada__strings__fixedS");
   u00132 : constant Version_32 := 16#60da0992#;
   pragma Export (C, u00132, "ada__strings__searchB");
   u00133 : constant Version_32 := 16#c1ab8667#;
   pragma Export (C, u00133, "ada__strings__searchS");
   u00134 : constant Version_32 := 16#b5988c27#;
   pragma Export (C, u00134, "gnatS");
   u00135 : constant Version_32 := 16#a55269e4#;
   pragma Export (C, u00135, "gnat__exception_tracesS");
   u00136 : constant Version_32 := 16#9c857b76#;
   pragma Export (C, u00136, "gnat__source_infoS");
   u00137 : constant Version_32 := 16#9c26d9a6#;
   pragma Export (C, u00137, "insa__simulator__tasksB");
   u00138 : constant Version_32 := 16#c6b8003e#;
   pragma Export (C, u00138, "insa__simulator__tasksS");
   u00139 : constant Version_32 := 16#b2c0902c#;
   pragma Export (C, u00139, "insa__timerB");
   u00140 : constant Version_32 := 16#ac2dea83#;
   pragma Export (C, u00140, "insa__timerS");
   u00141 : constant Version_32 := 16#608e2cd1#;
   pragma Export (C, u00141, "system__concat_5B");
   u00142 : constant Version_32 := 16#c16baf2a#;
   pragma Export (C, u00142, "system__concat_5S");
   u00143 : constant Version_32 := 16#932a4690#;
   pragma Export (C, u00143, "system__concat_4B");
   u00144 : constant Version_32 := 16#3851c724#;
   pragma Export (C, u00144, "system__concat_4S");
   u00145 : constant Version_32 := 16#2b70b149#;
   pragma Export (C, u00145, "system__concat_3B");
   u00146 : constant Version_32 := 16#4d45b0a1#;
   pragma Export (C, u00146, "system__concat_3S");
   u00147 : constant Version_32 := 16#fd83e873#;
   pragma Export (C, u00147, "system__concat_2B");
   u00148 : constant Version_32 := 16#44953bd4#;
   pragma Export (C, u00148, "system__concat_2S");
   u00149 : constant Version_32 := 16#57674f80#;
   pragma Export (C, u00149, "system__finalization_mastersB");
   u00150 : constant Version_32 := 16#4552acd4#;
   pragma Export (C, u00150, "system__finalization_mastersS");
   u00151 : constant Version_32 := 16#7268f812#;
   pragma Export (C, u00151, "system__img_boolB");
   u00152 : constant Version_32 := 16#b3ec9def#;
   pragma Export (C, u00152, "system__img_boolS");
   u00153 : constant Version_32 := 16#35d6ef80#;
   pragma Export (C, u00153, "system__storage_poolsB");
   u00154 : constant Version_32 := 16#3d430bb3#;
   pragma Export (C, u00154, "system__storage_poolsS");
   u00155 : constant Version_32 := 16#021224f8#;
   pragma Export (C, u00155, "system__pool_globalB");
   u00156 : constant Version_32 := 16#29da5924#;
   pragma Export (C, u00156, "system__pool_globalS");
   u00157 : constant Version_32 := 16#eca5ecae#;
   pragma Export (C, u00157, "system__memoryB");
   u00158 : constant Version_32 := 16#1f488a30#;
   pragma Export (C, u00158, "system__memoryS");
   u00159 : constant Version_32 := 16#d5d8c501#;
   pragma Export (C, u00159, "system__storage_pools__subpoolsB");
   u00160 : constant Version_32 := 16#e136d7bf#;
   pragma Export (C, u00160, "system__storage_pools__subpoolsS");
   u00161 : constant Version_32 := 16#84042202#;
   pragma Export (C, u00161, "system__storage_pools__subpools__finalizationB");
   u00162 : constant Version_32 := 16#8bd8fdc9#;
   pragma Export (C, u00162, "system__storage_pools__subpools__finalizationS");
   u00163 : constant Version_32 := 16#5252521d#;
   pragma Export (C, u00163, "system__stream_attributesB");
   u00164 : constant Version_32 := 16#d573b948#;
   pragma Export (C, u00164, "system__stream_attributesS");
   u00165 : constant Version_32 := 16#3e25f63c#;
   pragma Export (C, u00165, "system__stream_attributes__xdrB");
   u00166 : constant Version_32 := 16#2f60cd1f#;
   pragma Export (C, u00166, "system__stream_attributes__xdrS");
   u00167 : constant Version_32 := 16#1e40f010#;
   pragma Export (C, u00167, "system__fat_fltS");
   u00168 : constant Version_32 := 16#3872f91d#;
   pragma Export (C, u00168, "system__fat_lfltS");
   u00169 : constant Version_32 := 16#42a257f7#;
   pragma Export (C, u00169, "system__fat_llfS");
   u00170 : constant Version_32 := 16#ed063051#;
   pragma Export (C, u00170, "system__fat_sfltS");
   u00171 : constant Version_32 := 16#6c86fe81#;
   pragma Export (C, u00171, "ecranB");
   u00172 : constant Version_32 := 16#aeace0cc#;
   pragma Export (C, u00172, "ecranS");
   u00173 : constant Version_32 := 16#8cc5eb86#;
   pragma Export (C, u00173, "insa__graphicsB");
   u00174 : constant Version_32 := 16#e10b47ab#;
   pragma Export (C, u00174, "insa__graphicsS");
   u00175 : constant Version_32 := 16#a83b7c85#;
   pragma Export (C, u00175, "system__concat_6B");
   u00176 : constant Version_32 := 16#94f2c1b6#;
   pragma Export (C, u00176, "system__concat_6S");
   u00177 : constant Version_32 := 16#46b1f5ea#;
   pragma Export (C, u00177, "system__concat_8B");
   u00178 : constant Version_32 := 16#a532a1d3#;
   pragma Export (C, u00178, "system__concat_8S");
   u00179 : constant Version_32 := 16#46899fd1#;
   pragma Export (C, u00179, "system__concat_7B");
   u00180 : constant Version_32 := 16#baf2b71b#;
   pragma Export (C, u00180, "system__concat_7S");
   u00181 : constant Version_32 := 16#4c3551f3#;
   pragma Export (C, u00181, "labB");
   u00182 : constant Version_32 := 16#f38d74f9#;
   pragma Export (C, u00182, "labS");
   u00183 : constant Version_32 := 16#21352bcf#;
   pragma Export (C, u00183, "insa__graphics__imagesB");
   u00184 : constant Version_32 := 16#0b7d6ee5#;
   pragma Export (C, u00184, "insa__graphics__imagesS");
   u00185 : constant Version_32 := 16#f64b89a4#;
   pragma Export (C, u00185, "ada__integer_text_ioB");
   u00186 : constant Version_32 := 16#2ec7c168#;
   pragma Export (C, u00186, "ada__integer_text_ioS");
   u00187 : constant Version_32 := 16#fdedfd10#;
   pragma Export (C, u00187, "ada__text_io__integer_auxB");
   u00188 : constant Version_32 := 16#2fe01d89#;
   pragma Export (C, u00188, "ada__text_io__integer_auxS");
   u00189 : constant Version_32 := 16#181dc502#;
   pragma Export (C, u00189, "ada__text_io__generic_auxB");
   u00190 : constant Version_32 := 16#305a076a#;
   pragma Export (C, u00190, "ada__text_io__generic_auxS");
   u00191 : constant Version_32 := 16#db42ae56#;
   pragma Export (C, u00191, "system__img_biuB");
   u00192 : constant Version_32 := 16#ded8165b#;
   pragma Export (C, u00192, "system__img_biuS");
   u00193 : constant Version_32 := 16#244fa59d#;
   pragma Export (C, u00193, "system__img_llbB");
   u00194 : constant Version_32 := 16#9f1f06a5#;
   pragma Export (C, u00194, "system__img_llbS");
   u00195 : constant Version_32 := 16#9dca6636#;
   pragma Export (C, u00195, "system__img_lliB");
   u00196 : constant Version_32 := 16#577ab9d5#;
   pragma Export (C, u00196, "system__img_lliS");
   u00197 : constant Version_32 := 16#cd1fde06#;
   pragma Export (C, u00197, "system__img_llwB");
   u00198 : constant Version_32 := 16#36732533#;
   pragma Export (C, u00198, "system__img_llwS");
   u00199 : constant Version_32 := 16#811cd12a#;
   pragma Export (C, u00199, "system__img_wiuB");
   u00200 : constant Version_32 := 16#b09991c9#;
   pragma Export (C, u00200, "system__img_wiuS");
   u00201 : constant Version_32 := 16#65de8d35#;
   pragma Export (C, u00201, "system__val_intB");
   u00202 : constant Version_32 := 16#f3ca8567#;
   pragma Export (C, u00202, "system__val_intS");
   u00203 : constant Version_32 := 16#5276dcb7#;
   pragma Export (C, u00203, "system__val_unsB");
   u00204 : constant Version_32 := 16#2dfce3af#;
   pragma Export (C, u00204, "system__val_unsS");
   u00205 : constant Version_32 := 16#49de6e1b#;
   pragma Export (C, u00205, "insa__base64B");
   u00206 : constant Version_32 := 16#d96a598c#;
   pragma Export (C, u00206, "insa__base64S");
   u00207 : constant Version_32 := 16#f17c2a30#;
   pragma Export (C, u00207, "insa__memoryB");
   u00208 : constant Version_32 := 16#147c1b1f#;
   pragma Export (C, u00208, "insa__memoryS");
   u00209 : constant Version_32 := 16#54648a23#;
   pragma Export (C, u00209, "spritesS");
   u00210 : constant Version_32 := 16#e14148c0#;
   pragma Export (C, u00210, "insa__audioB");
   u00211 : constant Version_32 := 16#b1e10964#;
   pragma Export (C, u00211, "insa__audioS");
   u00212 : constant Version_32 := 16#77397a88#;
   pragma Export (C, u00212, "insa__audio__synthesizerB");
   u00213 : constant Version_32 := 16#07368c84#;
   pragma Export (C, u00213, "insa__audio__synthesizerS");

   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  ada.characters%s
   --  ada.characters.latin_1%s
   --  interfaces%s
   --  system%s
   --  system.img_bool%s
   --  system.img_bool%b
   --  system.img_int%s
   --  system.img_int%b
   --  system.img_lli%s
   --  system.img_lli%b
   --  system.io%s
   --  system.io%b
   --  system.os_primitives%s
   --  system.os_primitives%b
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  interfaces.c_streams%s
   --  interfaces.c_streams%b
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.string_hash%s
   --  system.string_hash%b
   --  system.htable%s
   --  system.htable%b
   --  system.strings%s
   --  system.strings%b
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  system.unsigned_types%s
   --  system.img_biu%s
   --  system.img_biu%b
   --  system.img_llb%s
   --  system.img_llb%b
   --  system.img_llw%s
   --  system.img_llw%b
   --  system.img_uns%s
   --  system.img_uns%b
   --  system.img_wiu%s
   --  system.img_wiu%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%s
   --  system.wch_cnv%b
   --  system.concat_2%s
   --  system.concat_2%b
   --  system.concat_3%s
   --  system.concat_3%b
   --  system.concat_4%s
   --  system.concat_4%b
   --  system.concat_5%s
   --  system.concat_5%b
   --  system.concat_6%s
   --  system.concat_6%b
   --  system.concat_7%s
   --  system.concat_7%b
   --  system.concat_8%s
   --  system.concat_8%b
   --  system.traceback%s
   --  system.traceback%b
   --  ada.characters.handling%s
   --  system.case_util%s
   --  system.os_lib%s
   --  system.secondary_stack%s
   --  system.standard_library%s
   --  ada.exceptions%s
   --  system.exceptions_debug%s
   --  system.exceptions_debug%b
   --  system.soft_links%s
   --  system.val_lli%s
   --  system.val_llu%s
   --  system.val_util%s
   --  system.val_util%b
   --  system.wch_stw%s
   --  system.wch_stw%b
   --  ada.exceptions.last_chance_handler%s
   --  ada.exceptions.last_chance_handler%b
   --  ada.exceptions.traceback%s
   --  ada.exceptions.traceback%b
   --  system.address_image%s
   --  system.address_image%b
   --  system.bit_ops%s
   --  system.bit_ops%b
   --  system.bounded_strings%s
   --  system.bounded_strings%b
   --  system.case_util%b
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.containers%s
   --  ada.io_exceptions%s
   --  ada.strings%s
   --  ada.strings.maps%s
   --  ada.strings.maps%b
   --  ada.strings.maps.constants%s
   --  interfaces.c%s
   --  interfaces.c%b
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.exceptions.machine%s
   --  system.exceptions.machine%b
   --  ada.characters.handling%b
   --  system.exception_traces%s
   --  system.exception_traces%b
   --  system.memory%s
   --  system.memory%b
   --  system.mmap%s
   --  system.mmap.os_interface%s
   --  system.mmap%b
   --  system.mmap.unix%s
   --  system.mmap.os_interface%b
   --  system.object_reader%s
   --  system.object_reader%b
   --  system.dwarf_lines%s
   --  system.dwarf_lines%b
   --  system.os_lib%b
   --  system.secondary_stack%b
   --  system.soft_links.initialize%s
   --  system.soft_links.initialize%b
   --  system.soft_links%b
   --  system.standard_library%b
   --  system.traceback.symbolic%s
   --  system.traceback.symbolic%b
   --  ada.exceptions%b
   --  system.val_lli%b
   --  system.val_llu%b
   --  ada.strings.search%s
   --  ada.strings.search%b
   --  ada.strings.fixed%s
   --  ada.strings.fixed%b
   --  ada.tags%s
   --  ada.tags%b
   --  ada.streams%s
   --  ada.streams%b
   --  gnat%s
   --  gnat.source_info%s
   --  system.arith_64%s
   --  system.arith_64%b
   --  system.fat_flt%s
   --  system.fat_lflt%s
   --  system.fat_llf%s
   --  system.fat_sflt%s
   --  system.file_control_block%s
   --  system.finalization_root%s
   --  system.finalization_root%b
   --  ada.finalization%s
   --  system.file_io%s
   --  system.file_io%b
   --  system.storage_pools%s
   --  system.storage_pools%b
   --  system.finalization_masters%s
   --  system.finalization_masters%b
   --  system.storage_pools.subpools%s
   --  system.storage_pools.subpools.finalization%s
   --  system.storage_pools.subpools.finalization%b
   --  system.storage_pools.subpools%b
   --  system.stream_attributes%s
   --  system.stream_attributes.xdr%s
   --  system.stream_attributes.xdr%b
   --  system.stream_attributes%b
   --  system.val_uns%s
   --  system.val_uns%b
   --  system.val_int%s
   --  system.val_int%b
   --  ada.calendar%s
   --  ada.calendar%b
   --  ada.calendar.delays%s
   --  ada.calendar.delays%b
   --  ada.text_io%s
   --  ada.text_io%b
   --  ada.text_io.generic_aux%s
   --  ada.text_io.generic_aux%b
   --  ada.text_io.integer_aux%s
   --  ada.text_io.integer_aux%b
   --  ada.integer_text_io%s
   --  ada.integer_text_io%b
   --  gnat.exception_traces%s
   --  system.pool_global%s
   --  system.pool_global%b
   --  insa%s
   --  insa%b
   --  insa.audio%s
   --  insa.audio%b
   --  insa.audio.synthesizer%s
   --  insa.audio.synthesizer%b
   --  insa.base64%s
   --  insa.base64%b
   --  insa.keys%s
   --  insa.simulator%s
   --  insa.keys%b
   --  insa.timer%s
   --  insa.simulator.tasks%s
   --  insa.simulator.tasks%b
   --  insa.simulator%b
   --  insa.timer%b
   --  carte%s
   --  carte%b
   --  insa.graphics%s
   --  insa.graphics%b
   --  ecran%s
   --  ecran%b
   --  insa.memory%s
   --  insa.memory%b
   --  insa.graphics.images%s
   --  insa.graphics.images%b
   --  sprites%s
   --  lab%s
   --  lab%b
   --  missionpacman%b
   --  END ELABORATION ORDER

end ada_main;
