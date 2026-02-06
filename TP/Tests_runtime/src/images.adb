------------------------------------------------------------------------------
--                                                                          --
--                             Tests Images                                 --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with insa.Graphics.Images;
with insa.Keys;
with Sprites;

package body images is

   -- Test createImage / DrawImage
   procedure TestImage is
      Label, Label2: Insa.Graphics.PWidget;
      Image: Insa.Graphics.PWidget;
   begin
      Label:=Insa.Graphics.CreateLabel(0,-(Insa.Graphics.SCREEN_HEIGHT/2)+20);
      Insa.Graphics.SetLabelText(Label, "Test DrawImage");
      Label2:=Insa.Graphics.CreateLabel(0,+(Insa.Graphics.SCREEN_HEIGHT/2)-20);
      Insa.Graphics.SetLabelText(Label2, "Press A to continue");

      Image:=Insa.Graphics.Images.CreateImage(0,0,Insa.Graphics.ALIGNEMENT_CENTER);
      Insa.Graphics.Images.DrawImage(Image, Sprites.Cerise'Access);
      Insa.Graphics.RealignWidget(Image);

      Insa.Keys.WaitForKey(Insa.Keys.Key_A);
      Insa.Graphics.ClearScreen;
   end TestImage;

end images;
