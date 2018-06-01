/*
 * Copyright (c) 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef CPU_SPARC_GC_SHARED_BARRIERSETASSEMBLER_SPARC_HPP
#define CPU_SPARC_GC_SHARED_BARRIERSETASSEMBLER_SPARC_HPP

#include "asm/macroAssembler.hpp"
#include "memory/allocation.hpp"
#include "oops/access.hpp"

class InterpreterMacroAssembler;

class BarrierSetAssembler: public CHeapObj<mtGC> {
public:
  virtual void arraycopy_prologue(MacroAssembler* masm, DecoratorSet decorators, BasicType type,
                                  Register src, Register dst, Register count) {}
  virtual void arraycopy_epilogue(MacroAssembler* masm, DecoratorSet decorators, BasicType type,
                                  Register src, Register dst, Register count) {}

  virtual void store_at(MacroAssembler* masm, DecoratorSet decorators, BasicType type,
                        Register src, Address dst, Register tmp);

  virtual void load_at(MacroAssembler* masm, DecoratorSet decorators, BasicType type,
                       Address src, Register dst, Register tmp);

  // Support for jniFastGetField to try resolving a jobject/jweak in native
  virtual void try_resolve_jobject_in_native(MacroAssembler* masm, Register robj, Register tmp, Label& slowpath);

  virtual void barrier_stubs_init() {}
};

#endif // CPU_SPARC_GC_SHARED_BARRIERSETASSEMBLER_SPARC_HPP
