
# include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore

CFLAGS          = -g -Wall -Wno-unused -O2 -DASF_MAIN

INCLUDES        = -I$(ASCINC) \
	        -I$(PT_SUPPORT)/include \
	        -I$(ERROR_SUPPORT)/include \
	        -I$(ASF_SUPPORT)/include \
	        -I$(ATERM)/include

pkgdata_DATA    = Rscript.trm.tbl Rstore.trm.tbl RscriptChecker.eqs

EXTRA_DIST      = \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs)

# ---- RscriptChecker

RscriptCalculator_SOURCES	= RscriptCalculator.c
RscriptCalculator_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm

# ---- Rstore

Rstore_SOURCES	= Rstore.c
Rstore_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm

# ---- General Make rules

# ---- Generate term parse table from SDF module

%.trm.tbl:: %.sdf
	pt-dump -m $(*F) -o $@

# ---- Convert from .asf to .eqs

%.eqs :: %.asf
	eqs-dump -m $(*F) -o $@

# ---- Convert from .eqs to .c

%.c:: %.asf
	eqs-dump -m $(*F) -o $(*F).eqs
	asfc -i $(*F).eqs -o $(*F) -v



