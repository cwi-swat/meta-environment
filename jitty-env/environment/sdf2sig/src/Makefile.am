

bin_PROGRAMS = Sdf2Sig

pkgdata_DATA = Sdf2Sig.idef

Sdf2Sig_SOURCES = Sdf2Sig.c toolSdf2Sig.tif.c
Sdf2Sig_LDADD =  -L$(ASC_SUPPORT)/lib -ltb-asc-support-me \
                 -L$(PT_SUPPORT)/lib -lmept \
                 -L$(ASF_SUPPORT)/lib -lASFME \
                 -L$(TOOLBUSLIB)/lib -lATB \
                 -L$(ATERM)/lib -lATerm 

noinst_HEADERS = toolSdf2Sig.tif.h

INCLUDES = -DASF_MAIN -DTOOLBUS \
                -I${ATERM}/include \
                -I${TOOLBUSLIB}/include \
                -I${PT_SUPPORT}/include \
                -I${ASF_SUPPORT}/include \
                -I${ASC_SUPPORT}/include

