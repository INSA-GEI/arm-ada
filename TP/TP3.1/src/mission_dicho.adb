------------------------------------------------------------------------------
--                                                                          --
--                             Mission Dicho                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Nombre;
use Nombre;

procedure Mission_Dicho is
   type T_Vecteur is array (Integer range <>) of Natural ;

   procedure RechercherValeur (T : in T_Vecteur ; V : in Integer ; Indice : out Positive ;Trouve : out Boolean) is
      Milieu : constant Natural := (T'First+T'Last) / 2 ;
   begin
      if T'Length = 0 then
         Trouve := False ;
      elsif T(Milieu) = V then
         Trouve := True ;
         Indice := Milieu ;
      else
         if V> T(Milieu) then
            RechercherValeur(T(Milieu+1..T'Last),V,Indice,Trouve);
         else
            RechercherValeur(T(T'First..Milieu-1),V,Indice,Trouve);
         end if;
      end if;
   end RechercherValeur ;

   procedure SaisirVecteur(T: out T_Vecteur) is
   begin
      T(T'First) := SaisirNombreCroissant (0) ;
      for I in T'First+1..T'Last loop
         T(I):=SaisirNombreCroissant (T(I-1));
      end loop ;
   end SaisirVecteur ;

   procedure AfficherVecteur (T : in T_Vecteur) is
   begin
      EffacerResultats;
      AjouterTexteResultats("Les valeurs sont :" & Newline & Newline);
      for I in T'Range loop
         AjouterTexteResultats(Integer'Image(T(I)) & ", ");
      end loop;
      AjouterTexteResultats(Newline & Newline);
   end AfficherVecteur;

   procedure TesterUnitaire is
      Val       : constant Integer := 8 ;

      PasVal    : constant T_Vecteur (1..9) := (1,2,3,4,5,6,7,9,10) ;
      Valbord1  : constant T_Vecteur (1..9) := (0,1,2,3,4,5,6,7,8) ;
      Valbord2  : constant T_Vecteur (1..9) := (8,9,10,11,12,13,14,15,16) ;
      Valmilieu : constant T_Vecteur (1..9) := (4,5,6,7,8,9,10,11,12) ;
      Valbidon  : constant T_Vecteur (1..9) := (6,7,8,9,10,11,12,13,14) ;

      type T_Test is array (1..5) of T_Vecteur(1..9) ;

      Test : constant T_Test := (1=>PasVal,
                        2=>Valbord1,
                        3=>Valbord2,
                        4=>Valmilieu,
                        5=>Valbidon);

      Position : Integer ;
      Present  : Boolean ;

   begin
      AfficherEcranTestsUnitaires;

      for I in Test'Range loop
         AfficherVecteur(Test(I));
         RechercherValeur(Test(I),Val,Position,Present);
         if Present then
            AjouterTexteResultats("8 se trouve a la position"&Integer'Image(Position));
         else
            AjouterTexteResultats("8 n'est pas present");
         end if;

         AjouterTexteResultats(Newline & "Appuyer sur A pour continuer");
         AttendreToucheA;
      end loop;
   end TesterUnitaire ;

   procedure TesterLibre is
      Position,TailleVecteur,ValeurRecherchee : Integer ;
      Present,Continuer : Boolean ;
   begin
      Continuer:=True;
      while Continuer loop

         AfficherEcranTestsLibres;

         TailleVecteur := SaisirTailleVecteur ;
         if TailleVecteur = 0 then
            Continuer := False;
         else
            declare
               Mon_Vecteur : T_Vecteur (1..TailleVecteur);
            begin

               SaisirVecteur(Mon_Vecteur);

               AjouterTexteResultats ("Votre vecteur est :" & Newline & Newline);
               AfficherVecteur(Mon_Vecteur);

               AttendreToucheA;
               ValeurRecherchee := SaisirValeurRecherchee ;

               RechercherValeur(Mon_Vecteur,ValeurRecherchee,Position,Present);
               if Present then
                  AjouterTexteResultats (Integer'Image(ValeurRecherchee)& " trouvee a la position "&Integer'Image(Position));
               else
                  AjouterTexteResultats (Integer'Image(ValeurRecherchee)& " pas trouvee");
               end if;
            end ;
         end if;

         AjouterTexteResultats(Newline & "Appuyer sur A pour continuer");
         AttendreToucheA;
      end loop;
   end TesterLibre ;

begin
   TesterUnitaire ;
   EffacerResultats;

   Testerlibre ;
   EffacerResultats;

   AjouterTexteResultats("Tests finis");
end Mission_Dicho;
