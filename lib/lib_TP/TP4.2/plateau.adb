------------------------------------------------------------------------------
--                                                                          --
--                             Mission Snake                                --
--                                                                          --
--                             Acteur Plateau                               -- 
--                                  Body                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires a l'affichage
-- du serpent.
--

with Insa , Carte, Insa.Graphics, Insa.Graphics.Images, Ada.Unchecked_Deallocation, Insa.Random_Number ;
use  Insa , Insa.Graphics, Insa.Graphics.Images;

with Sprites;
use Sprites;

package body Plateau is
   
   TailleSymbole : constant Integer := 20 ;
       
   SPRITE_WIDTH : constant Integer := TailleSymbole;
   SPRITE_HEIGHT : constant Integer := TailleSymbole;
        
   type T_Tableau_Couleur is array (0..9) of Insa.Graphics.Images.PImg_Dsc_T;
    
   Les_CouleursSnake : constant T_Tableau_Couleur := 
     (Corps1'Access, Corps2'Access, Corps3'Access, Corps4'Access, Corps5'Access,
      Corps6'Access, Corps7'Access, Corps8'Access, Corps9'Access, Corps10'Access);
       
   Lab_Image: array (0..(PLATEAU_LARGEUR-1),0..(PLATEAU_HAUTEUR-1)) of PWidget;   
   
   IndexCouleurSnake : Integer := Les_CouleursSnake'First ;
   
   procedure DessinerBlocVide(X,Y : Integer);
   procedure DessinerBlocSnake(X,Y : Integer);
   procedure DessinerBlocCerise(X,Y : Integer);
   procedure DessinerMur (X,Y : Integer);
         
   -- Dessine a la Xeme ligne, Yeme colonne de la table un T_Bloc defini par TypeBloc
   procedure DessinerBloc (X,Y : Integer ; TypeBloc : T_Bloc) is
   begin   
      case TypeBloc is
      when Mur    => DessinerMur(X,Y);
      when Vide   => DessinerBlocVide(X,Y);
      when Cerise => DessinerBlocCerise(X,Y) ;
      when Snake  => DessinerBlocSnake(X,Y) ;
      end case;
   end DessinerBloc;
   
   -- Retourne T de type T_Table avec toutes les case vides
   -- et la position du serpent S au milieu
   -- affiche ce serpent
   procedure InitialiserJeu (T: out T_Table ; S: out T_Snake) is 
      COIN_X: constant Integer:=-190;
      COIN_Y: constant Integer:=-100;
   begin 
      for Y in Lab_Image'Range(2) loop
         for X in Lab_Image'Range(1) loop
            Lab_Image(X,Y):= CreateImage(COIN_X+(X*SPRITE_WIDTH), COIN_Y +(Y*SPRITE_HEIGHT), ALIGNEMENT_CENTER);
            DrawImage(Lab_Image(X,Y),Sprites.Vide'Access);
         end loop;
      end loop;
      
      T:= (others => (others => Vide));
      
      S.Posx := T'First(1)+T'Length(1)/2 ;
      S.PosY := T'First(2)+T'Length(2)/2 ;
      T(S.Posx,S.PosY) := Snake ;
   end InitialiserJeu ;
   
   -- Libere l'espace memoire reserve a un pointeur L
   -- Attention il est indispensable d'appeler cette procedure
   -- Pour faire une desallocation "propre" de pointeur 
   -- pour ne pas saturer la memoire de la carte 
   procedure EffacerMemoireElement (L : in out P_Element) is
      procedure Liberer_Element is 
        new Ada.Unchecked_Deallocation(Element,P_Element);
   begin
      Liberer_Element(L);
   end EffacerMemoireElement ;
   
   -- placer une cerise aleatoirement
   -- dans la table T et a l'ecran
   procedure PlacerCerise (T:in out T_Table) is
      LocalX,LocalY : Integer ;
   begin
      if Carte.TempsEcoule mod 50 = 0 then

         Localx := Insa.Random_Number.GetValue;      
         Localx := (Localx*(T'Last(1)+1))/65536;
         if Localx > T'Last(1) then Localx :=T'Last(1);
         end if;
 
         Localy := Insa.Random_Number.GetValue; 
         Localy := (Localy*(T'Last(2)+1))/65536;
         if Localy > T'Last(2) then Localy :=T'Last(2);
         end if;

         if T(LocalX,LocalY) = Vide then 
            T(LocalX,LocalY) := Cerise ;	    
            DessinerBloc(LocalX,LocalY,Cerise) ;
         end if;
      end if;
   end PlacerCerise ;
  
   --
   -- Fonctions privées, ne pas utiliser directement
   --
   
   procedure DessinerBlocVide(X,Y : Integer) is
   begin
      DrawImage(Lab_Image(X,Y), Sprites.Vide'Access);
   end DessinerBlocVide ;
      
   procedure DessinerBlocSnake(X,Y : Integer) is
   begin

      IndexCouleurSnake := IndexCouleurSnake +1 ;
      if IndexCouleurSnake>Les_CouleursSnake'Last then
         IndexCouleurSnake:=Les_CouleursSnake'First;
      end if;

      DrawImage(Lab_Image(X,Y), Les_CouleursSnake(IndexCouleurSnake));
   end DessinerBlocSnake ;
   
   procedure DessinerBlocCerise(X,Y : Integer) is
   begin
      DrawImage(Lab_Image(X,Y), Sprites.Cerise'Access);
   end DessinerBlocCerise ;
   
   procedure DessinerMur (X,Y : Integer) is
   begin
      DrawImage(Lab_Image(X,Y), Sprites.Vide'Access);
   end DessinerMur;
end Plateau;  
