-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--
with Ada;
--  with Ada.Unchecked_Deallocation;

package body Insa.Graphics.Images is
   pragma Warnings (Off);
   
   -- CreateImage
   -- Create a new image widget
   function CreateImage(Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget is
      -- function Wrp_UI_IMAGE_Create(X: Integer; Y: Integer; Alignment: Integer) return PWidget;
      -- pragma Import (C, Wrp_UI_IMAGE_Create, "UI_IMAGE_Create");
      function Wrp_Lv_Img_Create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_Lv_Img_Create, "lv_img_create");
      Tmp: PWidget;
   begin
      Tmp:= Wrp_Lv_Img_Create(Parent, null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp,X,Y);
      return Tmp;
   end CreateImage;
   
   -- CreateImage
   -- Create a new image widget
   function CreateImage(X: Integer; Y: Integer; Length: Integer:=0) return PWidget is  
   begin
      return CreateImage(GetScreenId, X, Y, Length);
   end CreateImage;
   
end Insa.Graphics.Images;
