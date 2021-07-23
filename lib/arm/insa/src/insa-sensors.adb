-- Package Insa.Sensors
-- Function for accessing sensor (accelerometer, magnetometer, gyroscope)
--

package body Insa.Sensors is
   
   type WRAPPER_VALUES is array(0..2) of FLOAT;
   type WRAPPER_ACCESS is access WRAPPER_VALUES;
   
   -- GetGyroscopicValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to gyroscopic sensor 
   -- values are given in mdps (milli degree of rotation per seconde)
   -- for example, if sensor has 5 degrees per seconde of rotation around X axis,
   -- returned value will be 5000.0
   
   -- gyroscope => speed of rotation around an axis
   
   function GetGyroscopicValues return SENSOR_VALUES is
   
     function Wrapper_GetGyroscopicValues return WRAPPER_ACCESS;
     pragma Import (C, Wrapper_GetGyroscopicValues, "BSP_GYRO_ReadValues");
     
     Values: SENSOR_VALUES;
     Wrapper_Values: WRAPPER_ACCESS;
     
   begin 
      Wrapper_Values := Wrapper_GetGyroscopicValues;
      
      pragma Warnings (Off);
      Values(1) := Wrapper_Values(0);
      Values(2) := Wrapper_Values(1);
      Values(3) := Wrapper_Values(2);
      pragma Warnings (On);
      
      return Values;
   end GetGyroscopicValues;
   
   -- GetMagneticValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to magnetic sensor 
   -- magnetic sensor => sense the magnetic field seen by an axis
   -- values are givien in milligauss
   function GetMagneticValues return SENSOR_VALUES is
      
     function Wrapper_GetMagneticValues return WRAPPER_ACCESS;
     pragma Import (C, Wrapper_GetMagneticValues, "BSP_MAG_ReadValues");
     
     Values: SENSOR_VALUES;
     Wrapper_Values: WRAPPER_ACCESS;
   begin
      Wrapper_Values := Wrapper_GetMagneticValues;
      
      pragma Warnings (Off);
      Values(1) := Wrapper_Values(0);
      Values(2) := Wrapper_Values(1);
      Values(3) := Wrapper_Values(2);
      pragma Warnings (On);
      
      return Values;
   end GetMagneticValues;
   
   -- GetAccelerometerValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to accelerometer sensor 
   -- accelerometer sensor => sense the acceleration as seen by an axis
   -- values are given in milliG (G, acceleration of earth attraction, 0,98 m/s)
   function GetAccelerometerValues return SENSOR_VALUES is
      
     function Wrapper_GetAccelerometerValues return WRAPPER_ACCESS;
     pragma Import (C, Wrapper_GetAccelerometerValues, "BSP_ACC_ReadValues");
     
     Values: SENSOR_VALUES;
     Wrapper_Values: WRAPPER_ACCESS;
   begin
      Wrapper_Values := Wrapper_GetAccelerometerValues;
      
      pragma Warnings (Off);
      Values(1) := Wrapper_Values(0);
      Values(2) := Wrapper_Values(1);
      Values(3) := Wrapper_Values(2);
      pragma Warnings (On);
      
      return Values;
   end GetAccelerometerValues;
   
   -- GetPressure
   -- return a float value corresponding to atmospheric pressure 
   -- value is given in pascal
   function GetPressure return FLOAT is
      
     procedure Wrapper_GetPressureValue (Pressure: out Float; Temperature: out Float);
     pragma Import (C, Wrapper_GetPressureValue, "BSP_PRESSURE_ReadCompensatedValues");
     
     Pressure,Temperature: FLOAT;
   begin
      Wrapper_GetPressureValue(Pressure, Temperature);
      
      return Pressure;
   end GetPressure;

   -- GetTemperature
   -- return a float value corresponding to temperature inside case 
   -- value is given in celsius degree
   function GetTemperature return FLOAT is
      
     procedure Wrapper_GetTemperatureValue (Pressure: out Float; Temperature: out Float);
     pragma Import (C, Wrapper_GetTemperatureValue, "BSP_PRESSURE_ReadCompensatedValues");
     
     Pressure,Temperature: FLOAT;
   begin
      Wrapper_GetTemperatureValue(Pressure, Temperature);
      
      return Temperature;
   end GetTemperature;
end Insa.Sensors;
