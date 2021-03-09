-- Package Insa.Keys
-- Functions to read keys state and potentiometer values
--

-- pragma Ada_95;
with Insa.Simulator;

package body Insa.Keys is
   
   -- GetKeyState
   -- Return the current state (Key_Pressed or Key_Released) of a given key (Key_A, Key_B, ...)
   -- Incorrect key id will raise CONSTRAINT_ERROR  
   function GetKeyState(Key: KEY_ID) return KEY_STATE is
      
      -- Wrapper to corresponding OS function
      -- function Wrapper_GetKeyState (key: KEY_ID) return KEY_STATE;
      -- pragma Import (C, Wrapper_GetKeyState, "KEYS_GetState");
      State: KEY_STATE:=Key_Released;
   begin
      -- return Wrapper_GetKeyState(Key);
      if Key = Key_A then
         State:=Simulator.GetSimulatorKeyState(Key_A);
      elsif Key = Key_B then
         State:=Simulator.GetSimulatorKeyState(Key_B);
      elsif Key = Key_X then
         State:=Simulator.GetSimulatorKeyState(Key_X);
      elsif Key = Key_Y then
         State:=Simulator.GetSimulatorKeyState(Key_Y);
      elsif Key = Key_Up then
         State:=Simulator.GetSimulatorKeyState(Key_Up);
      elsif Key = Key_Down then
         State:=Simulator.GetSimulatorKeyState(Key_Down);
      elsif Key = Key_Left then
         State:=Simulator.GetSimulatorKeyState(Key_Left);
      elsif Key = Key_Right then
         State:=Simulator.GetSimulatorKeyState(Key_Right);
      else
         null;
      end if;
      
      return State;
   end GetKeyState;
   
   -- GetAllKeys
   -- Return all keys state in a single structure
   function GetAllKeys return KEY_LIST is
      Keys: KEY_LIST;
   begin
      Keys.A:=GetKeyState(KEY_A);
      Keys.B:=GetKeyState(KEY_B);
      Keys.X:=GetKeyState(Key_X);
      Keys.Y:=GetKeyState(Key_Y);
      Keys.Center:=GetKeyState(KEY_CENTER);
      Keys.Up:=GetKeyState(KEY_UP);
      Keys.Down:=GetKeyState(KEY_DOWN);
      Keys.Left:=GetKeyState(KEY_LEFT);
      Keys.Right:=GetKeyState(KEY_RIGHT);
      
      return Keys;
   end GetAllKeys;
   
   -- GetPotentiometerValue
   -- Return the current value (range 0 to 255) of a given potentiometer (Potentiometer_Left or Potentiometer_Right)
   -- Incorrect potentiometer id will raise CONSTRAINT_ERROR  
   function GetPotentiometerValue(Pot: POTENTIOMETER_ID) return POTENTIOMETER_VALUE is
      
      -- Wrapper to corresponding OS function
      -- function Wrapper_GetPotentiometerValue(pot: POTENTIOMETER_ID) return POTENTIOMETER_VALUE;
      -- pragma Import (C, Wrapper_GetPotentiometerValue, "POT_GetValue");
      
   begin
      -- return Wrapper_GetPotentiometerValue(Pot);
      return 0;
   end GetPotentiometerValue;
   
end Insa.Keys;
