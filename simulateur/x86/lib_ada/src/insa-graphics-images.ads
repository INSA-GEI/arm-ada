-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--
-- pragma Ada_95;

with Insa.Graphics;
use Insa.Graphics;

with Insa.Memory;
use Insa.Memory;

package Insa.Graphics.Images is
   pragma Warnings (Off);
   
   type BITMAP is array(NATURAL range <>) of COLOR;
   type BITMAP_ACCESS is access all BITMAP;
   type IMAGE is 
      record
         Width: NATURAL := 0;
         Height: NATURAL := 0;
         Data : BITMAP_ACCESS;
      end record;
   
   type PACK_BITMAP_ELEMENT is 
      record
         Pixel : COLOR;
         Length : BYTE;
      end record;
   
   type PACK_BITMAP is array(NATURAL range <>) of PACK_BITMAP_ELEMENT;
   type PACK_BITMAP_ACCESS is access constant PACK_BITMAP;
   type PACK_IMAGE is
      record
         Width: NATURAL := 0;
         Height: NATURAL := 0;
         Data : PACK_BITMAP_ACCESS;
      end record;
   
   -- NewImage
   -- Create a new, empty image with a given width and height
   function NewImage(W: NATURAL; H: NATURAL) return IMAGE;
   
   -- FreeImage
   -- Destroy an image and free memory used
   procedure FreeImage (Img: in out IMAGE);
   
   -- DrawImage
   -- Draw an image at position (x,y) on screen
   procedure DrawImage(X: PIXEL_X; Y: PIXEL_Y; Img: IMAGE);
   
   -- DrawImageFromSRAM
   -- Draw an image, stored in SRAM, at position (x,y) on screen
   procedure DrawImageFromSRAM(X: PIXEL_X; Y: PIXEL_Y; W: NATURAL; H: NATURAL; Addr: MEMORY_ADDRESS);
   
   -- UnpackImage
   -- Unpack a compressed image to an usable image
   function UnpackImage(Pack_Img: PACK_IMAGE) return IMAGE;
   
   -- UnpackImageToSRAM
   -- Unpack a compressed image to an usable image directly into SRAM
   procedure UnpackImageToSRAM(Pack_Img: PACK_IMAGE; Addr: MEMORY_ADDRESS);

end Insa.Graphics.Images;
