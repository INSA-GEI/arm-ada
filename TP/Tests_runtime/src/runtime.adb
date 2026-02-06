------------------------------------------------------------------------------
--                                                                          --
--                             Tests runtime                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with insa.Graphics;
with insa.Keys;
with Ada.Exceptions;  use Ada.Exceptions;

package body runtime is

   --  Test declare bloc
   procedure TestDeclare is
      Label, Label2: Insa.Graphics.PWidget;
      LabelArr: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Declare bloc");

      declare
         A: Integer;
         Arr: array (1..10) of Integer;
      begin
         A:=0;

         for I in Arr'Range loop
            Arr(I):=A;
            A:=A+1;
         end loop;

         LabelArr:=Insa.Graphics.CreateLabel(0,0);
         Insa.Graphics.SetLabelText(LabelArr,
                                    "A=" & Integer'Image(A) &
                                      ", arr(1)=" & Integer'Image(Arr(1)) &
                                      ", arr(10)=" & Integer'Image(Arr(10)));
      end;

      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestDeclare;

   --  Test Exception handling
   procedure TestException is
      Label, Label2, LabelException: Insa.Graphics.PWidget;

      ButtonRecursivity: Insa.Graphics.PWidget;
      ButtonRange: Insa.Graphics.PWidget;
      ButtonCatch:Insa.Graphics.PWidget;

      ButtonRecursivityLabel: Insa.Graphics.PWidget;
      ButtonRangeLabel: Insa.Graphics.PWidget;
      ButtonCatchLabel: Insa.Graphics.PWidget;

      MyException : exception;

      function RecursiveError(Val: Integer) return Integer is
      begin
         if Val>10 then
            return 1;
         else
            return RecursiveError(Val);
         end if;
      end RecursiveError;

      procedure RangeError is
         Val: Positive;
      begin
         Val := 5;

         loop
            Val:=Val-1;
         end loop;
      end RangeError;

      procedure RaiseException is
         Val: Integer;
      begin
         Val := 5;

         loop
            Val:=Val-1;
            if Val = 0 then
               raise MyException;
            end if;
         end loop;
      end RaiseException;

      Tmp: Integer;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test Exception handling");

      ButtonRecursivity:=Insa.Graphics.CreateButton(-100, -30, 150);
      ButtonRecursivityLabel:=Insa.Graphics.AddLabelToButton(ButtonRecursivity);
      Insa.Graphics.SetLabelText(ButtonRecursivityLabel, "Recursivity");
      Insa.Graphics.RealignWidget(ButtonRecursivity);

      ButtonRange:=Insa.Graphics.CreateButton(100, -30, 150);
      ButtonRangeLabel:=Insa.Graphics.AddLabelToButton(ButtonRange);
      Insa.Graphics.SetLabelText(ButtonRangeLabel, "Range");
      Insa.Graphics.RealignWidget(ButtonRange);

      ButtonCatch:=Insa.Graphics.CreateButton(0, 30, 150);
      ButtonCatchLabel:=Insa.Graphics.AddLabelToButton(ButtonCatch);
      Insa.Graphics.SetLabelText(ButtonCatchLabel, "Catch exception");
      Insa.Graphics.RealignWidget(ButtonCatch);

      while
        Insa.Graphics.GetButtonState(ButtonRecursivity) /= True and
        Insa.Graphics.GetButtonState(ButtonRange) /= True and
        Insa.Graphics.GetButtonState(ButtonCatch) /= True
      loop
         null;
      end loop;

      if Insa.Graphics.GetButtonState(ButtonRecursivity) then
         Insa.Graphics.WaitForButton(ButtonRecursivity);

         Tmp:=RecursiveError(5); -- Should raise STORAGE ERROR Exception
      elsif Insa.Graphics.GetButtonState(ButtonRange) then
         Insa.Graphics.WaitForButton(ButtonRange);

         RangeError;             -- Should raise CONSTRAINT ERROR exception
      elsif Insa.Graphics.GetButtonState(ButtonCatch) then
         Insa.Graphics.WaitForButton(ButtonCatch);

         begin
            RaiseException;         -- Should raise MyException exception
         exception
            when E : MyException =>
               --       ^ Exception to be handled
               LabelException:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-50);
               Insa.Graphics.SetLabelText(LabelException, "Exception " &  Ada.Exceptions.Exception_Name(E) & " caught");
         end;
      else
         null;
      end if;

      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestException;

end runtime;
