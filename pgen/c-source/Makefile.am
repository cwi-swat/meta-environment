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

INCLUDES		= -I$(ASCINC) -I$(ASFIXINC) -I$(ATERMINC)

LDFLAGS			= -L${ASCLIB} -L${ASFIXLIB} -L${ATERMLIB}
LDLIBS          	= -lasc-support -lAsFix -lATB -lATerm

noinst_LIBRARIES	= libSdf2-Normalization.a

bin_PROGRAMS		= Sdf2-Normalization

Sdf2_Normalization_SOURCES		= init.c
Sdf2_Normalization_LDADD		= libSdf2-Normalization.a ${LDLIBS} ${SOCKLIBS}

libSdf2_Normalization_a_SOURCES	= $(SPEC_SRCS)
libSdf2_Normalization_a_LIBADD	= init.o

# Old versions of automake put all dependencies on a single line which
# causes several tools to crash (sed for instance) because of line length
# limitations. We therefore split all dependencies and define them among
# several SPEC_SRCSx variables. These are all combined in SPEC_SRCS which
# forms the concatenation of all sub varibales ( SPEC_SRCS = $(SPEC_SRCS1)
# ... $(SPEC_SRCSn)
#
SPEC_SRCS1=\
   AUX-Basic-Integers4.c AUX-Basic-Integers3.c AUX-Basic-Integers2.c\
   AUX-Basic-Integers1.c AUX-Character-Normalization1.c AUX-Integers11.c\
   AUX-Integers10.c AUX-Integers9.c AUX-Integers8.c AUX-Integers7.c\
   AUX-Integers6.c AUX-Integers5.c AUX-Integers4.c AUX-Integers3.c\
   AUX-Integers2.c AUX-Integers1.c AUX-RealCon1.c AUX-Character-Syntax7.c\
   AUX-Character-Syntax6.c AUX-Character-Syntax5.c AUX-Character-Syntax4.c\
   AUX-Character-Syntax3.c AUX-Character-Syntax2.c AUX-Character-Syntax1.c\
   AUX-Character-Arithmetic10.c AUX-Character-Arithmetic9.c\
   AUX-Character-Arithmetic8.c AUX-Character-Arithmetic7.c\
   AUX-Character-Arithmetic6.c AUX-Character-Arithmetic5.c\
   AUX-Character-Arithmetic4.c AUX-Character-Arithmetic3.c\
   AUX-Character-Arithmetic2.c AUX-Character-Arithmetic1.c\
   AUX-Symbols-Projection4.c AUX-Symbols-Projection3.c\
   AUX-Symbols-Projection2.c AUX-Symbols-Projection1.c AUX-ATerms1.c\
   AUX-Basic-Sdf-Normalization13.c AUX-Basic-Sdf-Normalization12.c\
   AUX-Basic-Sdf-Normalization11.c AUX-Basic-Sdf-Normalization10.c\
   AUX-Basic-Sdf-Normalization9.c AUX-Basic-Sdf-Normalization8.c\
   AUX-Basic-Sdf-Normalization7.c AUX-Basic-Sdf-Normalization6.c\
   AUX-Basic-Sdf-Normalization5.c AUX-Basic-Sdf-Normalization4.c\
   AUX-Basic-Sdf-Normalization3.c AUX-Basic-Sdf-Normalization2.c\
   AUX-Basic-Sdf-Normalization1.c AUX-Renaming-Sdf-Renaming2.c\
   AUX-Renaming-Sdf-Renaming1.c AUX-Layout1.c AUX-Symbols1.c\
   AUX-Character-Class-Syntax8.c AUX-Character-Class-Syntax7.c\
   AUX-Character-Class-Syntax6.c AUX-Character-Class-Syntax5.c\
   AUX-Character-Class-Syntax4.c AUX-Character-Class-Syntax3.c\
   AUX-Character-Class-Syntax2.c AUX-Character-Class-Syntax1.c\
   AUX-Character-Class-Membership5.c AUX-Character-Class-Membership4.c\
   AUX-Character-Class-Membership3.c AUX-Character-Class-Membership2.c\
   AUX-Character-Class-Membership1.c AUX-Symbol-Sets4.c AUX-Symbol-Sets3.c\
   AUX-Symbol-Sets2.c AUX-Symbol-Sets1.c AUX-Renaming-Sdf-Syntax1.c

