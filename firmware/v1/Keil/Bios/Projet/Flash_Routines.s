; ------------------------------------------------------
; Function located in ram for flash programming
; ------------------------------------------------------

				AREA    |.ram_text|, CODE, READONLY

_FLASH_CR		EQU			0x40022010
_FLASH_SR		EQU			0x4002200C
_FLASH_AR		EQU			0x40022014
	
_FLASH_CR_PG	EQU			0x00000001
_FLASH_CR_PER	EQU			0x00000002
_FLASH_SR_PGERR	EQU			0x00000004
_FLASH_SR_WRPERR	EQU		0x00000010
_FLASH_SR_EOP	EQU			0x00000020
_FLASH_SR_BUSY	EQU			0x00000001
	
_NEG_FLASH_SR_BUSY	EQU			0xFFFE
_NEG_FLASH_CR_PG	EQU			0xFFFFFFFE	
	
; program function
; R0 -> @ en flash
; R1 -> @ du buffer à ecrire
; R2 -> longueur du buffer
;
; retour
; R0 -> status: 0=Success, 1= Echec
;
; Registres sauvés
;
;

DoProgram_RAM   PROC
                EXPORT  	DoProgram_RAM             
				EXPORT  	DoProgram_RAM_End
					
				PUSH 		{R4-R7}
				
				MOVW		R5, #(_FLASH_CR & 0xFFFF)	; Charge R5 avec l'@ de FLASH_CR
				MOVT		R5, #(_FLASH_CR >>16)
				MOVW		R6, #(_FLASH_SR & 0xFFFF)	; Charge R6 avec l'@ de FLASH_SR
				MOVT		R6, #(_FLASH_SR >>16)		
				
				LDR			R7,	[R5]		; charge le contenu du registre FLASH_CR
				ORR			R7, R7, #_FLASH_CR_PG	; Active le bit PG
				STR			R7,	[R5]		; mets a jour le registre FLASH_CR

DoProgram_MainLoop
				LDRH		R4, [R1], #2 	; Charge l'element du buffer pointé par R1 et incremente la pointeur	
				STRH		R4,	[R0], #2    ; Ecrit l'element à l'adresse R0 (pointeur en flash) et incremente R0
				
DoProgram_WaitLoop
				LDR			R7,	[R6]		; Charge le registre FLASH_SR
				ANDS		R7, R7, #_FLASH_SR_BUSY ; Verifie le bit BUSY
				BNE			DoProgram_WaitLoop ; Boucle tant que BUSY != 0

				SUBS		R2,	#2			; Decremente de 2 le nombre d'octet à ecrire
				BNE			DoProgram_MainLoop ; Boucle tant que R2 != 0 (tant qu'il reste de données à ecrire)
				
				LDR			R7,	[R5]		; charge le contenu du registre FLASH_CR
				MOVW		R6, #(_NEG_FLASH_CR_PG & 0xFFFF)
				MOVT		R6, #(_NEG_FLASH_CR_PG >>16)
				AND			R7, R7, R6		; Desactive le bit PG
				STR			R7,	[R5]		; mets a jour le registre FLASH_CR
				
				EOR			R0, R0			; Met 0 Dans R0 (retour ok)
				POP			{R4-R7}			; Recupere les registres modifiés
				
				BX			LR				; Retourne à l'appelant
					
DoProgram_RAM_End
                ENDP
					
				END
						
						