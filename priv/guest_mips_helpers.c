
/*---------------------------------------------------------------*/
/*--- begin                              guest_mips_helpers.c ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of Valgrind, a dynamic binary instrumentation
   framework.

   Copyright (C) 2010-2013 RT-RK
      mips-valgrind@rt-rk.com

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#include "libvex_basictypes.h"
#include "libvex_emnote.h"
#include "libvex_guest_mips32.h"
#include "libvex_guest_mips64.h"
#include "libvex_ir.h"
#include "libvex.h"

#include "main_util.h"
#include "main_globals.h"
#include "guest_generic_bb_to_IR.h"
#include "guest_mips_defs.h"

/* This file contains helper functions for mips guest code.  Calls to
   these functions are generated by the back end.
*/

#define ALWAYSDEFD32(field)                           \
    { offsetof(VexGuestMIPS32State, field),            \
      (sizeof ((VexGuestMIPS32State*)0)->field) }

#define ALWAYSDEFD64(field)                            \
    { offsetof(VexGuestMIPS64State, field),            \
      (sizeof ((VexGuestMIPS64State*)0)->field) }

IRExpr *guest_mips32_spechelper(const HChar * function_name, IRExpr ** args,
                                IRStmt ** precedingStmts, Int n_precedingStmts)
{
   return NULL;
}

IRExpr *guest_mips64_spechelper ( const HChar * function_name, IRExpr ** args,
                                  IRStmt ** precedingStmts,
                                  Int n_precedingStmts )
{
   return NULL;
}

/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestMIPS32_initialise( /*OUT*/ VexGuestMIPS32State * vex_state)
{
   vex_state->guest_r0 = 0;   /* Hardwired to 0 */
   vex_state->guest_r1 = 0;   /* Assembler temporary */
   vex_state->guest_r2 = 0;   /* Values for function returns ... */
   vex_state->guest_r3 = 0;   /* ...and expression evaluation */
   vex_state->guest_r4 = 0;   /* Function arguments */
   vex_state->guest_r5 = 0;
   vex_state->guest_r6 = 0;
   vex_state->guest_r7 = 0;
   vex_state->guest_r8 = 0;   /* Temporaries */
   vex_state->guest_r9 = 0;
   vex_state->guest_r10 = 0;
   vex_state->guest_r11 = 0;
   vex_state->guest_r12 = 0;
   vex_state->guest_r13 = 0;
   vex_state->guest_r14 = 0;
   vex_state->guest_r15 = 0;
   vex_state->guest_r16 = 0;  /* Saved temporaries */
   vex_state->guest_r17 = 0;
   vex_state->guest_r18 = 0;
   vex_state->guest_r19 = 0;
   vex_state->guest_r20 = 0;
   vex_state->guest_r21 = 0;
   vex_state->guest_r22 = 0;
   vex_state->guest_r23 = 0;
   vex_state->guest_r24 = 0;  /* Temporaries */
   vex_state->guest_r25 = 0;
   vex_state->guest_r26 = 0;  /* Reserved for OS kernel */
   vex_state->guest_r27 = 0;
   vex_state->guest_r28 = 0;  /* Global pointer */
   vex_state->guest_r29 = 0;  /* Stack pointer */
   vex_state->guest_r30 = 0;  /* Frame pointer */
   vex_state->guest_r31 = 0;  /* Return address */
   vex_state->guest_PC = 0;   /* Program counter */
   vex_state->guest_HI = 0;   /* Multiply and divide register higher result */
   vex_state->guest_LO = 0;   /* Multiply and divide register lower result */

   /* FPU Registers */
   vex_state->guest_f0 = 0x7ff80000;   /* Floting point general purpose registers */
   vex_state->guest_f1 = 0x7ff80000;
   vex_state->guest_f2 = 0x7ff80000;
   vex_state->guest_f3 = 0x7ff80000;
   vex_state->guest_f4 = 0x7ff80000;
   vex_state->guest_f5 = 0x7ff80000;
   vex_state->guest_f6 = 0x7ff80000;
   vex_state->guest_f7 = 0x7ff80000;
   vex_state->guest_f8 = 0x7ff80000;
   vex_state->guest_f9 = 0x7ff80000;
   vex_state->guest_f10 = 0x7ff80000;
   vex_state->guest_f11 = 0x7ff80000;
   vex_state->guest_f12 = 0x7ff80000;
   vex_state->guest_f13 = 0x7ff80000;
   vex_state->guest_f14 = 0x7ff80000;
   vex_state->guest_f15 = 0x7ff80000;
   vex_state->guest_f16 = 0x7ff80000;
   vex_state->guest_f17 = 0x7ff80000;
   vex_state->guest_f18 = 0x7ff80000;
   vex_state->guest_f19 = 0x7ff80000;
   vex_state->guest_f20 = 0x7ff80000;
   vex_state->guest_f21 = 0x7ff80000;
   vex_state->guest_f22 = 0x7ff80000;
   vex_state->guest_f23 = 0x7ff80000;
   vex_state->guest_f24 = 0x7ff80000;
   vex_state->guest_f25 = 0x7ff80000;
   vex_state->guest_f26 = 0x7ff80000;
   vex_state->guest_f27 = 0x7ff80000;
   vex_state->guest_f28 = 0x7ff80000;
   vex_state->guest_f29 = 0x7ff80000;
   vex_state->guest_f30 = 0x7ff80000;
   vex_state->guest_f31 = 0x7ff80000;

   vex_state->guest_FIR = 0;  /* FP implementation and revision register */
   vex_state->guest_FCCR = 0; /* FP condition codes register */
   vex_state->guest_FEXR = 0; /* FP exceptions register */
   vex_state->guest_FENR = 0; /* FP enables register */
   vex_state->guest_FCSR = 0; /* FP control/status register */
   vex_state->guest_ULR = 0; /* TLS */

   /* Various pseudo-regs mandated by Vex or Valgrind. */
   /* Emulation notes */
   vex_state->guest_EMNOTE = 0;

   /* For clflush: record start and length of area to invalidate */
   vex_state->guest_TISTART = 0;
   vex_state->guest_TILEN = 0;
   vex_state->host_EvC_COUNTER = 0;
   vex_state->host_EvC_FAILADDR = 0;

   /* Used to record the unredirected guest address at the start of
      a translation whose start has been redirected. By reading
      this pseudo-register shortly afterwards, the translation can
      find out what the corresponding no-redirection address was.
      Note, this is only set for wrap-style redirects, not for
      replace-style ones. */
   vex_state->guest_NRADDR = 0;

   vex_state->guest_COND = 0;

   /* MIPS32 DSP ASE(r2) specific registers */
   vex_state->guest_DSPControl = 0;   /* DSPControl register */
   vex_state->guest_ac0 = 0;          /* Accumulator 0 */
   vex_state->guest_ac1 = 0;          /* Accumulator 1 */
   vex_state->guest_ac2 = 0;          /* Accumulator 2 */
   vex_state->guest_ac3 = 0;          /* Accumulator 3 */
}

