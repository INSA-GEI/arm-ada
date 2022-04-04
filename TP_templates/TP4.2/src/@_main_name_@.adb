------------------------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Morse;
use Morse;

procedure @_Main_Name_@ is
   type T_Mot ;
   type Ptr_Mot is access T_Mot ;
   type T_Mot is record
      Lettre : Ptr_Element ;
      Suiv : Ptr_Mot ;
   end record ;
   
begin
   loop    
      InitialiseEcran; 
      null;
   end loop;
end @_Main_Name_@;
