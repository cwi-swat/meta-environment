# $Id$

include ${top_srcdir}/make_rules

INCLUDES	= -I$(ASC_SUPPORT)/include \
		-I$(PT_SUPPORT)/include \
		-I$(ASF_SUPPORT)/include \
		-I$(ERROR_SUPPORT)/include \
		-I$(TOOLBUSLIB)/include \
		-I$(ATERM)/include

AM_CFLAGS = -DASF_MAIN
bin_PROGRAMS = ActionScriptChecker
bin_SCRIPTS = actionchecker

EXTRA_DIST = ActionScriptChecker.trm.tbl \
		ActionScript.def.pt \
		actionchecker.src

CLEANFILES = actionchecker ActionScriptChecker

ActionScriptChecker_SOURCES = ActionScriptChecker.c
ActionScriptChecker_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
			-L$(SGLR)/lib -lsglr \
			-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(ERROR_SUPPORT)/lib -lErrorAPI \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			${SOCKLIBS}

pkgdata_DATA = ActionScriptChecker.trm.tbl \
		ActionScript.def.pt

% : %.src
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PTPRETTY__@$(PTPRETTY)@g;\
	     s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ && \
	chmod +x $@

asfc: ActionScriptChecker.eqs
	asfc -i ActionScriptChecker.eqs -o ActionScriptChecker.c -v

ActionScriptChecker.eqs:
	cd ../spec ; eqs-dump -m ActionScriptChecker -o ../src/ActionScriptChecker.eqs
