# $Id$

include $(top_srcdir)/make_rules

SUBDIRS = muasf

bin_PROGRAMS     = asfc
data_DATA        = asfc.idef

EXTRA_DIST       = asfc.idef

#CFLAGS		= -DNO_SHARING

asfc_SOURCES = asfc.tif.c \
               asfc.c \
               chars.c \
               c-code.c \
               asf2muasf.c \
               lex-cons.c \
               muasf2c.c \
               c-compiler.c \
               Compiler.c

noinst_HEADERS = chars.h \
                 c-code.h \
                 asf2muasf.h \
                 lex-cons.h \
                 asfc.tif.h \
                 muasf2c.h \
                 c-compiler.h

asfc_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
               -L$(PT_SUPPORT)/lib -lmept  \
               -L$(ASF_SUPPORT)/lib -lASFME \
               -L./muasf -lMuASF \
               -L$(TOOLBUSLIB)/lib -lATB \
               -L$(ATERM)/lib -lATerm \
		$(SOCKLIBS)

DEFINES = -DASC_SUPPORT=\"$(ASC_SUPPORT)\" \
          -DPT_SUPPORT=\"$(PT_SUPPORT)\"   \
          -DASF_SUPPORT=\"$(ASF_SUPPORT)\"   \
          -DATERM=\"$(ATERM)\"

INCLUDES  = $(DEFINES) \
            -I$(ASC_SUPPORT)/include \
            -I$(PT_SUPPORT)/include \
            -I$(ASF_SUPPORT)/include \
            -I$(ATERM)/include \
            -I$(TOOLBUSLIB)/include \
            -I$(srcdir)/muasf 

