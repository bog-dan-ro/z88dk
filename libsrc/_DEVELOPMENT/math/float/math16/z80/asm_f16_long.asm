;
;  Copyright (c) 2020 Phillip Stevens
;
;  This Source Code Form is subject to the terms of the Mozilla Public
;  License, v. 2.0. If a copy of the MPL was not distributed with this
;  file, You can obtain one at http://mozilla.org/MPL/2.0/.
;
;  feilipu, 2020 May
;
;-------------------------------------------------------------------------
;  asm_f24_long - z80 half floating to long
;-------------------------------------------------------------------------
;
;  unpacked format: sign in d[7], exponent in e, mantissa in hl
;  return normalized result also in unpacked format
;
;  return long in dehl
;
;-------------------------------------------------------------------------

SECTION code_fp_math16

EXTERN  l_neg_dehl

PUBLIC asm_f24_2long
PUBLIC asm_f24_2ulong

; Convert floating point number to long
.asm_f24_2long
.asm_f24_2ulong
    ld b,d                      ;Holds sign
    ld a,e                      ;Holds exponent
    and a
    jr Z,lzero                  ;exponent was 0, return 0
    cp $7e + 32
    jp NC,lmax                  ;number too large
    ld d,h                      ;place mantissa in long
    ld e,l
    ld h,0
    ld l,h
.lloop
    srl d                       ;fill with 0
    rr e
    rr h
    rr l
    inc a
    cp $7e + 32
    jr NZ,lloop
    rl b                        ;check sign bit
    call C,l_neg_dehl
    ret

.lzero
    ld de,0
    ld hl,0
    ret

.lmax
    ld de,0FFh
    ld hl,0FFh
    ret