SPEC_SRCS2=\
   AUX-Basic-Sdf-Syntax4.c AUX-Basic-Sdf-Syntax3.c AUX-Basic-Sdf-Syntax2.c\
   AUX-Basic-Sdf-Syntax1.c AUX-Modular-Sdf-Syntax4.c\
   AUX-Modular-Sdf-Syntax3.c AUX-Modular-Sdf-Syntax2.c\
   AUX-Modular-Sdf-Syntax1.c AUX-Label-Sdf-Syntax1.c\
   AUX-Basic-Sdf-Renaming3.c AUX-Basic-Sdf-Renaming2.c\
   AUX-Basic-Sdf-Renaming1.c AUX-Modular-Sdf-Section3.c\
   AUX-Modular-Sdf-Section2.c AUX-Modular-Sdf-Section1.c\
   AUX-Grammar-Syntax2.c AUX-Grammar-Syntax1.c AUX-Booleans6.c\
   AUX-Booleans5.c AUX-Booleans4.c AUX-Booleans3.c AUX-Booleans2.c\
   AUX-Booleans1.c AUX-IntCon1.c AUX-Literals1.c AUX-Kernel-Sdf-Syntax3.c\
   AUX-Kernel-Sdf-Syntax2.c AUX-Kernel-Sdf-Syntax1.c\
   AUX-CC-Sdf-Syntax1.c AUX-Character-Class-Normalization16.c\
   AUX-Character-Class-Normalization15.c\
   AUX-Character-Class-Normalization14.c\
   AUX-Character-Class-Normalization13.c\
   AUX-Character-Class-Normalization12.c\
   AUX-Character-Class-Normalization11.c\
   AUX-Character-Class-Normalization10.c\
   AUX-Character-Class-Normalization9.c AUX-Character-Class-Normalization8.c\
   AUX-Character-Class-Normalization7.c AUX-Character-Class-Normalization6.c\
   AUX-Character-Class-Normalization5.c AUX-Character-Class-Normalization4.c\
   AUX-Character-Class-Normalization3.c AUX-Character-Class-Normalization2.c\
   AUX-Character-Class-Normalization1.c AUX-Alias-Sdf-Syntax2.c\
   AUX-Alias-Sdf-Syntax1.c AUX-Grammar-Normalization2.c\
   AUX-Grammar-Normalization1.c AUX-Kernel-Sdf-Projection15.c\
   AUX-Kernel-Sdf-Projection14.c AUX-Kernel-Sdf-Projection13.c\
   AUX-Kernel-Sdf-Projection12.c AUX-Kernel-Sdf-Projection11.c\
   AUX-Kernel-Sdf-Projection10.c AUX-Kernel-Sdf-Projection9.c\
   AUX-Kernel-Sdf-Projection8.c AUX-Kernel-Sdf-Projection7.c\
   AUX-Kernel-Sdf-Projection6.c AUX-Kernel-Sdf-Projection5.c

SPEC_SRCS3=\
   AUX-Kernel-Sdf-Projection4.c AUX-Kernel-Sdf-Projection3.c\
   AUX-Kernel-Sdf-Projection2.c AUX-Kernel-Sdf-Projection1.c\
   AUX-Sorts-Sdf-Projection2.c AUX-Sorts-Sdf-Projection1.c\
   AUX-Renaming-Sdf-Projection5.c AUX-Renaming-Sdf-Projection4.c\
   AUX-Renaming-Sdf-Projection3.c AUX-Renaming-Sdf-Projection2.c\
   AUX-Renaming-Sdf-Projection1.c AUX-Restrictions-Sdf-Projection4.c\
   AUX-Restrictions-Sdf-Projection3.c AUX-Restrictions-Sdf-Projection2.c\
   AUX-Restrictions-Sdf-Projection1.c AUX-Sdf2-Syntax1.c\
   AUX-Priority-Sdf-Renaming3.c AUX-Priority-Sdf-Renaming2.c\
   AUX-Priority-Sdf-Renaming1.c AUX-Regular-Sdf-Renaming1.c\
   AUX-Literals-Sdf-Renaming1.c AUX-CC-Sdf-Renaming1.c\
   AUX-Sorts-Sdf-Renaming1.c AUX-Restrictions-Sdf-Renaming2.c\
   AUX-Restrictions-Sdf-Renaming1.c AUX-Modular-Sdf-Renaming2.c\
   AUX-Modular-Sdf-Renaming1.c AUX-Alias-Sdf-Renaming2.c\
   AUX-Alias-Sdf-Renaming1.c AUX-Modular-Sdf-Projection6.c\
   AUX-Modular-Sdf-Projection5.c AUX-Modular-Sdf-Projection4.c\
   AUX-Modular-Sdf-Projection3.c AUX-Modular-Sdf-Projection2.c\
   AUX-Modular-Sdf-Projection1.c AUX-Grammar-Projection2.c\
   AUX-Grammar-Projection1.c AUX-Priority-Sdf-Projection6.c\
   AUX-Priority-Sdf-Projection5.c AUX-Priority-Sdf-Projection4.c\
   AUX-Priority-Sdf-Projection3.c AUX-Priority-Sdf-Projection2.c\
   AUX-Priority-Sdf-Projection1.c AUX-Regular-Sdf-Syntax3.c\
   AUX-Regular-Sdf-Syntax2.c AUX-Regular-Sdf-Syntax1.c\
   AUX-Priority-Sdf-Syntax2.c AUX-Priority-Sdf-Syntax1.c\
   AUX-Literals-Sdf-Syntax3.c AUX-Literals-Sdf-Syntax2.c\
   AUX-Literals-Sdf-Syntax1.c AUX-Sorts-Sdf-Syntax2.c AUX-Sorts-Sdf-Syntax1.c\
   AUX-Restrictions-Sdf-Syntax6.c AUX-Restrictions-Sdf-Syntax5.c\
   AUX-Restrictions-Sdf-Syntax4.c AUX-Restrictions-Sdf-Syntax3.c\
   AUX-Restrictions-Sdf-Syntax2.c AUX-Restrictions-Sdf-Syntax1.c\
   AUX-CC-Sdf-Normalization1.c AUX-Alias-Sdf-Projection4.c

