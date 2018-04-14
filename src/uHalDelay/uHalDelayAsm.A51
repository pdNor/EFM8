NAME    A_FUNC

?PR?a_func?A_FUNC    SEGMENT CODE
        PUBLIC  a_func

        RSEG    ?PR?a_func?A_FUNC
a_func:
        USING   0
;       POP     34h
;        MOV	    34h,r7
AGAIN: 	NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		DJNZ R7, AGAIN
		RET
        END
