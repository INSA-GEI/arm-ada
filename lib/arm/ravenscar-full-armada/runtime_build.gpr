with "target_options.gpr";
--  with "bsp_build.gpr";

project Runtime_Build is

   for Languages use ("Ada", "C", "Asm_Cpp");
   for Runtime ("ada") use project'Project_Dir;
   for Target use "arm-eabi";
   for Library_Auto_Init use "False";
   for Library_Name use "gnat";
   for Library_Kind use "static";
   for Library_Dir use "adalib";
   for Object_Dir use "obj";
   for Source_Dirs use ("gnat_user", "gnat", "gnarl_user", "gnarl");

   package Compiler renames Target_Options.Compiler;

   package Builder is
      for Switches ("ada") use ("-j4", "-g");
      for Switches ("C") use ("-j4", "-g");
   end Builder;

end Runtime_Build;

