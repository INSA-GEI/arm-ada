package morse is

   type Element ;
   type T_Symbole is (Long,Court,FinLettre,FinMot) ;
   type Ptr_Element is access Element ;
   type Element is record 
      symb : T_Symbole ;
      suiv : Ptr_Element ;
   end record ;
   
   type T_Tab is array (character range 'a'..'z') of Ptr_Element ;
   
   DicoMorse : constant T_tab := 
     (
      'a'=>new Element'(Court,new Element'(Long,null)), --fdsfsq
      'b'=>new Element'(Long,new Element'(Court,new Element'(Court,new Element'(Court,null)))),
      'c'=>new Element'(Long,new Element'(Court,new Element'(Long,new Element'(Court,null)))),
      'd'=>new Element'(Long,new Element'(Court,new Element'(Court,null))),
      'e'=>new Element'(Court,null),
      'f'=>new Element'(Court,new Element'(Court,new Element'(Long,new Element'(Court,null)))),
      'g'=>new Element'(Long,new Element'(Long,new Element'(Court,null))),
      'h'=>new Element'(Court,new Element'(Court,new Element'(Court,new Element'(Court,null)))),
      'i'=>new Element'(Court,new Element'(Court,null)),
      'j'=>new Element'(Court,new Element'(Long,new Element'(Long,new Element'(Long,null)))),
      'k'=>new Element'(Long,new Element'(Court,new Element'(Long,null))),
      'l'=>new Element'(Court,new Element'(Long,new Element'(Court,new Element'(Court,null)))),
      'm'=>new Element'(Long,new Element'(Long,null)),
      'n'=>new Element'(Long,new Element'(Court,null)),
      'o'=>new Element'(Long,new Element'(Long,new Element'(Long,null))),
      'p'=>new Element'(Court,new Element'(Long,new Element'(Long,new Element'(Court,null)))),
      'q'=>new Element'(Long,new Element'(Long,new Element'(Court,new Element'(Long,null)))),
      'r'=>new Element'(Court,new Element'(Long,new Element'(Court,null))),
      's'=>new Element'(Court,new Element'(Court,new Element'(Court,null))),
      't'=>new Element'(Long,null),
      'u'=>new Element'(Court,new Element'(Court,new Element'(Long,null))),
      'v'=>new Element'(Court,new Element'(Court,new Element'(Court,new Element'(Long,null)))),
      'w'=>new Element'(Court,new Element'(Long,new Element'(Long,null))),
      'x'=>new Element'(Long,new Element'(Court,new Element'(Court,new Element'(Long,null)))),
      'y'=>new Element'(Long,new Element'(Court,new Element'(Long,new Element'(Long,null)))),
      'z'=>new Element'(Long,new Element'(Long,new Element'(Court,new Element'(Court,null))))
     );

     
   procedure AfficherSymbole (S: T_Symbole) ;
   procedure AfficherLettre (L : Ptr_Element);
   
end morse;
