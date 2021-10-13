-- Package Insa.Graphics
-- Functions for drawing primitives and character string on screen
--

-- pragma Ada_95;
with Interfaces.C.Strings;

package body Insa.Graphics is
   pragma Warnings (Off);

   type MessageBoxCallbackType is access procedure (Obj: PWidget; Event: BYTE) ;
   pragma Convention(C, MessageBoxCallbackType);
   
   type EventCallbackType is access procedure (Obj: PWidget; Event: BYTE) ;
   pragma Convention(C, EventCallbackType);
   
   MessageBoxFlag : Boolean:=False;
   
   procedure MessageBoxCallback (Obj: PWidget; Event: BYTE);
   pragma Convention(C, MessageBoxCallback);
   
   procedure MessageBox2Callback (Obj: PWidget; Event: BYTE);
   pragma Convention(C, MessageBox2Callback);
   
   ----------------------------------------------------------
   -- Lvgl basic functions
   ----------------------------------------------------------
   
   -- Wrp_lv_obj_create
   -- Create a raw object, mainly to serve as a container
   function Wrp_lv_obj_create(Parent: PWidget; Copy: PWidget) return PWidget;
   pragma Import (C, Wrp_lv_obj_create, "lv_obj_create");
   
   -- SetWidgetPosition
   -- Move widget to a given position, relative to screen (parent =null )
   procedure SetWidgetPosition (Widget: PWidget; X: Integer; Y: Integer) is
      procedure Wrp_Lv_Obj_Align(Widget: PWidget; Parent: PWidget; Alignment: Integer; X: Interfaces.C.short; Y: Interfaces.C.short);
      pragma Import (C, Wrp_Lv_Obj_Align, "lv_obj_align");
   begin
      Wrp_Lv_Obj_Align(Widget, null, ALIGNEMENT_CENTER, Interfaces.C.Short(X), Interfaces.C.Short(Y));
   end SetWidgetPosition;
   
   -- SetWidgetPosition
   -- Move widget to a given position relatively to another widget, with given alignement
   -- Set Parent to null for position relatively to screen
   procedure SetWidgetPosition (Widget: PWidget; Parent: PWidget; X: Integer; Y: Integer; Alignment: Integer) is
      procedure Wrp_Lv_Obj_Align(Widget: PWidget; Parent: PWidget; Alignment: Integer; X: Interfaces.C.short; Y: Interfaces.C.short);
      pragma Import (C, Wrp_Lv_Obj_Align, "lv_obj_align");
   begin
      Wrp_Lv_Obj_Align(Widget, Parent, ALIGNEMENT_CENTER, Interfaces.C.Short(X), Interfaces.C.Short(Y));
   end SetWidgetPosition;
   
   -- SetWidgetSize
   -- Resize a widget to a new size
   -- Set Width or Height to -1 for not changing this dimension
   procedure SetWidgetSize (Widget: PWidget; Width: Integer; Height: Integer) is
      procedure Wrp_UI_ResizeObject(Widget: PWidget; Width: Integer; Height: Integer);
      pragma Import (C, Wrp_UI_ResizeObject, "UI_ResizeObject"); 
      
   begin
      Wrp_UI_ResizeObject(Widget, Width, Height);
   end SetWidgetSize;
      
   -- SetWidgetWidth
   -- Change widget width
   procedure SetWidgetWidth (Widget: PWidget; Width: Integer) is
      procedure Wrp_lv_obj_set_width(Widget: PWidget; Width: Interfaces.C.short);
      pragma Import (C, Wrp_lv_obj_set_width, "lv_obj_set_width"); 
   begin
      Wrp_lv_obj_set_width(Widget, Interfaces.C.Short(Width));
   end SetWidgetWidth;
   
   -- SetWidgetHeight
   -- Change widget width
   procedure SetWidgetHeight (Widget: PWidget; Height: Integer) is
      procedure Wrp_lv_obj_set_height(Widget: PWidget; Height: Interfaces.C.short);
      pragma Import (C, Wrp_lv_obj_set_height, "lv_obj_set_height"); 
   begin
      Wrp_lv_obj_set_height(Widget, Interfaces.C.Short(Height));
   end SetWidgetHeight;
   
   -- AddChild
   -- Add a child to an existing widget
   procedure AddChild (Child: PWidget; Parent: PWidget) is
   begin
      SetWidgetPosition(Child, Parent, 0,0, ALIGNEMENT_CENTER);
   end AddChild;
   
   -- DestroyWidget
   -- Remove a widget and free its allocation and all of its child
   -- Widget access is set to null
   procedure DestroyWidget (Widget: in out Pwidget) is
      procedure Wrp_Lv_Obj_Clean(Widget: PWidget);
      pragma Import (C, Wrp_Lv_Obj_Clean, "lv_obj_clean");
   begin
      Wrp_Lv_Obj_Clean(Widget);
      
      Widget := null;
   end DestroyWidget;
   
   -- ClearScreen
   -- Empty screen, remove all widgets
   procedure ClearScreen is
      Main_Screen: PWidget := GetScreenId;
   begin
      DestroyWidget(Main_Screen);
   end ClearScreen;
   
   -- GetScreenId
   -- Get reference ID of Screen (for alignement)
   function GetScreenId return PWidget is
      function Wrp_Lv_Scr_Act return PWidget;
      pragma Import (C, Wrp_lv_scr_act, "UI_GetScreenId");
   begin
      return Wrp_lv_scr_act;
   end GetScreenId;
   
   function Wrp_lv_label_create(Parent: PWidget; Copy: PWidget) return PWidget;
   pragma Import (C, Wrp_lv_label_create, "lv_label_create");
   
   procedure Wrp_lv_msgbox_start_auto_close(Mbx: PWidget; Tempo: WORD);
   pragma Import (C, Wrp_lv_msgbox_start_auto_close, "lv_msgbox_start_auto_close");
   
   -----------------------------------------------------
   -- Messagebox
   ----------------------------------------------------
   
   -- CreateMessageBox
   -- Create a messagebox for information 
   procedure CreateMessageBox (Msg: String; Button_Txt: String) is
      function Wrp_UI_MESSAGEBOX_Create(Msg: Interfaces.C.Strings.Chars_Ptr; 
                                        Button_Txt: Interfaces.C.Strings.Chars_Ptr_Array; 
                                        Callback: MessageBoxCallbackType) return PWidget;
      pragma Import (C, Wrp_UI_MESSAGEBOX_Create, "UI_MESSAGEBOX_Create");

      procedure Wrp_Lv_Msgbox_Close(Mbx: PWidget; Tempo: WORD);
      pragma Import (C, Wrp_Lv_Msgbox_Close, "lv_msgbox_start_auto_close");

      Mbx: PWidget;
      Msg_C : Interfaces.C.Strings.Chars_Ptr := Interfaces.C.Strings.New_String (Msg);
      Button_Txt_Array: Interfaces.C.Strings.Chars_Ptr_Array(0..1) 
        := (Interfaces.C.Strings.New_String (Button_Txt), 
            Interfaces.C.Strings.New_String (""));
   begin
      MessageBoxFlag:= False;
      Mbx:=Wrp_UI_MESSAGEBOX_Create(Msg_C, Button_Txt_Array, MessageBoxCallback'Access);
      
      while (MessageBoxFlag = False) loop
         null;
      end loop;
      
      Wrp_Lv_Msgbox_Close(Mbx, 10);
      --DestroyWidget(Mbx);
      Insa.SysDelay(500);
      
   end CreateMessageBox;
   
   -- CreateMessageBox2
   -- Create a messagebox for information 
   procedure CreateMessageBox2 (Msg: String; Button_Txt: String) is
      Mbx: PWidget;
      Container: Pwidget;
      Container_Style:PStyle;
      
      Msg_C : Interfaces.C.Strings.Chars_Ptr := Interfaces.C.Strings.New_String (Msg);
      Button_Txt_Array: Interfaces.C.Strings.Chars_Ptr_Array(0..1) 
        := (Interfaces.C.Strings.New_String (Button_Txt), 
            Interfaces.C.Strings.New_String (""));
      
      function Wrp_lv_msgbox_create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_msgbox_create, "lv_msgbox_create");

      procedure Wrp_Lv_Msgbox_Close(Mbx: PWidget; Tempo: WORD);
      pragma Import (C, Wrp_Lv_Msgbox_Close, "lv_msgbox_start_auto_close");

      procedure Wrp_lv_msgbox_add_btns(Mbx: PWidget; Button_Txt: Interfaces.C.Strings.Chars_Ptr_Array);
      pragma Import (C, Wrp_lv_msgbox_add_btns, "lv_msgbox_add_btns");
      
      procedure Wrp_lv_msgbox_set_text(Mbx: PWidget; Msg: Interfaces.C.Strings.Chars_Ptr);
      pragma Import (C, Wrp_lv_msgbox_set_text, "lv_msgbox_set_text");
      
      procedure Wrp_lv_obj_set_event_cb(Mbx: PWidget; Callback: MessageBoxCallbackType);
      pragma Import (C, Wrp_lv_obj_set_event_cb, "lv_obj_set_event_cb");
      
      function Wrp_UI_GetEmptyStyle return PStyle;
      pragma Import (C, Wrp_UI_GetEmptyStyle, "UI_GetEmptyStyle");
      
      procedure Wrp_lv_style_set_color(Style: PStyle; State: Byte; Col: Color);
      pragma Import (C, Wrp_lv_style_set_color, "_lv_style_set_color");
      
      procedure Wrp_lv_obj_add_style(Widget: Pwidget; Part: Byte; Style: PStyle);
      pragma Import (C, Wrp_lv_obj_add_style, "lv_obj_add_style");

      procedure Wrp_lv_obj_reset_style_list(Widget: Pwidget; Part: Byte);
      pragma Import (C, Wrp_lv_obj_reset_style_list, "lv_obj_reset_style_list");
   begin
      MessageBoxFlag:= False;
      Container_Style:=Wrp_UI_GetEmptyStyle;
      Wrp_lv_style_set_color(Container_Style,16#29#, Black);
      
      Container:= Wrp_Lv_Obj_Create(GetScreenId, null);
      Wrp_Lv_Obj_Reset_Style_List(Container, PART_MAIN);
      Wrp_Lv_Obj_Add_Style(Container,PART_MAIN,Container_Style);
      SetWidgetPosition(Container,-SCREEN_WIDTH/2+41,-SCREEN_HEIGHT/2+21);
      SetWidgetSize(Container, SCREEN_WIDTH, SCREEN_HEIGHT);
      
      Mbx := Wrp_Lv_Msgbox_Create(Container, null);
      Wrp_Lv_Msgbox_Add_Btns(Mbx, Button_Txt_Array);
      Wrp_Lv_Msgbox_Set_Text(Mbx, Msg_C);
      SetWidgetPosition(Mbx,0,0);
      Wrp_Lv_Obj_Set_Event_Cb(Mbx, MessageBox2Callback'Access);
      
      while (MessageBoxFlag = False) loop
         null;
      end loop;

      Insa.SysDelay(500);
   end CreateMessageBox2;
   
   -----------------------------------------------------
   -- Label
   ----------------------------------------------------
   
   -- CreateLabel
   -- Create a label widget for writing text, and move it to given position
   function CreateLabel (X: Integer; Y: Integer) return PWidget is
      Tmp: PWidget;
   begin
      Tmp := Wrp_lv_label_create(GetScreenId,null);
      SetWidgetPosition(Tmp,X,Y);
      
      return Tmp;
   end CreateLabel;
   
   -- SetLabelText
   -- Change label text
   procedure SetLabelText (Label: PWidget; Text: String) is
      procedure Wrp_lv_label_set_text(Label: PWidget; Text: Interfaces.C.Strings.Chars_Ptr);
      pragma Import (C, Wrp_lv_label_set_text, "lv_label_set_text");
      Tmp_String: Interfaces.C.Strings.Chars_Ptr:=  Interfaces.C.Strings.New_String (Text);
   begin
      Wrp_lv_label_set_text(Label, Tmp_String);
      RealignWidget(Label);
      
      Interfaces.C.Strings.Free (Tmp_String);
   end SetLabelText;

   -----------------------------------------------------
   -- Slider
   -----------------------------------------------------
   
   -- CreateSlider
   -- Create a slider widget for selecting values
   function CreateSlider (X: Integer; Y: Integer; Length: Integer) return PWidget is
      function Wrp_lv_slider_create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_slider_create, "lv_slider_create");
      Tmp: PWidget;
   begin
      Tmp:= Wrp_lv_slider_create(GetScreenId,null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp,X,Y);
      
      return Tmp;
   end CreateSlider;
   
   -- AddLabelToSlider
   -- Add a label under a slider
   function AddLabelToSlider (Slider: PWidget; X: Integer; Y: Integer; Length: Integer) return PWidget is
      Tmp: PWidget;
   begin
      Tmp:=Wrp_Lv_Label_Create(GetScreenId, null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp, Slider, X, Y, ALIGNEMENT_CENTER);
      
      return Tmp;
   end AddLabelToSlider;
   
   -- GetSliderValue
   -- Get current slider value
   function GetSliderValue (Slider: PWidget) return Interfaces.C.short is
      --  function Wrp_UI_SLIDER_GetValue(Slider: PWidget) return Integer_16;
      function Wrp_UI_SLIDER_GetValue(Slider: PWidget) return Interfaces.C.short;
      pragma Import (C, Wrp_UI_SLIDER_GetValue, "UI_SLIDER_GetValue");
   begin
      return Wrp_UI_SLIDER_GetValue(Slider);
   end GetSliderValue;
   
   -----------------------------------------------------
   -- Button
   ----------------------------------------------------
   
   -- CreateButton
   -- Create a button widget
   function CreateButton (X: Integer; Y: Integer; Length: Integer) return PWidget is
      function Wrp_lv_btn_create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_btn_create, "lv_btn_create");
      Tmp: PWidget;
   begin
      Tmp := Wrp_lv_btn_create(GetScreenId, null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp,X,Y);
      
      return Tmp;
   end CreateButton;
   
   -- AddLabelToButton
   -- Add a label in a button
   function AddLabelToButton (Button: PWidget) return PWidget is
     Tmp: PWidget;
   begin
      Tmp:=Wrp_Lv_Label_Create(GetScreenId, null);     
      SetWidgetPosition(Tmp, Button, 0, 0, ALIGNEMENT_CENTER);
      return Tmp;
   end AddLabelToButton;
   
   -- GetButtonState
   -- Get current button state
   function GetButtonState (Button: PWidget) return Boolean is
      function Wrp_lv_btn_get_state(Button: PWidget) return Interfaces.Integer_8;
      pragma Import (C, Wrp_lv_btn_get_state, "lv_btn_get_state");
   begin
      if Wrp_lv_btn_get_state(Button) = 0 then
         return False;
      else 
         return True;
      end if;
   end GetButtonState;
   
      -- WaitforButton
   -- Wait until given button was pressed THEN released (to avoid multiple keypress)
   procedure WaitForButton (Button: PWidget) is
   begin
      while GetButtonState(Button) /= True loop
         null;
      end loop;
      
      while GetButtonState(Button) = True loop
         null;
      end loop;
   end WaitForButton;
   
   -----------------------------------------------------
   -- Progressbar
   ----------------------------------------------------
   
   -- CreateProgressbar
   -- Create a progress bar widget
   function CreateProgressbar (X: Integer; Y: Integer; Length: Integer) return PWidget is
      function Wrp_lv_bar_create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_bar_create, "lv_bar_create");
      Tmp: PWidget;
   begin
      Tmp := Wrp_Lv_Bar_Create(GetScreenId, null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp,X,Y);
      
      return Tmp;
   end CreateProgressbar;
   
   -- AddLabelToProgressbar
   -- Add a label under a progressbar
   function AddLabelToProgressbar (Progressbar: PWidget; X: Integer; Y: Integer; Length: Integer) return PWidget is
     Tmp: PWidget;
   begin
      Tmp:=Wrp_Lv_Label_Create(GetScreenId, null);
      if Length>0 then 
         SetWidgetWidth(Tmp,Length);
      end if;
      
      SetWidgetPosition(Tmp, Progressbar, X, Y, ALIGNEMENT_CENTER);
      return Tmp;
   end AddLabelToProgressbar;
   
   -- SetProgressbarValue
   -- Set current progressbar value state
   procedure SetProgressbarValue (Progressbar: PWidget; Value: Integer) is
      --procedure Wrp_lv_bar_set_value(Slider: PWidget; Value: Interfaces.C.Short; Animation: Integer);
      --pragma Import (C, Wrp_lv_bar_set_value, "lv_bar_set_value");
      procedure Wrp_UI_PROGRESSBAR_SetValue(Slider: PWidget; Value: Interfaces.C.Short);
      pragma Import (C, Wrp_UI_PROGRESSBAR_SetValue, "UI_PROGRESSBAR_SetValue");
   begin
      --Wrp_lv_bar_set_value(Progressbar, Interfaces.C.short(Value),1);
      Wrp_UI_PROGRESSBAR_SetValue(Progressbar, Interfaces.C.short(Value));
   end SetProgressbarValue;
   
   ----------------------------------------------------
   -- Private part
   ----------------------------------------------------
   
   -- messagebox callback
   procedure MessageBoxCallback (Obj: PWidget; Event: BYTE) is
   begin
      if Event = EVENT_RELEASED then
         MessageBoxFlag:=True;
      else
         null;
      end if;
   end MessageBoxCallback;
   
   -- messagebox callback 2
   procedure MessageBox2Callback (Obj: PWidget; Event: BYTE) is
      function Wrp_lv_obj_get_parent(Widget: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_obj_get_parent, "lv_obj_get_parent");
      
      procedure Wrp_lv_obj_del_async(Widget: PWidget);
      pragma Import (C, Wrp_lv_obj_del_async, "lv_obj_del_async");
   begin
      if Event = EVENT_RELEASED then
         Wrp_Lv_Msgbox_Start_Auto_Close(Obj,10);
      elsif Event = EVENT_DELETE then
         Wrp_Lv_Obj_Del_Async(Wrp_Lv_Obj_Get_Parent(Obj));
         MessageBoxFlag:=True;
      end if;
   end MessageBox2Callback;
   
end Insa.Graphics;
