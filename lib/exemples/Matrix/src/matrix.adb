with Insa;
with Insa.Graphics;

use Insa;
use Insa.Graphics;

with Insa.Random_Number;

with Insa.Keys;
use Insa.Keys;

with Ada.Text_Io;

with Insa.Simulator;
with Insa.Simulator.Tasks;

procedure Matrix is

   MAX_NEW_DROP          : constant Natural := 5;
   MAX_TOTAL_DROPS       : constant Natural := 35;

   DropColor             : array (0..8) of COLOR := 
     (
      16#00#, 16#04#, 16#08#, 16#0C#, 16#10#,
      16#14#, 16#18#, 16#1C#, 16#FF#
     );

   type MATRIX_RAIN_ELEMENT is record
      Value              : Natural;
      Color              : Integer;
   end record; 

   type MATRIX_RAIN_ARRAY is array (0..TEXT_X'Last,0..TEXT_Y'Last) of MATRIX_RAIN_ELEMENT;
   MatrixRain            : MATRIX_RAIN_ARRAY := (others => (others => (0,0)));

   CurrentDropQuantity   : Natural:=0;

   procedure WriteChar(X : Natural; Y: Natural) is 
   begin   
      SetTextColor(DropColor(MatrixRain(X,Y).Color));
      if MatrixRain(X,Y).Value=0 then
         DrawString(X, Y, "0");
      elsif MatrixRain(X,Y).Value=1 then
         DrawString(X, Y, "1");
      else
         DrawString(X, Y, " ");
      end if;
   end WriteChar;

   function DrawValue return Natural is
      Val                : Insa.Random_Number.RANDOM_VALUE;
   begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Comme Valeur Soit 0 Soit 1
      if (Val mod 2)=0 then return 0;
      else return 1;
      end if;
   end DrawValue;

   function DrawColumn return Natural is
      Val                : Insa.Random_Number.RANDOM_VALUE;
      Column             : Natural;
   begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Une Valeur Entre 0 Et TEXT_X'Last
      Column := Val mod (TEXT_X'Last+1);
      return Column;
   end DrawColumn;

   function DrawDropNumber return Natural is
      Val                : Insa.Random_Number.RANDOM_VALUE;
      DropNumber         : Natural;
   begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Une Valeur Entre 0 Et MAX_NEW_DROP
      DropNumber := Val mod (MAX_NEW_DROP+1); 
      return DropNumber;
   end DrawDropNumber;

   procedure UpdateScreen is
   begin
      for Y in 0..TEXT_Y'Last loop
         for X in 0..TEXT_X'Last loop
            if MatrixRain(X,Y).Color /= 0 then
               MatrixRain(X,Y).Color:=MatrixRain(X,Y).Color-1;
               WriteChar(X,Y);
            end if;
         end loop;
      end loop;
   end UpdateScreen;

   procedure MoveDrops is
   begin
      SetTextColor(DropColor(DropColor'Last));
      CurrentDropQuantity:=0;

      for Y in reverse 0..TEXT_Y'Last loop
         for X in 0..TEXT_X'Last loop
            if MatrixRain(X,Y).Color = (DropColor'Last-1) then
               if Y<=(TEXT_Y'Last-1) then
                  CurrentDropQuantity:=CurrentDropQuantity+1;
                  MatrixRain(X, Y+1):=(DrawValue,DropColor'Last);
                  WriteChar(X,Y+1);
               end if;
            end if;
         end loop;
      end loop;
   end MoveDrops;

   procedure AddDrops is
      Quantity           : Natural;
      Column             : Natural;
   begin
      Quantity:=DrawDropNumber;
      SetTextColor(DropColor(DropColor'Last));

      if CurrentDropQuantity + Quantity > MAX_TOTAL_DROPS then
         Quantity := MAX_TOTAL_DROPS-CurrentDropQuantity;
      end if;

      for I in 1..Quantity loop
         Column := DrawColumn;
         MatrixRain(Column, 0):= (DrawValue,DropColor'Last);
         WriteChar(Column,0);
      end loop;

      CurrentDropQuantity:=CurrentDropQuantity+Quantity;
   end AddDrops;

   
begin
   SetTextColor(Black);
   SetBackColor(Black);
   DrawFillRectangle(0,0,PIXEL_X'Last, PIXEL_Y'Last);
   SetTextColor(DropColor(DropColor'Last));
   
   while True loop
      UpdateScreen;
   
      -- While GetKeyState(Key_A)/=Key_Pressed Loop
      --  Null;
      --End Loop;
   
      --While GetKeyState(Key_A)=Key_Pressed Loop
      --  Null;
      --End Loop;
   
      MoveDrops;
   
      AddDrops;
   
      SysDelay(100);
   end loop;
end Matrix;
