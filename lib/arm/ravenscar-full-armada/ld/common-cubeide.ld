/****************************************************************************
 *                                                                          *
 *                         GNAT COMPILER COMPONENTS                         *
 *                                                                          *
 *                                  A R M                                   *
 *                                                                          *
 *                            Linker Script File                            *
 *                                                                          *
 *      Copyright (C) 1999-2002 Universidad Politecnica de Madrid           *
 *             Copyright (C) 2003-2006 The European Space Agency            *
 *                   Copyright (C) 2003-2015 AdaCore                        *
 *                                                                          *
 * GNAT is free software;  you can  redistribute it  and/or modify it under *
 * terms of the  GNU General Public License as published  by the Free Soft- *
 * ware  Foundation;  either version 2,  or (at your option) any later ver- *
 * sion.  GNAT is distributed in the hope that it will be useful, but WITH- *
 * OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License *
 * for  more details.  You should have  received  a copy of the GNU General *
 * Public License  distributed with GNAT;  see file COPYING.  If not, write *
 * to  the  Free Software Foundation,  51  Franklin  Street,  Fifth  Floor, *
 * Boston, MA 02110-1301, USA.                                              *
 *                                                                          *
 * As a  special  exception,  if you  link  this file  with other  files to *
 * produce an executable,  this file does not by itself cause the resulting *
 * executable to be covered by the GNU General Public License. This except- *
 * ion does not  however invalidate  any other reasons  why the  executable *
 * file might be covered by the  GNU Public License.                        *
 *                                                                          *
 * GNARL was developed by the GNARL team at Florida State University.       *
 * Extensive contributions were provided by Ada Core Technologies, Inc.     *
 * The  executive  was developed  by the  Real-Time  Systems  Group  at the *
 * Technical University of Madrid.                                          *
 *                                                                          *
 ****************************************************************************/

/* This is a ARM specific version of this file */

/* This script replaces ld's default linker script, providing the
   appropriate memory map and output format. */

MEMORY
{
  FLASH    ( rx) : ORIGIN = 0x08000000, LENGTH = 1024K
  SRAM_CCM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
  SRAM     (rwx) : ORIGIN = 0x20010000, LENGTH = 240K
  SRAM_EXT (rw ) : ORIGIN = 0xC0000000, LENGTH = 4M
}

_DEFAULT_STACK_SIZE = 4*1024;
_INTERRUPT_STACK_SIZE = 1024;
_Min_Heap_Size = 0x800;      /* required amount of heap  */

ENTRY(_start_rom);
ENTRY(Reset_Handler);

