------------------------------------------------------------------------------
--                                                                          --
--                             Mission Dicho                                --
--                                                                          --
--                             Acteur Nombre                                -- 
--                                 Body                                     --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires à l'interface utilisateur
-- du TP sur la dichotomie
--

with Insa, Insa.Graphics, Insa.Keys;
use Insa, Insa.Graphics, Insa.Keys; 

with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;

package body Nombre is

   -- Variables locales utilisées pour l'affichage
   -- Ne pas utiliser directement
   LabelResultats: PWidget;
   TexteResultats: Unbounded_String := Null_Unbounded_String;
   LabelTitre: PWidget;

   -- Affiche le titre "Tests Unitaires" en haut de l'ecran
   procedure AfficherEcranTestsUnitaires is
   begin
      SetLabelText(LabelTitre,"Tests Unitaires");
   end AfficherEcranTestsUnitaires;
   
   -- Affiche le titre "Tests Libres" en haut de l'ecran
   procedure AfficherEcranTestsLibres is
   begin
      SetLabelText(LabelTitre,"Tests Libres");
   end AfficherEcranTestsLibres;
   
   -- Efface la zone de resultats (centre de l'ecran)
   procedure EffacerResultats is
   begin
      SetLabelText(LabelResultats, "");
      TexteResultats := Null_Unbounded_String;
   end EffacerResultats; 
   
   -- Ajoute du texte à la zone de resultats
   procedure AjouterTexteResultats(S: String) is
   begin
      Append(TexteResultats, S);
      SetLabelText(LabelResultats, To_String(TexteResultats));
   end AjouterTexteResultats;  
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA is
   begin
      WaitForKey(Key_A);
   end AttendreToucheA;
   
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- la taille du vecteur de recherche
   function SaisirTailleVecteur return Integer  is
      Depth: Natural:=1;
      NewDepth:Natural:=1;
      
      Slider: Pwidget;
      Label, ButtonLabel,SliderLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      Slider:=CreateSlider(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "Saisissez la taille du vecteur");
      
      SliderLabel:=AddLabelToSlider(Slider,0,30);
      SetLabelText(SliderLabel, Natural'Image(Depth));
      
      NewDepth:=Depth;
      
      while GetKeyState(Key_A) /= Key_Pressed and GetButtonState(Button) = False loop
         NewDepth:= Natural((15*GetSliderValue(Slider)/100)+1);
         
         if NewDepth /= Depth then
            Depth:=NewDepth;
            SetLabelText(SliderLabel, Natural'Image(Depth));
         end if;
         
         Insa.SysDelay(50);
      end loop;
      
      while GetKeyState(Key_A) = Key_Pressed loop
         null;
      end loop;
      
      DestroyWidget(SliderLabel);
      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      return Depth;
   end SaisirTailleVecteur;
   
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- la valeur recherchée
   function SaisirValeurRecherchee return Integer  is
      Depth: Natural:=1;
      NewDepth:Natural:=1;
      
      Slider: Pwidget;
      Label, ButtonLabel,SliderLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      Slider:=CreateSlider(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "Saisissez la valeur recherchee");
      
      SliderLabel:=AddLabelToSlider(Slider,0,30);
      SetLabelText(SliderLabel, Natural'Image(Depth));
      
      NewDepth:=Depth;
      
      while GetKeyState(Key_A) /= Key_Pressed and GetButtonState(Button) = False loop
         NewDepth:= Natural((15*GetSliderValue(Slider)/100)+1);
         
         if NewDepth /= Depth then
            Depth:=NewDepth;
            SetLabelText(SliderLabel, Natural'Image(Depth));
         end if;
         
         Insa.SysDelay(50);
      end loop;
      
      while GetKeyState(Key_A) = Key_Pressed loop
         null;
      end loop;
      
      DestroyWidget(SliderLabel);
      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      return Depth;
   end SaisirValeurRecherchee;
   
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- les valeurs recherchées de manieres croissantes
   function SaisirNombreCroissant (PlusPetiteValeur : Integer ) return Integer is
      Depth: Natural:=1;
      NewDepth:Natural:=1;
      
      Slider: Pwidget;
      Label, ButtonLabel,SliderLabel: Pwidget;
      Button:Pwidget;
      Window: PWidget;
   begin
      Window:=CreateModalWindow(SCREEN_WIDTH-150, SCREEN_HEIGHT-50);
      Slider:=CreateSlider(Window,0,-10);
      Label:=CreateLabel(Window,0,-90);
      Button:=CreateButton(Window, 0,80);
      
      ButtonLabel:=AddLabelToButton(Button);
      SetLabelText(ButtonLabel, "Ok");
      SetLabelText(Label, "Saisissez votre valeur");
      
      SliderLabel:=AddLabelToSlider(Slider,0,30);
      SetLabelText(SliderLabel, Natural'Image(Depth));
      
      NewDepth:=Depth;
      
      while GetKeyState(Key_A) /= Key_Pressed and GetButtonState(Button) = False loop
         NewDepth:= Natural((15*GetSliderValue(Slider)/100)+PlusPetiteValeur);
         
         if NewDepth /= Depth then
            Depth:=NewDepth;
            SetLabelText(SliderLabel, Natural'Image(Depth));
         end if;
         
         Insa.SysDelay(50);
      end loop;
      
      while GetKeyState(Key_A) = Key_Pressed or GetButtonState(Button) = True loop
         null;
      end loop;
      
      DestroyWidget(SliderLabel);
      DestroyWidget(ButtonLabel);
      DestroyWidget(Window);
      return Depth;
   end SaisirNombreCroissant;
   
begin
   LabelTitre := Insa.Graphics.CreateLabel(0, -120);
   Insa.Graphics.SetLabelText(LabelTitre, "");
   LabelResultats := Insa.Graphics.CreateLabel(0, 0);
   Insa.Graphics.SetLabelText(LabelResultats, "");
end Nombre;
