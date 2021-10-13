-- Package Insa.Keys
-- Functions to read keys state and potentiometer values
--

package Insa.Keys is
   pragma Warnings (Off);

   subtype KEY_STATE is INTEGER range 0 .. 1;
   subtype KEY_ID is INTEGER;
   
   type KEY_LIST is record
      A: KEY_STATE;
      B: KEY_STATE;
      X: KEY_STATE;
      Y: KEY_STATE;
      Down: KEY_STATE;
      Up: KEY_STATE;
      Right: KEY_STATE;
      Left: KEY_STATE;
   end record;
   
   -- Declaration of keys ID
   Key_A:      constant KEY_ID := 256+8; 
   Key_B:      constant KEY_ID := 256+4;
   Key_X:      constant KEY_ID := 256+2; 
   Key_Y:      constant KEY_ID := 256+1;
   Key_Up:     constant KEY_ID := 256+128; 
   Key_Down:   constant KEY_ID := 256+64; 
   Key_Left:   constant KEY_ID := 256+32; 
   Key_Right:  constant KEY_ID := 256+16; 
   
   -- Declaration of keys states
   Key_Released:  constant KEY_STATE := 0; 
   Key_Pressed:   constant KEY_STATE := 1; 
   
   -- GetKeyState
   -- Return the current state (Key_Pressed or Key_Released) of a given key (Key_A, Key_B, ...)
   -- Incorrect key id will raise CONSTRAINT_ERROR
   function GetKeyState(key: KEY_ID) return KEY_STATE;
   
   -- GetAllKeys
   -- Return all keys state in a single structure
   function GetAllKeys return KEY_LIST;
   
   -- WaitForKey
   -- Wait until key given in parameter has been pressed then release
   procedure WaitForKey(key: KEY_ID);

end Insa.Keys;
