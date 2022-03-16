------------------------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Morse;
use Morse;

procedure Mission_Morse is

   type T_Mot ;
   type Ptr_Mot is access T_Mot ;
   type T_Mot is record
      Lettre : Ptr_Element ;
      Suiv : Ptr_Mot ;
   end record ;

   procedure InsererFinSymb (L : in out Ptr_Element ; S : T_Symbole) is
   begin
      if L = null then
         L:= new Element'(S,null);
      else
         InsererFinSymb(L.all.Suiv,S);
      end if;
   end InsererFinSymb ;

   --  procedure AfficherListe (L : in Ptr_Element) is
   --  begin
   --     if L/= null then
   --        AfficherSymboleSaisi(L.all.Symb);
   --        AfficherListe(L.all.Suiv);
   --     end if;
   --  end AfficherListe;

   function TesterEgalite (L1,L2 : Ptr_Element) return Boolean is
      Pareil : Boolean := True ;

   begin
      if L1 = L2 then
         Pareil := True ; -- pas necessaire car initialise a true mais c'est plus beau
      elsif L1 = null or L2 =null then
         Pareil := False ;
      elsif L1.all.Symb /= L2.all.Symb then
         Pareil := False ;
      else
         Pareil := TesterEgalite(L1.all.Suiv,L2.all.Suiv);
      end if;
      return Pareil ;
   end TesterEgalite ;

   function ChercherDico(Liste : Ptr_Element) return Character is
      Lettre : Character := '?'; -- ? pour pas trouve
      Trouve : Boolean := False ;
      --Aux : Ptr_Element := Liste ;
      Indice : Character := DicoMorse'First;
   begin
      while not Trouve and Indice <= DicoMorse'Last loop
         if TesterEgalite(DicoMorse(Indice),Liste) then
            Trouve := True;
            Lettre := Indice ;
         else
            Indice := Character'Succ(Indice) ;
         end if;
      end loop ;
      return Lettre ;
   end ChercherDico ;

   procedure InsererFinLettre (M : in out Ptr_Mot ; L : in out Ptr_Element) is
   begin
      if M = null then
         M := new T_Mot' (L,null) ;
      else
         InsererFinLettre(M.all.Suiv,L);
      end if;
   end InsererFinLettre ;

   procedure AfficherSymbolesLettre (Liste : Ptr_Element) is
   begin
      if Liste /= null then
         AfficherSymboleResultat(Liste.all.Symb);
         JouerBruitSymbole(Liste.all.Symb);

         AfficherSymbolesLettre(Liste.all.Suiv);
      else
         AfficherSymboleResultat(FinLettre);
         JouerBruitSymbole(FinLettre);
      end if;
   end AfficherSymbolesLettre;

   procedure AfficherMot(M : in Ptr_Mot ) is
   begin
      if M /= null then
         if M.all.Lettre /= null then
            AfficherSymbolesLettre(M.all.Lettre);
            AfficherCaractereResultat(ChercherDico(M.all.Lettre));
         end if;

         AfficherMot(M.all.Suiv);
      end if;
   end AfficherMot ;

   MonMot : Ptr_Mot ;
   Fin : Boolean := False ;
   LettreEnCours : Ptr_Element ;
   SymboleSaisi : T_Symbole;

begin
   loop
      InitialiseEcran;
      Fin := False;
      MonMot:=null;
      LettreEnCours:=null;

      while not Fin loop
         SymboleSaisi:=AttendreSymbole;
         AfficherSymboleSaisi(SymboleSaisi);
         JouerBruitSymbole(SymboleSaisi);

         case SymboleSaisi is
         when FinMot =>
            Fin := True ;
            InsererFinLettre(MonMot,LettreEnCours);

         when Long =>
            InsererFinSymb(LettreEnCours,Long);

         when Court =>
            InsererFinSymb(LettreEnCours,Court);

         when FinLettre =>
            if LettreEnCours /= null then
               AfficherCaractereSaisi(ChercherDico(LettreEnCours));
            end if;

            InsererFinLettre(MonMot,LettreEnCours);
            LettreEnCours := null;

         end case;
      end loop;

      OuvrirFenetreResultat;
      AfficherMot(MonMot);

      AttendreBoutonFermer;
      FermerFenetreResultat;

   end loop;
end Mission_Morse;
