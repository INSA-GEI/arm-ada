------------------------------------------------------------------------------
--                                                                          --
--                             Mission dichotomie                           --
--                                                                          --
--                                                                          --
------------------------------------------------------------------------------

with Nombre;
use Nombre;

procedure @_Main_Name_@ is
 type T_Vecteur is array (Integer range <>) of Natural ;
   
   -- attention
   -- ajouter les parametres necessaires 
   procedure RechercherValeur is
   begin
   -- a completer    
      null;
   end RechercherValeur ;
   
   -- procedure fournie 
   -- pour afficher les composantes d'un tableau
   -- ne pas modifier
   procedure AfficherVecteur (T : in T_Vecteur) is
   begin
      EffacerResultats;
      AjouterTexteResultats("Les valeurs sont :" & Newline & Newline);
      for I in T'Range loop
         AjouterTexteResultats(Integer'Image(T(I)) & ", ");
      end loop;
      AjouterTexteResultats(Newline & Newline);
   end AfficherVecteur;

   -- 1ere etape : Travail sur des tableaux pre initialises
   -- procedure a completer 
   -- pour tester votre sous programme de recherche
   procedure TesterUnitaire is
      Val       : constant Integer := 8 ;
      
      PasVal    : constant T_Vecteur (1..9) := (1,2,3,4,5,6,7,9,10) ;
      Valbord1  : constant T_Vecteur (1..9) := (0,1,2,3,4,5,6,7,8) ;
      Valbord2  : constant T_Vecteur (1..9) := (8,9,10,11,12,13,14,15,16) ;
      Valmilieu : constant T_Vecteur (1..9) := (4,5,6,7,8,9,10,11,12) ;
      Valbidon  : constant T_Vecteur (1..9) := (6,7,8,9,10,11,12,13,14) ;
      
      type T_Test is array (1..5) of T_Vecteur(1..9) ;
      
      Test : T_Test := (1=>PasVal,
			2=>Valbord1,
			3=>Valbord2,
			4=>Valmilieu,
			5=>Valbidon);  
   begin
      AfficherEcranTestsUnitaires;
      -- a completer
   end TesterUnitaire ;

   -- 2eme etape : Saisie libre des valeurs du tableau 
   -- procedure a completer 
   -- pour tester votre sous programme de recherche
   procedure TesterLibre is
   begin
      AfficherEcranTestsLibres;
      -- a completer
   end TesterLibre ;
   
begin
   -- Decommenter une des deux lignes suivantes
   -- TesterUnitaire;
   -- Testerlibre; 
   null;  
end @_Main_Name_@;