void LibVEX_GuestMIPS64_initialise ( /*OUT*/ VexGuestMIPS64State * vex_state )
{
   vex_state->guest_r0 = 0;  /* Hardwired to 0 */
   vex_state->guest_r1 = 0;  /* Assembler temporary */
   vex_state->guest_r2 = 0;  /* Values for function returns ... */
   vex_state->guest_r3 = 0;
   vex_state->guest_r4 = 0;  /* Function arguments */
   vex_state->guest_r5 = 0;
   vex_state->guest_r6 = 0;
   vex_state->guest_r7 = 0;
   vex_state->guest_r8 = 0;
   vex_state->guest_r9 = 0;
   vex_state->guest_r10 = 0;
   vex_state->guest_r11 = 0;
   vex_state->guest_r12 = 0;  /* Temporaries */
   vex_state->guest_r13 = 0;
   vex_state->guest_r14 = 0;
   vex_state->guest_r15 = 0;
   vex_state->guest_r16 = 0;  /* Saved temporaries */
   vex_state->guest_r17 = 0;
   vex_state->guest_r18 = 0;
   vex_state->guest_r19 = 0;
   vex_state->guest_r20 = 0;
   vex_state->guest_r21 = 0;
   vex_state->guest_r22 = 0;
   vex_state->guest_r23 = 0;
   vex_state->guest_r24 = 0;  /* Temporaries */
   vex_state->guest_r25 = 0;
   vex_state->guest_r26 = 0;  /* Reserved for OS kernel */
   vex_state->guest_r27 = 0;
   vex_state->guest_r28 = 0;  /* Global pointer */
   vex_state->guest_r29 = 0;  /* Stack pointer */
   vex_state->guest_r30 = 0;  /* Frame pointer */
   vex_state->guest_r31 = 0;  /* Return address */
   vex_state->guest_PC = 0;   /* Program counter */
   vex_state->guest_HI = 0;   /* Multiply and divide register higher result */
   vex_state->guest_LO = 0;   /* Multiply and divide register lower result */

   /* FPU Registers */
   vex_state->guest_f0 = 0xffffffffffffffffULL;  /* Floting point registers */
   vex_state->guest_f1 = 0xffffffffffffffffULL;
   vex_state->guest_f2 = 0xffffffffffffffffULL;
   vex_state->guest_f3 = 0xffffffffffffffffULL;
   vex_state->guest_f4 = 0xffffffffffffffffULL;
   vex_state->guest_f5 = 0xffffffffffffffffULL;
   vex_state->guest_f6 = 0xffffffffffffffffULL;
   vex_state->guest_f7 = 0xffffffffffffffffULL;
   vex_state->guest_f8 = 0xffffffffffffffffULL;
   vex_state->guest_f9 = 0xffffffffffffffffULL;
   vex_state->guest_f10 = 0xffffffffffffffffULL;
   vex_state->guest_f11 = 0xffffffffffffffffULL;
   vex_state->guest_f12 = 0xffffffffffffffffULL;
   vex_state->guest_f13 = 0xffffffffffffffffULL;
   vex_state->guest_f14 = 0xffffffffffffffffULL;
   vex_state->guest_f15 = 0xffffffffffffffffULL;
   vex_state->guest_f16 = 0xffffffffffffffffULL;
   vex_state->guest_f17 = 0xffffffffffffffffULL;
   vex_state->guest_f18 = 0xffffffffffffffffULL;
   vex_state->guest_f19 = 0xffffffffffffffffULL;
   vex_state->guest_f20 = 0xffffffffffffffffULL;
   vex_state->guest_f21 = 0xffffffffffffffffULL;
   vex_state->guest_f22 = 0xffffffffffffffffULL;
   vex_state->guest_f23 = 0xffffffffffffffffULL;
   vex_state->guest_f24 = 0xffffffffffffffffULL;
   vex_state->guest_f25 = 0xffffffffffffffffULL;
   vex_state->guest_f26 = 0xffffffffffffffffULL;
   vex_state->guest_f27 = 0xffffffffffffffffULL;
   vex_state->guest_f28 = 0xffffffffffffffffULL;
   vex_state->guest_f29 = 0xffffffffffffffffULL;
   vex_state->guest_f30 = 0xffffffffffffffffULL;
   vex_state->guest_f31 = 0xffffffffffffffffULL;

   vex_state->guest_FIR = 0;   /* FP implementation and revision register */
   vex_state->guest_FCCR = 0;  /* FP condition codes register */
   vex_state->guest_FEXR = 0;  /* FP exceptions register */
   vex_state->guest_FENR = 0;  /* FP enables register */
   vex_state->guest_FCSR = 0;  /* FP control/status register */

   vex_state->guest_ULR = 0;

   /* Various pseudo-regs mandated by Vex or Valgrind. */
   /* Emulation notes */
   vex_state->guest_EMNOTE = 0;

   /* For clflush: record start and length of area to invalidate */
   vex_state->guest_TISTART = 0;
   vex_state->guest_TILEN = 0;
   vex_state->host_EvC_COUNTER = 0;
   vex_state->host_EvC_FAILADDR = 0;

   /* Used to record the unredirected guest address at the start of
      a translation whose start has been redirected. By reading
      this pseudo-register shortly afterwards, the translation can
      find out what the corresponding no-redirection address was.
      Note, this is only set for wrap-style redirects, not for
      replace-style ones. */
   vex_state->guest_NRADDR = 0;

   vex_state->guest_COND = 0;
}

