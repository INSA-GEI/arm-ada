------------------------------------------------------------------------------
--                                                                          --
--                             Mission Capteurs                             --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Sensors;
use Sensors;

procedure @_Main_Name_@ is
   type Element ;
   type P_Element is access Element;

   Type Element is 
      record
	      Norme : Integer;
	      Num : Natural;
	      Suiv : P_Element;
      end record;
   
begin
   loop     
      null;
   end loop;
end @_Main_Name_@;
