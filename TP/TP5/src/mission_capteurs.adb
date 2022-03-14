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

      AfficheMessage("Demarrer l'enregistrement","appuyez sur OK");

      L := null;
      while Continuer loop
         if Attendre1secondesOuB then
            Continuer := False ;
         else
            Valeurs_Capteurs := ObtenirValeursCapteur;
            Val := CalculerRacineCarre(Valeurs_Capteurs.X**2 + Valeurs_Capteurs.Y**2 + Valeurs_Capteurs.Z**2);

            Ajouter_Croissant_Rec(L, Val, Num);
            Num := Num + 1;
            AjouterEcranEnregistrement(Val);
         end if;
      end loop;

      EffacerEcran;
   end Enregistrer;

   procedure AfficherNPremiers(L : in P_Element; N : in Integer) is
      Aux : P_Element := L;
      Ligne : Integer :=1;
   begin
      if Aux /=null then
         while Ligne <= N loop
            Ligne := Ligne +1 ;
            if Aux/= null then
               AjouterPremier(Aux.all.Norme);
               Aux:=Aux.all.Suiv;
            end if;
         end loop;
      end if;
   end AfficherNPremiers;

   procedure AfficherNDerniers(L : in P_Element; N : in out Integer ; Max : in out Integer) is
   begin
      if L /= null then
         AfficherNDerniers(L.all.Suiv,N,Max);
         if N= 5 then
            Max := L.all.Norme ;
         end if;
         if N /=0 then
            AjouterDernier(L.all.Norme);
            N:=N-1;
         end if;
      end if;
      if L = null and N <= 0 then
         N := N - 1 ;
      end if;
   end AfficherNDerniers;

   procedure Afficher(L : in P_Element) is
      NbreLignesAffichees,Max : Integer :=5 ;
   begin
      AfficherEcranResultatsBruts(Max);
      AfficherNPremiers(L,NbreLignesAffichees);
      AfficherNDerniers(L,NbreLignesAffichees,Max);

      AttendreToucheA;
      EffacerEcran;
   end Afficher;

   procedure AfficherFiltrage(L : in P_Element; Nb_Supprimes: Integer) is
      NbreLignesAffichees,Max : Integer :=5 ;
   begin
      AfficherEcranResultatsFiltre(Max, Nb_Supprimes);
      AfficherNPremiers(L,NbreLignesAffichees);
      AfficherNDerniers(L,NbreLignesAffichees,Max);

      AttendreToucheA;
      EffacerEcran;
   end AfficherFiltrage;

   Liste: P_Element:=null;
   Nombre_Valeurs_Supprimees : Integer ;

begin
   loop
      Enregistrer(Liste);

      Afficher(Liste);

      Filtrer(Liste,Nombre_Valeurs_Supprimees);

      AfficherFiltrage(Liste,Nombre_Valeurs_Supprimees);
   end loop;
end Mission_Capteurs;
