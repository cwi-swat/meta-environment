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

noinst_LIBRARIES = libAsFix2C.a

BUILT_SOURCES    = init.c

libAsFix2C_a_SOURCES  = $(SPEC_SRCS)

libAsFix2C_a_LIBADD   = init.o

# Old versions of automake put all dependencies on a single line which
# causes several tools to crash (sed for instance) because of line length
# limitations. We therefore split all dependencies and define them among
# several SPEC_SRCSx variables. These are all combined in SPEC_SRCS which
# forms the concatenation of all sub varibales ( SPEC_SRCS = $(SPEC_SRCS1)
# ... $(SPEC_SRCSn)
#
SPEC_SRCS1=\
   AUX-AVars4.c AUX-AVars3.c AUX-AVars2.c AUX-AVars1.c\
   AUX-ATypes3.c AUX-ATypes2.c AUX-ATypes1.c AUX-ATerm-Operations23.c\
   AUX-ATerm-Operations22.c AUX-ATerm-Operations21.c AUX-ATerm-Operations20.c\
   AUX-ATerm-Operations19.c AUX-ATerm-Operations18.c AUX-ATerm-Operations17.c\
   AUX-ATerm-Operations16.c AUX-ATerm-Operations15.c AUX-ATerm-Operations14.c\
   AUX-ATerm-Operations13.c AUX-ATerm-Operations12.c AUX-ATerm-Operations11.c\
   AUX-ATerm-Operations10.c AUX-ATerm-Operations9.c AUX-ATerm-Operations8.c\
   AUX-ATerm-Operations7.c AUX-ATerm-Operations6.c AUX-ATerm-Operations5.c\
   AUX-ATerm-Operations4.c AUX-ATerm-Operations3.c AUX-ATerm-Operations2.c\
   AUX-ATerm-Operations1.c AUX-Substitution5.c AUX-Substitution4.c\
   AUX-Substitution3.c AUX-Substitution2.c AUX-Substitution1.c\
   AUX-ATerm-Lists20.c AUX-ATerm-Lists19.c AUX-ATerm-Lists18.c\
   AUX-ATerm-Lists17.c AUX-ATerm-Lists16.c AUX-ATerm-Lists15.c\
   AUX-ATerm-Lists14.c AUX-ATerm-Lists13.c AUX-ATerm-Lists12.c\
   AUX-ATerm-Lists11.c AUX-ATerm-Lists10.c AUX-ATerm-Lists9.c\
   AUX-ATerm-Lists8.c AUX-ATerm-Lists7.c AUX-ATerm-Lists6.c\
   AUX-ATerm-Lists5.c AUX-ATerm-Lists4.c AUX-ATerm-Lists3.c\
   AUX-ATerm-Lists2.c AUX-ATerm-Lists1.c AUX-Matching2.c AUX-Matching1.c\
   AUX-ATerm-Tables6.c AUX-ATerm-Tables5.c AUX-ATerm-Tables4.c\
   AUX-ATerm-Tables3.c AUX-ATerm-Tables2.c AUX-ATerm-Tables1.c\
   AUX-ATerm-Trees11.c AUX-ATerm-Trees10.c AUX-ATerm-Trees9.c\
   AUX-ATerm-Trees8.c AUX-ATerm-Trees7.c AUX-ATerm-Trees6.c\
   AUX-ATerm-Trees5.c AUX-ATerm-Trees4.c AUX-ATerm-Trees3.c\
   AUX-ATerm-Trees2.c AUX-ATerm-Trees1.c AUX-ATermTools2.c AUX-ATermTools1.c\
   AUX-ParseTree-Constructors1.c AUX-Literals5.c AUX-Literals4.c\
   AUX-Literals3.c AUX-Literals2.c AUX-Literals1.c AUX-Grammars6.c\
   AUX-Grammars5.c AUX-Grammars4.c AUX-Grammars3.c AUX-Grammars2.c\
   AUX-Grammars1.c AUX-AsFix-Constructors1.c AUX-ATerms3.c AUX-ATerms2.c\
   AUX-ATerms1.c AUX-ParseTrees21.c AUX-ParseTrees20.c AUX-ParseTrees19.c\
   AUX-ParseTrees18.c AUX-ParseTrees17.c AUX-ParseTrees16.c

