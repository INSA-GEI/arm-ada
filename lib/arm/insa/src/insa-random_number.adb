-- Package Insa.Random_Number
-- Function for generating random number
--

with Interfaces.C;
use Interfaces.C;

package body Insa.Random_Number is
   
   -- GetValue
   -- return a random number from 0 to 65535
   function GetValue return RANDOM_VALUE is
      
      function Wrapper_GetValue return Interfaces.C.unsigned;
      pragma Import (C, Wrapper_GetValue, "BSP_RNG_GetNumber");
      
      Tmp: Interfaces.C.Unsigned;
      
   begin
      Tmp := Wrapper_GetValue;
      return RANDOM_VALUE(Tmp/65536);
   end GetValue; 
   
end Insa.Random_Number;
