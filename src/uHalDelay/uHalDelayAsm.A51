NAME    DELAY

?PR?delayUs?DELAY    SEGMENT CODE
        PUBLIC  delayUs

        RSEG    ?PR?delayUs?DELAY
delayUs:
        USING   0
AGAIN: 	NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		DJNZ R7, AGAIN
		RET
        END
