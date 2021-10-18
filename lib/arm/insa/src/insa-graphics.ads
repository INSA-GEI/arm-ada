-- Package Insa.Graphics
-- Functions for drawing primitives and character string on screen
--

-- pragma Ada_95;
-- with System;
with Interfaces;

use Interfaces;

package Insa.Graphics is
   pragma Warnings (Off);

   SCREEN_WIDTH:  constant Integer := 480;
   SCREEN_HEIGHT: constant Integer := 272;
     
   FONT_HEIGHT: constant Integer := 15;
   FONT_WIDTH : constant Integer := 8;
   
   subtype PIXEL_X is Integer range 0 .. (SCREEN_WIDTH-1);
   subtype PIXEL_Y is Integer range 0 .. (SCREEN_HEIGHT-1);
   
   subtype Color is Interfaces.Unsigned_16;
   
   Black:      constant Color := 16#0000#;
   Navy:       constant Color := 16#0001#;
   DarkGreen:  constant Color := 16#000C#;
   DarkCyan:   constant Color := 16#000D#;
   Maroon:     constant Color := 16#0060#;
   Purple:     constant Color := 16#0061#;
   Olive:      constant Color := 16#006C#;
   LightGrey:  constant Color := 16#00B6#;
   DarkGrey:   constant Color := 16#006D#;
   Blue:       constant Color := 16#0003#;
   Green:      constant Color := 16#001C#;
   Cyan:       constant Color := 16#001F#;
   Red:        constant Color := 16#00E0#;
   LightRed:   constant Color := 16#00EC#;
   Magenta:    constant Color := 16#00E3#;
   Yellow:     constant Color := 16#00FC#;
   White:      constant Color := 16#FFFF#;
   
   type PWidget is access all Integer;
   type PStyle is access all Integer;
   
   ALIGNEMENT_CENTER : constant Integer := 0;
   ALIGNEMENT_IN_TOP_LEFT: constant Integer := 1;
   ALIGNEMENT_IN_TOP_MID: constant Integer := 2;
   ALIGNEMENT_IN_TOP_RIGHT: constant Integer := 3;
   ALIGNEMENT_IN_BOTTOM_LEFT: constant Integer := 4;
   ALIGNEMENT_IN_BOTTOM_MID: constant Integer := 5;
   ALIGNEMENT_IN_BOTTOM_RIGHT: constant Integer := 6;
   ALIGNEMENT_IN_LEFT_MID: constant Integer := 7;
   ALIGNEMENT_IN_RIGHT_MID: constant Integer := 8;
   ALIGNEMENT_OUT_TOP_LEFT: constant Integer := 8;
   ALIGNEMENT_OUT_TOP_MID: constant Integer := 9;
   ALIGNEMENT_OUT_TOP_RIGHT: constant Integer := 10;
   ALIGNEMENT_OUT_BOTTOM_LEFT: constant Integer := 11;
   ALIGNEMENT_OUT_BOTTOM_MID: constant Integer := 12;
   ALIGNEMENT_OUT_BOTTOM_RIGHT: constant Integer := 13;
   ALIGNEMENT_OUT_LEFT_TOP: constant Integer := 14;
   ALIGNEMENT_OUT_LEFT_MID: constant Integer := 15;
   ALIGNEMENT_OUT_LEFT_BOTTOM: constant Integer := 16;
   ALIGNEMENT_OUT_RIGHT_TOP: constant Integer := 17;
   ALIGNEMENT_OUT_RIGHT_MID: constant Integer := 18;
   ALIGNEMENT_OUT_RIGHT_BOTTOM: constant Integer := 19;
     
   EVENT_PRESSED: constant BYTE := 0;             -- The object has been pressed
   EVENT_PRESSING: constant BYTE := 1;            -- The object is being pressed (called continuously while pressing)
   EVENT_PRESS_LOST: constant BYTE := 2;          -- User is still pressing but slid cursor/finger off of the object 
   EVENT_SHORT_CLICKED: constant BYTE := 3;       -- User pressed object for a short period of time, then released it. Not called if dragged. 
   EVENT_LONG_PRESSED: constant BYTE := 4;        -- Object has been pressed for at least `LV_INDEV_LONG_PRESS_TIME`.  Not called if dragged.
   EVENT_LONG_PRESSED_REPEAT: constant BYTE := 5; -- Called after `LV_INDEV_LONG_PRESS_TIME` in every `LV_INDEV_LONG_PRESS_REP_TIME` ms.  Not called if dragged.
   EVENT_CLICKED: constant BYTE := 6;             -- Called on release if not dragged (regardless to long press)
   EVENT_RELEASED: constant BYTE := 7;            -- Called in every cases when the object has been released
   EVENT_DRAG_BEGIN: constant BYTE := 8;
   EVENT_DRAG_END: constant BYTE := 9;
   EVENT_DRAG_THROW_BEGIN: constant BYTE := 10;
   EVENT_GESTURE: constant BYTE := 11;             -- The object has been gesture
   EVENT_KEY: constant BYTE := 12;
   EVENT_FOCUSED: constant BYTE := 13;
   EVENT_DEFOCUSED: constant BYTE := 14;
   EVENT_LEAVE: constant BYTE := 15;
   EVENT_VALUE_CHANGED: constant BYTE := 16;       -- The object's value has changed (i.e. slider moved) 
   EVENT_INSERT: constant BYTE := 17;
   EVENT_REFRESH: constant BYTE := 18;
   EVENT_APPLY: constant BYTE := 19;               -- "Ok", "Apply" or similar specific button has clicked
   EVENT_CANCEL: constant BYTE := 20;              -- "Close", "Cancel" or similar specific button has clicked
   EVENT_DELETE: constant BYTE := 21;
            
   PART_MAIN: constant Byte:= 0;
   PART_ALL: constant Byte := 255;

   STATE_DEFAULT: constant Byte:= 16#00#;
   STATE_CHECKED: constant Byte:=16#01#;
   STATE_FOCUSED: constant Byte:=16#02#;
   STATE_EDITED: constant Byte:=16#04#;
   STATE_HOVERED: constant Byte:=16#08#;
   STATE_PRESSED: constant Byte:=16#10#;
   STATE_DISABLED: constant Byte:= 16#20#;
   
   -- SetWidgetPosition
   -- Move widget to a given position
   procedure SetWidgetPosition (Widget: PWidget; X: Integer; Y: Integer);
   
   -- SetWidgetPosition
   -- Move widget to a given position relatively to another widget, with given alignement
   -- Set Parent to null for position relatively to screen
   procedure SetWidgetPosition (Widget: PWidget; Parent: PWidget; X: Integer; Y: Integer; Alignment: Integer);
   
   -- SetWidgetSize
   -- Resize a widget to a new size
   -- Set Width or Height to -1 for not changing this dimension
   procedure SetWidgetSize (Widget: PWidget; Width: Integer; Height: Integer);
   
   -- SetWidgetWidth
   -- Change widget width
   procedure SetWidgetWidth (Widget: PWidget; Width: Integer);
   
   -- SetWidgetHeight
   -- Change widget width
   procedure SetWidgetHeight (Widget: PWidget; Height: Integer);
     
   -- RealignWidget
   -- Realign widget depending on last alignement parameter
   procedure RealignWidget(Widget: PWidget);
   pragma Import(C,RealignWidget,"lv_obj_realign");
   
   -- AddChild
   -- Add a child to an existing widget
   procedure AddChild (Child: PWidget; Parent: PWidget);
   
   -- DestroyWidget
   -- Remove a widget and free its allocation and all of its child
   -- Widget access is set to null
   procedure DestroyWidget (Widget: in out PWidget);
   
   -- ClearScreen
   -- Empty screen, remove all widgets
   procedure ClearScreen;
   
   -- GetScreenId
   -- Get reference ID of Screen (for alignement)
   function GetScreenId return PWidget;
   
   ----------------------------------------------------
   -- Generic container (modal window)
   ----------------------------------------------------
   function CreateModalWindow(Width: Integer; Height: Integer) return Pwidget;
   
   -----------------------------------------------------
   -- Messagebox
   ----------------------------------------------------
   
   -- CreateMessageBox
   -- Create a messagebox for information 
   procedure CreateMessageBox (Msg: String; Button_Txt: String);
   procedure CreateMessageBox2 (Msg: String; Button_Txt: String);
   -----------------------------------------------------
   -- Label
   ----------------------------------------------------
   
   -- CreateLabel
   -- Create a label widget for writting text, and move it to given position
   function CreateLabel (X: Integer; Y: Integer) return PWidget;
   
   -- CreateLabel
   -- Create a label widget into a parent widget, for writting text, and move it to given position
   function CreateLabel (Parent: not null Pwidget; X: Integer; Y: Integer) return PWidget;
   
   -- SetLabelText
   -- Change label text
   procedure SetLabelText (Label: PWidget; Text: String);
   
   -----------------------------------------------------
   -- Slider
   -----------------------------------------------------
   
   -- CreateSlider
   -- Create a slider widget for selecting values
   function CreateSlider (Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- CreateSlider
   -- Create a slider widget for selecting values
   function CreateSlider (X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- AddLabelToSlider
   -- Add a label under a slider
   function AddLabelToSlider (Slider: PWidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- GetSliderValue
   -- Get current slider value
   function GetSliderValue (Slider: PWidget) return Natural;
   
   -----------------------------------------------------
   -- Button
   ----------------------------------------------------
   
   -- CreateButton
   -- Create a button widget
   function CreateButton (Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- CreateButton
   -- Create a button widget
   function CreateButton (X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- AddLabelToButton
   -- Add a label in a button
   function AddLabelToButton (Button: PWidget) return PWidget;
   
   -- GetButtonState
   -- Get current button state
   function GetButtonState (Button: PWidget) return Boolean;
   
   -- WaitforButton
   -- Wait until given button was pressed THEN released (to avoid multiple keypress)
   procedure WaitForButton (Button: PWidget);
   
   -----------------------------------------------------
   -- Progressbar
   ----------------------------------------------------
   
   -- CreateProgressbar
   -- Create a progress bar widget
   function CreateProgressbar (Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- CreateProgressbar
   -- Create a progress bar widget
   function CreateProgressbar (X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- AddLabelToProgressbar
   -- Add a label under a progressbar
   function AddLabelToProgressbar (Progressbar: PWidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget;
   
   -- SetProgressbarValue
   -- Set current progressbar value state
   procedure SetProgressbarValue (Progressbar: PWidget; Value: Integer);

end Insa.Graphics;
