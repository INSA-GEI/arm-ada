------------------------------------------------------------------------------
--                                                                          --
--                             Mission Morse                                --
--                                                                          --
--                             Acteur Morse                                 -- 
--                                  Specs                                   --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines et ressources necessaires à la saisie
-- et l'affichage des elements de morse.
--

package Morse is
      
   type T_Symbole is (Long,Court,FinLettre,FinMot) ;
   
   type Element ;
   type Ptr_Element is access Element ;
   type Element is record 
      symb : T_Symbole ;
      suiv : Ptr_Element ;
   end record ;
   
   type T_Tab is array (character range 'a'..'z') of Ptr_Element ;
   
   DicoMorse : constant T_tab := 
     ( 
      'a'=>new Element'(Court,new Element'(Long,null)),
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

   -- Procedures et fonctions liees à l'ecran principal (saisie des symboles morse)
   procedure InitialiseEcran;
   function AttendreSymbole return T_Symbole;
   procedure AfficherSymboleSaisi (S: T_Symbole);
   procedure AfficherCaractereSaisi (C: Character);
   
   -- Procedures et fonctions liees à la fenetre de resultat
   procedure OuvrirFenetreResultat;
   procedure FermerFenetreResultat; 
   procedure AttendreBoutonFermer;
   procedure AfficherCaractereResultat(C:Character);
   procedure AfficherSymboleResultat(S:T_Symbole);
   
   -- Procedure pour faire du bruit
   procedure JouerBruitSymbole(S:T_Symbole);
   
end Morse;