SPEC_SRCS2=\
   AUX-ParseTrees15.c AUX-ParseTrees14.c AUX-ParseTrees13.c\
   AUX-ParseTrees12.c AUX-ParseTrees11.c AUX-ParseTrees10.c\
   AUX-ParseTrees9.c AUX-ParseTrees8.c AUX-ParseTrees7.c AUX-ParseTrees6.c\
   AUX-ParseTrees5.c AUX-ParseTrees4.c AUX-ParseTrees3.c AUX-ParseTrees2.c\
   AUX-ParseTrees1.c AUX-Pos-Constructors1.c AUX-ATermPrint3.c\
   AUX-ATermPrint2.c AUX-ATermPrint1.c AUX-AsFixParseTrees1.c\
   AUX-RemAsFixWspace7.c AUX-RemAsFixWspace6.c AUX-RemAsFixWspace5.c\
   AUX-RemAsFixWspace4.c AUX-RemAsFixWspace3.c AUX-RemAsFixWspace2.c\
   AUX-RemAsFixWspace1.c AUX-AsFixPrint2.c AUX-AsFixPrint1.c\
   AUX-AsFix2muASFnames16.c AUX-AsFix2muASFnames15.c AUX-AsFix2muASFnames14.c\
   AUX-AsFix2muASFnames13.c AUX-AsFix2muASFnames12.c AUX-AsFix2muASFnames11.c\
   AUX-AsFix2muASFnames10.c AUX-AsFix2muASFnames9.c AUX-AsFix2muASFnames8.c\
   AUX-AsFix2muASFnames7.c AUX-AsFix2muASFnames6.c AUX-AsFix2muASFnames5.c\
   AUX-AsFix2muASFnames4.c AUX-AsFix2muASFnames3.c AUX-AsFix2muASFnames2.c\
   AUX-AsFix2muASFnames1.c AUX-AsFix-Basics12.c AUX-AsFix-Basics11.c\
   AUX-AsFix-Basics10.c AUX-AsFix-Basics9.c AUX-AsFix-Basics8.c\
   AUX-AsFix-Basics7.c AUX-AsFix-Basics6.c AUX-AsFix-Basics5.c\
   AUX-AsFix-Basics4.c AUX-AsFix-Basics3.c AUX-AsFix-Basics2.c\
   AUX-AsFix-Basics1.c AUX-IntCon4.c AUX-IntCon3.c AUX-IntCon2.c\
   AUX-IntCon1.c AUX-Integers11.c AUX-Integers10.c AUX-Integers9.c\
   AUX-Integers8.c AUX-Integers7.c AUX-Integers6.c AUX-Integers5.c\
   AUX-Integers4.c AUX-Integers3.c AUX-Integers2.c AUX-Integers1.c\
   AUX-TermAsFixAccess57.c AUX-TermAsFixAccess56.c AUX-TermAsFixAccess55.c\
   AUX-TermAsFixAccess54.c AUX-TermAsFixAccess53.c AUX-TermAsFixAccess52.c\
   AUX-TermAsFixAccess51.c AUX-TermAsFixAccess50.c AUX-TermAsFixAccess49.c\
   AUX-TermAsFixAccess48.c AUX-TermAsFixAccess47.c AUX-TermAsFixAccess46.c\
   AUX-TermAsFixAccess45.c AUX-TermAsFixAccess44.c AUX-TermAsFixAccess43.c\
   AUX-TermAsFixAccess42.c AUX-TermAsFixAccess41.c AUX-TermAsFixAccess40.c\
   AUX-TermAsFixAccess39.c AUX-TermAsFixAccess38.c AUX-TermAsFixAccess37.c\
   AUX-TermAsFixAccess36.c AUX-TermAsFixAccess35.c AUX-TermAsFixAccess34.c

