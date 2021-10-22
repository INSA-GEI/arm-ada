-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--

with System;
with Insa.Graphics;

with Interfaces.C;

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
   -- Create a new image widget into a parent widget
   function CreateImage (Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- CreateImage
   -- Create a new image widget on main screen
   function CreateImage (X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
     
   -- DrawImage
   -- Draw an image in an already created widget
   procedure DrawImage(Widget: not null PWidget; Image: not null PImg_Dsc_T);
   pragma Import (C, DrawImage, "lv_img_set_src");
   
   ------------------------------------------------------------------
   -- Routines pour l'objet Canvas
   --
   -- L'objet canvas sert a dessiner de maniere arbitraire (point, lignes, images)
   --
   --  type T_CanvasBuffer is array (Natural range <>, Natural range <>) of Insa.Graphics.Color;
   --  pragma Convention (C, T_CanvasBuffer);
   --  type PCanvasBuffer is access all T_CanvasBuffer;
   
   type PCanvasBuffer is access all Integer;
   
   -- CreateCanvas
   -- Create a canvas object into a parent widget
   function CreateCanvas (Parent: not null Pwidget; X: Integer; Y: Integer) return PWidget;
   
   -- CreateCanvas
   -- Create a canvas object on main screen
   function CreateCanvas (X: Integer; Y: Integer) return PWidget;

   -- AddBufferToCanvas
   -- Set a buffer for the canvas.
   -- buf a buffer where the content of the canvas will be.
   --  The required size is (lv_img_color_format_get_px_size(cf) * w) / 8 * h)
   --  It can be allocated with `lv_mem_alloc()` or
   --  it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or
   --  it can be an address in RAM or external SRAM
   procedure AddBufferToCanvas (Canvas: PWidget; W: Natural; H: Natural; C: Color);
   
   -- AllocateBufferforCanvas
   -- Set a buffer for the canvas.
   -- buf a buffer where the content of the canvas will be.
   --  The required size is (lv_img_color_format_get_px_size(cf) * w) / 8 * h)
   --  It can be allocated with `lv_mem_alloc()` or
   --  it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or
   --  it can be an address in RAM or external SRAM
   function AllocateBufferforCanvas (W: Natural; H: Natural; C: Color) return PCanvasBuffer;
   
   type T_Point is record
      X: Interfaces.C.Short;
      Y: Interfaces.C.Short;
   end record;
   pragma Convention (C, T_Point);
   
   type T_PointArray is array (Natural range <>) of T_Point;
   pragma Convention (C, T_PointArray);
   
   type T_Line is record
      Color: Insa.Graphics.Color;      -- Color of the line
      Width: Interfaces.C.Short;       -- width (in pixel) of the line
      Dash_Width: Interfaces.C.Short;  -- Dash length, in pixel
      Dash_Gap: Interfaces.C.Short;    -- Dash space, in pixel
      Opa : Byte;                      -- OPA = Transparency: 0=>Fully transparent, 255 => not transparent at all
      Other: Byte;                     -- unknown use
   end record;
   pragma Convention (C, T_Line);
     
   type P_Line is access all T_Line;
   
   procedure DrawLine(Canvas: PWidget; Points: T_PointArray; Point_Cnt: Integer; Line_Attr: P_Line);
end Insa.Graphics.Images;
