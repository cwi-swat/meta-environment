
bin_PROGRAMS    = RscriptChecker RscriptCalculator Rstore

CFLAGS          = -g -Wall -Wno-unused -O2 -DASF_MAIN

INCLUDES        = -I$(ASCINC) \
	        -I$(PT_SUPPORT)/include \
	        -I$(ERROR_SUPPORT)/include \
	        -I$(ASF_SUPPORT)/include \
	        -I$(ATERM)/include

pkgdata_DATA    = Rscript.trm.tbl

EXTRA_DIST      = \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs)

# ---- RscriptChecker

RscriptChecker_SOURCES	= RscriptChecker.c
RscriptChecker_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm

RscriptChecker.eqs:
	eqs-dump -m RscriptChecker -o RscriptChecker.eqs

RscriptChecker.c:
	asfc -i RscriptChecker.eqs -o RscriptChecker.c -v

# ---- RscriptCalculator

RscriptCalculator_SOURCES	= RscriptCalculator.c
RscriptCalculator_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm

RscriptCalculator.eqs:
	eqs-dump -m RscriptCalculator -o RscriptCalculator.eqs

RscriptCalculator.c:
	asfc -i RscriptCalculator.eqs -o RscriptCalculator.c -v


# ---- Rstore

Rstore_SOURCES	= Rstore.c
Rstore_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm

Rstore.eqs:
	eqs-dump -m Rstore -o Rstore.eqs

Rstore.c:
	asfc -i Rstore.eqs -o Rstore.c -v


# ---- Rscript.trm.tbl

Rscript.trm.tbl:
	pt-dump -m Rscript -o Rscript.trm.tbl



