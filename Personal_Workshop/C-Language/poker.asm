	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 1
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #464
	stp	x28, x27, [sp, #432]            ; 16-byte Folded Spill
	stp	x29, x30, [sp, #448]            ; 16-byte Folded Spill
	add	x29, sp, #448
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	mov	w0, #0                          ; =0x0
	str	wzr, [sp, #120]
	adrp	x1, l_.str.22@PAGE
	add	x1, x1, l_.str.22@PAGEOFF
	bl	_setlocale
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_10 Depth 2
	adrp	x0, _menuOptions@PAGE
	add	x0, x0, _menuOptions@PAGEOFF
	mov	w1, #3                          ; =0x3
	mov	w2, #28                         ; =0x1c
	mov	w3, #22                         ; =0x16
	mov	w8, #1                          ; =0x1
	and	w4, w8, #0x1
	adrp	x5, _printTitle@PAGE
	add	x5, x5, _printTitle@PAGEOFF
	mov	x6, #0                          ; =0x0
	bl	_displayChoices
	str	w0, [sp, #116]
	ldr	w8, [sp, #116]
	str	w8, [sp, #76]                   ; 4-byte Folded Spill
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #76]                   ; 4-byte Folded Reload
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB0_5
	b	LBB0_3
LBB0_3:
	ldr	w8, [sp, #76]                   ; 4-byte Folded Reload
	subs	w8, w8, #2
	cset	w8, eq
	tbnz	w8, #0, LBB0_6
	b	LBB0_7
LBB0_4:
	b	LBB0_26
LBB0_5:                                 ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_10
LBB0_6:
	b	LBB0_9
LBB0_7:
	b	LBB0_8
LBB0_8:
	bl	_clearScreen
	adrp	x0, l_.str.23@PAGE
	add	x0, x0, l_.str.23@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #120]
	b	LBB0_27
LBB0_9:
	bl	_clearScreen
	str	wzr, [sp, #120]
	b	LBB0_27
LBB0_10:                                ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	adrp	x0, _currentSettings@GOTPAGE
	ldr	x0, [x0, _currentSettings@GOTPAGEOFF]
	bl	_loadSettings
	adrp	x0, _settingOptions@PAGE
	add	x0, x0, _settingOptions@PAGEOFF
	mov	w1, #4                          ; =0x4
	mov	w2, #21                         ; =0x15
	mov	w3, #22                         ; =0x16
	mov	w8, #1                          ; =0x1
	and	w4, w8, #0x1
	adrp	x5, _printSettings@PAGE
	add	x5, x5, _printSettings@PAGEOFF
	mov	x6, #0                          ; =0x0
	bl	_displayChoices
	str	w0, [sp, #116]
	ldr	w8, [sp, #116]
	subs	w8, w8, #0
	mov	w8, w8
                                        ; kill: def $x8 killed $w8
	str	x8, [sp, #64]                   ; 8-byte Folded Spill
	subs	x8, x8, #3
	cset	w8, hi
	tbnz	w8, #0, LBB0_24
; %bb.11:                               ;   in Loop: Header=BB0_10 Depth=2
	ldr	x11, [sp, #64]                  ; 8-byte Folded Reload
	adrp	x10, lJTI0_0@PAGE
	add	x10, x10, lJTI0_0@PAGEOFF
Ltmp0:
	adr	x8, Ltmp0
	ldrsw	x9, [x10, x11, lsl #2]
	add	x8, x8, x9
	br	x8
LBB0_12:                                ;   in Loop: Header=BB0_10 Depth=2
	adrp	x8, l_.str.24@PAGE
	add	x8, x8, l_.str.24@PAGEOFF
	str	x8, [sp, #104]
	ldr	x3, [sp, #104]
	adrp	x8, _currentSettings@GOTPAGE
	ldr	x8, [x8, _currentSettings@GOTPAGEOFF]
	ldr	w8, [x8, #4]
                                        ; implicit-def: $x10
	mov	x10, x8
	adrp	x8, _maxPlayerText@PAGE
	ldr	x8, [x8, _maxPlayerText@PAGEOFF]
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	add	x0, sp, #224
	str	x0, [sp, #48]                   ; 8-byte Folded Spill
	mov	w1, #0                          ; =0x0
	mov	x2, #200                        ; =0xc8
	bl	___sprintf_chk
	ldr	x6, [sp, #48]                   ; 8-byte Folded Reload
	adrp	x8, l_constinit@PAGE
	add	x8, x8, l_constinit@PAGEOFF
	ldr	q0, [x8]
	add	x0, sp, #192
	str	q0, [sp, #192]
	ldr	x8, [x8, #16]
	str	x8, [sp, #208]
	mov	w1, #3                          ; =0x3
	mov	w2, #21                         ; =0x15
	mov	w3, #22                         ; =0x16
	mov	w8, #1                          ; =0x1
	and	w4, w8, #0x1
	adrp	x5, _printSettings@PAGE
	add	x5, x5, _printSettings@PAGEOFF
	bl	_displayChoices
	str	w0, [sp, #116]
	ldr	w8, [sp, #116]
	str	w8, [sp, #60]                   ; 4-byte Folded Spill
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_14
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	w8, [sp, #60]                   ; 4-byte Folded Reload
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB0_18
	b	LBB0_19
LBB0_14:                                ;   in Loop: Header=BB0_10 Depth=2
	adrp	x0, l_.str.27@PAGE
	add	x0, x0, l_.str.27@PAGEOFF
	bl	_printf
	mov	x9, sp
	add	x8, sp, #112
	str	x8, [x9]
	adrp	x0, l_.str.28@PAGE
	add	x0, x0, l_.str.28@PAGEOFF
	bl	_scanf
	ldr	w8, [sp, #112]
	subs	w8, w8, #1
	cset	w8, lt
	tbnz	w8, #0, LBB0_16
	b	LBB0_15
LBB0_15:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	w8, [sp, #112]
	subs	w8, w8, #8
	cset	w8, le
	tbnz	w8, #0, LBB0_17
	b	LBB0_16
LBB0_16:                                ;   in Loop: Header=BB0_10 Depth=2
	mov	w8, #4                          ; =0x4
	str	w8, [sp, #112]
	b	LBB0_17
LBB0_17:                                ;   in Loop: Header=BB0_10 Depth=2
	bl	_getchar
	ldr	w8, [sp, #112]
	adrp	x9, _currentSettings@GOTPAGE
	ldr	x9, [x9, _currentSettings@GOTPAGEOFF]
	str	w8, [x9, #4]
	b	LBB0_20
LBB0_18:                                ;   in Loop: Header=BB0_10 Depth=2
	adrp	x9, _currentSettings@GOTPAGE
	ldr	x9, [x9, _currentSettings@GOTPAGEOFF]
	mov	w8, #4                          ; =0x4
	str	w8, [x9, #4]
	b	LBB0_20
LBB0_19:                                ;   in Loop: Header=BB0_10 Depth=2
	b	LBB0_20
LBB0_20:                                ;   in Loop: Header=BB0_10 Depth=2
	adrp	x0, _currentSettings@GOTPAGE
	ldr	x0, [x0, _currentSettings@GOTPAGEOFF]
	bl	_saveSettings
	b	LBB0_10
LBB0_21:                                ;   in Loop: Header=BB0_10 Depth=2
	b	LBB0_10
LBB0_22:                                ;   in Loop: Header=BB0_10 Depth=2
	b	LBB0_10
LBB0_23:                                ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_1
LBB0_24:
	b	LBB0_25
LBB0_25:
	b	LBB0_26
LBB0_26:
	bl	_clearScreen
	bl	_printTitle
	adrp	x0, _currentSettings@GOTPAGE
	ldr	x0, [x0, _currentSettings@GOTPAGEOFF]
	bl	_loadSettings
	adrp	x8, l_constinit.29@PAGE
	add	x8, x8, l_constinit.29@PAGEOFF
	ldr	q0, [x8]
	add	x1, sp, #160
	str	q0, [sp, #160]
	ldr	w8, [x8, #16]
	str	w8, [sp, #176]
	add	x2, sp, #99
	mov	w8, #83                         ; =0x53
	str	w8, [sp, #36]                   ; 4-byte Folded Spill
	strb	w8, [sp, #99]
	mov	w9, #72                         ; =0x48
	str	w9, [sp, #24]                   ; 4-byte Folded Spill
	strb	w9, [sp, #100]
	mov	w9, #68                         ; =0x44
	str	w9, [sp, #28]                   ; 4-byte Folded Spill
	strb	w9, [sp, #101]
	mov	w9, #67                         ; =0x43
	str	w9, [sp, #32]                   ; 4-byte Folded Spill
	strb	w9, [sp, #102]
	strb	w8, [sp, #103]
	mov	w0, #5                          ; =0x5
	bl	_printCard
	ldr	w11, [sp, #24]                  ; 4-byte Folded Reload
	ldr	w10, [sp, #28]                  ; 4-byte Folded Reload
	ldr	w9, [sp, #32]                   ; 4-byte Folded Reload
	ldr	w8, [sp, #36]                   ; 4-byte Folded Reload
	add	x1, sp, #144
	mov	w12, #7                         ; =0x7
	str	w12, [sp, #144]
	mov	w12, #8                         ; =0x8
	str	w12, [sp, #148]
	mov	w12, #9                         ; =0x9
	str	w12, [sp, #152]
	mov	w12, #10                        ; =0xa
	str	w12, [sp, #156]
	add	x2, sp, #95
	strb	w11, [sp, #95]
	strb	w10, [sp, #96]
	strb	w9, [sp, #97]
	strb	w8, [sp, #98]
	mov	w0, #4                          ; =0x4
	bl	_printCard
	ldr	w10, [sp, #28]                  ; 4-byte Folded Reload
	ldr	w9, [sp, #32]                   ; 4-byte Folded Reload
	ldr	w8, [sp, #36]                   ; 4-byte Folded Reload
	add	x1, sp, #132
	mov	w11, #1                         ; =0x1
	str	w11, [sp, #44]                  ; 4-byte Folded Spill
	str	w11, [sp, #132]
	mov	w11, #11                        ; =0xb
	str	w11, [sp, #136]
	mov	w11, #12                        ; =0xc
	str	w11, [sp, #140]
	add	x2, sp, #92
	strb	w10, [sp, #92]
	strb	w9, [sp, #93]
	strb	w8, [sp, #94]
	mov	w0, #3                          ; =0x3
	bl	_printCard
	ldr	w9, [sp, #32]                   ; 4-byte Folded Reload
	ldr	w8, [sp, #36]                   ; 4-byte Folded Reload
	ldr	w10, [sp, #44]                  ; 4-byte Folded Reload
	add	x1, sp, #124
	mov	w11, #13                        ; =0xd
	str	w11, [sp, #124]
	str	w10, [sp, #128]
	add	x2, sp, #90
	strb	w9, [sp, #90]
	strb	w8, [sp, #91]
	mov	w0, #2                          ; =0x2
	str	w0, [sp, #40]                   ; 4-byte Folded Spill
	bl	_printCard
	ldr	w8, [sp, #40]                   ; 4-byte Folded Reload
	ldr	w0, [sp, #44]                   ; 4-byte Folded Reload
	add	x1, sp, #84
	str	w8, [sp, #84]
	add	x2, sp, #83
	mov	w8, #88                         ; =0x58
	strb	w8, [sp, #83]
	bl	_printCard
	bl	_getch
	b	LBB0_27
LBB0_27:
	ldr	w8, [sp, #120]
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB0_29
	b	LBB0_28
LBB0_28:
	bl	___stack_chk_fail
LBB0_29:
	ldr	w0, [sp, #20]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #448]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #432]            ; 16-byte Folded Reload
	add	sp, sp, #464
	ret
	.cfi_endproc
	.p2align	2
lJTI0_0:
	.long	LBB0_12-Ltmp0
	.long	LBB0_21-Ltmp0
	.long	LBB0_22-Ltmp0
	.long	LBB0_23-Ltmp0
                                        ; -- End function
	.globl	_displayChoices                 ; -- Begin function displayChoices
	.p2align	2
_displayChoices:                        ; @displayChoices
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	stur	w2, [x29, #-16]
	stur	w3, [x29, #-20]
	and	w8, w4, #0x1
	sturb	w8, [x29, #-21]
	str	x5, [sp, #32]
	str	x6, [sp, #24]
	str	wzr, [sp, #20]
	strb	wzr, [sp, #19]
	b	LBB1_1
LBB1_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_7 Depth 2
                                        ;     Child Loop BB1_11 Depth 2
                                        ;     Child Loop BB1_15 Depth 2
                                        ;       Child Loop BB1_17 Depth 3
                                        ;     Child Loop BB1_26 Depth 2
                                        ;     Child Loop BB1_30 Depth 2
	ldrb	w8, [sp, #19]
	tbnz	w8, #0, LBB1_59
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	bl	_clearScreen
	ldr	x8, [sp, #32]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #32]
	blr	x8
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_1 Depth=1
	adrp	x0, l_.str.45@PAGE
	add	x0, x0, l_.str.45@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #24]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_6
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.46@PAGE
	add	x0, x0, l_.str.46@PAGEOFF
	bl	_printf
	b	LBB1_6
LBB1_6:                                 ;   in Loop: Header=BB1_1 Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_7
LBB1_7:                                 ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-16]
	add	w9, w9, #4
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_10
	b	LBB1_8
LBB1_8:                                 ;   in Loop: Header=BB1_7 Depth=2
	adrp	x0, l_.str.47@PAGE
	add	x0, x0, l_.str.47@PAGEOFF
	bl	_printf
	b	LBB1_9
LBB1_9:                                 ;   in Loop: Header=BB1_7 Depth=2
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_7
LBB1_10:                                ;   in Loop: Header=BB1_1 Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_11
LBB1_11:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_14
	b	LBB1_12
LBB1_12:                                ;   in Loop: Header=BB1_11 Depth=2
	adrp	x0, l_.str.48@PAGE
	add	x0, x0, l_.str.48@PAGEOFF
	bl	_printf
	b	LBB1_13
LBB1_13:                                ;   in Loop: Header=BB1_11 Depth=2
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_11
LBB1_14:                                ;   in Loop: Header=BB1_1 Depth=1
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_15
LBB1_15:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Loop Header: Depth=2
                                        ;       Child Loop BB1_17 Depth 3
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_25
	b	LBB1_16
LBB1_16:                                ;   in Loop: Header=BB1_15 Depth=2
	adrp	x8, _j@GOTPAGE
	ldr	x8, [x8, _j@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_17
LBB1_17:                                ;   Parent Loop BB1_1 Depth=1
                                        ;     Parent Loop BB1_15 Depth=2
                                        ; =>    This Inner Loop Header: Depth=3
	adrp	x8, _j@GOTPAGE
	ldr	x8, [x8, _j@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-16]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_20
	b	LBB1_18
LBB1_18:                                ;   in Loop: Header=BB1_17 Depth=3
	adrp	x0, l_.str.47@PAGE
	add	x0, x0, l_.str.47@PAGEOFF
	bl	_printf
	b	LBB1_19
LBB1_19:                                ;   in Loop: Header=BB1_17 Depth=3
	adrp	x9, _j@GOTPAGE
	ldr	x9, [x9, _j@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_17
LBB1_20:                                ;   in Loop: Header=BB1_15 Depth=2
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	cset	w8, ne
	tbnz	w8, #0, LBB1_22
	b	LBB1_21
LBB1_21:                                ;   in Loop: Header=BB1_15 Depth=2
	ldur	x8, [x29, #-8]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.49@PAGE
	add	x0, x0, l_.str.49@PAGEOFF
	bl	_printf
	b	LBB1_23
LBB1_22:                                ;   in Loop: Header=BB1_15 Depth=2
	ldur	x8, [x29, #-8]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.50@PAGE
	add	x0, x0, l_.str.50@PAGEOFF
	bl	_printf
	b	LBB1_23
LBB1_23:                                ;   in Loop: Header=BB1_15 Depth=2
	b	LBB1_24
LBB1_24:                                ;   in Loop: Header=BB1_15 Depth=2
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_15
LBB1_25:                                ;   in Loop: Header=BB1_1 Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_26
LBB1_26:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-16]
	add	w9, w9, #4
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_29
	b	LBB1_27
LBB1_27:                                ;   in Loop: Header=BB1_26 Depth=2
	adrp	x0, l_.str.47@PAGE
	add	x0, x0, l_.str.47@PAGEOFF
	bl	_printf
	b	LBB1_28
LBB1_28:                                ;   in Loop: Header=BB1_26 Depth=2
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_26
LBB1_29:                                ;   in Loop: Header=BB1_1 Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB1_30
LBB1_30:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_33
	b	LBB1_31
LBB1_31:                                ;   in Loop: Header=BB1_30 Depth=2
	adrp	x0, l_.str.48@PAGE
	add	x0, x0, l_.str.48@PAGEOFF
	bl	_printf
	b	LBB1_32
LBB1_32:                                ;   in Loop: Header=BB1_30 Depth=2
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_30
LBB1_33:                                ;   in Loop: Header=BB1_1 Depth=1
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	ldurb	w8, [x29, #-21]
	tbz	w8, #0, LBB1_46
	b	LBB1_34
LBB1_34:                                ;   in Loop: Header=BB1_1 Depth=1
	bl	_detect_arrow_key
	str	w0, [sp, #12]                   ; 4-byte Folded Spill
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_37
	b	LBB1_35
LBB1_35:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB1_40
	b	LBB1_36
LBB1_36:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	subs	w8, w8, #99
	cset	w8, eq
	tbnz	w8, #0, LBB1_43
	b	LBB1_44
LBB1_37:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #20]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	ldr	w8, [sp, #20]
	subs	w8, w8, #0
	cset	w8, ge
	tbnz	w8, #0, LBB1_39
	b	LBB1_38
LBB1_38:                                ;   in Loop: Header=BB1_1 Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB1_39
LBB1_39:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_45
LBB1_40:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	ldr	w8, [sp, #20]
	ldur	w9, [x29, #-12]
	subs	w9, w9, #1
	subs	w8, w8, w9
	cset	w8, le
	tbnz	w8, #0, LBB1_42
	b	LBB1_41
LBB1_41:                                ;   in Loop: Header=BB1_1 Depth=1
	str	wzr, [sp, #20]
	b	LBB1_42
LBB1_42:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_45
LBB1_43:                                ;   in Loop: Header=BB1_1 Depth=1
	mov	w8, #1                          ; =0x1
	strb	w8, [sp, #19]
	b	LBB1_45
LBB1_44:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_45
LBB1_45:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_58
LBB1_46:                                ;   in Loop: Header=BB1_1 Depth=1
	bl	_detect_arrow_key
	str	w0, [sp, #8]                    ; 4-byte Folded Spill
	subs	w8, w0, #2
	cset	w8, eq
	tbnz	w8, #0, LBB1_49
	b	LBB1_47
LBB1_47:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	subs	w8, w8, #3
	cset	w8, eq
	tbnz	w8, #0, LBB1_52
	b	LBB1_48
LBB1_48:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	subs	w8, w8, #99
	cset	w8, eq
	tbnz	w8, #0, LBB1_55
	b	LBB1_56
LBB1_49:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #20]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	ldr	w8, [sp, #20]
	subs	w8, w8, #0
	cset	w8, ge
	tbnz	w8, #0, LBB1_51
	b	LBB1_50
LBB1_50:                                ;   in Loop: Header=BB1_1 Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB1_51
LBB1_51:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_57
LBB1_52:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	ldr	w8, [sp, #20]
	ldur	w9, [x29, #-12]
	subs	w9, w9, #1
	subs	w8, w8, w9
	cset	w8, le
	tbnz	w8, #0, LBB1_54
	b	LBB1_53
LBB1_53:                                ;   in Loop: Header=BB1_1 Depth=1
	str	wzr, [sp, #20]
	b	LBB1_54
LBB1_54:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_57
LBB1_55:                                ;   in Loop: Header=BB1_1 Depth=1
	mov	w8, #1                          ; =0x1
	strb	w8, [sp, #19]
	b	LBB1_57
LBB1_56:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_57
LBB1_57:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_58
LBB1_58:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_1
LBB1_59:
	ldr	w0, [sp, #20]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_loadSettings                   ; -- Begin function loadSettings
	.p2align	2
_loadSettings:                          ; @loadSettings
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	adrp	x8, _settingsFileName@PAGE
	ldr	x0, [x8, _settingsFileName@PAGEOFF]
	adrp	x1, l_.str.55@PAGE
	add	x1, x1, l_.str.55@PAGEOFF
	bl	_fopen
	str	x0, [sp]
	ldr	x8, [sp]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_2
	b	LBB2_1
LBB2_1:
	adrp	x0, l_.str.56@PAGE
	add	x0, x0, l_.str.56@PAGEOFF
	bl	_printf
	ldr	x9, [sp, #8]
	mov	w8, #4                          ; =0x4
	str	w8, [x9, #4]
	ldr	x9, [sp, #8]
	mov	w8, #10000                      ; =0x2710
	str	w8, [x9]
	ldr	x9, [sp, #8]
	mov	w8, #20                         ; =0x14
	str	w8, [x9, #8]
	ldr	x0, [sp, #8]
	bl	_saveSettings
	b	LBB2_3
LBB2_2:
	ldr	x0, [sp, #8]
	ldr	x3, [sp]
	mov	x1, #12                         ; =0xc
	mov	x2, #1                          ; =0x1
	bl	_fread
	ldr	x0, [sp]
	bl	_fclose
	b	LBB2_3
LBB2_3:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_saveSettings                   ; -- Begin function saveSettings
	.p2align	2
_saveSettings:                          ; @saveSettings
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	adrp	x8, _settingsFileName@PAGE
	ldr	x0, [x8, _settingsFileName@PAGEOFF]
	adrp	x1, l_.str.53@PAGE
	add	x1, x1, l_.str.53@PAGEOFF
	bl	_fopen
	str	x0, [sp]
	ldr	x8, [sp]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_2
	b	LBB3_1
LBB3_1:
	adrp	x0, l_.str.54@PAGE
	add	x0, x0, l_.str.54@PAGEOFF
	bl	_perror
	b	LBB3_3
LBB3_2:
	ldr	x0, [sp, #8]
	ldr	x3, [sp]
	mov	x1, #12                         ; =0xc
	mov	x2, #1                          ; =0x1
	bl	_fwrite
	ldr	x0, [sp]
	bl	_fclose
	b	LBB3_3
LBB3_3:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printCard                      ; -- Begin function printCard
	.p2align	2
_printCard:                             ; @printCard
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	w0, [x29, #-24]
	stur	x1, [x29, #-32]
	str	x2, [sp, #40]
	ldur	w8, [x29, #-24]
	subs	w8, w8, #0
	cset	w8, lt
	tbnz	w8, #0, LBB4_2
	b	LBB4_1
LBB4_1:
	ldur	w8, [x29, #-24]
	subs	w8, w8, #5
	cset	w8, le
	tbnz	w8, #0, LBB4_3
	b	LBB4_2
LBB4_2:
	adrp	x0, l_.str.33@PAGE
	add	x0, x0, l_.str.33@PAGEOFF
	bl	_printf
	b	LBB4_62
LBB4_3:
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_4
LBB4_4:                                 ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_7
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_4 Depth=1
	adrp	x0, l_.str.34@PAGE
	add	x0, x0, l_.str.34@PAGEOFF
	bl	_printf
	b	LBB4_6
LBB4_6:                                 ;   in Loop: Header=BB4_4 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_4
LBB4_7:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_8
LBB4_8:                                 ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_18
	b	LBB4_9
LBB4_9:                                 ;   in Loop: Header=BB4_8 Depth=1
	ldr	x8, [sp, #40]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #88
	cset	w8, ne
	tbnz	w8, #0, LBB4_11
	b	LBB4_10
LBB4_10:                                ;   in Loop: Header=BB4_8 Depth=1
	adrp	x0, l_.str.36@PAGE
	add	x0, x0, l_.str.36@PAGEOFF
	bl	_printf
	b	LBB4_16
LBB4_11:                                ;   in Loop: Header=BB4_8 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w8, [x8, x9, lsl #2]
	subs	w8, w8, #1
	cset	w8, le
	tbnz	w8, #0, LBB4_14
	b	LBB4_12
LBB4_12:                                ;   in Loop: Header=BB4_8 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w8, [x8, x9, lsl #2]
	subs	w8, w8, #11
	cset	w8, ge
	tbnz	w8, #0, LBB4_14
	b	LBB4_13
LBB4_13:                                ;   in Loop: Header=BB4_8 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.37@PAGE
	add	x0, x0, l_.str.37@PAGEOFF
	bl	_printf
	b	LBB4_15
LBB4_14:                                ;   in Loop: Header=BB4_8 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w1, [x8, x9, lsl #2]
	add	x0, sp, #38
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	bl	_solveCardNumber
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.38@PAGE
	add	x0, x0, l_.str.38@PAGEOFF
	bl	_printf
	b	LBB4_15
LBB4_15:                                ;   in Loop: Header=BB4_8 Depth=1
	b	LBB4_16
LBB4_16:                                ;   in Loop: Header=BB4_8 Depth=1
	b	LBB4_17
LBB4_17:                                ;   in Loop: Header=BB4_8 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_8
LBB4_18:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_19
LBB4_19:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_22
	b	LBB4_20
LBB4_20:                                ;   in Loop: Header=BB4_19 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_21
LBB4_21:                                ;   in Loop: Header=BB4_19 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_19
LBB4_22:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_23
LBB4_23:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_26
	b	LBB4_24
LBB4_24:                                ;   in Loop: Header=BB4_23 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_25
LBB4_25:                                ;   in Loop: Header=BB4_23 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_23
LBB4_26:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_27
LBB4_27:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_30
	b	LBB4_28
LBB4_28:                                ;   in Loop: Header=BB4_27 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_29
LBB4_29:                                ;   in Loop: Header=BB4_27 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_27
LBB4_30:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_31
LBB4_31:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_34
	b	LBB4_32
LBB4_32:                                ;   in Loop: Header=BB4_31 Depth=1
	ldr	x8, [sp, #40]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldrsb	w1, [x8, x9]
	add	x0, sp, #32
	bl	_solveCardFace
	ldr	w9, [sp, #32]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.40@PAGE
	add	x0, x0, l_.str.40@PAGEOFF
	bl	_wprintf
	b	LBB4_33
LBB4_33:                                ;   in Loop: Header=BB4_31 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_31
LBB4_34:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_35
LBB4_35:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_38
	b	LBB4_36
LBB4_36:                                ;   in Loop: Header=BB4_35 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_37
LBB4_37:                                ;   in Loop: Header=BB4_35 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_35
LBB4_38:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_39
LBB4_39:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_42
	b	LBB4_40
LBB4_40:                                ;   in Loop: Header=BB4_39 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_41
LBB4_41:                                ;   in Loop: Header=BB4_39 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_39
LBB4_42:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_43
LBB4_43:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_46
	b	LBB4_44
LBB4_44:                                ;   in Loop: Header=BB4_43 Depth=1
	adrp	x0, l_.str.39@PAGE
	add	x0, x0, l_.str.39@PAGEOFF
	bl	_printf
	b	LBB4_45
LBB4_45:                                ;   in Loop: Header=BB4_43 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_43
LBB4_46:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_47
LBB4_47:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_57
	b	LBB4_48
LBB4_48:                                ;   in Loop: Header=BB4_47 Depth=1
	ldr	x8, [sp, #40]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #88
	cset	w8, ne
	tbnz	w8, #0, LBB4_50
	b	LBB4_49
LBB4_49:                                ;   in Loop: Header=BB4_47 Depth=1
	adrp	x0, l_.str.41@PAGE
	add	x0, x0, l_.str.41@PAGEOFF
	bl	_printf
	b	LBB4_55
LBB4_50:                                ;   in Loop: Header=BB4_47 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w8, [x8, x9, lsl #2]
	subs	w8, w8, #1
	cset	w8, le
	tbnz	w8, #0, LBB4_53
	b	LBB4_51
LBB4_51:                                ;   in Loop: Header=BB4_47 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w8, [x8, x9, lsl #2]
	subs	w8, w8, #11
	cset	w8, ge
	tbnz	w8, #0, LBB4_53
	b	LBB4_52
LBB4_52:                                ;   in Loop: Header=BB4_47 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.42@PAGE
	add	x0, x0, l_.str.42@PAGEOFF
	bl	_printf
	b	LBB4_54
LBB4_53:                                ;   in Loop: Header=BB4_47 Depth=1
	ldur	x8, [x29, #-32]
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldrsw	x9, [x9]
	ldr	w1, [x8, x9, lsl #2]
	add	x0, sp, #30
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	bl	_solveCardNumber
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.43@PAGE
	add	x0, x0, l_.str.43@PAGEOFF
	bl	_printf
	b	LBB4_54
LBB4_54:                                ;   in Loop: Header=BB4_47 Depth=1
	b	LBB4_55
LBB4_55:                                ;   in Loop: Header=BB4_47 Depth=1
	b	LBB4_56
LBB4_56:                                ;   in Loop: Header=BB4_47 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_47
LBB4_57:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	str	wzr, [x8]
	b	LBB4_58
LBB4_58:                                ; =>This Inner Loop Header: Depth=1
	adrp	x8, _i@GOTPAGE
	ldr	x8, [x8, _i@GOTPAGEOFF]
	ldr	w8, [x8]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB4_61
	b	LBB4_59
LBB4_59:                                ;   in Loop: Header=BB4_58 Depth=1
	adrp	x0, l_.str.44@PAGE
	add	x0, x0, l_.str.44@PAGEOFF
	bl	_printf
	b	LBB4_60
LBB4_60:                                ;   in Loop: Header=BB4_58 Depth=1
	adrp	x9, _i@GOTPAGE
	ldr	x9, [x9, _i@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB4_58
LBB4_61:
	adrp	x0, l_.str.35@PAGE
	add	x0, x0, l_.str.35@PAGEOFF
	bl	_printf
	b	LBB4_62
LBB4_62:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB4_64
	b	LBB4_63
LBB4_63:
	bl	___stack_chk_fail
LBB4_64:
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_getch                          ; -- Begin function getch
	.p2align	2
_getch:                                 ; @getch
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #208
	stp	x29, x30, [sp, #192]            ; 16-byte Folded Spill
	add	x29, sp, #192
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	mov	w0, #0                          ; =0x0
	str	w0, [sp, #20]                   ; 4-byte Folded Spill
	sub	x1, x29, #80
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	_tcgetattr
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	add	x0, sp, #40
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	mov	x2, #72                         ; =0x48
	bl	_memcpy
	ldr	x2, [sp, #8]                    ; 8-byte Folded Reload
	ldr	w1, [sp, #20]                   ; 4-byte Folded Reload
	ldr	x8, [sp, #64]
	mov	x9, #-265                       ; =0xfffffffffffffef7
	and	x8, x8, x9
	str	x8, [sp, #64]
	mov	x0, x1
	bl	_tcsetattr
	bl	_getchar
	ldr	w1, [sp, #20]                   ; 4-byte Folded Reload
	ldr	x2, [sp, #24]                   ; 8-byte Folded Reload
	strb	w0, [sp, #39]
	mov	x0, x1
	bl	_tcsetattr
	ldrsb	w8, [sp, #39]
	str	w8, [sp, #32]                   ; 4-byte Folded Spill
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB5_2
	b	LBB5_1
LBB5_1:
	bl	___stack_chk_fail
LBB5_2:
	ldr	w0, [sp, #32]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #192]            ; 16-byte Folded Reload
	add	sp, sp, #208
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_is_key_pressed                 ; -- Begin function is_key_pressed
	.p2align	2
_is_key_pressed:                        ; @is_key_pressed
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	sturb	w0, [x29, #-1]
	bl	_getch
	sturb	w0, [x29, #-2]
	ldursb	w0, [x29, #-2]
	bl	_toupper
	str	w0, [sp, #8]                    ; 4-byte Folded Spill
	ldursb	w0, [x29, #-1]
	bl	_toupper
	mov	x8, x0
	ldr	w0, [sp, #8]                    ; 4-byte Folded Reload
	subs	w8, w0, w8
	cset	w8, eq
	and	w0, w8, #0x1
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_detect_arrow_key               ; -- Begin function detect_arrow_key
	.p2align	2
_detect_arrow_key:                      ; @detect_arrow_key
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	bl	_getch
	sturb	w0, [x29, #-5]
	ldursb	w8, [x29, #-5]
	subs	w8, w8, #10
	cset	w8, eq
	tbnz	w8, #0, LBB7_2
	b	LBB7_1
LBB7_1:
	ldursb	w8, [x29, #-5]
	subs	w8, w8, #13
	cset	w8, ne
	tbnz	w8, #0, LBB7_3
	b	LBB7_2
LBB7_2:
	mov	w8, #99                         ; =0x63
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_3:
	ldursb	w8, [x29, #-5]
	subs	w8, w8, #27
	cset	w8, ne
	tbnz	w8, #0, LBB7_13
	b	LBB7_4
LBB7_4:
	bl	_getch
	sturb	w0, [x29, #-5]
	ldursb	w8, [x29, #-5]
	subs	w8, w8, #91
	cset	w8, ne
	tbnz	w8, #0, LBB7_12
	b	LBB7_5
LBB7_5:
	bl	_getch
	sturb	w0, [x29, #-5]
	ldursb	w8, [x29, #-5]
	subs	w8, w8, #65
	mov	w8, w8
                                        ; kill: def $x8 killed $w8
	str	x8, [sp]                        ; 8-byte Folded Spill
	subs	x8, x8, #3
	cset	w8, hi
	tbnz	w8, #0, LBB7_11
; %bb.6:
	ldr	x11, [sp]                       ; 8-byte Folded Reload
	adrp	x10, lJTI7_0@PAGE
	add	x10, x10, lJTI7_0@PAGEOFF
Ltmp1:
	adr	x8, Ltmp1
	ldrsw	x9, [x10, x11, lsl #2]
	add	x8, x8, x9
	br	x8
LBB7_7:
	stur	wzr, [x29, #-4]
	b	LBB7_15
LBB7_8:
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_9:
	mov	w8, #3                          ; =0x3
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_10:
	mov	w8, #2                          ; =0x2
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_11:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_12:
	b	LBB7_13
LBB7_13:
	b	LBB7_14
LBB7_14:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB7_15
LBB7_15:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
	.p2align	2
lJTI7_0:
	.long	LBB7_7-Ltmp1
	.long	LBB7_8-Ltmp1
	.long	LBB7_9-Ltmp1
	.long	LBB7_10-Ltmp1
                                        ; -- End function
	.globl	_clearScreen                    ; -- Begin function clearScreen
	.p2align	2
_clearScreen:                           ; @clearScreen
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str.30@PAGE
	add	x0, x0, l_.str.30@PAGEOFF
	bl	_system
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printTitle                     ; -- Begin function printTitle
	.p2align	2
_printTitle:                            ; @printTitle
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str.31@PAGE
	add	x0, x0, l_.str.31@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printSettings                  ; -- Begin function printSettings
	.p2align	2
_printSettings:                         ; @printSettings
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str.32@PAGE
	add	x0, x0, l_.str.32@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_solveCardNumber                ; -- Begin function solveCardNumber
	.p2align	2
_solveCardNumber:                       ; @solveCardNumber
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #4]
	subs	w8, w8, #11
	cset	w8, ne
	tbnz	w8, #0, LBB11_2
	b	LBB11_1
LBB11_1:
	mov	w8, #74                         ; =0x4a
	strb	w8, [sp]
	b	LBB11_12
LBB11_2:
	ldr	w8, [sp, #4]
	subs	w8, w8, #12
	cset	w8, ne
	tbnz	w8, #0, LBB11_4
	b	LBB11_3
LBB11_3:
	mov	w8, #81                         ; =0x51
	strb	w8, [sp]
	b	LBB11_11
LBB11_4:
	ldr	w8, [sp, #4]
	subs	w8, w8, #13
	cset	w8, ne
	tbnz	w8, #0, LBB11_6
	b	LBB11_5
LBB11_5:
	mov	w8, #75                         ; =0x4b
	strb	w8, [sp]
	b	LBB11_10
LBB11_6:
	ldr	w8, [sp, #4]
	subs	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB11_8
	b	LBB11_7
LBB11_7:
	mov	w8, #65                         ; =0x41
	strb	w8, [sp]
	b	LBB11_9
LBB11_8:
	adrp	x0, l_.str.51@PAGE
	add	x0, x0, l_.str.51@PAGEOFF
	bl	_printf
	b	LBB11_13
LBB11_9:
	b	LBB11_10
LBB11_10:
	b	LBB11_11
LBB11_11:
	b	LBB11_12
LBB11_12:
	mov	x1, sp
	strb	wzr, [sp, #1]
	ldr	x0, [sp, #8]
	mov	x2, #2                          ; =0x2
	mov	x3, #-1                         ; =0xffffffffffffffff
	bl	___memcpy_chk
	b	LBB11_13
LBB11_13:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_solveCardFace                  ; -- Begin function solveCardFace
	.p2align	2
_solveCardFace:                         ; @solveCardFace
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	sturb	w1, [x29, #-9]
	ldursb	w8, [x29, #-9]
	subs	w8, w8, #67
	mov	w8, w8
                                        ; kill: def $x8 killed $w8
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	subs	x8, x8, #21
	cset	w8, hi
	tbnz	w8, #0, LBB12_7
; %bb.1:
	ldr	x11, [sp, #8]                   ; 8-byte Folded Reload
	adrp	x10, lJTI12_0@PAGE
	add	x10, x10, lJTI12_0@PAGEOFF
Ltmp2:
	adr	x8, Ltmp2
	ldrsw	x9, [x10, x11, lsl #2]
	add	x8, x8, x9
	br	x8
LBB12_2:
	ldur	x9, [x29, #-8]
	mov	w8, #9824                       ; =0x2660
	str	w8, [x9]
	b	LBB12_8
LBB12_3:
	ldur	x9, [x29, #-8]
	mov	w8, #9829                       ; =0x2665
	str	w8, [x9]
	b	LBB12_8
LBB12_4:
	ldur	x9, [x29, #-8]
	mov	w8, #9830                       ; =0x2666
	str	w8, [x9]
	b	LBB12_8
LBB12_5:
	ldur	x9, [x29, #-8]
	mov	w8, #9827                       ; =0x2663
	str	w8, [x9]
	b	LBB12_8
LBB12_6:
	ldur	x9, [x29, #-8]
	mov	w8, #88                         ; =0x58
	str	w8, [x9]
	b	LBB12_8
LBB12_7:
	adrp	x0, l_.str.52@PAGE
	add	x0, x0, l_.str.52@PAGEOFF
	bl	_printf
	b	LBB12_8
LBB12_8:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
	.p2align	2
lJTI12_0:
	.long	LBB12_5-Ltmp2
	.long	LBB12_4-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_3-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_2-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_7-Ltmp2
	.long	LBB12_6-Ltmp2
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"PokerNight-Settings.dat"

	.section	__DATA,__data
	.globl	_settingsFileName               ; @settingsFileName
	.p2align	3, 0x0
_settingsFileName:
	.quad	l_.str

	.section	__TEXT,__cstring,cstring_literals
l_.str.1:                               ; @.str.1
	.asciz	"$"

	.section	__DATA,__data
	.globl	_currency                       ; @currency
	.p2align	3, 0x0
_currency:
	.quad	l_.str.1

	.section	__TEXT,__cstring,cstring_literals
l_.str.2:                               ; @.str.2
	.asciz	"8 Players"

	.section	__DATA,__data
	.globl	_maxPlayerText                  ; @maxPlayerText
	.p2align	3, 0x0
_maxPlayerText:
	.quad	l_.str.2

	.section	__TEXT,__cstring,cstring_literals
l_.str.3:                               ; @.str.3
	.asciz	"15 Seconds"

	.section	__DATA,__data
	.globl	_timeoutIntervalText            ; @timeoutIntervalText
	.p2align	3, 0x0
_timeoutIntervalText:
	.quad	l_.str.3

	.section	__TEXT,__cstring,cstring_literals
l_.str.4:                               ; @.str.4
	.asciz	"1M"

	.section	__DATA,__data
	.globl	_maxInitialMoneyText            ; @maxInitialMoneyText
	.p2align	3, 0x0
_maxInitialMoneyText:
	.quad	l_.str.4

	.section	__TEXT,__cstring,cstring_literals
l_.str.5:                               ; @.str.5
	.asciz	"High Card"

l_.str.6:                               ; @.str.6
	.asciz	"One Pair"

l_.str.7:                               ; @.str.7
	.asciz	"Two Pair"

l_.str.8:                               ; @.str.8
	.asciz	"Three of A Kind"

l_.str.9:                               ; @.str.9
	.asciz	"Straight"

l_.str.10:                              ; @.str.10
	.asciz	"Flush"

l_.str.11:                              ; @.str.11
	.asciz	"Full House"

l_.str.12:                              ; @.str.12
	.asciz	"Four of A Kind"

l_.str.13:                              ; @.str.13
	.asciz	"Straight Flush"

l_.str.14:                              ; @.str.14
	.asciz	"Royal Flush"

	.section	__DATA,__data
	.globl	_cardRanks                      ; @cardRanks
	.p2align	3, 0x0
_cardRanks:
	.quad	l_.str.5
	.quad	l_.str.6
	.quad	l_.str.7
	.quad	l_.str.8
	.quad	l_.str.9
	.quad	l_.str.10
	.quad	l_.str.11
	.quad	l_.str.12
	.quad	l_.str.13
	.quad	l_.str.14

	.section	__TEXT,__cstring,cstring_literals
l_.str.15:                              ; @.str.15
	.asciz	"Start Game"

l_.str.16:                              ; @.str.16
	.asciz	"Settings"

l_.str.17:                              ; @.str.17
	.asciz	"Exit"

	.section	__DATA,__data
	.globl	_menuOptions                    ; @menuOptions
	.p2align	3, 0x0
_menuOptions:
	.quad	l_.str.15
	.quad	l_.str.16
	.quad	l_.str.17

	.section	__TEXT,__const
	.globl	_menuSize                       ; @menuSize
	.p2align	2, 0x0
_menuSize:
	.long	3                               ; 0x3

	.section	__TEXT,__cstring,cstring_literals
l_.str.18:                              ; @.str.18
	.asciz	"Maximum Player"

l_.str.19:                              ; @.str.19
	.asciz	"Inital Money"

l_.str.20:                              ; @.str.20
	.asciz	"Timeout Interval"

l_.str.21:                              ; @.str.21
	.asciz	"< Back >"

	.section	__DATA,__data
	.globl	_settingOptions                 ; @settingOptions
	.p2align	3, 0x0
_settingOptions:
	.quad	l_.str.18
	.quad	l_.str.19
	.quad	l_.str.20
	.quad	l_.str.21

	.section	__TEXT,__const
	.globl	_settingSize                    ; @settingSize
	.p2align	2, 0x0
_settingSize:
	.long	4                               ; 0x4

	.section	__TEXT,__cstring,cstring_literals
l_.str.22:                              ; @.str.22
	.space	1

l_.str.23:                              ; @.str.23
	.asciz	"Unexpected error occured while in Runtime state, aborting..."

	.comm	_currentSettings,12,2           ; @currentSettings
l_.str.24:                              ; @.str.24
	.asciz	"                           Current: %d\n                           Maximum: %s"

l_.str.25:                              ; @.str.25
	.asciz	"Modify Settings"

l_.str.26:                              ; @.str.26
	.asciz	"Reset to Default"

	.section	__DATA,__const
	.p2align	3, 0x0                          ; @constinit
l_constinit:
	.quad	l_.str.25
	.quad	l_.str.26
	.quad	l_.str.21

	.section	__TEXT,__cstring,cstring_literals
l_.str.27:                              ; @.str.27
	.asciz	"Type the value: "

l_.str.28:                              ; @.str.28
	.asciz	"%d"

	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @constinit.29
l_constinit.29:
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6

	.section	__TEXT,__cstring,cstring_literals
l_.str.30:                              ; @.str.30
	.asciz	"clear"

l_.str.31:                              ; @.str.31
	.asciz	"              __| |____________________________________________________| |__\n              __   ____________________________________________________   __\n                | |                                                    | |  \n                | | ____       _               _   _ _       _     _   | |  \n                | ||  _ \\ ___ | | _____ _ __  | \\ | (_) __ _| |__ | |_ | |  \n                | || |_) / _ \\| |/ / _ \\ '__| |  \\| | |/ _` | '_ \\| __|| |  \n                | ||  __/ (_) |   <  __/ |    | |\\  | | (_| | | | | |_ | |  \n                | ||_|   \\___/|_|\\_\\___|_|    |_| \\_|_|\\__, |_| |_|\\__|| |  \n                | |                                    |___/           | |  \n              __| |____________________________________________________| |__\n              __   ____________________________________________________   __\n                | |                                                    | |  \n"

l_.str.32:                              ; @.str.32
	.asciz	"              __| |______________________________________| |__\n              __   ______________________________________   __\n                | |                                      | |  \n                | | ____       _   _   _                 | |  \n                | |/ ___|  ___| |_| |_(_)_ __   __ _ ___ | |  \n                | |\\___ \\ / _ \\ __| __| | '_ \\ / _` / __|| |  \n                | | ___) |  __/ |_| |_| | | | | (_| \\__ \\| |  \n                | ||____/ \\___|\\__|\\__|_|_| |_|\\__, |___/| |  \n                | |                            |___/     | |  \n              __| |______________________________________| |__\n              __   ______________________________________   __\n                | |                                      | |  \n"

l_.str.33:                              ; @.str.33
	.asciz	"Amount of card(s) exceed limit, only up to 5 were allowed."

	.comm	_i,4,2                          ; @i
l_.str.34:                              ; @.str.34
	.asciz	"\342\224\214\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\220    "

l_.str.35:                              ; @.str.35
	.asciz	"\n"

l_.str.36:                              ; @.str.36
	.asciz	"\342\224\202X            \342\224\202    "

l_.str.37:                              ; @.str.37
	.asciz	"\342\224\202%-2d           \342\224\202    "

l_.str.38:                              ; @.str.38
	.asciz	"\342\224\202%s            \342\224\202    "

l_.str.39:                              ; @.str.39
	.asciz	"\342\224\202             \342\224\202    "

	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @.str.40
l_.str.40:
	.long	9474                            ; 0x2502
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	37                              ; 0x25
	.long	108                             ; 0x6c
	.long	99                              ; 0x63
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	9474                            ; 0x2502
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	32                              ; 0x20
	.long	0                               ; 0x0

	.section	__TEXT,__cstring,cstring_literals
l_.str.41:                              ; @.str.41
	.asciz	"\342\224\202            X\342\224\202    "

l_.str.42:                              ; @.str.42
	.asciz	"\342\224\202           %2d\342\224\202    "

l_.str.43:                              ; @.str.43
	.asciz	"\342\224\202            %s\342\224\202    "

l_.str.44:                              ; @.str.44
	.asciz	"\342\224\224\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\230    "

l_.str.45:                              ; @.str.45
	.asciz	"\n\n\n"

l_.str.46:                              ; @.str.46
	.asciz	"%s\n\n\n"

l_.str.47:                              ; @.str.47
	.asciz	" "

l_.str.48:                              ; @.str.48
	.asciz	"-"

	.comm	_j,4,2                          ; @j
l_.str.49:                              ; @.str.49
	.asciz	"-> | %-20s |\n"

l_.str.50:                              ; @.str.50
	.asciz	"   | %-20s |\n"

l_.str.51:                              ; @.str.51
	.asciz	"Number of card exceed limit, 1 | 11 | 12 | 13 expected."

l_.str.52:                              ; @.str.52
	.asciz	"Card character not found, (S [Spades], H [Hearts], D [Diamonds], C [Clover], X [Conceal]) expected."

l_.str.53:                              ; @.str.53
	.asciz	"wb"

l_.str.54:                              ; @.str.54
	.asciz	"Error encountered while trying to save the settings file."

l_.str.55:                              ; @.str.55
	.asciz	"rb"

l_.str.56:                              ; @.str.56
	.asciz	"Settings file not found, creating a new one using default settings."

	.comm	_k,4,2                          ; @k
	.comm	_n,4,2                          ; @n
	.comm	_previousDealer,4,2             ; @previousDealer
.subsections_via_symbols
