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

LDLIBS          	= -lasc-support -lPT -lASF -lATB -lATerm

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
   AUX-Compiler2.c AUX-Compiler1.c AUX-MuASF2C4.c AUX-MuASF2C3.c\
   AUX-MuASF2C2.c AUX-MuASF2C1.c AUX-MuASF2MuASF2.c AUX-MuASF2MuASF1.c\
   AUX-MuASF2NameTable20.c AUX-MuASF2NameTable19.c AUX-MuASF2NameTable18.c\
   AUX-MuASF2NameTable17.c AUX-MuASF2NameTable16.c AUX-MuASF2NameTable15.c\
   AUX-MuASF2NameTable14.c AUX-MuASF2NameTable13.c AUX-MuASF2NameTable12.c\
   AUX-MuASF2NameTable11.c AUX-MuASF2NameTable10.c AUX-MuASF2NameTable9.c\
   AUX-MuASF2NameTable8.c AUX-MuASF2NameTable7.c AUX-MuASF2NameTable6.c\
   AUX-MuASF2NameTable5.c AUX-MuASF2NameTable4.c AUX-MuASF2NameTable3.c\
   AUX-MuASF2NameTable2.c AUX-MuASF2NameTable1.c AUX-MuASF-Rules2C20.c\
   AUX-MuASF-Rules2C19.c AUX-MuASF-Rules2C18.c AUX-MuASF-Rules2C17.c\
   AUX-MuASF-Rules2C16.c AUX-MuASF-Rules2C15.c AUX-MuASF-Rules2C14.c\
   AUX-MuASF-Rules2C13.c AUX-MuASF-Rules2C12.c AUX-MuASF-Rules2C11.c\
   AUX-MuASF-Rules2C10.c AUX-MuASF-Rules2C9.c AUX-MuASF-Rules2C8.c\
   AUX-MuASF-Rules2C7.c AUX-MuASF-Rules2C6.c AUX-MuASF-Rules2C5.c\
   AUX-MuASF-Rules2C4.c AUX-MuASF-Rules2C3.c AUX-MuASF-Rules2C2.c\
   AUX-MuASF-Rules2C1.c AUX-MuASF-Sign2C12.c AUX-MuASF-Sign2C11.c\
   AUX-MuASF-Sign2C10.c AUX-MuASF-Sign2C9.c AUX-MuASF-Sign2C8.c\
   AUX-MuASF-Sign2C7.c AUX-MuASF-Sign2C6.c AUX-MuASF-Sign2C5.c\
   AUX-MuASF-Sign2C4.c AUX-MuASF-Sign2C3.c AUX-MuASF-Sign2C2.c\
   AUX-MuASF-Sign2C1.c AUX-Make-Assign-Conds9.c AUX-Make-Assign-Conds8.c\
   AUX-Make-Assign-Conds7.c AUX-Make-Assign-Conds6.c AUX-Make-Assign-Conds5.c\
   AUX-Make-Assign-Conds4.c AUX-Make-Assign-Conds3.c AUX-Make-Assign-Conds2.c\
   AUX-Make-Assign-Conds1.c AUX-Make-Left-Linear11.c AUX-Make-Left-Linear10.c\
   AUX-Make-Left-Linear9.c AUX-Make-Left-Linear8.c AUX-Make-Left-Linear7.c\
   AUX-Make-Left-Linear6.c AUX-Make-Left-Linear5.c AUX-Make-Left-Linear4.c\
   AUX-Make-Left-Linear3.c AUX-Make-Left-Linear2.c AUX-Make-Left-Linear1.c\
   AUX-Remove-Lists24.c AUX-Remove-Lists23.c AUX-Remove-Lists22.c\
   AUX-Remove-Lists21.c AUX-Remove-Lists20.c AUX-Remove-Lists19.c\
   AUX-Remove-Lists18.c AUX-Remove-Lists17.c AUX-Remove-Lists16.c\
   AUX-Remove-Lists15.c AUX-Remove-Lists14.c AUX-Remove-Lists13.c

