include $(top_srcdir)/Makefile.meta

bin_PROGRAMS     = asfc
noinst_PROGRAMS  = test-asfc
pkgdata_DATA     = asfc.idef

EXTRA_DIST       = asfc.idef.src

CLEANFILES += asfc.idef


noinst_HEADERS = asfc.tif.h \
		 chars.h \
                 c-code.h \
                 asf2muasf.h \
                 asfc.tif.h \
                 muasf2c.h \
                 c-compiler.h \
                 idef.h \
		 MuASF.h \
		 MuASF_dict.h



ASFC_C_LINKER=$(shell echo $(LINK) | sed 's@${top_builddir}/libtool@${libexecdir}/libtool@g;s@-o.*@@')
abs_topbuilddir=$(shell cd ${top_builddir}; pwd)
ASFC_TEST_C_LINKER=$(shell echo $(LINK) | sed 's@${top_builddir}/libtool@${abs_topbuilddir}/libtool@g;s@-o.*@@')

asfc_DEPENDENCIES =
asfc_LDADD   = $(ASC_SUPPORT_LIBS)
asfc_CPPFLAGS =  \
		-DASC_SUPPORT_CFLAGS="\"$(ASC_SUPPORT_CFLAGS)\"" \
		-DASC_SUPPORT_LIBS="\"$(ASC_SUPPORT_LIBS)\""   \
		-DIDEF2TIF="\"$(TOOLBUS)/bin/idef2tif\"" \
		-DTIFSTOC="\"$(TOOLBUS)/bin/tifstoc\"" \
		-DCOMPILE="\"$(CC)\"" \
		-DLINK="\"$(ASFC_C_LINKER)\"" \
		$(ASC_SUPPORT_CFLAGS)
asfc_SOURCES = asfc.tif.c \
               asfc.c \
               chars.c \
               c-code.c \
               asf2muasf.c \
               muasf2c.c \
               c-compiler.c \
               idef.c \
               Compiler.c \
	       MuASF.c \
	       MuASF_dict.c

test_asfc_DEPENDENCIES=
test_asfc_LDADD = $(asfc_LDADD)
test_asfc_CPPFLAGS =  \
		-DASC_SUPPORT_CFLAGS="\"$(ASC_SUPPORT_CFLAGS)\"" \
		-DASC_SUPPORT_LIBS="\"$(ASC_SUPPORT_LIBS)\""   \
		-DIDEF2TIF="\"$(TOOLBUS)/bin/idef2tif\"" \
		-DTIFSTOC="\"$(TOOLBUS)/bin/tifstoc\"" \
		-DCOMPILE="\"$(CC)\"" \
		-DLINK="\"$(ASFC_TEST_C_LINKER)\"" \
		$(ASC_SUPPORT_CFLAGS)
test_asfc_SOURCES = $(asfc_SOURCES)

bootstrap: 
	asfc -i Compiler.eqs -o Compiler.c -v

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@


EXTRA_DIST += MuASF.label.def

if MAINTAINER_MODE

LIBRARY=../../../../sdf-library/library
SPEC=../../../../asf-library/library/languages/asf/compiler

MuASF.label.def:
	(echo "definition"; \
	cat ${SPEC}/muasf/MuASF.sdf ; echo ""; \
	cat ${LIBRARY}/basic/Whitespace.sdf; echo ""; \
	cat ${LIBRARY}/basic/StrCon.sdf; echo ""; \
	cat ${LIBRARY}/basic/NatCon.sdf; echo ""; \
	cat ${LIBRARY}/basic/IdentifierCon.sdf ) > $@

api: MuASF.label.def
	sdf2-to-c \
		--input $< \
		--output MuASF \
		--prefix MA_ 

api-clean:
	rm -f MuASF.[ch] MuASF_dict.* MuASF.adt

endif
