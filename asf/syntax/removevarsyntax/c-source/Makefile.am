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

INCLUDES         = -I$(ASC_SUPPORT)/include -I$(ASFIX)/include -I$(ATERM)/include

noinst_LIBRARIES = libRemove-Var-Syntax.a

BUILT_SOURCES    = init.c

libRemove_Var_Syntax_a_SOURCES  = $(SPEC_SRCS)

libRemove_Var_Syntax_a_LIBADD   = init.o

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
   AUX-Restrictions-Sdf-Syntax1.c AUX-Alias-Sdf-Syntax1.c AUX-Sdf2-Syntax1.c\
   AUX-Sdf21.c AUX-Remove-Var-Syntax9.c AUX-Remove-Var-Syntax8.c\
   AUX-Remove-Var-Syntax7.c AUX-Remove-Var-Syntax6.c AUX-Remove-Var-Syntax5.c\
   AUX-Remove-Var-Syntax4.c AUX-Remove-Var-Syntax3.c AUX-Remove-Var-Syntax2.c\
   AUX-Remove-Var-Syntax1.c

SPEC_SRCS = $(SPEC_SRCS1)

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