SECTIONS
{
  /* The startup code goes first into FLASH */
  .interrupt_vector :
  {
    . = ALIGN(0x200);    /* 2^9 aligné pour y mettre le vecteur d'it */
    
    KEEP (*(.vectors))
    KEEP (*(.isr_vector)) /* Startup code */
    
  } > FLASH
  
  .text :
  {
    . = ALIGN(0x4);

    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)
    *(.gnu.linkonce.t*)
    *(.gnu.warning)
    
    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(0x4);
    _etext = .;        /* define a global symbols at end of code */
  } > FLASH

  .rodata :
  {
    . = ALIGN(0x4);
  
    *(.rodata)
    *(.rodata.*)   
    *(.lit)
    *(.gnu.linkonce.r*)
    
    . = ALIGN(0x4);
  } > FLASH

  .ARM.extab : 
  { 
     . = ALIGN(0x4);
     
     *(.ARM.extab*) 
     *(.gnu.linkonce.armextab.*) 
     
     . = ALIGN(0x4);
  } > FLASH
  
  .ARM : 
  {
     /* .ARM.exidx is 4-bytes aligned, so __exidx_start needs to be
     aligned too. Note that assigning the location counter also makes
     ld attach the following symbols to the next section (instead of the
     previous section which is the default), so will properly
     consider the location counter of .ARM.exidx for __exidx_start and
      __exidx_end and not the previous section's one. */
      
     . = ALIGN(0x4);
     
     PROVIDE_HIDDEN (__exidx_start = .);
     *(.ARM.exidx*)
     *(.gnu.linkonce.armexidx.*)
     PROVIDE_HIDDEN (__exidx_end = .);
     
     . = ALIGN(0x4);
  } > FLASH

  .preinit_array     :
  {
    . = ALIGN(0x4);
    
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    
    . = ALIGN(0x4);
  } > FLASH
  
  .init_array :
  {
    . = ALIGN(0x4);
    
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
    
    . = ALIGN(0x4);
  } > FLASH
  
  .fini_array :
  {
    . = ALIGN(0x4);
    
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    
    . = ALIGN(0x4);
    __rom_end = .;
  } > FLASH
  
  .app_stack (NOLOAD) :
  {
    . = ALIGN(0x8);
    _stack_start = .;
    
    . += _DEFAULT_STACK_SIZE;
    *(.app_stacks)
    
    . = ALIGN(0x8);
    _stack_end = .;
    _estack = _stack_end;
  } > SRAM_CCM
  
  .interrupt_stack (NOLOAD) :
  {
    . = ALIGN(0x8);
    _interrupt_stack_start = .;
    
    . += _INTERRUPT_STACK_SIZE;
    *(.interrupt_stacks)
    
    . = ALIGN(0x8);
    _interrupt_stack_end = .;
  } > SRAM_CCM
  
  .ram_vector_table :
  {
    . = ALIGN(0x200);          /* 2^9 aligné pour y mettre le vecteur d'it */
    _svector_table = .;        /* create a global symbol at vector_table start */
    
    *(.ccmdata)
    *(.ccmdata.*)
    _evector_table = .;        /* create a global symbol at vector_table end */
  } > SRAM_CCM AT> FLASH
  _sivector_table = LOADADDR(.ram_vector_table);
  __vector_table_words = (_evector_table - _svector_table) >> 2;
    
  .data :
  {
    . = ALIGN(0x4);
    __data_start = .;
    _sdata = .;        /* create a global symbol at data start */
    
    *(.data)
    *(.data.*)
    *(.gnu.linkonce.d*)

    /* Ensure that the end of the data section is always word aligned.
       Initial values are stored in 4-bytes blocks so we must guarantee
       that these blocks do not fall out the section (otherwise they are
       truncated and the initial data for the last block are lost). */

    . = ALIGN(0x4);
    __data_end = .;
    _edata = .;        /* define a global symbol at data end */
  } > SRAM AT> FLASH
  _sidata = LOADADDR(.data);
  __data_words = (__data_end - __data_start) >> 2;

  .bss (NOLOAD): 
  {
   . = ALIGN(0x4);
   _sbss = .;         /* define a global symbol at bss start */
   __bss_start__ = _sbss;

   *(.bss)
   *(.bss.*)
   *(COMMON)

   . = ALIGN(0x4);    /* Align data to 32 bits */
   _ebss = .;         /* define a global symbol at bss end */
   __bss_end__ = _ebss;
   
  } > SRAM
  __bss_words = (__bss_end__ - __bss_start__) >> 2;
  
  .heap_stack :
  {
   . = ALIGN(0x4);
   PROVIDE ( end = . );
   PROVIDE ( _end = . );
   __heap_start = .;

   . = . + _Min_Heap_Size;
   . = ORIGIN(SRAM) + LENGTH(SRAM) - 0x4;

   __heap_end = ORIGIN(SRAM) + LENGTH(SRAM);

  } > SRAM

  /*__heap_start = 0xC007F800;
  __heap_end = 0xC0400000-1;
  _legacysram_start = 0xC007F800;
  _lv_mem_addr = 0xC007F800;*/

  .sdram (NOLOAD): 
  {
      . = ALIGN(0x4);
      *(.framebuffer)
      
      . = ALIGN(0x4);
      *(.sdram)
      *(.sdram.*)
  } > SRAM_EXT

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}
