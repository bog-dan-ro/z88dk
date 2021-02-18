

	SECTION		code_graphics
	PUBLIC		generic_console_cls

	EXTERN		swapgfxbk
	EXTERN		swapgfxbk1

	EXTERN		__bdos

generic_console_cls:
	call	swapgfxbk
	ld	hl,0
	ld	de,1
	ld	bc,+(80 * 200) - 1
	ld	(hl),0		
	ldir
	call	swapgfxbk1
	ret

	SECTION	code_rodata

	; Switches to graphics mode, sets VRAM to 0x00
initscr:        defb    27, '1', '$'

        SECTION code_crt_init

        ld      de,initscr
        ld      c,9
        call    __bdos
