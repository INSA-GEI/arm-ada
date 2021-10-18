------------------------------------------------------------------------------
--                                                                          --
--                             Mission Simon                                --
--                                                                          --
--                              Acteur Simon                                -- 
--                                 Specs                                    --
--                                                                          --
------------------------------------------------------------------------------
--
-- Cet acteur fourni les routines necessaires pour le TP sur Simon
--

with Ada.Characters.Latin_1;

package Simon is
   
   -- ###############################
   -- GESTION SEQUENCE
   -- ###############################
   -- Utiliser newline pour faire un retour à la ligne (dans EcrireInfos)
   --
   -- Exemple:
   -- EcrireInfos("Ma premiere ligne" & NewLine & "Ma deuxieme ligne");
   Newline: constant Character := Ada.Characters.Latin_1.LF;
   
   type T_Direction is (Jaune, Bleu, Vert, Rouge, Immobile); 

   type T_Sequence is array (Positive range <>) of T_Direction;
   
   -- Dessine ou Efface un pave 
   procedure DessinerPave (P : T_Direction ; Efface : Boolean);
   
   -- Efface tous les paves
   procedure EffaceTout;
   
   -- Affiche une fenetre pour que l'utilisateur saisisse 
   -- la taille du vecteur
   function SaisirLongueurSequence return Integer;  
      
   -- Genere une sequence aleatoire de la taille de S'Length
   procedure GenererSequence(S : in out T_Sequence);
   
   -- Affiche la sequence S
   procedure AfficherSequence (S : T_Sequence);
   
   -- Faire une petite pause entre 2 séquences (par ex.)
   procedure PetitePause ;
   
   -- ###############################
   -- GESTION TOUCHE 
   -- ###############################   
   
   -- renvoie la derniere touche de direction appuyee de type T_Direction
   function  DetecterDirection return T_Direction;
   
   -- ###############################
   -- GESTION MESSAGES LIBRES ECRAN
   -- ###############################
   
   -- attend un appui sur la touche A
   procedure AttendreToucheA ;
   
   -- Ecrit la chaine S dans le champ "Information"
   -- Pensez à inserer des newline pour eviter que les chaines soient trop longues
   procedure EcrireInfos(S: String);
   
   -- Ecrit la valeur V dans le champ "longueur sequence"
   procedure EcrireLongueurSequence(V: Integer);

   -- Affiche l'ecran "perdu"
   procedure AfficherGameOver;

   -- Affiche l'ecran "gagné"
   procedure AfficherGagne;
   
end Simon ;

