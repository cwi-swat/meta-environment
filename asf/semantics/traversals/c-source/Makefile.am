#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum,
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

INCLUDES         = -I$(ASCINC)                    -I$(ASFIXINC)                    -I$(ATERMINC)

noinst_LIBRARIES = libTraversals.a

BUILT_SOURCES    = init.c

libTraversals_a_SOURCES  = $(SPEC_SRCS)

libTraversals_a_LIBADD   = init.o

# Old versions of automake put all dependencies on a single line which
# causes several tools to crash (sed for instance) because of line length
# limitations. We therefore split all dependencies and define them among
# several SPEC_SRCSx variables. These are all combined in SPEC_SRCS which
# forms the concatenation of all sub varibales ( SPEC_SRCS = $(SPEC_SRCS1)
# ... $(SPEC_SRCSn)
#
SPEC_SRCS1=\
   AUX-Character-Syntax1.c AUX-Layout1.c AUX-RealCon1.c AUX-Symbols1.c\
   AUX-Grammar-Syntax1.c AUX-Renaming-Sdf-Syntax1.c AUX-IntCon1.c\
   AUX-Character-Class-Syntax1.c AUX-Literals1.c AUX-ATerms1.c\
   AUX-Kernel-Sdf-Syntax1.c AUX-Basic-Sdf-Syntax1.c AUX-Modular-Sdf-Syntax1.c\
   AUX-Regular-Sdf-Syntax1.c AUX-Priority-Sdf-Syntax1.c AUX-CC-Sdf-Syntax1.c\
   AUX-Sorts-Sdf-Syntax1.c AUX-Literals-Sdf-Syntax1.c AUX-Label-Sdf-Syntax1.c\
   AUX-Restrictions-Sdf-Syntax1.c AUX-Alias-Sdf-Syntax1.c\
   AUX-Sdf2-Syntax1.c AUX-Sdf21.c AUX-Traversals-Closure9.c\
   AUX-Traversals-Closure8.c AUX-Traversals-Closure7.c\
   AUX-Traversals-Closure6.c AUX-Traversals-Closure5.c\
   AUX-Traversals-Closure4.c AUX-Traversals-Closure3.c\
   AUX-Traversals-Closure2.c AUX-Traversals-Closure1.c\
   AUX-Traversals-Utils1.c AUX-Traversals-Collect17.c\
   AUX-Traversals-Collect16.c AUX-Traversals-Collect15.c\
   AUX-Traversals-Collect14.c AUX-Traversals-Collect13.c\
   AUX-Traversals-Collect12.c AUX-Traversals-Collect11.c\
   AUX-Traversals-Collect10.c AUX-Traversals-Collect9.c\
   AUX-Traversals-Collect8.c AUX-Traversals-Collect7.c\
   AUX-Traversals-Collect6.c AUX-Traversals-Collect5.c\
   AUX-Traversals-Collect4.c AUX-Traversals-Collect3.c\
   AUX-Traversals-Collect2.c AUX-Traversals-Collect1.c\
   AUX-Traversals-Remove6.c AUX-Traversals-Remove5.c AUX-Traversals-Remove4.c\
   AUX-Traversals-Remove3.c AUX-Traversals-Remove2.c AUX-Traversals-Remove1.c\
   AUX-Traversals-Add3.c AUX-Traversals-Add2.c AUX-Traversals-Add1.c\
   AUX-Traversals-Make6.c AUX-Traversals-Make5.c AUX-Traversals-Make4.c\
   AUX-Traversals-Make3.c AUX-Traversals-Make2.c AUX-Traversals-Make1.c\
   AUX-Traversals-Priorities2.c AUX-Traversals-Priorities1.c\
   AUX-Traversals-Imports18.c AUX-Traversals-Imports17.c\
   AUX-Traversals-Imports16.c AUX-Traversals-Imports15.c\
   AUX-Traversals-Imports14.c AUX-Traversals-Imports13.c

SPEC_SRCS2=\
   AUX-Traversals-Imports12.c AUX-Traversals-Imports11.c\
   AUX-Traversals-Imports10.c AUX-Traversals-Imports9.c\
   AUX-Traversals-Imports8.c AUX-Traversals-Imports7.c\
   AUX-Traversals-Imports6.c AUX-Traversals-Imports5.c\
   AUX-Traversals-Imports4.c AUX-Traversals-Imports3.c\
   AUX-Traversals-Imports2.c AUX-Traversals-Imports1.c AUX-Traversals7.c\
   AUX-Traversals6.c AUX-Traversals5.c AUX-Traversals4.c AUX-Traversals3.c\
   AUX-Traversals2.c AUX-Traversals1.c

SPEC_SRCS = $(SPEC_SRCS1) $(SPEC_SRCS2)

init.c: $(SPEC_SRCS)
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
