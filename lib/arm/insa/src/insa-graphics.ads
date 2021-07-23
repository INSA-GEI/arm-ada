-- Package Insa.Graphics
-- Functions for drawing primitives and character string on screen
--

-- pragma Ada_95;
with System;
with Interfaces;

package Insa.Graphics is
   pragma Warnings (Off);

   SCREEN_WIDTH:  constant Integer := 480;
   SCREEN_HEIGHT: constant Integer := 272;
     
   subtype PIXEL_X is Integer range 0 .. (SCREEN_WIDTH-1);
   subtype PIXEL_Y is Integer range 0 .. (SCREEN_HEIGHT-1);
   
   --------------------------------------------------------------
   -- Colors are 16 bit wide
   -- 16 bit values are split in RGB components
   -- with 5 bits for Red, 6 for Green et 5 for blue (RGB 5:6:5)
   --------------------------------------------------------------
   type Color_Red is mod (2 ** 5);
   type Color_Green is mod (2 ** 6);
   type Color_Blue is mod (2 ** 5);
   
   type Color is
      record
         R : Color_Red;
         G : Color_Green;
         B : Color_Blue;
      end record;

   for Color use
      record
         R at 0 range 11 .. 15;
         G at 0 range 5 .. 10;
         B at 0 range 0 .. 4;
      end record;
   for Color'Size use Interfaces.Unsigned_16'Size;
   for Color'Bit_Order use System.High_Order_First;
   
   Black:      constant Color := (16#00#, 16#00#, 16#00#);
   --  Navy:       constant Color := 16#0001#;
   --  DarkGreen:  constant Color := 16#000C#;
   --  DarkCyan:   constant Color := 16#000D#;
   --  Maroon:     constant Color := 16#0060#;
   --  Purple:     constant Color := 16#0061#;
   --  Olive:      constant Color := 16#006C#;
   --  LightGrey:  constant Color := 16#00B6#;
   --  DarkGrey:   constant Color := 16#006D#;
   --  Blue:       constant Color := 16#0003#;
   --  Green:      constant Color := 16#001C#;
   --  Cyan:       constant Color := 16#001F#;
   --  Red:        constant Color := 16#00E0#;
   --  LightRed:   constant Color := 16#00EC#;
   --  Magenta:    constant Color := 16#00E3#;
   --  Yellow:     constant Color := 16#00FC#;
   --  White:      constant Color := 16#FFFF#;
   
   type PWidget is access all Integer;
   
   -- SetWidgetPosition
   -- Move widget to a given position
   procedure SetWidgetPosition (Widget: PWidget; X: PIXEL_X; Y: PIXEL_Y);
   
   -- SetWidgetSize
   -- Resize a widget to a new size
   -- Set Width or Height to -1 for not changing this dimension
   procedure SetWidgetSize (Widget: PWidget; Width: Integer; Height: Integer);
   
   -- AddChild
   -- Add a child to an existing widget
   procedure AddChild (Parent: PWidget; Child: PWidget);
   
   -- DestroyWidget
   -- Remove a widget and free its allocation and all of its child
   -- Widget access is set to null
   procedure DestroyWidget (Widget: in out Pwidget);
   
   -- ClearScreen
   -- Empty screen, remove all widgets
   procedure ClearScreen;
   
   -- CreateMessageBox
   -- Create a messagebox for information 
   procedure CreateMessageBox (Msg: String; Button_Txt: String);
   
   -- CreateLabel
   -- Create a label widget for writting text, and move it to given position
   function CreateLabel (X: PIXEL_Y; Y: PIXEL_Y; Text: String:="") return PWidget;
   
   -- SetLabelText
   -- Change label text
   procedure SetLabelText (Label: PWidget; Text: String);
   
   --  -- PutPixel
   --  -- Draw a single pixel (dot) on screen
   --  procedure PutPixel (x: PIXEL_X; y: PIXEL_Y; c: COLOR);
   --  
   --  -- DrawString
   --  -- Draw a string on screen, like on a tty display
   --  procedure DrawString (x: PIXEL_X; y: PIXEL_Y; s: String);
   --  
   --  -- DrawChar
   --  -- Draw a character on screen, like on a tty display
   --  procedure DrawChar (x: PIXEL_X; y: PIXEL_Y; c: Character);
   --  
   --  -- DrawLine
   --  -- Draw a line on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawLine(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --  
   --  -- DrawRectangle
   --  -- Draw an empty (only border) rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --  
   --  -- DrawRectangle
   --  -- Draw a solid filled rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawFillRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --  
   --  -- DrawCircle
   --  -- Draw an empty (only border) circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   --  procedure DrawCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER);
   --  
   --  -- DrawCircle
   --  -- Draw a solid filled circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   --  procedure DrawFillCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER);

end Insa.Graphics;