SPEC_SRCS3=\
   AUX-TermAsFixAccess33.c AUX-TermAsFixAccess32.c AUX-TermAsFixAccess31.c\
   AUX-TermAsFixAccess30.c AUX-TermAsFixAccess29.c AUX-TermAsFixAccess28.c\
   AUX-TermAsFixAccess27.c AUX-TermAsFixAccess26.c AUX-TermAsFixAccess25.c\
   AUX-TermAsFixAccess24.c AUX-TermAsFixAccess23.c AUX-TermAsFixAccess22.c\
   AUX-TermAsFixAccess21.c AUX-TermAsFixAccess20.c AUX-TermAsFixAccess19.c\
   AUX-TermAsFixAccess18.c AUX-TermAsFixAccess17.c AUX-TermAsFixAccess16.c\
   AUX-TermAsFixAccess15.c AUX-TermAsFixAccess14.c AUX-TermAsFixAccess13.c\
   AUX-TermAsFixAccess12.c AUX-TermAsFixAccess11.c AUX-TermAsFixAccess10.c\
   AUX-TermAsFixAccess9.c AUX-TermAsFixAccess8.c AUX-TermAsFixAccess7.c\
   AUX-TermAsFixAccess6.c AUX-TermAsFixAccess5.c AUX-TermAsFixAccess4.c\
   AUX-TermAsFixAccess3.c AUX-TermAsFixAccess2.c AUX-TermAsFixAccess1.c\
   AUX-Layout1.c AUX-MuLiterals2.c AUX-MuLiterals1.c AUX-Basic-Integers4.c\
   AUX-Basic-Integers3.c AUX-Basic-Integers2.c AUX-Basic-Integers1.c\
   AUX-MuASF-Term2C14.c AUX-MuASF-Term2C13.c AUX-MuASF-Term2C12.c\
   AUX-MuASF-Term2C11.c AUX-MuASF-Term2C10.c AUX-MuASF-Term2C9.c\
   AUX-MuASF-Term2C8.c AUX-MuASF-Term2C7.c AUX-MuASF-Term2C6.c\
   AUX-MuASF-Term2C5.c AUX-MuASF-Term2C4.c AUX-MuASF-Term2C3.c\
   AUX-MuASF-Term2C2.c AUX-MuASF-Term2C1.c AUX-Integers-Extended3.c\
   AUX-Integers-Extended2.c AUX-Integers-Extended1.c AUX-TermAsFix2Sign24.c\
   AUX-TermAsFix2Sign23.c AUX-TermAsFix2Sign22.c AUX-TermAsFix2Sign21.c\
   AUX-TermAsFix2Sign20.c AUX-TermAsFix2Sign19.c AUX-TermAsFix2Sign18.c\
   AUX-TermAsFix2Sign17.c AUX-TermAsFix2Sign16.c AUX-TermAsFix2Sign15.c\
   AUX-TermAsFix2Sign14.c AUX-TermAsFix2Sign13.c AUX-TermAsFix2Sign12.c\
   AUX-TermAsFix2Sign11.c AUX-TermAsFix2Sign10.c AUX-TermAsFix2Sign9.c\
   AUX-TermAsFix2Sign8.c AUX-TermAsFix2Sign7.c AUX-TermAsFix2Sign6.c\
   AUX-TermAsFix2Sign5.c AUX-TermAsFix2Sign4.c AUX-TermAsFix2Sign3.c\
   AUX-TermAsFix2Sign2.c AUX-TermAsFix2Sign1.c AUX-ATerm-Booleans6.c\
   AUX-ATerm-Booleans5.c AUX-ATerm-Booleans4.c AUX-ATerm-Booleans3.c\
   AUX-ATerm-Booleans2.c AUX-ATerm-Booleans1.c AUX-C1.c AUX-MuASF1.c\
   AUX-Rules2C-Aux43.c AUX-Rules2C-Aux42.c AUX-Rules2C-Aux41.c

