-- Package Insa.Graphics
-- Functions for drawing primitives and character string on screen
--

-- pragma Ada_95;
with Interfaces.C, Interfaces.C.Strings;

package body Insa.Graphics is
   pragma Warnings (Off);

   type MessageBoxCallbackType is access procedure (Obj: PWidget; Event: BYTE) ;
   pragma Convention(C, MessageBoxCallbackType);
   
   MessageBoxFlag : Boolean:=False;
   
   procedure MessageBoxCallback (Obj: PWidget; Event: BYTE);
   pragma Convention(C, MessageBoxCallback);
   
   -- SetWidgetPosition
   -- Move widget to a given position
   procedure SetWidgetPosition (Widget: PWidget; X: PIXEL_X; Y: PIXEL_Y) is
      procedure Wrapper_wrap(Widget: PWidget; X: PIXEL_X; Y: PIXEL_Y);
      pragma Import (C, Wrapper_wrap, "wrap");
   begin
      Wrapper_Wrap(Widget, X, Y);
   end SetWidgetPosition;
   
   -- SetWidgetPosition
   -- Move widget to a given position relatively to another widget, with given alignement
   -- Set Parent to null for position relatively to screen
   procedure SetWidgetPosition (Widget: PWidget; Parent: PWidget; X: PIXEL_X; Y: PIXEL_Y; Alignment: Integer) is
   begin
      null;
   end SetWidgetPosition;
   
   -- SetWidgetSize
   -- Resize a widget to a new size
   -- Set Width or Height to -1 for not changing this dimension
   procedure SetWidgetSize (Widget: PWidget; Width: Integer; Height: Integer) is
   begin 
      null;
   end SetWidgetSize;
      
   -- AddChild
   -- Add a child to an existing widget
   procedure AddChild (Parent: PWidget; Child: PWidget) is
   begin
      null;
   end AddChild;
   
   -- DestroyWidget
   -- Remove a widget and free its allocation and all of its child
   -- Widget access is set to null
   procedure DestroyWidget (Widget: in out Pwidget) is
      procedure Wrp_lv_obj_clean(Widget: PWidget);
      pragma Import (C, Wrp_lv_obj_clean, "lv_obj_clean");
   begin
      Wrp_Lv_Obj_Clean(Widget);
      
      Widget := null;
   end DestroyWidget;
   
   -- ClearScreen
   -- Empty screen, remove all widgets
   procedure ClearScreen is
      function Wrp_lv_scr_act return PWidget;
      pragma Import (C, Wrp_lv_scr_act, "lv_scr_act");
      
      Main_Screen: PWidget := Wrp_Lv_Scr_Act;
   begin
      DestroyWidget(Main_Screen);
   end ClearScreen;
   
   -- CreateMessageBox
   -- Create a messagebox for information 
   procedure CreateMessageBox (Msg: String; Button_Txt: String) is

      function Wrp_UI_MESSAGEBOX_Create(Msg: Interfaces.C.Strings.chars_ptr; 
                                        Button_Txt: Interfaces.C.Strings.chars_ptr_array; 
                                        Callback: MessageBoxCallbackType) return PWidget;
      pragma Import (C, Wrp_UI_MESSAGEBOX_Create, "UI_MESSAGEBOX_Create");

      procedure Wrp_Lv_Msgbox_Close(Mbx: PWidget; tempo: WORD);
      pragma Import (C, Wrp_Lv_Msgbox_Close, "lv_msgbox_start_auto_close");

      Mbx: PWidget;
      Msg_C : Interfaces.C.Strings.chars_ptr := Interfaces.C.Strings.New_String (Msg);
      Button_Txt_Array: Interfaces.C.Strings.Chars_Ptr_Array(0..1) 
        := (Interfaces.C.Strings.New_String (Button_Txt), 
            Interfaces.C.Strings.New_String (""));
   begin
      MessageBoxFlag:= False;
      Mbx:=Wrp_UI_MESSAGEBOX_Create(Msg_C, Button_Txt_Array, MessageBoxCallback'Access);
      
      while (MessageBoxFlag = False) loop
         null;
      end loop;
      
      Wrp_Lv_Msgbox_Close(Mbx, 50);
   end CreateMessageBox;
   
   -- CreateLabel
   -- Create a label widget for writting text, and move it to given position
   function CreateLabel (X: PIXEL_Y; Y: PIXEL_Y; Text: String:="") return PWidget is
   begin
      return null;
   end CreateLabel;
   
   -- SetLabelText
   -- Change label text
   procedure SetLabelText (Label: PWidget; Text: String) is
   begin
      null;
   end SetLabelText;

   ------------------
   -- Private part
   ------------------
   
   -- messagebox callback
   procedure MessageBoxCallback (Obj: PWidget; Event: BYTE) is
   begin
      MessageBoxFlag:=True;
   end MessageBoxCallback;
        
   --  -- DrawString
   --  -- Draw a string on screen, like on a tty display
   --  procedure DrawString (x: TEXT_X; y: TEXT_Y; s: String) is
   --  
   --     procedure DrawADAString(x: TEXT_X; y: TEXT_Y; len: Natural; s: String);
   --     pragma Import (C, DrawADAString, "GLCD_DrawADAString");
   --  
   --  begin
   --     DrawADAString(x, y, s'Length, s);
   --  end DrawString;
   --  
   --  -- DrawChar
   --  -- Draw a character on screen, like on a tty display
   --  procedure DrawChar (x: TEXT_X; y: TEXT_Y; c: Character) is
   --     procedure Wrapper_DrawChar(x: TEXT_X; y: TEXT_Y; c: Character);
   --     pragma Import (C, Wrapper_DrawChar, "GLCD_DrawChar");
   --  begin
   --     Wrapper_DrawChar(x, y, c);
   --  end DrawChar;
   --  
   --  -- SetTextColor
   --  -- Set the color used for drawing text (Black, Navy, DrakGreen ...)
   --  procedure SetTextColor(val: COLOR) is
   --     procedure Wrapper_SetTextColor(val: COLOR);
   --     pragma Import (C, Wrapper_SetTextColor, "GLCD_SetTextColor");
   --  begin
   --     Wrapper_SetTextColor(Val);
   --  end SetTextColor;
   --  
   --  -- SetBackColor
   --  -- Set the color used for drawing text background (Black, Navy, DrakGreen ...)
   --  procedure SetBackColor(val: COLOR) is
   --     procedure Wrapper_SetBackColor(val: COLOR);
   --     pragma Import (C, Wrapper_SetBackColor, "GLCD_SetBackColor");
   --  begin
   --     Wrapper_SetBackColor(Val);
   --  end SetBackColor;
   --  
   --  -- SetPenColor
   --  -- Set the color used for drawing graphic primitives like lines, circles, rectangles
   --  procedure SetPenColor(val: COLOR) is
   --     procedure Wrapper_SetPenColor(val: COLOR);
   --     pragma Import (C, Wrapper_SetPenColor, "GLCD_SetTextColor");
   --  begin
   --     Wrapper_SetPenColor(Val);
   --  end SetPenColor;
   --  
   --  -- ClearScreen
   --  -- Empty screen, with background defined
   --  procedure ClearScreen(val: COLOR) is
   --     procedure Wrapper_ClearScreen(val: COLOR);
   --     pragma Import (C, Wrapper_ClearScreen, "GLCD_Clear");
   --  begin
   --     Wrapper_ClearScreen(Val);
   --  end ClearScreen;
   --  
   --  -- PutPixel
   --  -- Draw a single pixel (dot) on screen
   --  procedure PutPixel (x: PIXEL_X; y: PIXEL_Y; c: COLOR) is
   --     procedure Wrapper_PutPixel(x: PIXEL_X; y: PIXEL_Y; C: COLOR);
   --     pragma Import (C, Wrapper_PutPixel, "GLCD_PutPixel");
   --  begin
   --     Wrapper_Putpixel(x, y, c);
   --  end Putpixel;
   --  
   --  -- DrawLine
   --  -- Draw a line, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawLine(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y) is
   --     procedure Wrapper_DrawLine(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --     pragma Import (C, Wrapper_DrawLine, "GLCD_DrawLine");
   --  begin
   --     Wrapper_DrawLine(X1, Y1, X2, Y2);
   --  end DrawLine;
   --  
   --  -- DrawRectangle
   --  -- Draw an empty rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y) is
   --     procedure Wrapper_DrawRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --     pragma Import (C, Wrapper_DrawRectangle, "GLCD_DrawRectangle");
   --  begin
   --     Wrapper_DrawRectangle(X1, Y1, X2, Y2);
   --  end DrawRectangle;
   --  
   --  -- DrawFillRectangle
   --  -- Draw a solid filled rectangle on screen, from (x1,y1) to (x2,y2) using color defined with SetPenColor
   --  procedure DrawFillRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y) is
   --     procedure Wrapper_DrawFillRectangle(x1: PIXEL_X; y1: PIXEL_Y; x2: PIXEL_X; y2: PIXEL_Y);
   --     pragma Import (C, Wrapper_DrawFillRectangle, "GLCD_DrawFillRectangle");
   --  begin
   --     Wrapper_DrawFillRectangle(X1, Y1, X2, Y2);
   --  end DrawFillRectangle;
   --  
   --  -- DrawCircle
   --  -- Draw an empty circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   --  procedure DrawCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER) is
   --     procedure Wrapper_DrawCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER);
   --     pragma Import (C, Wrapper_DrawCircle, "GLCD_DrawCircle");
   --  begin
   --     Wrapper_DrawCircle(X, Y, Radius);
   --  end DrawCircle;
   --  
   --  -- DrawFillCircle
   --  -- Draw a solid filled circle on screen, center on (x,y), with radius and using color defined with SetPenColor
   --  procedure DrawFillCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER) is
   --     procedure Wrapper_DrawFillCircle(x: PIXEL_X; y: PIXEL_Y; radius: INTEGER);
   --     pragma Import (C, Wrapper_DrawFillCircle, "GLCD_DrawFillCircle");
   --  begin
   --     Wrapper_DrawFillCircle(X, Y, Radius);
   --  end DrawFillCircle;
   
end Insa.Graphics;
