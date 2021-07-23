-- Package Insa.Sensors
-- Function for accessing sensor (accelerometer, magnetometer, gyroscope)
--

package Insa.Sensors is
   pragma Warnings (Off);
   
   type SENSOR_VALUES is array(1 .. 3) of Float;
   
   -- GetGyroscopicValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to gyroscopic sensor 
   -- values are given in mdps (milli degree of rotation per seconde)
   -- for example, if sensor has 5 degrees per seconde of rotation around X axis,
   -- returned value will be 5000.0
   
   -- gyroscope => speed of rotation around an axis
   function GetGyroscopicValues return SENSOR_VALUES;
   
   -- GetMagneticValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to magnetic sensor 
   -- magnetic sensor => sense the magnetic field seen by an axis
   -- values are givien in milligauss
   function GetMagneticValues return SENSOR_VALUES;
   
   -- GetAccelerometerValues
   -- return an array of 3 float values (axis X, Y and Z) corresponding to accelerometer sensor 
   -- accelerometer sensor => sense the acceleration as seen by an axis
   -- values are given in milliG (G, acceleration of earth attraction, 0,98 m/s)
   function GetAccelerometerValues return SENSOR_VALUES;

   -- GetPressure
   -- return a float value corresponding to atmospheric pressure 
   -- value is given in pascal
   function GetPressure return FLOAT;

   -- GetTemperature
   -- return a float value corresponding to temperature inside case 
   -- value is given in celsius degree
   function GetTemperature return FLOAT;
end Insa.Sensors;
