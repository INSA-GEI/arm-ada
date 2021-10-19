------------------------------------------------------------------------------
--                                                                          --
--                             Mission Simon                                --
--                                                                          --
------------------------------------------------------------------------------
--
--

with Simon ;
use Simon ;

with Toto;

procedure Mission_Simon is
   LongueurSequence : Integer ;
   PositionSeqGlobale : Integer ;
   PositionSeqLocale : Integer ;
   Perdu : Boolean := False ;

   Touche: T_Direction:= Immobile;

   RetourAuCentre : Boolean := False;
begin
   loop
      LongueurSequence := SaisirLongueurSequence ;
      Toto.Truc;

      declare
         MaSeq : T_Sequence (1..LongueurSequence);
      begin
         --AfficherSimon;
         GenererSequence(MaSeq);

         -- initialisation des variables du jeu
         PositionSeqGlobale := MaSeq'First ;
         RetourAuCentre:=True;
         Perdu := False ;

         while not Perdu and PositionSeqGlobale <= MaSeq'Last loop
            EcrireLongueurSequence(PositionSeqGlobale);
            AfficherSequence(MaSeq(MaSeq'First..PositionSeqGlobale));
            PositionSeqlocale:= MaSeq'First ;

            while not Perdu and PositionSeqLocale <= PositionSeqGlobale loop

               Touche:=DetecterDirection;

               case Touche is
               when Immobile =>
                  RetourAuCentre := True ;
                  EffaceTout;
               when others =>
                  if RetourAuCentre then
                     RetourAuCentre := False;
                     DessinerPave (Touche, False);
                     if MaSeq(PositionSeqLocale) /= Touche then
                        Perdu := True;
                     else
                        PositionSeqLocale :=  Positionseqlocale +1;
                     end if;
                  end if;
               end case;

            end loop;

            PetitePause;
            EffaceTout;
            PositionSeqGlobale := PositionSeqGlobale +1;
         end loop;

         EffaceTout;
         -- EffaceEcranFinDuJeu;
         if Perdu then
            AfficherGameOver;
         else
            AfficherGagne;
         end if;
      end ;
   end loop;
end Mission_Simon;
