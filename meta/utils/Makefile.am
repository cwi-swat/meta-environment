# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS       = meta-paths imports imports_mept
bin_SCRIPTS        = parse-file parse-sdf2 ps-dot insert-license \
                     insert-header change-sdf2-ext sdf2stats \
                     change-eqs-ext

man_MANS           = parse-sdf2.1

data_DATA          = lang.types

noinst_LIBRARIES   = libutils.a

EXTRA_DIST         = parse-file.sh.src parse-sdf2.sh.src \
                     ps-dot.sh.src insert-header.pl.src \
                     insert-license.sh.src test-help test-version \
                     lang.types perform-test.sh.src \
                     parse-sdf2.pod change-sdf2-ext \
                     sdf2stats.sh.src change-eqs-ext imports.c

CLEANFILES         = parse-file parse-sdf2 ps-dot insert-header \
                     insert-license perform-test parse-sdf2.1 \
                     sdf2stats

meta_paths_SOURCES = meta-paths.c
meta_paths_LDADD   = libutils.a \
                     -L$(ATERM)/lib -lATerm

imports_SOURCES    = 
imports_LDADD      = imports.o libutils.a \
                     -L$(PT_SUPPORT)/lib -lPT \
                     -L$(SDF_SUPPORT)/lib -lSDF \
                     -L$(ATERM)/lib -lATerm

imports_mept_SOURCES	=
imports_mept_LDADD      = imports-mept.o \
			meta-utils-mept.o \
			module-utils-mept.o \
                     	-L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(ATERM)/lib -lATerm

imports.o: ${srcdir}/imports.c
	${COMPILE} -DASFIX1 -c $< -o $@

imports-mept.o: ${srcdir}/imports.c
	${COMPILE} -DMEPT -c $< -o $@

meta-utils-mept.o: ${srcdir}/meta-utils.c
	${COMPILE} -DMEPT -c $< -o $@

module-utils-mept.o: ${srcdir}/module-utils.c
	${COMPILE} -DMEPT -c $< -o $@

libutils_a_SOURCES = meta-utils.c meta-utils.h module-utils.c module-utils.h

INCLUDES           = -I$(SDF_SUPPORT)/include \
                     -I$(PT_SUPPORT)/include \
                     -I$(ATERM)/include

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
	     s@__VERSION__@$(VERSION)@g;\
	     s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

%: %.pl.src Makefile
	sed 's@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@
