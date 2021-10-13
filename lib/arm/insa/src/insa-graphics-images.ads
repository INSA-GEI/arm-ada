-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--

with System;
with Insa.Graphics;

package Insa.Graphics.Images is
   pragma Warnings (Off);
   
   type ColorFormat is mod    (2 ** 5);
   type AlwaysZeroField is mod    (2 ** 3);
   type ReservedField is mod (2**2);
   type ImageWidth is mod (2**11);
   type ImageHeight is mod (2**11);

   IMG_CF_UNKNOWN :constant ColorFormat := 0;
   
   IMG_CF_RAW:constant ColorFormat := 1;                     -- Contains the file as it is. Needs custom decoder function
   IMG_CF_RAW_ALPHA:constant ColorFormat := 2;               -- Contains the file as it is. The image has alpha. Needs custom decoder function
   IMG_CF_RAW_CHROMA_KEYED:constant ColorFormat := 3;        -- Contains the file as it is. The image is chroma keyed. Needs custom decoder function

   IMG_CF_TRUE_COLOR:constant ColorFormat := 4;              -- Color format and depth should match with LV_COLOR settings
   IMG_CF_TRUE_COLOR_ALPHA:constant ColorFormat := 5;        -- Same as `LV_IMG_CF_TRUE_COLOR` but every pixel has an alpha byte
   IMG_CF_TRUE_COLOR_CHROMA_KEYED:constant ColorFormat := 6; -- Same as `LV_IMG_CF_TRUE_COLOR` but LV_COLOR_TRANSP pixels will be transparent

   IMG_CF_INDEXED_1BIT:constant ColorFormat := 7;            -- Can have 2 different colors in a palette (always chroma keyed)
   IMG_CF_INDEXED_2BIT:constant ColorFormat := 8;            -- Can have 4 different colors in a palette (always chroma keyed)
   IMG_CF_INDEXED_4BIT:constant ColorFormat := 9;            -- Can have 16 different colors in a palette (always chroma keyed)
   IMG_CF_INDEXED_8BIT:constant ColorFormat := 10;            -- Can have 256 different colors in a palette (always chroma keyed)

   IMG_CF_ALPHA_1BIT:constant ColorFormat := 11;              -- Can have one color and it can be drawn or not
   IMG_CF_ALPHA_2BIT:constant ColorFormat := 12;              -- Can have one color but 4 different alpha value
   IMG_CF_ALPHA_4BIT:constant ColorFormat := 13;              -- Can have one color but 16 different alpha value
   IMG_CF_ALPHA_8BIT:constant ColorFormat := 14;              -- Can have one color but 256 different alpha value
   
   type Img_Header_T is record
      Cf : ColorFormat;             -- Color format: See `lv_img_color_format_t`
      Always_Zero : AlwaysZeroField;-- It the upper bits of the first byte. Always zero to look like a non-printable character
      Reserved : ReservedField;     -- Reserved to be used later
      W : ImageWidth;               -- Width of the image map
      H : ImageHeight;              -- Height of the image map
   end record with Atomic;
   pragma Convention (C, Img_Header_T);
   
   --  for Img_Header_T use
   --     record
   --        Cf          at 0 range 0 .. 4;
   --        Always_Zero at 0 range 5 .. 7;
   --        Reserved    at 0 range 8 .. 9;
   --        W           at 0 range 10 .. 20;
   --        H           at 0 range 21 .. 31;
   --     end record;
   for Img_Header_T use
      record
         Cf          at 0 range 0 .. 4;             
         Always_Zero at 0 range 5 .. 7; 
         Reserved    at 0 range 8 .. 9;   
         W           at 0 range 10 .. 20;             
         H           at 0 range 21 .. 31;           
      end record;
   
   for Img_Header_T'Size use 32;
   for Img_Header_T'Bit_Order use System.Low_Order_First;
   
   type Bitmap is array(NATURAL range <>) of BYTE;
   type PBitmap is access constant Bitmap;
   
   type Img_Dsc_T is record
      Header:Img_Header_T;
      Data_Size:Interfaces.C.Unsigned;
      Data : PBitmap;
   end record;
   pragma Convention (C, Img_Dsc_T);
   
   type PImg_Dsc_T is access constant Img_Dsc_T;
   
   -- CreateImage
   -- Create a new image widget
   function CreateImage (X: PIXEL_Y; Y: PIXEL_Y; Alignement: Integer) return PWidget;
     
   -- DrawImage
   -- Draw an image in an already created widget
   procedure DrawImage(Widget: not null PWidget; Image: not null PImg_Dsc_T);
   pragma Import (C, DrawImage, "lv_img_set_src");

   --  type BITMAP is array(NATURAL range <>) of COLOR;
   --  type BITMAP_ACCESS is access all BITMAP;
   --  type IMAGE is
   --     record
   --        Width: NATURAL := 0;
   --        Height: NATURAL := 0;
   --        Data : BITMAP_ACCESS;
   --     end record;
   --  
   --  type PACK_BITMAP_ELEMENT is
   --     record
   --        Pixel : COLOR;
   --        Length : BYTE;
   --     end record;
   --  
   --  type PACK_BITMAP is array(NATURAL range <>) of PACK_BITMAP_ELEMENT;
   --  type PACK_BITMAP_ACCESS is access constant PACK_BITMAP;
   --  type PACK_IMAGE is
   --     record
   --        Width: NATURAL := 0;
   --        Height: NATURAL := 0;
   --        Data : PACK_BITMAP_ACCESS;
   --     end record;
   --  
   --  -- NewImage
   --  -- Create a new, empty image with a given width and height
   --  function NewImage(W: NATURAL; H: NATURAL) return IMAGE;
   --  
   --  -- FreeImage
   --  -- Destroy an image and free memory used
   --  procedure FreeImage (Img: in out IMAGE);
  
   -- DrawImage
   -- Draw an image at position (x,y) on screen
   --  procedure DrawImage(Widget: PWidget; Image: IMAGE);
   
   --  -- UnpackImage
   --  -- Unpack a compressed image to an usable image
   --  function UnpackImage(Pack_Img: PACK_IMAGE) return IMAGE;

end Insa.Graphics.Images;
