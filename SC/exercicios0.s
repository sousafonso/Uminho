	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _a@GOTPAGE
	ldr	x8, [x8, _a@GOTPAGEOFF]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	adrp	x9, _b@GOTPAGE
	ldr	x9, [x9, _b@GOTPAGEOFF]
	stur	x9, [x29, #-8]                  ; 8-byte Folded Spill
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_scanf
	ldr	x10, [sp, #16]                  ; 8-byte Folded Reload
	ldur	x9, [x29, #-8]                  ; 8-byte Folded Reload
	ldr	w8, [x10]
	lsl	w8, w8, #1
	str	w8, [x9]
	ldr	w8, [x9]
	ldr	w10, [x10]
	subs	w10, w8, w10
	adrp	x8, _c@GOTPAGE
	ldr	x8, [x8, _c@GOTPAGEOFF]
	str	w10, [x8]
	ldr	w9, [x9]
                                        ; implicit-def: $x10
	mov	x10, x9
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
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
