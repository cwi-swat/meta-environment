# $Id$

include $(top_srcdir)/make_rules

SUBDIRS = muasf

bin_PROGRAMS     = asfc
pkgdata_DATA     = asfc.idef

EXTRA_DIST       = asfc.idef

asfc_SOURCES = asfc.tif.c \
               asfc.c \
               chars.c \
               c-code.c \
               asf2muasf.c \
               lex-cons.c \
               muasf2c.c \
               c-compiler.c \
               idef.c \
               Compiler.c

noinst_HEADERS = asfc.tif.h \
		 chars.h \
                 c-code.h \
                 asf2muasf.h \
                 lex-cons.h \
                 asfc.tif.h \
                 muasf2c.h \
                 c-compiler.h \
                 idef.h

asfc_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
               -L$(PT_SUPPORT)/lib -lmept -lconversion -lasfix2  \
               -L$(ASF_SUPPORT)/lib -lASFME \
               -L./muasf -lMuASF \
               -L$(TOOLBUSLIB)/lib -lATB \
               -L$(ATERM)/lib -lATerm \
		$(SOCKLIBS)

DEFINES = -DASC_SUPPORT=\"$(ASC_SUPPORT)\" \
          -DPT_SUPPORT=\"$(PT_SUPPORT)\"   \
          -DASF_SUPPORT=\"$(ASF_SUPPORT)\"   \
          -DATERM=\"$(ATERM)\" \
          -DTOOLBUSLIB=\"$(TOOLBUSLIB)\" \
          -DIDEF2TIF=\"$(TOOLBUS)/bin/idef2tif\" \
          -DTIFSTOC=\"$(TOOLBUS)/bin/tifstoc\" \
          -DCOMPILER=\"$(CC)\" \
          -DCOMPILERFLAGS="\"$(CFLAGS)\""

INCLUDES  = $(DEFINES) \
            -I$(ASC_SUPPORT)/include \
            -I$(PT_SUPPORT)/include \
            -I$(ASF_SUPPORT)/include \
            -I$(ATERM)/include \
            -I$(TOOLBUSLIB)/include \
            -I$(srcdir)/muasf 

