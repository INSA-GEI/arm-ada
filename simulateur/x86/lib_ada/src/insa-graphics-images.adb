-- Package Insa.Graphics.Image
-- Functions for unpacking and drawing image bitmap on screen
--
-- pragma Ada_95;

with Ada;
with Ada.Unchecked_Deallocation;

with Insa.Simulator;
with Ada.Streams;

with Insa.Base64;

with Ada.Text_IO;
with Ada.Integer_Text_IO;

package body Insa.Graphics.Images is
   pragma Warnings (Off);
   
   -- NewImage
   -- Create a new, empty image with a given width and height
   function NewImage(W: NATURAL; H: NATURAL) return IMAGE is
      Img: IMAGE;
   begin 
      Img.Data := new BITMAP(0..(W*H)-1);
      Img.Width := W;
      Img.Height := H;
      
      return Img;
   end NewImage;
   
   -- FreeImage
   -- Destroy an image and free memory used
   procedure FreeImage (Img: in out IMAGE) is
      procedure Free_BMP is new Ada.Unchecked_Deallocation (BITMAP, BITMAP_ACCESS);
      Bmp_Ptr: BITMAP_ACCESS := Img.Data;
   begin
      Free_BMP(BMP_Ptr);
      Img.Data :=null;
   end FreeImage; 
   
   procedure ImageToStream(Img: in BITMAP_ACCESS; StreamBuffer: out Ada.Streams.Stream_Element_Array ) is
             
      procedure ColorToRGB16(C: in COLOR; Msb: out BYTE; Lsb: out BYTE) is
         R,G,B: WORD;
      begin
         R:= WORD(Shift_Right((C and 16#E0#),5));
         G:= WORD(Shift_Right((C and 16#1C#),2));
         B:= WORD(C and 16#03#);
          
         --  Ada.Text_IO.Put ("RGB_8: ");
         --  Ada.Integer_Text_IO.Put (Integer(R), Base => 16);
         --  Ada.Text_IO.Put (",");
         --  Ada.Integer_Text_IO.Put (Integer(G), Base => 16);
         --  Ada.Text_IO.Put (",");
         --  Ada.Integer_Text_IO.Put (Integer(B), Base => 16);
         --  Ada.Text_IO.New_Line;

         R:= (R*31)/7;
         G:= (G*63)/7;
         B:= (B*31)/3;
         
         --  Ada.Text_IO.Put ("RGB_16: ");
         --  Ada.Integer_Text_IO.Put (Integer(R), Base => 16);
         --  Ada.Text_IO.Put (",");
         --  Ada.Integer_Text_IO.Put (Integer(G), Base => 16);
         --  Ada.Text_IO.Put (",");
         --  Ada.Integer_Text_IO.Put (Integer(B), Base => 16);
         --  Ada.Text_IO.New_Line;
         
         Msb := BYTE(Shift_Left(R,3) or Shift_Right(G,3));
         Lsb := BYTE((Shift_Left(G,5) and 16#E0#) or B);
         
         --  Ada.Text_IO.Put ("MSB,LSB: ");
         --  Ada.Integer_Text_IO.Put (Integer(MSB), Base => 16);
         --  Ada.Text_IO.Put (",");
         --  Ada.Integer_Text_IO.Put (Integer(LSB), Base => 16);
         --  Ada.Text_IO.New_Line;
         --  Ada.Text_IO.New_Line;
      end ColorToRGB16;
      
      Counter: Integer;
      Msb,Lsb: BYTE;
      
   begin
      --  Ada.Text_IO.Put_Line("Streambuffer First = " & Integer'Image(Integer(Streambuffer'First)) & "; Last = " & Integer'Image(Integer(Streambuffer'Last)));
      --  Ada.Text_IO.Put_Line("Img First = " & Integer'Image(Img'First) & "; Last = " & Integer'Image(Img'Last));

      for Counter in Img'Range loop
         ColorToRGB16(Img(Counter), Msb, Lsb);
         --  Ada.Text_IO.Put_Line("Counter = " & Integer'Image(Counter));
         
         Streambuffer(Ada.Streams.Stream_Element_Offset(1+(2*Counter))) := Ada.Streams.Stream_Element(Lsb);
         Streambuffer(Ada.Streams.Stream_Element_Offset(1+(2*Counter)+1)) := Ada.Streams.Stream_Element(Msb);
      end loop;
      
   end ImageToStream;
   
   -- DrawImage
   -- Draw an image at position (x,y) on screen
   procedure DrawImage(X: PIXEL_X; Y: PIXEL_Y; Img: IMAGE) is
      -- procedure Wrapper_DrawImage(Bmp_ptr: BITMAP_ACCESS; x: NATURAL; y: NATURAL; W: NATURAL; H:NATURAL);
      -- pragma Import (C, Wrapper_DrawImage, "GLCD_DrawImage");
      StreamBuffer : Ada.Streams.Stream_Element_Array(1..Ada.Streams.Stream_Element_Offset((Img.Width*Img.Height*2))); -- 2 fois la taille de l'image car en 16 bits
      
   begin
      -- Wrapper_DrawImage(Img.Data, NATURAL(x), NATURAL(y), Img.Width, Img.Height);
      
      ImageToStream(Img.Data, StreamBuffer); 
      --Ada.Text_IO.Put_Line("Image size (16 bits): " & Integer'Image(Img.Width) & "*" & Integer'Image(Img.Height) & "=>" & Integer'Image(Img.Width*Img.Height));
      --Ada.Text_IO.Put_Line("Stream size (Bytes): " & Integer'Image(StreamBuffer'Length));
      --Ada.Text_IO.Put_Line("Base64 Encode => " & Base64.Encode(StreamBuffer));
      
      Simulator.SendMessage("DRAWIMAGE=" & Integer'Image(X) & "," & Integer'Image(Y) & "," 
                            & Integer'Image(Img.Width) & "," & Integer'Image(Img.Height) & "," 
                            & Base64.Encode(StreamBuffer));
      
   end DrawImage;
   
   -- DrawImageFromSRAM
   -- Draw an image, stored in SRAM, at position (x,y) on screen
   procedure DrawImageFromSRAM(X: PIXEL_X; Y: PIXEL_Y; W: NATURAL; H: NATURAL; Addr: MEMORY_ADDRESS) is
      procedure Wrapper_DrawImageFromSRAM(Addr: MEMORY_ADDRESS; X: NATURAL; Y: NATURAL; W: NATURAL; H:NATURAL);
      pragma Import (C, Wrapper_DrawImageFromSRAM, "GLCD_DrawImagefromSRAM");
   begin
      Wrapper_DrawImageFromSRAM(Addr, NATURAL(X), NATURAL(Y), NATURAL(W), NATURAL(H));
   end DrawImageFromSRAM;

   -- UnpackImage
   -- Unpack a compressed image to an usable image
   function UnpackImage(Pack_Img: PACK_IMAGE) return IMAGE is
      Img: IMAGE;
      Index: NATURAL:=0;
   begin
      Img:=NewImage(Pack_Img.Width,Pack_Img.Height);
      
      for I in Pack_Img.Data'Range loop
         for X in 0 .. Pack_Img.Data(I).Length-1 loop
            Img.Data(Index+Natural(X)):=Pack_Img.Data(I).Pixel;
         end loop;
	 
         Index:=Index + NATURAL(Pack_Img.Data(I).Length);
      end loop;
      
      return Img;
   end UnpackImage;
   
   -- UnpackImageToSRAM
   -- Unpack a compressed image to an usable image directly into SRAM
   procedure UnpackImageToSRAM(Pack_Img: PACK_IMAGE; Addr: MEMORY_ADDRESS) is
      Index: MEMORY_ADDRESS:=Addr;
   begin
      for I in Pack_Img.Data'Range loop
         for X in 0 .. Pack_Img.Data(I).Length-1 loop
            --Img.Data(Index+Natural(X)):=Pack_Img.Data(I).Pixel;
            WriteByte(Index+MEMORY_ADDRESS(X), MEMORY_BYTE(Pack_Img.Data(I).Pixel));
         end loop;
	 
         Index:=Index + MEMORY_ADDRESS(Pack_Img.Data(I).Length);
      end loop;
   end UnpackImageToSRAM;

end Insa.Graphics.Images;