SPEC_SRCS2=\
   AUX-Remove-Lists12.c AUX-Remove-Lists11.c AUX-Remove-Lists10.c\
   AUX-Remove-Lists9.c AUX-Remove-Lists8.c AUX-Remove-Lists7.c\
   AUX-Remove-Lists6.c AUX-Remove-Lists5.c AUX-Remove-Lists4.c\
   AUX-Remove-Lists3.c AUX-Remove-Lists2.c AUX-Remove-Lists1.c\
   AUX-Optimize-MuASF40.c AUX-Optimize-MuASF39.c AUX-Optimize-MuASF38.c\
   AUX-Optimize-MuASF37.c AUX-Optimize-MuASF36.c AUX-Optimize-MuASF35.c\
   AUX-Optimize-MuASF34.c AUX-Optimize-MuASF33.c AUX-Optimize-MuASF32.c\
   AUX-Optimize-MuASF31.c AUX-Optimize-MuASF30.c AUX-Optimize-MuASF29.c\
   AUX-Optimize-MuASF28.c AUX-Optimize-MuASF27.c AUX-Optimize-MuASF26.c\
   AUX-Optimize-MuASF25.c AUX-Optimize-MuASF24.c AUX-Optimize-MuASF23.c\
   AUX-Optimize-MuASF22.c AUX-Optimize-MuASF21.c AUX-Optimize-MuASF20.c\
   AUX-Optimize-MuASF19.c AUX-Optimize-MuASF18.c AUX-Optimize-MuASF17.c\
   AUX-Optimize-MuASF16.c AUX-Optimize-MuASF15.c AUX-Optimize-MuASF14.c\
   AUX-Optimize-MuASF13.c AUX-Optimize-MuASF12.c AUX-Optimize-MuASF11.c\
   AUX-Optimize-MuASF10.c AUX-Optimize-MuASF9.c AUX-Optimize-MuASF8.c\
   AUX-Optimize-MuASF7.c AUX-Optimize-MuASF6.c AUX-Optimize-MuASF5.c\
   AUX-Optimize-MuASF4.c AUX-Optimize-MuASF3.c AUX-Optimize-MuASF2.c\
   AUX-Optimize-MuASF1.c AUX-VarEnv25.c AUX-VarEnv24.c AUX-VarEnv23.c\
   AUX-VarEnv22.c AUX-VarEnv21.c AUX-VarEnv20.c AUX-VarEnv19.c\
   AUX-VarEnv18.c AUX-VarEnv17.c AUX-VarEnv16.c AUX-VarEnv15.c\
   AUX-VarEnv14.c AUX-VarEnv13.c AUX-VarEnv12.c AUX-VarEnv11.c\
   AUX-VarEnv10.c AUX-VarEnv9.c AUX-VarEnv8.c AUX-VarEnv7.c AUX-VarEnv6.c\
   AUX-VarEnv5.c AUX-VarEnv4.c AUX-VarEnv3.c AUX-VarEnv2.c AUX-VarEnv1.c\
   AUX-Locate-Constants24.c AUX-Locate-Constants23.c AUX-Locate-Constants22.c\
   AUX-Locate-Constants21.c AUX-Locate-Constants20.c AUX-Locate-Constants19.c\
   AUX-Locate-Constants18.c AUX-Locate-Constants17.c AUX-Locate-Constants16.c\
   AUX-Locate-Constants15.c AUX-Locate-Constants14.c AUX-Locate-Constants13.c\
   AUX-Locate-Constants12.c AUX-Locate-Constants11.c AUX-Locate-Constants10.c\
   AUX-Locate-Constants9.c AUX-Locate-Constants8.c AUX-Locate-Constants7.c\
   AUX-Locate-Constants6.c AUX-Locate-Constants5.c AUX-Locate-Constants4.c

