-- Package Insa.Graphics
-- Functions for drawing primitives and character string on screen
--

-- pragma Ada_95;

with Insa.Simulator; use Insa.Simulator;

package body Insa.Graphics is
   
   type RGB is 
      record
         R:BYTE;
         G:BYTE;
         B:BYTE;
      end record;
   
   function ColorToRGB (C: COLOR) return RGB is
      Crgb: RGB;
   begin
      Crgb.B:=C and 16#03#;
      
      Crgb.R:=C and 16#E0#;
      Crgb.R:=Shift_Right(Crgb.R,5);
      
      Crgb.G:=C and 16#1C#;
      Crgb.G:=Shift_Right(Crgb.G,2);
      
      return Crgb;
   end ColorToRGB;
   
   function RGBToColor (R: BYTE; G: BYTE; B: BYTE) return Color is
      C: Color;
   begin
      C:=16#00#;
      return C;
   end RGBToColor;
   
   -- DrawString
   -- Draw a string on screen, like on a tty display
   procedure DrawString (X: TEXT_X; Y: TEXT_Y; S: String) is
   begin
      SendMessage("DRAWTEXT=" & Integer'Image(X) & "," & Integer'Image(Y) & "," & S);
   end DrawString;
   
   -- SetTextColor
   -- Set the color used for drawing text (Black, Navy, DrakGreen ...)   
   procedure SetTextColor(Val: COLOR) is
      Crgb : RGB;
   begin
      Crgb:=ColorToRGB(Val);
      SendMessage("SETTEXTCOLOR=" & Integer'Image(Integer(Crgb.R)) & "," & Integer'Image(Integer(Crgb.G)) & "," & Integer'Image(Integer(Crgb.B)));
   end SetTextColor;
   
   -- SetBackColor
   -- Set the color used for drawing text background (Black, Navy, DrakGreen ...)  
   procedure SetBackColor(Val: COLOR) is
      Crgb : RGB;
   begin
      Crgb:=ColorToRGB(Val);
      SendMessage("SETBGCOLOR=" & Integer'Image(Integer(Crgb.R)) & "," & Integer'Image(Integer(Crgb.G)) & "," & Integer'Image(Integer(Crgb.B)));
   end SetBackColor;
   
   -- SetPenColor
   -- Set the color used for drawing graphic primitives like lines, circles, rectangles
   procedure SetPenColor(Val: COLOR) is
   begin 
      SetTextColor(Val);
   end SetPenColor;
   
   -- ClearScreen
   -- Empty screen, with background defined
   procedure ClearScreen(Val: COLOR) is
      Crgb : RGB;
   begin
      Crgb:=ColorToRGB(Val);
      SendMessage("CLEARSCREEN=" & Integer'Image(Integer(Crgb.R)) & "," & Integer'Image(Integer(Crgb.G)) & "," & Integer'Image(Integer(Crgb.B)));
   end ClearScreen;
   
   -- PutPixel
   -- Draw a single pixel (dot) on screen
   procedure PutPixel (X: PIXEL_X; Y: PIXEL_Y; C: COLOR) is
      Crgb : RGB;
   begin
      Crgb:=ColorToRGB(C);
      SendMessage("PUTPIXEL=" & Integer'Image(X) & "," & Integer'Image(Y) & "," & Integer'Image(Integer(Crgb.R)) & "," & Integer'Image(Integer(Crgb.G)) & "," & Integer'Image(Integer(Crgb.B)));
   end Putpixel;

   -- DrawLine
   -- Draw a line, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   procedure DrawLine(X1: PIXEL_X; Y1: PIXEL_Y; X2: PIXEL_X; Y2: PIXEL_Y) is
   begin 
      SendMessage("DRAWLINE=" & Integer'Image(X1) & "," & Integer'Image(Y1) & "," & Integer'Image(X2) & "," & Integer'Image(Y2));
   end DrawLine;
   
   -- DrawRectangle
   -- Draw an empty rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   procedure DrawRectangle(X1: PIXEL_X; Y1: PIXEL_Y; X2: PIXEL_X; Y2: PIXEL_Y) is
   begin
      SendMessage("DRAWRECT=" & Integer'Image(X1) & "," & Integer'Image(Y1) & "," & Integer'Image(X2) & "," & Integer'Image(Y2));
   end DrawRectangle;
   
   -- DrawFillRectangle
   -- Draw a solid filled rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   procedure DrawFillRectangle(X1: PIXEL_X; Y1: PIXEL_Y; X2: PIXEL_X; Y2: PIXEL_Y) is
   begin
      SendMessage("DRAWFILLRECT=" & Integer'Image(X1) & "," & Integer'Image(Y1) & "," & Integer'Image(X2) & "," & Integer'Image(Y2));
   end DrawFillRectangle;
   
   -- DrawCircle
   -- Draw an empty circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   procedure DrawCircle(X: PIXEL_X; Y: PIXEL_Y; Radius: INTEGER) is
   begin
      SendMessage("DRAWCIRCLE=" & Integer'Image(X) & "," & Integer'Image(Y) & "," & Integer'Image(Radius));
   end DrawCircle;
   
   -- DrawFillCircle
   -- Draw a solid filled circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   procedure DrawFillCircle(X: PIXEL_X; Y: PIXEL_Y; Radius: INTEGER) is
   begin
      SendMessage("DRAWFILLCIRCLE=" & Integer'Image(X) & "," & Integer'Image(Y) & "," & Integer'Image(Radius));
   end DrawFillCircle;
   
end Insa.Graphics;