/*-----------------------------------------------------------*/
/*--- Describing the mips guest state, for the benefit    ---*/
/*--- of iropt and instrumenters.                         ---*/
/*-----------------------------------------------------------*/

/* Figure out if any part of the guest state contained in minoff
   .. maxoff requires precise memory exceptions.  If in doubt return
   True (but this generates significantly slower code).

   We enforce precise exns for guest SP, PC.

   Only SP is needed in mode VexRegUpdSpAtMemAccess.
*/
Bool guest_mips32_state_requires_precise_mem_exns(Int minoff, Int maxoff)
{
   Int sp_min = offsetof(VexGuestMIPS32State, guest_r29);
   Int sp_max = sp_min + 4 - 1;
   Int pc_min = offsetof(VexGuestMIPS32State, guest_PC);
   Int pc_max = pc_min + 4 - 1;

   if (maxoff < sp_min || minoff > sp_max) {
      /* no overlap with sp */
      if (vex_control.iropt_register_updates == VexRegUpdSpAtMemAccess)
         return False;  /* We only need to check stack pointer. */
   } else {
      return True;
   }

   if (maxoff < pc_min || minoff > pc_max) {
      /* no overlap with pc */
   } else {
      return True;
   }

   /* We appear to need precise updates of R11 in order to get proper
      stacktraces from non-optimised code. */
   Int fp_min = offsetof(VexGuestMIPS32State, guest_r30);
   Int fp_max = fp_min + 4 - 1;

   if (maxoff < fp_min || minoff > fp_max) {
      /* no overlap with fp */
   } else {
      return True;
   }

   return False;
}

Bool guest_mips64_state_requires_precise_mem_exns ( Int minoff, Int maxoff )
{
   Int sp_min = offsetof(VexGuestMIPS64State, guest_r29);
   Int sp_max = sp_min + 8 - 1;
   Int pc_min = offsetof(VexGuestMIPS64State, guest_PC);
   Int pc_max = pc_min + 8 - 1;

   if ( maxoff < sp_min || minoff > sp_max ) {
      /* no overlap with sp */
      if (vex_control.iropt_register_updates == VexRegUpdSpAtMemAccess)
         return False;  /* We only need to check stack pointer. */
   } else {
      return True;
   }

   if ( maxoff < pc_min || minoff > pc_max ) {
      /* no overlap with pc */
   } else {
      return True;
   }

   Int fp_min = offsetof(VexGuestMIPS64State, guest_r30);
   Int fp_max = fp_min + 8 - 1;

   if ( maxoff < fp_min || minoff > fp_max ) {
      /* no overlap with fp */
   } else {
      return True;
   }

   return False;
}

VexGuestLayout mips32Guest_layout = {
   /* Total size of the guest state, in bytes. */
   .total_sizeB = sizeof(VexGuestMIPS32State),
   /* Describe the stack pointer. */
   .offset_SP = offsetof(VexGuestMIPS32State, guest_r29),
   .sizeof_SP = 4,
   /* Describe the frame pointer. */
   .offset_FP = offsetof(VexGuestMIPS32State, guest_r30),
   .sizeof_FP = 4,
   /* Describe the instruction pointer. */
   .offset_IP = offsetof(VexGuestMIPS32State, guest_PC),
   .sizeof_IP = 4,
   /* Describe any sections to be regarded by Memcheck as
      'always-defined'. */
   .n_alwaysDefd = 8,
   /* ? :(  */
   .alwaysDefd = {
             /* 0 */ ALWAYSDEFD32(guest_r0),
             /* 1 */ ALWAYSDEFD32(guest_r1),
             /* 2 */ ALWAYSDEFD32(guest_EMNOTE),
             /* 3 */ ALWAYSDEFD32(guest_TISTART),
             /* 4 */ ALWAYSDEFD32(guest_TILEN),
             /* 5 */ ALWAYSDEFD32(guest_r29),
             /* 6 */ ALWAYSDEFD32(guest_r31),
             /* 7 */ ALWAYSDEFD32(guest_ULR)
             }
};

VexGuestLayout mips64Guest_layout = {
   /* Total size of the guest state, in bytes. */
   .total_sizeB = sizeof(VexGuestMIPS64State),
   /* Describe the stack pointer. */
   .offset_SP = offsetof(VexGuestMIPS64State, guest_r29),
   .sizeof_SP = 8,
   /* Describe the frame pointer. */
   .offset_FP = offsetof(VexGuestMIPS64State, guest_r30),
   .sizeof_FP = 8,
   /* Describe the instruction pointer. */
   .offset_IP = offsetof(VexGuestMIPS64State, guest_PC),
   .sizeof_IP = 8,
   /* Describe any sections to be regarded by Memcheck as
      'always-defined'. */
   .n_alwaysDefd = 7,
   /* ? :(  */
   .alwaysDefd = {
                  /* 0 */ ALWAYSDEFD64 (guest_r0),
                  /* 1 */ ALWAYSDEFD64 (guest_EMNOTE),
                  /* 2 */ ALWAYSDEFD64 (guest_TISTART),
                  /* 3 */ ALWAYSDEFD64 (guest_TILEN),
                  /* 4 */ ALWAYSDEFD64 (guest_r29),
                  /* 5 */ ALWAYSDEFD64 (guest_r31),
                  /* 6 */ ALWAYSDEFD64 (guest_ULR)
                  }
};