SPEC_SRCS4=\
   AUX-Rules2C-Aux40.c AUX-Rules2C-Aux39.c AUX-Rules2C-Aux38.c\
   AUX-Rules2C-Aux37.c AUX-Rules2C-Aux36.c AUX-Rules2C-Aux35.c\
   AUX-Rules2C-Aux34.c AUX-Rules2C-Aux33.c AUX-Rules2C-Aux32.c\
   AUX-Rules2C-Aux31.c AUX-Rules2C-Aux30.c AUX-Rules2C-Aux29.c\
   AUX-Rules2C-Aux28.c AUX-Rules2C-Aux27.c AUX-Rules2C-Aux26.c\
   AUX-Rules2C-Aux25.c AUX-Rules2C-Aux24.c AUX-Rules2C-Aux23.c\
   AUX-Rules2C-Aux22.c AUX-Rules2C-Aux21.c AUX-Rules2C-Aux20.c\
   AUX-Rules2C-Aux19.c AUX-Rules2C-Aux18.c AUX-Rules2C-Aux17.c\
   AUX-Rules2C-Aux16.c AUX-Rules2C-Aux15.c AUX-Rules2C-Aux14.c\
   AUX-Rules2C-Aux13.c AUX-Rules2C-Aux12.c AUX-Rules2C-Aux11.c\
   AUX-Rules2C-Aux10.c AUX-Rules2C-Aux9.c AUX-Rules2C-Aux8.c\
   AUX-Rules2C-Aux7.c AUX-Rules2C-Aux6.c AUX-Rules2C-Aux5.c\
   AUX-Rules2C-Aux4.c AUX-Rules2C-Aux3.c AUX-Rules2C-Aux2.c\
   AUX-Rules2C-Aux1.c AUX-MuASF-Conds2C9.c AUX-MuASF-Conds2C8.c\
   AUX-MuASF-Conds2C7.c AUX-MuASF-Conds2C6.c AUX-MuASF-Conds2C5.c\
   AUX-MuASF-Conds2C4.c AUX-MuASF-Conds2C3.c AUX-MuASF-Conds2C2.c\
   AUX-MuASF-Conds2C1.c AUX-Check-List-Pats29.c AUX-Check-List-Pats28.c\
   AUX-Check-List-Pats27.c AUX-Check-List-Pats26.c AUX-Check-List-Pats25.c\
   AUX-Check-List-Pats24.c AUX-Check-List-Pats23.c AUX-Check-List-Pats22.c\
   AUX-Check-List-Pats21.c AUX-Check-List-Pats20.c AUX-Check-List-Pats19.c\
   AUX-Check-List-Pats18.c AUX-Check-List-Pats17.c AUX-Check-List-Pats16.c\
   AUX-Check-List-Pats15.c AUX-Check-List-Pats14.c AUX-Check-List-Pats13.c\
   AUX-Check-List-Pats12.c AUX-Check-List-Pats11.c AUX-Check-List-Pats10.c\
   AUX-Check-List-Pats9.c AUX-Check-List-Pats8.c AUX-Check-List-Pats7.c\
   AUX-Check-List-Pats6.c AUX-Check-List-Pats5.c AUX-Check-List-Pats4.c\
   AUX-Check-List-Pats3.c AUX-Check-List-Pats2.c AUX-Check-List-Pats1.c\
   AUX-MuASF-Signature-Ops12.c AUX-MuASF-Signature-Ops11.c\
   AUX-MuASF-Signature-Ops10.c AUX-MuASF-Signature-Ops9.c\
   AUX-MuASF-Signature-Ops8.c AUX-MuASF-Signature-Ops7.c\
   AUX-MuASF-Signature-Ops6.c AUX-MuASF-Signature-Ops5.c

