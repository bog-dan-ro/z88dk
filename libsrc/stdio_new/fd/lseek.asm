; CALLER linkage for function pointers

XLIB lseek

LIB lseek_callee
XREF ASMDISP_LSEEK_CALLEE

.lseek

   pop af
   pop bc
   pop de
   pop hl
   exx
   pop hl
   push hl
   push hl
   push hl
   push hl
   push af
   
   jp lseek_callee + ASMDISP_LSEEK_CALLEE
