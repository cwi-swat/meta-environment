include $(top_srcdir)/make_rules

SUBDIRS = muasf .
 
bin_PROGRAMS     = asfc
pkgdata_DATA     = asfc.idef

EXTRA_DIST       = asfc.idef.src

CLEANFILES = asfc.idef

asfc_SOURCES = asfc.tif.c \
               asfc.c \
               chars.c \
               c-code.c \
               asf2muasf.c \
               muasf2c.c \
               c-compiler.c \
               idef.c \
               Compiler.c

noinst_HEADERS = asfc.tif.h \
		 chars.h \
                 c-code.h \
                 asf2muasf.h \
                 asfc.tif.h \
                 muasf2c.h \
                 c-compiler.h \
                 idef.h

asfc_DEPENDENCIES =
asfc_LDADD   = \
               -L./muasf -lMuASF \
	       $(ASC_LD_FLAGS)

DEFINES = -DASC_INCLUDES="\"$(ASC_INCLUDES)\"" \
          -DASC_LD_FLAGS="\"$(ASC_LD_FLAGS)\""   \
          -DIDEF2TIF="\"$(TOOLBUS)/bin/idef2tif\"" \
          -DTIFSTOC="\"$(TOOLBUS)/bin/tifstoc\"" \
          -DCOMPILER="\"$(CC)\"" \
          -DCOMPILERFLAGS="\"$(CFLAGS)\""

INCLUDES  = $(DEFINES) \
	    $(ASC_INCLUDES) \
            -I$(srcdir)/muasf 

bootstrap: 
	asfc -i Compiler.eqs -o Compiler.c -v

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
