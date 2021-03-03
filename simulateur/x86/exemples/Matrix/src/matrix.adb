With Insa;
With Insa.Graphics;

Use Insa;
Use Insa.Graphics;

With Insa.Random_Number;

With Insa.Keys;
Use Insa.Keys;

With Ada.Text_Io;

with Insa.Simulator;

Procedure Matrix Is

   MAX_NEW_DROP          : Constant Natural := 5;
   MAX_TOTAL_DROPS       : Constant Natural := 35;

   DropColor             : Array (0..8) Of COLOR := 
     (
      16#00#, 16#04#, 16#08#, 16#0C#, 16#10#,
      16#14#, 16#18#, 16#1C#, 16#FF#
     );

   Type MATRIX_RAIN_ELEMENT Is Record
      Value              : Natural;
      Color              : Integer;
   End Record; 

   Type MATRIX_RAIN_ARRAY Is Array (0..TEXT_X'Last,0..TEXT_Y'Last) Of MATRIX_RAIN_ELEMENT;
   MatrixRain            : MATRIX_RAIN_ARRAY := (Others => (Others => (0,0)));

   CurrentDropQuantity   : Natural:=0;

   Procedure WriteChar(X : Natural; Y: Natural) Is 
   Begin   
      SetTextColor(DropColor(MatrixRain(X,Y).Color));
      If MatrixRain(X,Y).Value=0 Then
         DrawString(X, Y, "0");
      Elsif MatrixRain(X,Y).Value=1 Then
         DrawString(X, Y, "1");
      Else
         DrawString(X, Y, " ");
      End If;
   End WriteChar;

   Function DrawValue Return Natural Is
      Val                : Insa.Random_Number.RANDOM_VALUE;
   Begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Comme Valeur Soit 0 Soit 1
      If (Val Mod 2)=0 Then Return 0;
      Else Return 1;
      End If;
   End DrawValue;

   Function DrawColumn Return Natural Is
      Val                : Insa.Random_Number.RANDOM_VALUE;
      Column             : Natural;
   Begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Une Valeur Entre 0 Et TEXT_X'Last
      Column := Val Mod (TEXT_X'Last+1);
      Return Column;
   End DrawColumn;

   Function DrawDropNumber Return Natural Is
      Val                : Insa.Random_Number.RANDOM_VALUE;
      DropNumber         : Natural;
   Begin
      Val := Insa.Random_Number.GetValue;

      -- Renvoi Une Valeur Entre 0 Et MAX_NEW_DROP
      DropNumber := Val Mod (MAX_NEW_DROP+1); 
      Return DropNumber;
   End DrawDropNumber;

   Procedure UpdateScreen Is
   Begin
      For Y In 0..TEXT_Y'Last Loop
         For X In 0..TEXT_X'Last Loop
            If MatrixRain(X,Y).Color /= 0 Then
               MatrixRain(X,Y).Color:=matrixRain(X,Y).Color-1;
               WriteChar(X,Y);
            End If;
         End Loop;
      End Loop;
   End UpdateScreen;

   Procedure MoveDrops Is
   Begin
      SetTextColor(DropColor(DropColor'Last));
      CurrentDropQuantity:=0;

      For Y In Reverse 0..TEXT_Y'Last Loop
         For X In 0..TEXT_X'Last Loop
            If MatrixRain(X,Y).Color = (DropColor'Last-1) Then
               If Y<=(TEXT_Y'Last-1) Then
                  CurrentDropQuantity:=currentDropQuantity+1;
                  MatrixRain(X, Y+1):=(DrawValue,DropColor'Last);
                  WriteChar(X,Y+1);
               End If;
            End If;
         End Loop;
      End Loop;
   End MoveDrops;

   Procedure AddDrops Is
      Quantity           : Natural;
      Column             : Natural;
   Begin
      Quantity:=DrawDropNumber;
      SetTextColor(DropColor(DropColor'Last));

      If CurrentDropQuantity + Quantity > MAX_TOTAL_DROPS Then
         Quantity := MAX_TOTAL_DROPS-CurrentDropQuantity;
      End If;

      For I In 1..Quantity Loop
         Column := DrawColumn;
         MatrixRain(Column, 0):= (DrawValue,DropColor'Last);
         WriteChar(Column,0);
      End Loop;

      CurrentDropQuantity:=currentDropQuantity+Quantity;
   End AddDrops;

   
begin
   Simulator.Test;
   Simulator.Init;
   Simulator.SendMessage ("Socket Yeah");
   Simulator.SendMessage ("Second line");
   
   -- Ada.Text_IO.Put_Line ("Received message: " & Simulator.ReceiveMessage);
   
   --  SetTextColor(Black);
   --  SetBackColor(Black);
   --  DrawFillRectangle(0,0,PIXEL_X'Last, PIXEL_Y'Last);
   --  SetTextColor(DropColor(DropColor'Last));
   --  
   --  While True Loop
   --     UpdateScreen;
   --  
   --     -- While GetKeyState(Key_A)/=Key_Pressed Loop
   --     --  Null;
   --     --End Loop;
   --  
   --     --While GetKeyState(Key_A)=Key_Pressed Loop
   --     --  Null;
   --     --End Loop;
   --  
   --     MoveDrops;
   --  
   --     AddDrops;
   --  
   --     SysDelay(100);
   --  End Loop;
   Simulator.Close;
End Matrix;
