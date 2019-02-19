with Simon ;
use Simon ;

procedure missionsimon is
   	Longueur : Integer ;
   	PositionSeqGlobale : Integer ;
   	PositionSeqLocale : Integer ;
   	Perdu : Boolean := False ;
   	RetourAuCentre : Boolean := False ;
    
	Touche: T_Direction:= Immobile;
	DerniereDirection : T_Direction;

   	procedure EffaceTout is
   	begin
      	DessinerPave (Haut_Gauche, True) ;
      	DessinerPave (Bas_Gauche, True) ;
      	DessinerPave (Haut_Droit, True) ;
      	DessinerPave (Bas_Droit, True) ;
   	end EffaceTout;
   
begin
   	while True loop 
       	Perdu := False ;

       	EffacerEcran ;
       	Longueur := SaisirLongueurSequence ;
       
	   	declare 
	  		MaSeq : T_Sequence (1..Longueur);
       	begin
	   		AfficherSimon;
	  		GenererSequence(MaSeq);
	  		PositionSeqGlobale := MaSeq'First ;	 
	  
	  		Touche:= Immobile;
			RetourAuCentre:=True;
			DerniereDirection:=Autre;

	  		while not Perdu and PositionSeqGlobale <= MaSeq'Last loop
	     		AfficherSequence(MaSeq(MaSeq'First..PositionSeqGlobale));
	     		positionseqlocale:= MaSeq'First ;
	     
		 		while not Perdu and PositionSeqLocale <= PositionSeqGlobale loop
					Touche:=DetecterDirection;

					case Touche is
		   			when Haut_Gauche =>		     
						if RetourAuCentre = True then
				  			RetourAuCentre :=False;
			      			DessinerPave (Haut_Gauche, False);
							DerniereDirection := Touche;
						end if;

		   			when Bas_Gauche =>  
						if RetourAuCentre = True then
				  			RetourAuCentre :=False;
			      			DessinerPave (Bas_Gauche, False);
							DerniereDirection := Touche;
						end if;
 
		   			when Haut_Droit => 
						if RetourAuCentre = True then
				  			RetourAuCentre :=False;
			      			DessinerPave (Haut_Droit, False);
							DerniereDirection := Touche;
						end if;
		   
		   			when Bas_Droit =>  
						if RetourAuCentre = True then
				  			RetourAuCentre :=False;
			      			DessinerPave (Bas_Droit, False);
							DerniereDirection := Touche;
						end if;
		   
		   			when Immobile =>  
		      			RetourAuCentre := True ;
		      			EffaceTout;
					when others =>
								null;
					end case;	

					EcrireEcran(1,2,T_Direction'Image(DerniereDirection));

					if RetourAuCentre = True and DerniereDirection/=Autre then
			 			if MaSeq(PositionSeqLocale) /= DerniereDirection then
			    			Perdu := True ;
			 			else
			    			PositionSeqLocale :=  positionseqlocale +1 ;
			 			end if ; 

						DerniereDirection:=Autre;
					end if;	
	     		end loop;
	     
		 		PetitePause ;
	     		EffaceTout ;
	     		Positionseqglobale := Positionseqglobale +1 ;
	  		end loop;
	  
	 		EffaceEcranFinDuJeu;
	 		if Perdu then
				AfficherGameOver;
	 		else
				AfficherGagne;
	 		end if;

      end ;
   	end loop;
end missionsimon ;
