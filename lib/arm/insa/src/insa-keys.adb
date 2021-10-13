-- Package Insa.Keys
-- Functions to read keys state and potentiometer values
--

package body Insa.Keys is
   
   -- GetKeyState
   -- Return the current state (Key_Pressed or Key_Released) of a given key (Key_A, Key_B, ...)
   -- Incorrect key id will raise CONSTRAINT_ERROR  
   function GetKeyState(Key: KEY_ID) return KEY_STATE is
      
      -- Wrapper to corresponding OS function
      function Wrapper_GetKeyState (Key: KEY_ID) return KEY_STATE;
      pragma Import (C, Wrapper_GetKeyState, "BSP_PB_GetState");
      
   begin
      return Wrapper_GetKeyState(Key);
   end GetKeyState;
   
   -- GetAllKeys
   -- Return all keys state in a single structure
   function GetAllKeys return KEY_LIST is
      Keys: KEY_LIST;
   begin
      Keys.A:=GetKeyState(Key_A);
      Keys.B:=GetKeyState(Key_B);
      Keys.A:=GetKeyState(Key_X);
      Keys.B:=GetKeyState(Key_Y);
      Keys.Up:=GetKeyState(Key_Up);
      Keys.Down:=GetKeyState(Key_Down);
      Keys.Left:=GetKeyState(Key_Left);
      Keys.Right:=GetKeyState(Key_Right);
      
      return Keys;
   end GetAllKeys;
   
   -- WaitForKey
   -- Wait until key given in parameter has been pressed then release
   procedure WaitForKey(Key: KEY_ID) is
   begin
      while GetKeyState(Key) /= Key_Pressed loop
         null;
      end loop;

      while GetKeyState(Key) /= Key_Released loop
         null;
      end loop;
   end WaitForKey;
   
end Insa.Keys;