#define ASM_VOLATILE_CASE(rd, sel) \
         case rd: \
            asm volatile ("mfc0 %0, $" #rd ", "#sel"\n\t" :"=r" (x) ); \
            break;

UInt mips32_dirtyhelper_mfc0(UInt rd, UInt sel)
{
   UInt x = 0;
#if defined(__mips__) && ((defined(__mips_isa_rev) && __mips_isa_rev >= 2))
   switch (sel) {
      case 0:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 0);
            ASM_VOLATILE_CASE(1, 0);
            ASM_VOLATILE_CASE(2, 0);
            ASM_VOLATILE_CASE(3, 0);
            ASM_VOLATILE_CASE(4, 0);
            ASM_VOLATILE_CASE(5, 0);
            ASM_VOLATILE_CASE(6, 0);
            ASM_VOLATILE_CASE(7, 0);
            ASM_VOLATILE_CASE(8, 0);
            ASM_VOLATILE_CASE(9, 0);
            ASM_VOLATILE_CASE(10, 0);
            ASM_VOLATILE_CASE(11, 0);
            ASM_VOLATILE_CASE(12, 0);
            ASM_VOLATILE_CASE(13, 0);
            ASM_VOLATILE_CASE(14, 0);
            ASM_VOLATILE_CASE(15, 0);
            ASM_VOLATILE_CASE(16, 0);
            ASM_VOLATILE_CASE(17, 0);
            ASM_VOLATILE_CASE(18, 0);
            ASM_VOLATILE_CASE(19, 0);
            ASM_VOLATILE_CASE(20, 0);
            ASM_VOLATILE_CASE(21, 0);
            ASM_VOLATILE_CASE(22, 0);
            ASM_VOLATILE_CASE(23, 0);
            ASM_VOLATILE_CASE(24, 0);
            ASM_VOLATILE_CASE(25, 0);
            ASM_VOLATILE_CASE(26, 0);
            ASM_VOLATILE_CASE(27, 0);
            ASM_VOLATILE_CASE(28, 0);
            ASM_VOLATILE_CASE(29, 0);
            ASM_VOLATILE_CASE(30, 0);
            ASM_VOLATILE_CASE(31, 0);
         default:
            break;
         }
         break;
      case 1:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 1);
            ASM_VOLATILE_CASE(1, 1);
            ASM_VOLATILE_CASE(2, 1);
            ASM_VOLATILE_CASE(3, 1);
            ASM_VOLATILE_CASE(4, 1);
            ASM_VOLATILE_CASE(5, 1);
            ASM_VOLATILE_CASE(6, 1);
            ASM_VOLATILE_CASE(7, 1);
            ASM_VOLATILE_CASE(8, 1);
            ASM_VOLATILE_CASE(9, 1);
            ASM_VOLATILE_CASE(10, 1);
            ASM_VOLATILE_CASE(11, 1);
            ASM_VOLATILE_CASE(12, 1);
            ASM_VOLATILE_CASE(13, 1);
            ASM_VOLATILE_CASE(14, 1);
            ASM_VOLATILE_CASE(15, 1);
            ASM_VOLATILE_CASE(16, 1);
            ASM_VOLATILE_CASE(17, 1);
            ASM_VOLATILE_CASE(18, 1);
            ASM_VOLATILE_CASE(19, 1);
            ASM_VOLATILE_CASE(20, 1);
            ASM_VOLATILE_CASE(21, 1);
            ASM_VOLATILE_CASE(22, 1);
            ASM_VOLATILE_CASE(23, 1);
            ASM_VOLATILE_CASE(24, 1);
            ASM_VOLATILE_CASE(25, 1);
            ASM_VOLATILE_CASE(26, 1);
            ASM_VOLATILE_CASE(27, 1);
            ASM_VOLATILE_CASE(28, 1);
            ASM_VOLATILE_CASE(29, 1);
            ASM_VOLATILE_CASE(30, 1);
            ASM_VOLATILE_CASE(31, 1);
         default:
            break;
         }
         break;
      case 2:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 2);
            ASM_VOLATILE_CASE(1, 2);
            ASM_VOLATILE_CASE(2, 2);
            ASM_VOLATILE_CASE(3, 1);
            ASM_VOLATILE_CASE(4, 2);
            ASM_VOLATILE_CASE(5, 2);
            ASM_VOLATILE_CASE(6, 2);
            ASM_VOLATILE_CASE(7, 2);
            ASM_VOLATILE_CASE(8, 2);
            ASM_VOLATILE_CASE(9, 2);
            ASM_VOLATILE_CASE(10, 2);
            ASM_VOLATILE_CASE(11, 2);
            ASM_VOLATILE_CASE(12, 2);
            ASM_VOLATILE_CASE(13, 2);
            ASM_VOLATILE_CASE(14, 2);
            ASM_VOLATILE_CASE(15, 2);
            ASM_VOLATILE_CASE(16, 2);
            ASM_VOLATILE_CASE(17, 2);
            ASM_VOLATILE_CASE(18, 2);
            ASM_VOLATILE_CASE(19, 2);
            ASM_VOLATILE_CASE(20, 2);
            ASM_VOLATILE_CASE(21, 2);
            ASM_VOLATILE_CASE(22, 2);
            ASM_VOLATILE_CASE(23, 2);
            ASM_VOLATILE_CASE(24, 2);
            ASM_VOLATILE_CASE(25, 2);
            ASM_VOLATILE_CASE(26, 2);
            ASM_VOLATILE_CASE(27, 2);
            ASM_VOLATILE_CASE(28, 2);
            ASM_VOLATILE_CASE(29, 2);
            ASM_VOLATILE_CASE(30, 2);
            ASM_VOLATILE_CASE(31, 2);
         default:
            break;
         }
         break;
      case 3:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 3);
            ASM_VOLATILE_CASE(1, 3);
            ASM_VOLATILE_CASE(2, 3);
            ASM_VOLATILE_CASE(3, 3);
            ASM_VOLATILE_CASE(4, 3);
            ASM_VOLATILE_CASE(5, 3);
            ASM_VOLATILE_CASE(6, 3);
            ASM_VOLATILE_CASE(7, 3);
            ASM_VOLATILE_CASE(8, 3);
            ASM_VOLATILE_CASE(9, 3);
            ASM_VOLATILE_CASE(10, 3);
            ASM_VOLATILE_CASE(11, 3);
            ASM_VOLATILE_CASE(12, 3);
            ASM_VOLATILE_CASE(13, 3);
            ASM_VOLATILE_CASE(14, 3);
            ASM_VOLATILE_CASE(15, 3);
            ASM_VOLATILE_CASE(16, 3);
            ASM_VOLATILE_CASE(17, 3);
            ASM_VOLATILE_CASE(18, 3);
            ASM_VOLATILE_CASE(19, 3);
            ASM_VOLATILE_CASE(20, 3);
            ASM_VOLATILE_CASE(21, 3);
            ASM_VOLATILE_CASE(22, 3);
            ASM_VOLATILE_CASE(23, 3);
            ASM_VOLATILE_CASE(24, 3);
            ASM_VOLATILE_CASE(25, 3);
            ASM_VOLATILE_CASE(26, 3);
            ASM_VOLATILE_CASE(27, 3);
            ASM_VOLATILE_CASE(28, 3);
            ASM_VOLATILE_CASE(29, 3);
            ASM_VOLATILE_CASE(30, 3);
            ASM_VOLATILE_CASE(31, 3);
         default:
            break;
         }
         break;
      case 4:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 4);
            ASM_VOLATILE_CASE(1, 4);
            ASM_VOLATILE_CASE(2, 4);
            ASM_VOLATILE_CASE(3, 4);
            ASM_VOLATILE_CASE(4, 4);
            ASM_VOLATILE_CASE(5, 4);
            ASM_VOLATILE_CASE(6, 4);
            ASM_VOLATILE_CASE(7, 4);
            ASM_VOLATILE_CASE(8, 4);
            ASM_VOLATILE_CASE(9, 4);
            ASM_VOLATILE_CASE(10, 4);
            ASM_VOLATILE_CASE(11, 4);
            ASM_VOLATILE_CASE(12, 4);
            ASM_VOLATILE_CASE(13, 4);
            ASM_VOLATILE_CASE(14, 4);
            ASM_VOLATILE_CASE(15, 4);
            ASM_VOLATILE_CASE(16, 4);
            ASM_VOLATILE_CASE(17, 4);
            ASM_VOLATILE_CASE(18, 4);
            ASM_VOLATILE_CASE(19, 4);
            ASM_VOLATILE_CASE(20, 4);
            ASM_VOLATILE_CASE(21, 4);
            ASM_VOLATILE_CASE(22, 4);
            ASM_VOLATILE_CASE(23, 4);
            ASM_VOLATILE_CASE(24, 4);
            ASM_VOLATILE_CASE(25, 4);
            ASM_VOLATILE_CASE(26, 4);
            ASM_VOLATILE_CASE(27, 4);
            ASM_VOLATILE_CASE(28, 4);
            ASM_VOLATILE_CASE(29, 4);
            ASM_VOLATILE_CASE(30, 4);
            ASM_VOLATILE_CASE(31, 4);
         default:
            break;
         }
         break;
      case 5:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 5);
            ASM_VOLATILE_CASE(1, 5);
            ASM_VOLATILE_CASE(2, 5);
            ASM_VOLATILE_CASE(3, 5);
            ASM_VOLATILE_CASE(4, 5);
            ASM_VOLATILE_CASE(5, 5);
            ASM_VOLATILE_CASE(6, 5);
            ASM_VOLATILE_CASE(7, 5);
            ASM_VOLATILE_CASE(8, 5);
            ASM_VOLATILE_CASE(9, 5);
            ASM_VOLATILE_CASE(10, 5);
            ASM_VOLATILE_CASE(11, 5);
            ASM_VOLATILE_CASE(12, 5);
            ASM_VOLATILE_CASE(13, 5);
            ASM_VOLATILE_CASE(14, 5);
            ASM_VOLATILE_CASE(15, 5);
            ASM_VOLATILE_CASE(16, 5);
            ASM_VOLATILE_CASE(17, 5);
            ASM_VOLATILE_CASE(18, 5);
            ASM_VOLATILE_CASE(19, 5);
            ASM_VOLATILE_CASE(20, 5);
            ASM_VOLATILE_CASE(21, 5);
            ASM_VOLATILE_CASE(22, 5);
            ASM_VOLATILE_CASE(23, 5);
            ASM_VOLATILE_CASE(24, 5);
            ASM_VOLATILE_CASE(25, 5);
            ASM_VOLATILE_CASE(26, 5);
            ASM_VOLATILE_CASE(27, 5);
            ASM_VOLATILE_CASE(28, 5);
            ASM_VOLATILE_CASE(29, 5);
            ASM_VOLATILE_CASE(30, 5);
            ASM_VOLATILE_CASE(31, 5);
         default:
            break;
         }
         break;
      case 6:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 6);
            ASM_VOLATILE_CASE(1, 6);
            ASM_VOLATILE_CASE(2, 6);
            ASM_VOLATILE_CASE(3, 6);
            ASM_VOLATILE_CASE(4, 6);
            ASM_VOLATILE_CASE(5, 6);
            ASM_VOLATILE_CASE(6, 6);
            ASM_VOLATILE_CASE(7, 6);
            ASM_VOLATILE_CASE(8, 6);
            ASM_VOLATILE_CASE(9, 6);
            ASM_VOLATILE_CASE(10, 6);
            ASM_VOLATILE_CASE(11, 6);
            ASM_VOLATILE_CASE(12, 6);
            ASM_VOLATILE_CASE(13, 6);
            ASM_VOLATILE_CASE(14, 6);
            ASM_VOLATILE_CASE(15, 6);
            ASM_VOLATILE_CASE(16, 6);
            ASM_VOLATILE_CASE(17, 6);
            ASM_VOLATILE_CASE(18, 6);
            ASM_VOLATILE_CASE(19, 6);
            ASM_VOLATILE_CASE(20, 6);
            ASM_VOLATILE_CASE(21, 6);
            ASM_VOLATILE_CASE(22, 6);
            ASM_VOLATILE_CASE(23, 6);
            ASM_VOLATILE_CASE(24, 6);
            ASM_VOLATILE_CASE(25, 6);
            ASM_VOLATILE_CASE(26, 6);
            ASM_VOLATILE_CASE(27, 6);
            ASM_VOLATILE_CASE(28, 6);
            ASM_VOLATILE_CASE(29, 6);
            ASM_VOLATILE_CASE(30, 6);
            ASM_VOLATILE_CASE(31, 6);
         default:
            break;
         }
         break;
      case 7:
         /* __asm__("mfc0 %0, $1, 0" :"=r" (x)); */
         switch (rd) {
            ASM_VOLATILE_CASE(0, 7);
            ASM_VOLATILE_CASE(1, 7);
            ASM_VOLATILE_CASE(2, 7);
            ASM_VOLATILE_CASE(3, 7);
            ASM_VOLATILE_CASE(4, 7);
            ASM_VOLATILE_CASE(5, 7);
            ASM_VOLATILE_CASE(6, 7);
            ASM_VOLATILE_CASE(7, 7);
            ASM_VOLATILE_CASE(8, 7);
            ASM_VOLATILE_CASE(9, 7);
            ASM_VOLATILE_CASE(10, 7);
            ASM_VOLATILE_CASE(11, 7);
            ASM_VOLATILE_CASE(12, 7);
            ASM_VOLATILE_CASE(13, 7);
            ASM_VOLATILE_CASE(14, 7);
            ASM_VOLATILE_CASE(15, 7);
            ASM_VOLATILE_CASE(16, 7);
            ASM_VOLATILE_CASE(17, 7);
            ASM_VOLATILE_CASE(18, 7);
            ASM_VOLATILE_CASE(19, 7);
            ASM_VOLATILE_CASE(20, 7);
            ASM_VOLATILE_CASE(21, 7);
            ASM_VOLATILE_CASE(22, 7);
            ASM_VOLATILE_CASE(23, 7);
            ASM_VOLATILE_CASE(24, 7);
            ASM_VOLATILE_CASE(25, 7);
            ASM_VOLATILE_CASE(26, 7);
            ASM_VOLATILE_CASE(27, 7);
            ASM_VOLATILE_CASE(28, 7);
            ASM_VOLATILE_CASE(29, 7);
            ASM_VOLATILE_CASE(30, 7);
            ASM_VOLATILE_CASE(31, 7);
         default:
            break;
         }
      break;

   default:
      break;
   }
