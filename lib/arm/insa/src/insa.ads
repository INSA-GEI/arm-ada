-- Package Insa
-- Define several usefull types and generic functions
--

-- pragma Ada_95;
with Interfaces;

package Insa is
   pragma Warnings (Off);
   
   -- Definition of an unsigned byte (8 bit long)
   type BYTE is new Interfaces.Unsigned_8;
   
   -- Definition of a signed byte (8 bit long)
   type SIGNED_BYTE is new Interfaces.Integer_8;
   
   -- Definition of an unsigned word (16 bit long)
   type WORD is new Interfaces.Unsigned_16;
   
   -- Definition of a signed word (16 bit long)
   type SIGNED_WORD is new Interfaces.Integer_16;
   
   -- GetOSVersion
   -- Return current version as Major.Minor
   procedure GetOSVersion(Major: out INTEGER; Minor: out INTEGER);
   
   -- SysDelay
   -- Wait during 'Time' millisecondes
   procedure SysDelay(Time: Positive);

end Insa;
