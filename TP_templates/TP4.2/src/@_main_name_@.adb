------------------------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Morse;
use Morse;

procedure mission_morse is
   
   type T_Lettre ;
   type Ptr_Lettre is access T_Lettre ;
   type T_Lettre is record
      Lettre : Ptr_Element ;
      Suiv : Ptr_Lettre ;
   end record ;
   
   
begin   
   while true loop
      null;
   end loop ;
end mission_morse;
