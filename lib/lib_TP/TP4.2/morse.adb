with Ada.Text_IO;
use Ada.Text_IO ;

package body morse is

   procedure AfficherSymbole (S: T_Symbole) is
   begin
      case S is 
         when Court => put(".") ;--Put("Court");
         when Long => put("-") ; --Put("Long");
         when FinLettre => Put("FinLettre");
         when FinMot => Put("Finmot");
      end case ;
   end AfficherSymbole ;
           
   procedure AfficherLettre (L : Ptr_Element) is
      aux : Ptr_Element := L;
   begin
      while aux /= null loop
         AfficherSymbole(aux.all.symb);
         put(" ");
         aux :=aux.all.suiv ;
      end loop ;
   end AfficherLettre ;
begin
   null ;
end morse;
