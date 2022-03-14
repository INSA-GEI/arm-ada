with morse, Ada.Text_IO ;
use morse, Ada.Text_IO ;
procedure Main is

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
         InsererFinSymb(L.all.suiv,S);
      end if;
   end InsererFinSymb ;


   procedure AfficherListe (L : in Ptr_Element) is
   begin
      if L/= null then
         AfficherSymbole(L.all.symb);
         AfficherListe(L.all.suiv);
      end if;
   end AfficherListe;

   function testerEgalite (L1,L2 : Ptr_Element) return boolean is
      pareil : Boolean := true ;

   begin
      if L1 = L2 then
         pareil := true ; -- pas necessaire car initialise a true mais c'est plus beau
      elsif L1 = null or L2 =null then
         pareil := false ;
      elsif L1.all.symb /= L2.all.symb then
         pareil := false ;
      else
         pareil := testerEgalite(L1.all.suiv,L2.all.suiv);
      end if;
      return pareil ;
   end testerEgalite ;

   function ChercherDico(Liste : Ptr_Element) return Character is
      lettre : Character := '$'; -- $ pour pas trouve
      trouve : boolean := false ;
      Aux : Ptr_Element := Liste ;
      indice : character := DicoMorse'first;
   begin
      while not trouve and indice <= DicoMorse'Last loop
         if testerEgalite(DicoMorse(indice),Liste) then
            trouve := true;
            lettre := indice ;
         else
            indice := Character'Succ(indice) ;
         end if;
      end loop ;
      return lettre ;
   end ChercherDico ;

   procedure InsererFinLettre (M : in out Ptr_Mot ; L : in out Ptr_Element) is
   begin
      if M = null then
         M := new T_mot' (L,null) ;
      else
         InsererFinLettre(M.all.Suiv,L);
      end if;
   end InsererFinLettre ;

   procedure AfficherMot(M : in Ptr_Mot ) is
   begin
      if M /= null then
         --AfficherLettre (M.all.Lettre) ;
         put(ChercherDico(M.all.Lettre));
         put(' ');
         AfficherMot(M.all.Suiv);
      end if;
   end AfficherMot ;


   MonMot : Ptr_Mot ;
   fin : Boolean := false ;
   Symbole : Character ;
   LettreEnCours : Ptr_Element ;

begin
   For I in DicoMorse'range loop
      put(I&"=> ");
      AfficherLettre(DicoMorse(I));
      new_Line;
   end loop;
   put_line("Taper la sequence : L(ong), C(ourt), M(ot) pour passer a la lettre suivante du mot ou F(in) pour terminer");
   while not fin loop
      get(Symbole);
      case Symbole is
         when 'F' | 'f' =>
            fin := true ;
            InsererFinLettre(MonMot,LettreEnCours);
         when 'l' | 'L' => InsererFinSymb(LettreEnCours,Long);
         when 'c' | 'C' => InsererFinSymb(LettreEnCours,Court);
         when 'm' | 'M' =>
            InsererFinLettre(MonMot,LettreEnCours);
            LettreEnCours := null;
         when others => null;
      end case;
   end loop;
   AfficherMot(MonMot);
   new_line;
   --put(ChercherDico(MaListe));
end Main;
