-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--
with Ada;
--  with Ada.Unchecked_Deallocation;

package body Insa.Graphics.Images is
   pragma Warnings (Off);
   
   --  -- NewImage
   --  -- Create a new, empty image with a given width and height
   --  function NewImage(W: NATURAL; H: NATURAL) return IMAGE is
   --     Img: IMAGE;
   --  begin
   --     Img.Data := new BITMAP(0..(W*H)-1);
   --     Img.Width := W;
   --     Img.Height := H;
   --  
   --     return Img;
   --  end NewImage;
   --  
   --  -- FreeImage
   --  -- Destroy an image and free memory used
   --  procedure FreeImage (Img: in out IMAGE) is
   --     procedure Free_BMP is new Ada.Unchecked_Deallocation (BITMAP, BITMAP_ACCESS);
   --     Bmp_Ptr: BITMAP_ACCESS := Img.Data;
   --  begin
   --     Free_BMP(BMP_Ptr);
   --     Img.Data :=null;
   --  end FreeImage;
   
   
   -- CreateImage
   -- Create a new image widget
   function CreateImage (X: PIXEL_Y; Y: PIXEL_Y; Alignement: Integer) return PWidget is
      function Wrp_UI_IMAGE_Create(X: PIXEL_Y; Y: PIXEL_Y; Alignment: Integer) return PWidget;
      pragma Import (C, Wrp_UI_IMAGE_Create, "UI_IMAGE_Create");
   begin
      return Wrp_UI_IMAGE_Create(X,Y,ALIGNEMENT_CENTER);
   end CreateImage;
   
   --   -- UnpackImage
   --   -- Unpack a compressed image to an usable image
   --   function UnpackImage(Pack_Img: PACK_IMAGE) return IMAGE is
   --      Img: IMAGE;
   --      Index: NATURAL:=0;
   --   begin
   --      Img:=NewImage(Pack_Img.Width,Pack_Img.Height);
   --  
   --      for I in Pack_Img.Data'Range loop
   --  for X in 0 .. Pack_Img.Data(I).Length-1 loop
   --     Img.Data(Index+Natural(X)):=Pack_Img.Data(I).Pixel;
   --  end loop;
   --  
   --  Index:=Index + NATURAL(Pack_Img.Data(I).Length);
   --      end loop;
   --  
   --      return Img;
   --   end UnpackImage;
   
end Insa.Graphics.Images;