SPEC_SRCS5=\
   AUX-MuASF-Signature-Ops4.c AUX-MuASF-Signature-Ops3.c\
   AUX-MuASF-Signature-Ops2.c AUX-MuASF-Signature-Ops1.c AUX-VarEnv25.c\
   AUX-VarEnv24.c AUX-VarEnv23.c AUX-VarEnv22.c AUX-VarEnv21.c\
   AUX-VarEnv20.c AUX-VarEnv19.c AUX-VarEnv18.c AUX-VarEnv17.c\
   AUX-VarEnv16.c AUX-VarEnv15.c AUX-VarEnv14.c AUX-VarEnv13.c\
   AUX-VarEnv12.c AUX-VarEnv11.c AUX-VarEnv10.c AUX-VarEnv9.c AUX-VarEnv8.c\
   AUX-VarEnv7.c AUX-VarEnv6.c AUX-VarEnv5.c AUX-VarEnv4.c AUX-VarEnv3.c\
   AUX-VarEnv2.c AUX-VarEnv1.c AUX-AsFix2Sign16.c AUX-AsFix2Sign15.c\
   AUX-AsFix2Sign14.c AUX-AsFix2Sign13.c AUX-AsFix2Sign12.c\
   AUX-AsFix2Sign11.c AUX-AsFix2Sign10.c AUX-AsFix2Sign9.c AUX-AsFix2Sign8.c\
   AUX-AsFix2Sign7.c AUX-AsFix2Sign6.c AUX-AsFix2Sign5.c AUX-AsFix2Sign4.c\
   AUX-AsFix2Sign3.c AUX-AsFix2Sign2.c AUX-AsFix2Sign1.c AUX-C-Basics16.c\
   AUX-C-Basics15.c AUX-C-Basics14.c AUX-C-Basics13.c AUX-C-Basics12.c\
   AUX-C-Basics11.c AUX-C-Basics10.c AUX-C-Basics9.c AUX-C-Basics8.c\
   AUX-C-Basics7.c AUX-C-Basics6.c AUX-C-Basics5.c AUX-C-Basics4.c\
   AUX-C-Basics3.c AUX-C-Basics2.c AUX-C-Basics1.c AUX-Improve-C-code12.c\
   AUX-Improve-C-code11.c AUX-Improve-C-code10.c AUX-Improve-C-code9.c\
   AUX-Improve-C-code8.c AUX-Improve-C-code7.c AUX-Improve-C-code6.c\
   AUX-Improve-C-code5.c AUX-Improve-C-code4.c AUX-Improve-C-code3.c\
   AUX-Improve-C-code2.c AUX-Improve-C-code1.c AUX-Transform-Constructors7.c\
   AUX-Transform-Constructors6.c AUX-Transform-Constructors5.c\
   AUX-Transform-Constructors4.c AUX-Transform-Constructors3.c\
   AUX-Transform-Constructors2.c AUX-Transform-Constructors1.c\
   AUX-Locate-Constants24.c AUX-Locate-Constants23.c AUX-Locate-Constants22.c\
   AUX-Locate-Constants21.c AUX-Locate-Constants20.c AUX-Locate-Constants19.c\
   AUX-Locate-Constants18.c AUX-Locate-Constants17.c AUX-Locate-Constants16.c\
   AUX-Locate-Constants15.c AUX-Locate-Constants14.c AUX-Locate-Constants13.c\
   AUX-Locate-Constants12.c AUX-Locate-Constants11.c AUX-Locate-Constants10.c\
   AUX-Locate-Constants9.c AUX-Locate-Constants8.c AUX-Locate-Constants7.c\
   AUX-Locate-Constants6.c AUX-Locate-Constants5.c AUX-Locate-Constants4.c

