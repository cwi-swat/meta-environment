# $Id$

SUBDIRS         = terms eqs ref fail

TESTS           = prepare-restore-test  regress-test

EXTRA_DIST      = prepare-restore-test.sh.src \
                  regress-test.sh.src 

noinst_PROGRAMS = prepare-restore 

CLEANFILES      = $(TESTS)

prepare_restore_SOURCES	= prepare-restore.c

prepare_restore_LDADD	= -L../src -leval \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(TOOLBUS)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			${TIDELIB} $(SOCKLIBS) 
	

prepare-restore.o: ../src/libeval.a

INCLUDES		= -I$(srcdir)/../src \
			-I$(ASC)/include \
			-I$(TOOLBUS)/include \
			-I$(ATERM)/include \
			-I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include

% : %.sh.src Makefile
	sed 's@__TOOLBUS__@$(TOOLBUS)/bin/toolbus@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__SRCDIR__@$(srcdir)@g' < $< > $@ && \
	chmod +x $@