SPEC_SRCS3=\
   AUX-Locate-Constants3.c AUX-Locate-Constants2.c AUX-Locate-Constants1.c\
   AUX-Transform-Constructors7.c AUX-Transform-Constructors6.c\
   AUX-Transform-Constructors5.c AUX-Transform-Constructors4.c\
   AUX-Transform-Constructors3.c AUX-Transform-Constructors2.c\
   AUX-Transform-Constructors1.c AUX-Improve-C-code12.c\
   AUX-Improve-C-code11.c AUX-Improve-C-code10.c AUX-Improve-C-code9.c\
   AUX-Improve-C-code8.c AUX-Improve-C-code7.c AUX-Improve-C-code6.c\
   AUX-Improve-C-code5.c AUX-Improve-C-code4.c AUX-Improve-C-code3.c\
   AUX-Improve-C-code2.c AUX-Improve-C-code1.c AUX-RenameVars7.c\
   AUX-RenameVars6.c AUX-RenameVars5.c AUX-RenameVars4.c AUX-RenameVars3.c\
   AUX-RenameVars2.c AUX-RenameVars1.c AUX-MuASF-Equations-Ops35.c\
   AUX-MuASF-Equations-Ops34.c AUX-MuASF-Equations-Ops33.c\
   AUX-MuASF-Equations-Ops32.c AUX-MuASF-Equations-Ops31.c\
   AUX-MuASF-Equations-Ops30.c AUX-MuASF-Equations-Ops29.c\
   AUX-MuASF-Equations-Ops28.c AUX-MuASF-Equations-Ops27.c\
   AUX-MuASF-Equations-Ops26.c AUX-MuASF-Equations-Ops25.c\
   AUX-MuASF-Equations-Ops24.c AUX-MuASF-Equations-Ops23.c\
   AUX-MuASF-Equations-Ops22.c AUX-MuASF-Equations-Ops21.c\
   AUX-MuASF-Equations-Ops20.c AUX-MuASF-Equations-Ops19.c\
   AUX-MuASF-Equations-Ops18.c AUX-MuASF-Equations-Ops17.c\
   AUX-MuASF-Equations-Ops16.c AUX-MuASF-Equations-Ops15.c\
   AUX-MuASF-Equations-Ops14.c AUX-MuASF-Equations-Ops13.c\
   AUX-MuASF-Equations-Ops12.c AUX-MuASF-Equations-Ops11.c\
   AUX-MuASF-Equations-Ops10.c AUX-MuASF-Equations-Ops9.c\
   AUX-MuASF-Equations-Ops8.c AUX-MuASF-Equations-Ops7.c\
   AUX-MuASF-Equations-Ops6.c AUX-MuASF-Equations-Ops5.c\
   AUX-MuASF-Equations-Ops4.c AUX-MuASF-Equations-Ops3.c\
   AUX-MuASF-Equations-Ops2.c AUX-MuASF-Equations-Ops1.c\
   AUX-C-Basics15.c AUX-C-Basics14.c AUX-C-Basics13.c AUX-C-Basics12.c\
   AUX-C-Basics11.c AUX-C-Basics10.c AUX-C-Basics9.c AUX-C-Basics8.c

SPEC_SRCS4=\
   AUX-C-Basics7.c AUX-C-Basics6.c AUX-C-Basics5.c AUX-C-Basics4.c\
   AUX-C-Basics3.c AUX-C-Basics2.c AUX-C-Basics1.c AUX-Trans-Set-Pats3.c\
   AUX-Trans-Set-Pats2.c AUX-Trans-Set-Pats1.c AUX-Normalize-Conds16.c\
   AUX-Normalize-Conds15.c AUX-Normalize-Conds14.c AUX-Normalize-Conds13.c\
   AUX-Normalize-Conds12.c AUX-Normalize-Conds11.c AUX-Normalize-Conds10.c\
   AUX-Normalize-Conds9.c AUX-Normalize-Conds8.c AUX-Normalize-Conds7.c\
   AUX-Normalize-Conds6.c AUX-Normalize-Conds5.c AUX-Normalize-Conds4.c\
   AUX-Normalize-Conds3.c AUX-Normalize-Conds2.c AUX-Normalize-Conds1.c\
   AUX-MuASF1.c AUX-Integers-Extended3.c AUX-Integers-Extended2.c\
   AUX-Integers-Extended1.c AUX-MuASF-Conds2C9.c AUX-MuASF-Conds2C8.c\
   AUX-MuASF-Conds2C7.c AUX-MuASF-Conds2C6.c AUX-MuASF-Conds2C5.c\
   AUX-MuASF-Conds2C4.c AUX-MuASF-Conds2C3.c AUX-MuASF-Conds2C2.c\
   AUX-MuASF-Conds2C1.c AUX-Rules2C-Aux44.c AUX-Rules2C-Aux43.c\
   AUX-Rules2C-Aux42.c AUX-Rules2C-Aux41.c AUX-Rules2C-Aux40.c\
   AUX-Rules2C-Aux39.c AUX-Rules2C-Aux38.c AUX-Rules2C-Aux37.c\
   AUX-Rules2C-Aux36.c AUX-Rules2C-Aux35.c AUX-Rules2C-Aux34.c\
   AUX-Rules2C-Aux33.c AUX-Rules2C-Aux32.c AUX-Rules2C-Aux31.c\
   AUX-Rules2C-Aux30.c AUX-Rules2C-Aux29.c AUX-Rules2C-Aux28.c\
   AUX-Rules2C-Aux27.c AUX-Rules2C-Aux26.c AUX-Rules2C-Aux25.c\
   AUX-Rules2C-Aux24.c AUX-Rules2C-Aux23.c AUX-Rules2C-Aux22.c\
   AUX-Rules2C-Aux21.c AUX-Rules2C-Aux20.c AUX-Rules2C-Aux19.c\
   AUX-Rules2C-Aux18.c AUX-Rules2C-Aux17.c AUX-Rules2C-Aux16.c\
   AUX-Rules2C-Aux15.c AUX-Rules2C-Aux14.c AUX-Rules2C-Aux13.c\
   AUX-Rules2C-Aux12.c AUX-Rules2C-Aux11.c AUX-Rules2C-Aux10.c\
   AUX-Rules2C-Aux9.c AUX-Rules2C-Aux8.c AUX-Rules2C-Aux7.c\
   AUX-Rules2C-Aux6.c AUX-Rules2C-Aux5.c AUX-Rules2C-Aux4.c\
   AUX-Rules2C-Aux3.c AUX-Rules2C-Aux2.c AUX-Rules2C-Aux1.c\
   AUX-MuASF-Signature-Ops12.c AUX-MuASF-Signature-Ops11.c\
   AUX-MuASF-Signature-Ops10.c AUX-MuASF-Signature-Ops9.c\
   AUX-MuASF-Signature-Ops8.c AUX-MuASF-Signature-Ops7.c

