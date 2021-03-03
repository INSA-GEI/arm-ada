-- Package Insa.Random_Number
-- Function for generating random number
--
-- pragma Ada_95;
with Ada.Numerics.Discrete_Random;

package body Insa.Random_Number is
   
   Firstrun : Boolean:=True;
   
   -- GetValue
   -- return a random number from 0 to 65535
   function GetValue return RANDOM_VALUE is
      
      -- function Wrapper_GetValue return RANDOM_VALUE;
      -- pragma Import (C, Wrapper_GetValue, "RNG_GetValue");
      package Random_Die is new Ada.Numerics.Discrete_Random (RANDOM_VALUE);
      use Random_Die;
      G : Generator;
   begin
      -- return Wrapper_GetValue;
      if Firstrun then
         Reset (G);
         Firstrun := False;
      end if;
      
      return Random(G);
        
   end GetValue; 
   
end Insa.Random_Number;
