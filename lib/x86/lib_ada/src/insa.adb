-- Package Insa
-- Define several usefull types and generic functions
--

-- pragma Ada_95;

package body Insa is
   pragma Warnings (Off);
   
   type VERSION is access INTEGER;
   
   -- GetOSVersion
   -- Return current version as Major.Minor
   procedure GetOSVersion(Major: out INTEGER; Minor: out INTEGER) is
   begin
      Major:=2;
      Minor:=14;
   end GetOSVersion;
   
   -- SysDelay
   -- Wait during 'Time' millisecondes
   procedure SysDelay(Time: Positive) is
      TimeToWait: Duration:=Duration(Time)/Duration(1000);
   begin
      delay TimeToWait;
   end SysDelay;
   
end Insa;