SPEC_SRCS5=\
   AUX-MuASF-Signature-Ops6.c AUX-MuASF-Signature-Ops5.c\
   AUX-MuASF-Signature-Ops4.c AUX-MuASF-Signature-Ops3.c\
   AUX-MuASF-Signature-Ops2.c AUX-MuASF-Signature-Ops1.c AUX-C1.c\
   AUX-Booleans6.c AUX-Booleans5.c AUX-Booleans4.c AUX-Booleans3.c\
   AUX-Booleans2.c AUX-Booleans1.c AUX-Check-List-Pats29.c\
   AUX-Check-List-Pats28.c AUX-Check-List-Pats27.c AUX-Check-List-Pats26.c\
   AUX-Check-List-Pats25.c AUX-Check-List-Pats24.c AUX-Check-List-Pats23.c\
   AUX-Check-List-Pats22.c AUX-Check-List-Pats21.c AUX-Check-List-Pats20.c\
   AUX-Check-List-Pats19.c AUX-Check-List-Pats18.c AUX-Check-List-Pats17.c\
   AUX-Check-List-Pats16.c AUX-Check-List-Pats15.c AUX-Check-List-Pats14.c\
   AUX-Check-List-Pats13.c AUX-Check-List-Pats12.c AUX-Check-List-Pats11.c\
   AUX-Check-List-Pats10.c AUX-Check-List-Pats9.c AUX-Check-List-Pats8.c\
   AUX-Check-List-Pats7.c AUX-Check-List-Pats6.c AUX-Check-List-Pats5.c\
   AUX-Check-List-Pats4.c AUX-Check-List-Pats3.c AUX-Check-List-Pats2.c\
   AUX-Check-List-Pats1.c AUX-Basic-Integers4.c AUX-Basic-Integers3.c\
   AUX-Basic-Integers2.c AUX-Basic-Integers1.c AUX-MuLiterals2.c\
   AUX-MuLiterals1.c AUX-Integers11.c AUX-Integers10.c AUX-Integers9.c\
   AUX-Integers8.c AUX-Integers7.c AUX-Integers6.c AUX-Integers5.c\
   AUX-Integers4.c AUX-Integers3.c AUX-Integers2.c AUX-Integers1.c\
   AUX-MuASF-Term2C14.c AUX-MuASF-Term2C13.c AUX-MuASF-Term2C12.c\
   AUX-MuASF-Term2C11.c AUX-MuASF-Term2C10.c AUX-MuASF-Term2C9.c\
   AUX-MuASF-Term2C8.c AUX-MuASF-Term2C7.c AUX-MuASF-Term2C6.c\
   AUX-MuASF-Term2C5.c AUX-MuASF-Term2C4.c AUX-MuASF-Term2C3.c\
   AUX-MuASF-Term2C2.c AUX-MuASF-Term2C1.c AUX-Layout1.c\
   AUX-Remove-Lists-Aux10.c AUX-Remove-Lists-Aux9.c AUX-Remove-Lists-Aux8.c\
   AUX-Remove-Lists-Aux7.c AUX-Remove-Lists-Aux6.c AUX-Remove-Lists-Aux5.c\
   AUX-Remove-Lists-Aux4.c AUX-Remove-Lists-Aux3.c AUX-Remove-Lists-Aux2.c\
   AUX-Remove-Lists-Aux1.c AUX-IntCon4.c AUX-IntCon3.c AUX-IntCon2.c\
   AUX-IntCon1.c

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
