# $Id$

include ${top_srcdir}/make_rules

INCLUDES	= -I$(ASC_SUPPORT)/include \
		-I$(PT_SUPPORT)/include \
		-I$(ASF_SUPPORT)/include \
		-I$(ATERM)/include

CFLAGS += -DASF_MAIN
bin_PROGRAMS = ActionScriptChecker
bin_SCRIPTS = actionchecker

EXTRA_DIST = ActionScriptChecker.trm.tbl \
		ActionScript.def.pt \
		actionchecker.src

CLEANFILES = actionchecker ActionScriptChecker

ActionScriptChecker_SOURCES = ActionScriptChecker.c
ActionScriptChecker_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
			-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(ATERM)/lib -lATerm

pkgdata_DATA = ActionScriptChecker.trm.tbl \
		ActionScript.def.pt

% : %.src
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PTPRETTY__@$(PTPRETTY)@g;\
	     s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ && \
	chmod +x $@
