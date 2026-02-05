with Insa;
with Insa.Graphics;
with Insa.Keys;

pragma Warnings (Off, "pragma Restrictions (No_Exception_Propagation) in effect");
pragma Warnings (Off, "*may call Last_Chance_Handler");

procedure Main is

   LabelInformation: Insa.Graphics.Pwidget;
   Label: Insa.Graphics.Pwidget;

   -- attend un appui sur la touche A
   procedure AttendreToucheA is
   begin
      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
   end AttendreToucheA;

   procedure TrowException is
      I: Natural:=10;
   begin
      loop
         I:=I-1;
      end loop;
   exception
         when others => Insa.Graphics.SetLabelText(Label, "exception in TrowException");
            raise Constraint_Error;
   end TrowException;



   I: Integer:=0;
   Str: constant String:="Ada rules !!";
begin

   LabelInformation := Insa.Graphics.CreateLabel(130, -80);
   Insa.Graphics.SetLabelText(LabelInformation, "Info");
   Label := Insa.Graphics.CreateLabel(130, -60);
   Insa.Graphics.SetLabelText(Label, Str);

   AttendreToucheA;

   loop
      begin
         TrowException;
      exception
         when others => Insa.Graphics.SetLabelText(Label, "Caught exception!");
      end;

      I:=I+1;

      AttendreToucheA;

      if I >1 then
         raise Constraint_Error;
      end if;

   end loop;

end Main;
