-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--
with Ada;
--  with Ada.Unchecked_Deallocation

package body Insa.Graphics.Images is
   pragma Warnings (Off);
   
   -- CreateImage
   -- Create a new image widget
   function CreateImage(Parent: not null Pwidget; X: Integer; Y: Integer; Length: Integer:=0) return PWidget is
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
   
   ------------------------------------------------------------------
   -- Routines pour l'objet Canvas
   --
   -- L'objet canvas sert a dessiner de maniere arbitraire (point, lignes, images)
   --
   
   -- CreateCanvas
   -- Create a canvas object into a parent widget
   function CreateCanvas (Parent: not null Pwidget; X: Integer; Y: Integer) return PWidget is
      function Wrp_lv_canvas_create(Parent: PWidget; Copy: PWidget) return PWidget;
      pragma Import (C, Wrp_lv_canvas_create, "lv_canvas_create");
      Tmp: PWidget;
   begin
      Tmp:= Wrp_lv_canvas_create(Parent, null);
      
      SetWidgetPosition(Tmp,X,Y);
      return Tmp;
   end CreateCanvas;
      
   -- CreateCanvas
   -- Create a canvas object on main screen
   function CreateCanvas (X: Integer; Y: Integer) return PWidget is
   begin
      return CreateCanvas(GetScreenId, X, Y);
   end CreateCanvas;
      
   -- AddBufferToCanvas
   -- Set a buffer for the canvas.
   -- buf a buffer where the content of the canvas will be.
   --  The required size is (lv_img_color_format_get_px_size(cf) * w) / 8 * h)
   --  It can be allocated with `lv_mem_alloc()` or
   --  it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or
   --  it can be an address in RAM or external SRAM
   procedure AddBufferToCanvas (Canvas: PWidget; W: Natural; H: Natural; C: Color) is
      procedure Wrp_UI_CANVAS_AddBuffer(Canvas: PWidget; W: Interfaces.C.short; H: Interfaces.C.Short; C: Color);
      pragma Import (C, Wrp_UI_CANVAS_AddBuffer, "UI_CANVAS_AddBuffer");
   begin 
      Wrp_UI_CANVAS_AddBuffer(Canvas, Interfaces.C.Short(W), Interfaces.C.Short(H), C);
      RealignWidget(Canvas);
   end AddBufferToCanvas;
   
   -- AllocateBufferforCanvas
   -- Set a buffer for the canvas.
   -- buf a buffer where the content of the canvas will be.
   --  The required size is (lv_img_color_format_get_px_size(cf) * w) / 8 * h)
   --  It can be allocated with `lv_mem_alloc()` or
   --  it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or
   --  it can be an address in RAM or external SRAM
   function AllocateBufferforCanvas (W: Natural; H: Natural; C: Color) return PCanvasBuffer is
      function Wrp_UI_CANVAS_AllocateBuffer(W: Interfaces.C.short; H: Interfaces.C.Short; C: Color) return PCanvasBuffer;
      pragma Import (C, Wrp_UI_CANVAS_AllocateBuffer, "UI_CANVAS_AllocateBuffer");
   begin 
      return Wrp_UI_CANVAS_AllocateBuffer(Interfaces.C.Short(W), Interfaces.C.Short(H), C);
   end AllocateBufferforCanvas;
   
   procedure DrawLine(Canvas: PWidget; Points: T_PointArray; Point_Cnt: Integer; Line_Attr: P_Line) is
      procedure Wrp_lv_canvas_draw_line(Canvas: PWidget; Points: T_PointArray; Point_Cnt: Integer; Line_Attr: P_Line);
      pragma Import (C, Wrp_lv_canvas_draw_line, "lv_canvas_draw_line");
   begin
      Wrp_Lv_Canvas_Draw_Line(Canvas, Points, Point_Cnt, Line_Attr);
   end DrawLine;
   
   
end Insa.Graphics.Images;
