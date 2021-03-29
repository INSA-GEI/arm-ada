with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

    task Looper is
        entry Pause;
        entry Resume;
    end Looper;

    task body Looper is
        Running: Boolean := True;
        Count: Integer := 0;
    begin
        loop
            select
                accept Pause do
                    Running := False;
                end;
            or
                accept Resume do
                    Running := True;
                end;
            else
                null;
            end select;
            delay 1.0;
            if Running then
                Put_Line("Running, Count = " & Integer'Image(Count));
            end if;
            Count := Count + 1;
        end loop;
    end Looper;

begin -- Main
    loop
        delay 3.0;
        Looper.Pause;
        delay 3.0;
        Looper.Resume;
    end loop;

end Main;