#endif
   return x;
}

#undef ASM_VOLATILE_CASE

#define ASM_VOLATILE_CASE(rd, sel) \
         case rd: \
            asm volatile ("dmfc0 %0, $" #rd ", "#sel"\n\t" :"=r" (x) ); \
            break;

ULong mips64_dirtyhelper_dmfc0 ( UInt rd, UInt sel )
{
   ULong x = 0;
#if defined(VGP_mips64_linux)
   switch (sel) {
     case 0:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 0);
           ASM_VOLATILE_CASE (1, 0);
           ASM_VOLATILE_CASE (2, 0);
           ASM_VOLATILE_CASE (3, 0);
           ASM_VOLATILE_CASE (4, 0);
           ASM_VOLATILE_CASE (5, 0);
           ASM_VOLATILE_CASE (6, 0);
           ASM_VOLATILE_CASE (7, 0);
           ASM_VOLATILE_CASE (8, 0);
           ASM_VOLATILE_CASE (9, 0);
           ASM_VOLATILE_CASE (10, 0);
           ASM_VOLATILE_CASE (11, 0);
           ASM_VOLATILE_CASE (12, 0);
           ASM_VOLATILE_CASE (13, 0);
           ASM_VOLATILE_CASE (14, 0);
           ASM_VOLATILE_CASE (15, 0);
           ASM_VOLATILE_CASE (16, 0);
           ASM_VOLATILE_CASE (17, 0);
           ASM_VOLATILE_CASE (18, 0);
           ASM_VOLATILE_CASE (19, 0);
           ASM_VOLATILE_CASE (20, 0);
           ASM_VOLATILE_CASE (21, 0);
           ASM_VOLATILE_CASE (22, 0);
           ASM_VOLATILE_CASE (23, 0);
           ASM_VOLATILE_CASE (24, 0);
           ASM_VOLATILE_CASE (25, 0);
           ASM_VOLATILE_CASE (26, 0);
           ASM_VOLATILE_CASE (27, 0);
           ASM_VOLATILE_CASE (28, 0);
           ASM_VOLATILE_CASE (29, 0);
           ASM_VOLATILE_CASE (30, 0);
           ASM_VOLATILE_CASE (31, 0);
         default:
           break;
        }
        break;
     case 1:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 1);
           ASM_VOLATILE_CASE (1, 1);
           ASM_VOLATILE_CASE (2, 1);
           ASM_VOLATILE_CASE (3, 1);
           ASM_VOLATILE_CASE (4, 1);
           ASM_VOLATILE_CASE (5, 1);
           ASM_VOLATILE_CASE (6, 1);
           ASM_VOLATILE_CASE (7, 1);
           ASM_VOLATILE_CASE (8, 1);
           ASM_VOLATILE_CASE (9, 1);
           ASM_VOLATILE_CASE (10, 1);
           ASM_VOLATILE_CASE (11, 1);
           ASM_VOLATILE_CASE (12, 1);
           ASM_VOLATILE_CASE (13, 1);
           ASM_VOLATILE_CASE (14, 1);
           ASM_VOLATILE_CASE (15, 1);
           ASM_VOLATILE_CASE (16, 1);
           ASM_VOLATILE_CASE (17, 1);
           ASM_VOLATILE_CASE (18, 1);
           ASM_VOLATILE_CASE (19, 1);
           ASM_VOLATILE_CASE (20, 1);
           ASM_VOLATILE_CASE (21, 1);
           ASM_VOLATILE_CASE (22, 1);
           ASM_VOLATILE_CASE (23, 1);
           ASM_VOLATILE_CASE (24, 1);
           ASM_VOLATILE_CASE (25, 1);
           ASM_VOLATILE_CASE (26, 1);
           ASM_VOLATILE_CASE (27, 1);
           ASM_VOLATILE_CASE (28, 1);
           ASM_VOLATILE_CASE (29, 1);
           ASM_VOLATILE_CASE (30, 1);
           ASM_VOLATILE_CASE (31, 1);
        default:
           break;
        }
        break;
     case 2:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 2);
           ASM_VOLATILE_CASE (1, 2);
           ASM_VOLATILE_CASE (2, 2);
           ASM_VOLATILE_CASE (3, 1);
           ASM_VOLATILE_CASE (4, 2);
           ASM_VOLATILE_CASE (5, 2);
           ASM_VOLATILE_CASE (6, 2);
           ASM_VOLATILE_CASE (7, 2);
           ASM_VOLATILE_CASE (8, 2);
           ASM_VOLATILE_CASE (9, 2);
           ASM_VOLATILE_CASE (10, 2);
           ASM_VOLATILE_CASE (11, 2);
           ASM_VOLATILE_CASE (12, 2);
           ASM_VOLATILE_CASE (13, 2);
           ASM_VOLATILE_CASE (14, 2);
           ASM_VOLATILE_CASE (15, 2);
           ASM_VOLATILE_CASE (16, 2);
           ASM_VOLATILE_CASE (17, 2);
           ASM_VOLATILE_CASE (18, 2);
           ASM_VOLATILE_CASE (19, 2);
           ASM_VOLATILE_CASE (20, 2);
           ASM_VOLATILE_CASE (21, 2);
           ASM_VOLATILE_CASE (22, 2);
           ASM_VOLATILE_CASE (23, 2);
           ASM_VOLATILE_CASE (24, 2);
           ASM_VOLATILE_CASE (25, 2);
           ASM_VOLATILE_CASE (26, 2);
           ASM_VOLATILE_CASE (27, 2);
           ASM_VOLATILE_CASE (28, 2);
           ASM_VOLATILE_CASE (29, 2);
           ASM_VOLATILE_CASE (30, 2);
           ASM_VOLATILE_CASE (31, 2);
         default:
           break;
         }
         break;
     case 3:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 3);
           ASM_VOLATILE_CASE (1, 3);
           ASM_VOLATILE_CASE (2, 3);
           ASM_VOLATILE_CASE (3, 3);
           ASM_VOLATILE_CASE (4, 3);
           ASM_VOLATILE_CASE (5, 3);
           ASM_VOLATILE_CASE (6, 3);
           ASM_VOLATILE_CASE (7, 3);
           ASM_VOLATILE_CASE (8, 3);
           ASM_VOLATILE_CASE (9, 3);
           ASM_VOLATILE_CASE (10, 3);
           ASM_VOLATILE_CASE (11, 3);
           ASM_VOLATILE_CASE (12, 3);
           ASM_VOLATILE_CASE (13, 3);
           ASM_VOLATILE_CASE (14, 3);
           ASM_VOLATILE_CASE (15, 3);
           ASM_VOLATILE_CASE (16, 3);
           ASM_VOLATILE_CASE (17, 3);
           ASM_VOLATILE_CASE (18, 3);
           ASM_VOLATILE_CASE (19, 3);
           ASM_VOLATILE_CASE (20, 3);
           ASM_VOLATILE_CASE (21, 3);
           ASM_VOLATILE_CASE (22, 3);
           ASM_VOLATILE_CASE (23, 3);
           ASM_VOLATILE_CASE (24, 3);
           ASM_VOLATILE_CASE (25, 3);
           ASM_VOLATILE_CASE (26, 3);
           ASM_VOLATILE_CASE (27, 3);
           ASM_VOLATILE_CASE (28, 3);
           ASM_VOLATILE_CASE (29, 3);
           ASM_VOLATILE_CASE (30, 3);
           ASM_VOLATILE_CASE (31, 3);
        default:
           break;
        }
        break;
     case 4:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 4);
           ASM_VOLATILE_CASE (1, 4);
           ASM_VOLATILE_CASE (2, 4);
           ASM_VOLATILE_CASE (3, 4);
           ASM_VOLATILE_CASE (4, 4);
           ASM_VOLATILE_CASE (5, 4);
           ASM_VOLATILE_CASE (6, 4);
           ASM_VOLATILE_CASE (7, 4);
           ASM_VOLATILE_CASE (8, 4);
           ASM_VOLATILE_CASE (9, 4);
           ASM_VOLATILE_CASE (10, 4);
           ASM_VOLATILE_CASE (11, 4);
           ASM_VOLATILE_CASE (12, 4);
           ASM_VOLATILE_CASE (13, 4);
           ASM_VOLATILE_CASE (14, 4);
           ASM_VOLATILE_CASE (15, 4);
           ASM_VOLATILE_CASE (16, 4);
           ASM_VOLATILE_CASE (17, 4);
           ASM_VOLATILE_CASE (18, 4);
           ASM_VOLATILE_CASE (19, 4);
           ASM_VOLATILE_CASE (20, 4);
           ASM_VOLATILE_CASE (21, 4);
           ASM_VOLATILE_CASE (22, 4);
           ASM_VOLATILE_CASE (23, 4);
           ASM_VOLATILE_CASE (24, 4);
           ASM_VOLATILE_CASE (25, 4);
           ASM_VOLATILE_CASE (26, 4);
           ASM_VOLATILE_CASE (27, 4);
           ASM_VOLATILE_CASE (28, 4);
           ASM_VOLATILE_CASE (29, 4);
           ASM_VOLATILE_CASE (30, 4);
           ASM_VOLATILE_CASE (31, 4);
           default:
              break;
           }
        break;
     case 5:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 5);
           ASM_VOLATILE_CASE (1, 5);
           ASM_VOLATILE_CASE (2, 5);
           ASM_VOLATILE_CASE (3, 5);
           ASM_VOLATILE_CASE (4, 5);
           ASM_VOLATILE_CASE (5, 5);
           ASM_VOLATILE_CASE (6, 5);
           ASM_VOLATILE_CASE (7, 5);
           ASM_VOLATILE_CASE (8, 5);
           ASM_VOLATILE_CASE (9, 5);
           ASM_VOLATILE_CASE (10, 5);
           ASM_VOLATILE_CASE (11, 5);
           ASM_VOLATILE_CASE (12, 5);
           ASM_VOLATILE_CASE (13, 5);
           ASM_VOLATILE_CASE (14, 5);
           ASM_VOLATILE_CASE (15, 5);
           ASM_VOLATILE_CASE (16, 5);
           ASM_VOLATILE_CASE (17, 5);
           ASM_VOLATILE_CASE (18, 5);
           ASM_VOLATILE_CASE (19, 5);
           ASM_VOLATILE_CASE (20, 5);
           ASM_VOLATILE_CASE (21, 5);
           ASM_VOLATILE_CASE (22, 5);
           ASM_VOLATILE_CASE (23, 5);
           ASM_VOLATILE_CASE (24, 5);
           ASM_VOLATILE_CASE (25, 5);
           ASM_VOLATILE_CASE (26, 5);
           ASM_VOLATILE_CASE (27, 5);
           ASM_VOLATILE_CASE (28, 5);
           ASM_VOLATILE_CASE (29, 5);
           ASM_VOLATILE_CASE (30, 5);
           ASM_VOLATILE_CASE (31, 5);
           default:
              break;
        }
        break;
     case 6:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 6);
           ASM_VOLATILE_CASE (1, 6);
           ASM_VOLATILE_CASE (2, 6);
           ASM_VOLATILE_CASE (3, 6);
           ASM_VOLATILE_CASE (4, 6);
           ASM_VOLATILE_CASE (5, 6);
           ASM_VOLATILE_CASE (6, 6);
           ASM_VOLATILE_CASE (7, 6);
           ASM_VOLATILE_CASE (8, 6);
           ASM_VOLATILE_CASE (9, 6);
           ASM_VOLATILE_CASE (10, 6);
           ASM_VOLATILE_CASE (11, 6);
           ASM_VOLATILE_CASE (12, 6);
           ASM_VOLATILE_CASE (13, 6);
           ASM_VOLATILE_CASE (14, 6);
           ASM_VOLATILE_CASE (15, 6);
           ASM_VOLATILE_CASE (16, 6);
           ASM_VOLATILE_CASE (17, 6);
           ASM_VOLATILE_CASE (18, 6);
           ASM_VOLATILE_CASE (19, 6);
           ASM_VOLATILE_CASE (20, 6);
           ASM_VOLATILE_CASE (21, 6);
           ASM_VOLATILE_CASE (22, 6);
           ASM_VOLATILE_CASE (23, 6);
           ASM_VOLATILE_CASE (24, 6);
           ASM_VOLATILE_CASE (25, 6);
           ASM_VOLATILE_CASE (26, 6);
           ASM_VOLATILE_CASE (27, 6);
           ASM_VOLATILE_CASE (28, 6);
           ASM_VOLATILE_CASE (29, 6);
           ASM_VOLATILE_CASE (30, 6);
           ASM_VOLATILE_CASE (31, 6);
        default:
           break;
        }
        break;
     case 7:
        /* __asm__("dmfc0 %0, $1, 0" :"=r" (x)); */
        switch (rd) {
           ASM_VOLATILE_CASE (0, 7);
           ASM_VOLATILE_CASE (1, 7);
           ASM_VOLATILE_CASE (2, 7);
           ASM_VOLATILE_CASE (3, 7);
           ASM_VOLATILE_CASE (4, 7);
           ASM_VOLATILE_CASE (5, 7);
           ASM_VOLATILE_CASE (6, 7);
           ASM_VOLATILE_CASE (7, 7);
           ASM_VOLATILE_CASE (8, 7);
           ASM_VOLATILE_CASE (9, 7);
           ASM_VOLATILE_CASE (10, 7);
           ASM_VOLATILE_CASE (11, 7);
           ASM_VOLATILE_CASE (12, 7);
           ASM_VOLATILE_CASE (13, 7);
           ASM_VOLATILE_CASE (14, 7);
           ASM_VOLATILE_CASE (15, 7);
           ASM_VOLATILE_CASE (16, 7);
           ASM_VOLATILE_CASE (17, 7);
           ASM_VOLATILE_CASE (18, 7);
           ASM_VOLATILE_CASE (19, 7);
           ASM_VOLATILE_CASE (20, 7);
           ASM_VOLATILE_CASE (21, 7);
           ASM_VOLATILE_CASE (22, 7);
           ASM_VOLATILE_CASE (23, 7);
           ASM_VOLATILE_CASE (24, 7);
           ASM_VOLATILE_CASE (25, 7);
           ASM_VOLATILE_CASE (26, 7);
           ASM_VOLATILE_CASE (27, 7);
           ASM_VOLATILE_CASE (28, 7);
           ASM_VOLATILE_CASE (29, 7);
           ASM_VOLATILE_CASE (30, 7);
           ASM_VOLATILE_CASE (31, 7);
         default:
           break;
         }
       break;

     default:
       break;
     }
#endif
   return x;
}

#define ASM_VOLATILE_CASE(rd, sel) \
   case rd: asm volatile ("dmfc0 %0, $" #rd ", "#sel"\n\t" :"=r" (x) ); break;

#define ASM_VOLATILE_SYNC(stype) \
        asm volatile ("sync \n\t");

void mips32_dirtyhelper_sync(UInt stype)
{
#if defined(__mips__) && ((defined(__mips_isa_rev) && __mips_isa_rev >= 2))
   ASM_VOLATILE_SYNC(0);
#endif
}

#if defined(__mips__) && ((defined(__mips_isa_rev) && __mips_isa_rev >= 2))
ULong mips64_dirtyhelper_rdhwr ( ULong rt, ULong rd )
{
   ULong x = 0;
   switch (rd) {
      case 1:  /* x = SYNCI_StepSize() */
         __asm__ __volatile__("rdhwr %0, $1\n\t" : "=r" (x) );
         break;

      default:
         vassert(0);
         break;
   }
   return x;
}
#endif

/*---------------------------------------------------------------*/
/*--- end                                guest_mips_helpers.c ---*/
/*---------------------------------------------------------------*/
