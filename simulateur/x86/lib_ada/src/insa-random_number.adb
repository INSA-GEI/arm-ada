-- Package Insa.Random_Number
-- Function for generating random number
--
-- pragma Ada_95;
with Ada.Numerics.Discrete_Random;

package body Insa.Random_Number is
   package Random_Range is new Ada.Numerics.Discrete_Random (RANDOM_VALUE);
   use Random_Range;
   
   G : Generator;
   
   -- GetValue
   -- return a random number from 0 to 65535
   function GetValue return RANDOM_VALUE is   
   begin
      return Random(G);        
   end GetValue; 

begin
   Reset (G); -- Initialize random generator
end Insa.Random_Number;
