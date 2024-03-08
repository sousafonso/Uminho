	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
Lloh0:
	adrp	x19, _a@GOTPAGE
Lloh1:
	ldr	x19, [x19, _a@GOTPAGEOFF]
	str	x19, [sp]
Lloh2:
	adrp	x0, l_.str@PAGE
Lloh3:
	add	x0, x0, l_.str@PAGEOFF
	bl	_scanf
	ldr	w8, [x19]
	lsl	w9, w8, #1
Lloh4:
	adrp	x10, _b@GOTPAGE
Lloh5:
	ldr	x10, [x10, _b@GOTPAGEOFF]
Lloh6:
	str	w9, [x10]
Lloh7:
	adrp	x10, _c@GOTPAGE
Lloh8:
	ldr	x10, [x10, _c@GOTPAGEOFF]
Lloh9:
	str	w8, [x10]
	stp	x9, x8, [sp]
Lloh10:
	adrp	x0, l_.str.1@PAGE
Lloh11:
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.loh AdrpAdd	Lloh10, Lloh11
	.loh AdrpLdrGotStr	Lloh7, Lloh8, Lloh9
	.loh AdrpLdrGotStr	Lloh4, Lloh5, Lloh6
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpLdrGot	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d"

	.comm	_a,4,2                          ; @a
	.comm	_b,4,2                          ; @b
	.comm	_c,4,2                          ; @c
l_.str.1:                               ; @.str.1
	.asciz	"%d %d\n"

.subsections_via_symbols
