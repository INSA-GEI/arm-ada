------------------------------------------------------------------------------
--                                                                          --
--                             Mission Capteurs                             --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Sensors;
use Sensors;

procedure Mission_Capteurs is

   type Element;
   type P_Element is access Element;

   type Element is
      record
         Norme : Integer;
         Num : Natural;
         Suiv : P_Element;
      end record;

   procedure Ajouter_Fin(L : in out P_Element; CM : in Integer ; Num : Integer) is
      Aux, P : P_Element;
   begin
      -- si la liste est vide alors
      -- la creer avec cet element
      if L = null then
         L := new Element'(CM, Num, null);
         -- sinon : il faut se placer a la fin
         -- et ajouter le nouvel element
      else
         -- se placer sur le dernier element
         Aux := L; -- Aux contient au moins 1 element
         while Aux.all.Suiv /= null loop
            Aux := Aux.all.Suiv;
         end loop;
         -- ajouter l element en fin
         P:=new Element'(CM, Num, null);
         Aux.all.Suiv := P;
      end if;
   end Ajouter_Fin;

   procedure Ajouter_Croissant_Rec(L : in out P_Element; CM : in Integer; Num : in Natural) is
   begin
      if L = null then
         L := new Element'(CM, Num, null);
      else
         -- si insertion en tete
         if CM <= L.all.Norme then
            L := new Element'(CM, Num, L);
         else
            Ajouter_Croissant_Rec(L.all.Suiv, CM, Num);
         end if;
      end if;
   end Ajouter_Croissant_Rec;

   procedure Filtrer(L : in P_Element ;  Nb_Val_Filtrees : out Integer ) is
      Aux : P_Element := L;
   begin
      Nb_Val_Filtrees := 0 ;
      while Aux /= null loop
         if Aux.all.Suiv /= null then
            if Aux.all.Norme = Aux.all.Suiv.Norme then
               Aux.all.Suiv := Aux.all.Suiv.all.Suiv;
               Nb_Val_Filtrees := Nb_Val_Filtrees + 1;
            else
               Aux := Aux.all.Suiv;
            end if;
         else
            Aux := null;
         end if;
      end loop;
   end Filtrer;

   procedure Enregistrer(L : out P_Element) is
      Val: Integer;
      Valeurs_Capteurs: T_Valeurs_Capteur;
      Num : Natural := 0;
      Continuer : Boolean := True ;
   begin
      AfficherEcranEnregistrement;

      AfficheMessage("Demarrer l'enregistrement", "Appuyez sur OK");

      L := null;
      while Continuer loop
         if Attendre2secondesOuB then
            Continuer := False ;
         else
            Valeurs_Capteurs := ObtenirValeursCapteur;
            Val := CalculerRacineCarre(Valeurs_Capteurs.X**2 + Valeurs_Capteurs.Y**2 + Valeurs_Capteurs.Z**2);
            --Ajouter_Fin(L, Val, Num);
            Ajouter_Croissant_Rec(L, Val, Num);
            Num := Num + 1;
            --  EcrireEcran(5, 5, "Dernier enregistrement :  " & Integer'Image(Integer(Val))&"    ");
         end if;
      end loop;

      EffacerEcran;
   end Enregistrer;

   Liste: P_Element:=null;
begin
   loop

      Enregistrer(Liste);

   end loop;
end Mission_Capteurs;