SPEC_SRCS6=\
   AUX-Locate-Constants3.c AUX-Locate-Constants2.c AUX-Locate-Constants1.c\
   AUX-Remove-Lists-Aux10.c AUX-Remove-Lists-Aux9.c AUX-Remove-Lists-Aux8.c\
   AUX-Remove-Lists-Aux7.c AUX-Remove-Lists-Aux6.c AUX-Remove-Lists-Aux5.c\
   AUX-Remove-Lists-Aux4.c AUX-Remove-Lists-Aux3.c AUX-Remove-Lists-Aux2.c\
   AUX-Remove-Lists-Aux1.c AUX-RenameVars7.c AUX-RenameVars6.c\
   AUX-RenameVars5.c AUX-RenameVars4.c AUX-RenameVars3.c AUX-RenameVars2.c\
   AUX-RenameVars1.c AUX-Normalize-Conds16.c AUX-Normalize-Conds15.c\
   AUX-Normalize-Conds14.c AUX-Normalize-Conds13.c AUX-Normalize-Conds12.c\
   AUX-Normalize-Conds11.c AUX-Normalize-Conds10.c AUX-Normalize-Conds9.c\
   AUX-Normalize-Conds8.c AUX-Normalize-Conds7.c AUX-Normalize-Conds6.c\
   AUX-Normalize-Conds5.c AUX-Normalize-Conds4.c AUX-Normalize-Conds3.c\
   AUX-Normalize-Conds2.c AUX-Normalize-Conds1.c AUX-Trans-Set-Pats3.c\
   AUX-Trans-Set-Pats2.c AUX-Trans-Set-Pats1.c AUX-MuASF-Equations-Ops32.c\
   AUX-MuASF-Equations-Ops31.c AUX-MuASF-Equations-Ops30.c\
   AUX-MuASF-Equations-Ops29.c AUX-MuASF-Equations-Ops28.c\
   AUX-MuASF-Equations-Ops27.c AUX-MuASF-Equations-Ops26.c\
   AUX-MuASF-Equations-Ops25.c AUX-MuASF-Equations-Ops24.c\
   AUX-MuASF-Equations-Ops23.c AUX-MuASF-Equations-Ops22.c\
   AUX-MuASF-Equations-Ops21.c AUX-MuASF-Equations-Ops20.c\
   AUX-MuASF-Equations-Ops19.c AUX-MuASF-Equations-Ops18.c\
   AUX-MuASF-Equations-Ops17.c AUX-MuASF-Equations-Ops16.c\
   AUX-MuASF-Equations-Ops15.c AUX-MuASF-Equations-Ops14.c\
   AUX-MuASF-Equations-Ops13.c AUX-MuASF-Equations-Ops12.c\
   AUX-MuASF-Equations-Ops11.c AUX-MuASF-Equations-Ops10.c\
   AUX-MuASF-Equations-Ops9.c AUX-MuASF-Equations-Ops8.c\
   AUX-MuASF-Equations-Ops7.c AUX-MuASF-Equations-Ops6.c\
   AUX-MuASF-Equations-Ops5.c AUX-MuASF-Equations-Ops4.c\
   AUX-MuASF-Equations-Ops3.c AUX-MuASF-Equations-Ops2.c\
   AUX-MuASF-Equations-Ops1.c AUX-TermAsFix2muASF8.c AUX-TermAsFix2muASF7.c\
   AUX-TermAsFix2muASF6.c AUX-TermAsFix2muASF5.c AUX-TermAsFix2muASF4.c

