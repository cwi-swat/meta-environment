#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2001  Stichting Mathematisch Centrum,
#                        Amsterdam, The Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or (at
#    your option) any later version.
#
#    This program is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
#    USA

INCLUDES		= -I$(ASC_SUPPORT)/include                           -I$(PT_SUPPORT)/include                           -I$(ATERM)/include                           -I$(ASF_SUPPORT)/include

LDFLAGS			= -L${ASC_SUPPORT}/lib                           -L${PT_SUPPORT}/lib                           -L${ASF_SUPPORT}/lib                           -L${ATERM}/lib

LDLIBS          	= -lasc-support-me -lmept -lATerm

noinst_LIBRARIES	= libCompiler.a

bin_PROGRAMS		= Compiler

Compiler_SOURCES		= init.c
Compiler_LDADD		= libCompiler.a ${LDLIBS} ${SOCKLIBS}

libCompiler_a_SOURCES	= $(SPEC_SRCS)
libCompiler_a_LIBADD	= init.o

# Old versions of automake put all dependencies on a single line which
# causes several tools to crash (sed for instance) because of line length
# limitations. We therefore split all dependencies and define them among
# several SPEC_SRCSx variables. These are all combined in SPEC_SRCS which
# forms the concatenation of all sub varibales ( SPEC_SRCS = $(SPEC_SRCS1)
# ... $(SPEC_SRCSn)
#
SPEC_SRCS1=\
   Compiler.c

SPEC_SRCS = $(SPEC_SRCS1)

init.c: $(SPEC_SRCS) Makefile
	@(echo "/*GENERATED AUTOMATICALLY, DO NOT MODIFY */" ;\
	SPEC_SRCS="$(SPEC_SRCS)" ;\
	for file in $$SPEC_SRCS; do \
		echo "extern void register_$$file();" ;\
		echo "extern void resolve_$$file();" ;\
		echo "extern void init_$$file();" ;\
	done ;\
	echo "void register_all() {" ;\
	for file in $$SPEC_SRCS; do \
		echo "  register_$$file();" ;\
	done ;\
	echo "}" ;\
	echo "void resolve_all() {" ;\
	for file in $$SPEC_SRCS; do \
		echo "  resolve_$$file();" ;\
	done ;\
	echo "}" ;\
	echo "void init_all() {" ;\
	for file in $$SPEC_SRCS; do \
		echo "  init_$$file();" ;\
	done ;\
	echo "}" ) | sed 's/.c()/()/g;s/-/_/g;' > $@
