
/*---------------------------------------------------------------*/
/*---                                                         ---*/
/*--- This file (guest-arm/gdefs.h) is                        ---*/
/*--- Copyright (c) 2004 OpenWorks LLP.  All rights reserved. ---*/
/*---                                                         ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of LibVEX, a library for dynamic binary
   instrumentation and translation.

   Copyright (C) 2004 OpenWorks, LLP.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; Version 2 dated June 1991 of the
   license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or liability
   for damages.  See the GNU General Public License for more details.

   Neither the names of the U.S. Department of Energy nor the
   University of California nor the names of its contributors may be
   used to endorse or promote products derived from this software
   without prior written permission.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA.
*/

/* Only to be used within the guest-arm directory. */


#ifndef __LIBVEX_GUEST_ARM_DEFS_H
#define __LIBVEX_GUEST_ARM_DEFS_H


/*---------------------------------------------------------*/
/*--- arm to IR conversion                              ---*/
/*---------------------------------------------------------*/

extern
IRBB* bbToIR_ARM ( UChar* armCode, 
                   Addr64 eip, 
                   Int*   guest_bytes_read, 
                   Bool   (*byte_accessible)(Addr64),
                   Bool   (*resteerOkFn)(Addr64),
                   Bool   host_bigendian );

/* Used by the optimiser to specialise calls to helpers. */
extern
IRExpr* guest_arm_spechelper ( Char* function_name,
                               IRExpr** args );

/* Describes to the optimser which part of the guest state require
   precise memory exceptions.  This is logically part of the guest
   state description. */
extern 
Bool guest_arm_state_requires_precise_mem_exns ( Int, Int );

extern
VexGuestLayout armGuest_layout;


/*---------------------------------------------------------*/
/*--- arm guest helpers                                 ---*/
/*---------------------------------------------------------*/

/* --- CLEAN HELPERS --- */

extern UInt  armg_calculate_flags_all ( 
                UInt cc_op, UInt cc_dep1, UInt cc_dep2 
             );

extern UInt  armg_calculate_condition ( 
                UInt/*ARMCondcode*/ cond, 
                UInt cc_op, 
                UInt cc_dep1, UInt cc_dep2 
             );


/*---------------------------------------------------------*/
/*--- Condition code stuff                              ---*/
/*---------------------------------------------------------*/

/* Flags masks.  Defines positions of flags bits in the CPSR. */
#define ARMG_CC_SHIFT_N  31
#define ARMG_CC_SHIFT_Z  30
#define ARMG_CC_SHIFT_C  29
#define ARMG_CC_SHIFT_V  28

#define ARMG_CC_MASK_N    (1 << ARMG_CC_SHIFT_N)
#define ARMG_CC_MASK_Z    (1 << ARMG_CC_SHIFT_Z)
#define ARMG_CC_MASK_V    (1 << ARMG_CC_SHIFT_V)
#define ARMG_CC_MASK_C    (1 << ARMG_CC_SHIFT_C)

/* Flag thunk descriptors.  A three-word thunk is used to record
   details of the most recent flag-setting operation, so the flags can
   be computed later if needed.

   The three words are:

      CC_OP, which describes the operation.

      CC_DEP1 and CC_DEP2.  These are arguments to the operation.
         We want Memcheck to believe that the resulting flags are
         data-dependent on both CC_DEP1 and CC_DEP2, hence the 
         name DEP.

   When building the thunk, it is always necessary to write words into
   CC_DEP1 and CC_DEP2, even if those args are not used given the
   CC_OP field.  This is important because otherwise Memcheck could
   give false positives as it does not understand the relationship
   between the CC_OP field and CC_DEP1 and CC_DEP2, and so believes
   that the definedness of the stored flags always depends on both
   CC_DEP1 and CC_DEP2.

   A summary of the field usages is:
   TODO: make this right

   Operation          DEP1               DEP2               NDEP
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   add/sub/mul        first arg          second arg         unused

   adc/sbb            first arg          (second arg)
                                         XOR old_carry      old_carry

   and/or/xor         result             zero               unused

   inc/dec            result             zero               old_carry

   shl/shr/sar        result             subshifted-        unused
                                         result

   rol/ror            result             zero               old_flags

   copy               old_flags          zero               unused.


   Therefore Memcheck will believe the following:

   * add/sub/mul -- definedness of result flags depends on definedness
     of both args.

     etc etc
*/
enum {
    ARMG_CC_OP_COPY,    /* DEP1 = current flags, DEP2 = 0 */
                        /* just copy DEP1 to output */

    ARMG_CC_OP_MOV,

    ARMG_CC_OP_LSL,     /* DEP1 = first arg, DEP2 = second arg */
    ARMG_CC_OP_LSR,
    ARMG_CC_OP_ASR,
    ARMG_CC_OP_ROR,


    ARMG_CC_OP_NUMBER
};

/* requires further study */



/* Defines conditions which we can ask for (ARM ARM 2e page A3-6) */

typedef
   enum {
      ARMCondEQ     = 0,  /* equal                               : Z=1 */
      ARMCondNE     = 1,  /* not equal                           : Z=0 */

      ARMCondHS     = 2,  /* >=u (higher or same)                : C=1 */
      ARMCondLO     = 3,  /* <u  (lower)                         : C=0 */

      ARMCondMI     = 4,  /* minus (negative)                    : N=1 */
      ARMCondPL     = 5,  /* plus (zero or +ve)                  : N=0 */

      ARMCondVS     = 6,  /* overflow                            : V=1 */
      ARMCondVC     = 7,  /* no overflow                         : V=0 */

      ARMCondHI     = 8,  /* >u   (higher)                       : C=1 && Z=0 */
      ARMCondLS     = 9,  /* <=u  (lower or same)                : C=0 || Z=1 */

      ARMCondGE     = 10, /* >=s (signed greater or equal)       : N=V */
      ARMCondLT     = 11, /* <s  (signed less than)              : N!=V */

      ARMCondGT     = 12, /* >s  (signed greater)                : Z=0 && N=V */
      ARMCondLE     = 13, /* <=s (signed less or equal)          : Z=1 || N!=V */

      ARMCondAL     = 14, /* always (unconditional)              : */
      ARMCondNV     = 15  /* never (basically undefined meaning) : */
                          /* NB: ARM have deprecated the use of the NV condition code
                             - you are now supposed to use MOV R0,R0 as a noop
                               rather than MOVNV R0,R0 as was previously recommended.
                             Future processors may have the NV condition code reused to do other things.  */
   }
   ARMCondcode;

#endif /* ndef __LIBVEX_GUEST_ARM_DEFS_H */

/*---------------------------------------------------------------*/
/*--- end                                   guest-arm/gdefs.h ---*/
/*---------------------------------------------------------------*/