SPEC_SRCS7=\
   AUX-TermAsFix2muASF3.c AUX-TermAsFix2muASF2.c AUX-TermAsFix2muASF1.c\
   AUX-MuASF-Sign2C12.c AUX-MuASF-Sign2C11.c AUX-MuASF-Sign2C10.c\
   AUX-MuASF-Sign2C9.c AUX-MuASF-Sign2C8.c AUX-MuASF-Sign2C7.c\
   AUX-MuASF-Sign2C6.c AUX-MuASF-Sign2C5.c AUX-MuASF-Sign2C4.c\
   AUX-MuASF-Sign2C3.c AUX-MuASF-Sign2C2.c AUX-MuASF-Sign2C1.c\
   AUX-MuASF-Rules2C17.c AUX-MuASF-Rules2C16.c AUX-MuASF-Rules2C15.c\
   AUX-MuASF-Rules2C14.c AUX-MuASF-Rules2C13.c AUX-MuASF-Rules2C12.c\
   AUX-MuASF-Rules2C11.c AUX-MuASF-Rules2C10.c AUX-MuASF-Rules2C9.c\
   AUX-MuASF-Rules2C8.c AUX-MuASF-Rules2C7.c AUX-MuASF-Rules2C6.c\
   AUX-MuASF-Rules2C5.c AUX-MuASF-Rules2C4.c AUX-MuASF-Rules2C3.c\
   AUX-MuASF-Rules2C2.c AUX-MuASF-Rules2C1.c AUX-Remove-Lists24.c\
   AUX-Remove-Lists23.c AUX-Remove-Lists22.c AUX-Remove-Lists21.c\
   AUX-Remove-Lists20.c AUX-Remove-Lists19.c AUX-Remove-Lists18.c\
   AUX-Remove-Lists17.c AUX-Remove-Lists16.c AUX-Remove-Lists15.c\
   AUX-Remove-Lists14.c AUX-Remove-Lists13.c AUX-Remove-Lists12.c\
   AUX-Remove-Lists11.c AUX-Remove-Lists10.c AUX-Remove-Lists9.c\
   AUX-Remove-Lists8.c AUX-Remove-Lists7.c AUX-Remove-Lists6.c\
   AUX-Remove-Lists5.c AUX-Remove-Lists4.c AUX-Remove-Lists3.c\
   AUX-Remove-Lists2.c AUX-Remove-Lists1.c AUX-Make-Left-Linear11.c\
   AUX-Make-Left-Linear10.c AUX-Make-Left-Linear9.c AUX-Make-Left-Linear8.c\
   AUX-Make-Left-Linear7.c AUX-Make-Left-Linear6.c AUX-Make-Left-Linear5.c\
   AUX-Make-Left-Linear4.c AUX-Make-Left-Linear3.c AUX-Make-Left-Linear2.c\
   AUX-Make-Left-Linear1.c AUX-Make-Assign-Conds9.c AUX-Make-Assign-Conds8.c\
   AUX-Make-Assign-Conds7.c AUX-Make-Assign-Conds6.c AUX-Make-Assign-Conds5.c\
   AUX-Make-Assign-Conds4.c AUX-Make-Assign-Conds3.c AUX-Make-Assign-Conds2.c\
   AUX-Make-Assign-Conds1.c AUX-AsFix2muASF12.c AUX-AsFix2muASF11.c\
   AUX-AsFix2muASF10.c AUX-AsFix2muASF9.c AUX-AsFix2muASF8.c\
   AUX-AsFix2muASF7.c AUX-AsFix2muASF6.c AUX-AsFix2muASF5.c\
   AUX-AsFix2muASF4.c AUX-AsFix2muASF3.c AUX-AsFix2muASF2.c\
   AUX-AsFix2muASF1.c AUX-MuASF2C7.c AUX-MuASF2C6.c AUX-MuASF2C5.c

SPEC_SRCS8=\
   AUX-MuASF2C4.c AUX-MuASF2C3.c AUX-MuASF2C2.c AUX-MuASF2C1.c\
   AUX-MuASF2MuASF2.c AUX-MuASF2MuASF1.c AUX-AsFix2C3.c AUX-AsFix2C2.c\
   AUX-AsFix2C1.c
SPEC_SRCS = $(SPEC_SRCS1) $(SPEC_SRCS2) $(SPEC_SRCS3) $(SPEC_SRCS4) $(SPEC_SRCS5) $(SPEC_SRCS6) $(SPEC_SRCS7) $(SPEC_SRCS8)

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