SPEC_SRCS4=\
   AUX-Alias-Sdf-Projection3.c AUX-Alias-Sdf-Projection2.c\
   AUX-Alias-Sdf-Projection1.c AUX-Kernel-Sdf-Normalization7.c\
   AUX-Kernel-Sdf-Normalization6.c AUX-Kernel-Sdf-Normalization5.c\
   AUX-Kernel-Sdf-Normalization4.c AUX-Kernel-Sdf-Normalization3.c\
   AUX-Kernel-Sdf-Normalization2.c AUX-Kernel-Sdf-Normalization1.c\
   AUX-Kernel-Sdf-Renaming7.c AUX-Kernel-Sdf-Renaming6.c\
   AUX-Kernel-Sdf-Renaming5.c AUX-Kernel-Sdf-Renaming4.c\
   AUX-Kernel-Sdf-Renaming3.c AUX-Kernel-Sdf-Renaming2.c\
   AUX-Kernel-Sdf-Renaming1.c AUX-Sdf2-Projection1.c AUX-Sdf2-Renaming1.c\
   AUX-Modular-Sdf-Normalization11.c AUX-Modular-Sdf-Normalization10.c\
   AUX-Modular-Sdf-Normalization9.c AUX-Modular-Sdf-Normalization8.c\
   AUX-Modular-Sdf-Normalization7.c AUX-Modular-Sdf-Normalization6.c\
   AUX-Modular-Sdf-Normalization5.c AUX-Modular-Sdf-Normalization4.c\
   AUX-Modular-Sdf-Normalization3.c AUX-Modular-Sdf-Normalization2.c\
   AUX-Modular-Sdf-Normalization1.c AUX-Priority-Sdf-Normalization10.c\
   AUX-Priority-Sdf-Normalization9.c AUX-Priority-Sdf-Normalization8.c\
   AUX-Priority-Sdf-Normalization7.c AUX-Priority-Sdf-Normalization6.c\
   AUX-Priority-Sdf-Normalization5.c AUX-Priority-Sdf-Normalization4.c\
   AUX-Priority-Sdf-Normalization3.c AUX-Priority-Sdf-Normalization2.c\
   AUX-Priority-Sdf-Normalization1.c AUX-Regular-Sdf-Normalization7.c\
   AUX-Regular-Sdf-Normalization6.c AUX-Regular-Sdf-Normalization5.c\
   AUX-Regular-Sdf-Normalization4.c AUX-Regular-Sdf-Normalization3.c\
   AUX-Regular-Sdf-Normalization2.c AUX-Regular-Sdf-Normalization1.c\
   AUX-Literals-Sdf-Normalization5.c AUX-Literals-Sdf-Normalization4.c\
   AUX-Literals-Sdf-Normalization3.c AUX-Literals-Sdf-Normalization2.c\
   AUX-Literals-Sdf-Normalization1.c AUX-Sorts-Sdf-Normalization1.c\
   AUX-Restrictions-Sdf-Normalization1.c AUX-Alias-Sdf-Normalization4.c\
   AUX-Alias-Sdf-Normalization3.c AUX-Alias-Sdf-Normalization2.c\
   AUX-Alias-Sdf-Normalization1.c AUX-Sdf2-Normalization11.c\
   AUX-Sdf2-Normalization10.c AUX-Sdf2-Normalization9.c

SPEC_SRCS5=\
   AUX-Sdf2-Normalization8.c AUX-Sdf2-Normalization7.c\
   AUX-Sdf2-Normalization6.c AUX-Sdf2-Normalization5.c\
   AUX-Sdf2-Normalization4.c AUX-Sdf2-Normalization3.c\
   AUX-Sdf2-Normalization2.c AUX-Sdf2-Normalization1.c Basic-Integers.c

SPEC_SRCS = $(SPEC_SRCS1) $(SPEC_SRCS2) $(SPEC_SRCS3) $(SPEC_SRCS4) $(SPEC_SRCS5)

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
