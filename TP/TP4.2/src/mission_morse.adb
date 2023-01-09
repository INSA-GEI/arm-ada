------------------------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------
with Morse;
use Morse;
procedure Mission_Morse is
   type T_Lettre ;
   type Ptr_Lettre is access T_Lettre ;
   type T_Lettre is record
      Lettre : Ptr_Element ;
      Suiv : Ptr_Lettre ;
   end record ;

   procedure InsererSymbole ( LS : in out Ptr_Element ; S : T_Symbole ) is
   begin
      if LS = null then
         LS := new Element'(S,null);
      else
         InsererSymbole(LS.all.Suiv,S);
      end if;
   end InsererSymbole ;

   procedure AfficherSymbole (LS : in Ptr_Element) is
   begin
      if LS /=null then
         JouerBruitSymbole(LS.all.Symb);
         AfficherSymboleResultat(LS.all.Symb);
         AfficherSymbole(LS.all.Suiv);
      end if;
   end AfficherSymbole ;

   procedure TestGestionSimpleLettre is
      Continuer : Boolean := True ;
      Symb : T_Symbole ;
      Lettre : Ptr_Element ;
   begin
      InitialiseEcran ;
      while Continuer loop
         Symb := AttendreSymbole ;
         case Symb is
         when FinLettre =>
            Continuer := False ;
         when Court | Long =>
            AfficherSymboleSaisi(Symb);
            JouerBruitSymbole(Symb);
            InsererSymbole(Lettre,Symb);
         when others => null;
         end case ;
      end loop;
      OuvrirFenetreResultat;
      AfficherSymbole(Lettre);
   end TestGestionSimpleLettre;

   function TesterEgaliteListe (LS1, LS2 : Ptr_Element ) return Boolean is
      Egales : Boolean ;
   begin
      if LS1 = null and LS2 = null then
         Egales := True ;
      elsif LS1 = null or LS2 = null then
         Egales := False ;
      elsif LS1.all.Symb /= LS2.all.Symb then
         Egales := False ;
      else
         Egales := TesterEgaliteListe (LS1.all.Suiv,LS2.all.Suiv);
      end if;
      return Egales ;
   end TesterEgaliteListe ;

   function RechercherLettre (LS : Ptr_Element) return Character is
      Lettre : Character := '?';
      Trouve : Boolean := False ;
      Indice : Character := DicoMorse'First ;
   begin
      while not Trouve and Indice <= DicoMorse'Last loop
         if TesterEgaliteListe(LS,DicoMorse(Indice)) then
            Lettre := Indice ;
            Trouve := True ;
         else
            Indice := Character'Succ(Indice);
         end if;
      end loop;
      return Lettre;
   end RechercherLettre ;

   procedure TestDetectionLettre is
      Continuer : Boolean := True ;
      Symb : T_Symbole ;
      Lettre : Ptr_Element ;
      Caractere : Character ;
   begin
      InitialiseEcran ;
      while Continuer loop
         Symb := AttendreSymbole ;
         case Symb is
         when FinLettre =>
            Continuer := False ;
            Caractere := RechercherLettre(Lettre) ;
            AfficherCaractereSaisi(Caractere);
         when Court | Long =>
            AfficherSymboleSaisi(Symb);
            JouerBruitSymbole(Symb);
            InsererSymbole(Lettre,Symb);
         when others => null;
         end case ;
      end loop;
      OuvrirFenetreResultat;
      AfficherSymbole(Lettre);
      AfficherCaractereResultat(Caractere);
   end TestDetectionLettre ;

   procedure InsererLettre (ML : in out Ptr_Lettre ; LS : in Ptr_Element) is
   begin
      if ML = null then
         ML := new T_Lettre'(LS,null) ;
      else
         InsererLettre (ML.all.Suiv,LS);
      end if;
   end InsererLettre;

   procedure GererFenetreResultat (M: Ptr_Lettre) is
      M1 : Ptr_Lettre := M;
      Caractere : Character ;
   begin
      OuvrirFenetreResultat;
      while M1 /= null loop
         Caractere := RechercherLettre(M1.all.Lettre);
         AfficherSymbole(M1.all.Lettre);
         AfficherCaractereResultat(Caractere);
         M1:=M1.all.Suiv;
      end loop;
      AttendreBoutonFermer ;
      FermerFenetreResultat ;
   end GererFenetreResultat ;

   procedure TestGestionMot is
      Continuer : Boolean := True ;
      Symb : T_Symbole ;
      Lettre : Ptr_Element ;
      Caractere : Character ;
      Mot : Ptr_Lettre ;
   begin
      InitialiseEcran ;
      while Continuer loop
         Symb := AttendreSymbole ;
         case Symb is
         when FinLettre =>
            Caractere := RechercherLettre(Lettre) ;
            AfficherCaractereSaisi(Caractere);
            AfficherSymboleSaisi(FinLettre);
            InsererLettre(Mot,Lettre);
            Lettre := null;
         when Court | Long =>
            AfficherSymboleSaisi(Symb);
            JouerBruitSymbole(Symb);
            InsererSymbole(Lettre,Symb);
         when FinMot =>
            Continuer := False ;
         end case ;
      end loop;
      GererFenetreResultat(Mot);
   end TestGestionMot;

begin
   -- testGestionSimpleLettre ;
   -- testDetectionLettre ;
   while True loop
      TestGestionMot ;
   end loop ;
end Mission_Morse;

