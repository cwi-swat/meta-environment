
# bin_PROGRAMS    = RscriptChecker RscriptCalculator Rstore
bin_PROGRAMS    = RscriptChecker

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

RscriptChecker_SOURCES	= RscriptChecker.c
RscriptChecker_LDADD	= -L$(ASCLIB) -lasc-support-me \
	                -L$(SGLR)/lib -lsglr \
	                -L$(ASF_SUPPORT)/lib -lASFME \
	                -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	                -L$(ERROR_SUPPORT)/lib -lErrorAPI \
	                -L$(ATERM)/lib -lATerm
RscriptChecker.c: dump
	asfc -i RscriptChecker.eqs -o RscriptChecker.c -v


table:
	pt-dump -m Rscript -o Rscript.trm.tbl

compile-spec: dump asfc

dump:
	eqs-dump -m RscriptChecker -o RscriptChecker.eqs
	eqs-dump -m RscriptCalculator -o RscriptCalculator.eqs
	eqs-dump -m Rstore -o Rstore.eqs

asfc:

	asfc -i RscriptCalculator.eqs -o RscriptCalculator.c -v
	asfc -i Rstore.eqs -o Rstore.c -v

