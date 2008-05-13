# $Id$

include $(top_srcdir)/Makefile.meta

BUILTIN_NAMES_ARITY=\
	set-anno_3\
	get-anno_2\
	get-term-anno_2 \
	get-lex-term-anno_2 \
	set-term-anno_3 \
	execute-command_1 \
	read-from-command_1 \
	term-less_2 \
	lift-to-tree_1 \
	lower-from-tree_1 \
	lift-to-term_1 \
	implode_1\
	parse-file_1 \
	parse-file-pos-info_1 \
	parse-bytes_1 \
	parse-bytes-pos-info_2 \
	unparse-to-bytes_1 \
	unparse-to-file_2 \
	read-term-from-file_1 \
	write-term-to-file_2\
	read-bytes-from-file_1\
	write-bytes-to-file_2\
	tide-connect_2\
	tide-disconnect_1\
	tide-step_1\
	next-id_0

BUILTIN_SOURCEFILES=\
	builtin-common.c \
	builtin-annos.c \
	builtin-term-compare.c \
	builtin-lifting.c \
	builtin-implode.c \
	builtin-io.c \
	builtin-tide.c \
	builtin-unique.c

# The names of the modules that need to be included in a generated lib
SDF_LIBRARY_MODULES=\
	basic/Whitespace \
	basic/StrCon \
	basic/BoolCon \
	basic/NatCon \
	basic/BytesCon \
	basic/Errors \
	basic/Locations \
	basic/Areas \
	basic/ReadWriteCon \
	basic/ParsetreeCon 

ASF_LIBRARY_MODULES=\
	basic/Booleans 

lib_LTLIBRARIES = libasc-support-me.la 

include_HEADERS = \
	asc-support-me.h \
	asc-support2-me.h  \
	asc-traversals.h \
	asc-builtins.h \
	asc-client.h \
	asc-muasf2pt.h \
	asc-ambiguity.h \
	asc-termstore.h \
	builtin-common.h \
	asc-options.h

libasc_support_me_la_CPPFLAGS = $(AM_CPPFLAGS)
libasc_support_me_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libasc_support_me_la_LIBADD = \
	$(SGLR_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(TIDE_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(RSTORE_SUPPORT_LIBS) \
	$(ATERM_LIBS)

libasc_support_me_la_SOURCES = \
	asc-builtins.h \
	asc-main.c\
	asc-support.c \
	asc-nametable.c \
	asc-traversals.c \
	asc-prod2str.c  \
	asc-prod2str.h  \
	asc-muasf2pt.c \
	asc-muasf2pt.h \
	asc-client.c\
	asc-tide.c\
	asc-options.c\
	asc-parsetable.c\
	asc-ambiguity.c\
	asc-termstore.c\
	builtin-forward.c\
	Library.c\
	Library.h\
	Library_dict.c\
	Library_dict.h\
	$(BUILTIN_SOURCEFILES)

# Default include directories
AM_CPPFLAGS += \
	$(PT_SUPPORT_CFLAGS) \
	$(ASF_SUPPORT_CFLAGS) \
	$(RSTORE_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(SGLR_CFLAGS) \
	$(TIDE_SUPPORT_CFLAGS) \
	$(ATERM_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(PTABLE_SUPPORT_CFLAGS)

TESTS = $(check_PROGRAMS)

#Below here should not be changed when adding a builtin:

EXTRA_DIST += Library.def 

# To check whether we implemented all the builtins mentioned we
# generate a program that calls all builtins and try to compile and link 
# it:
check_PROGRAMS = builtin-link-test

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

builtin_link_test_SOURCES=builtin-link-test.c
builtin_link_test_LDADD = \
	-L. -lasc-support-me \
	$(SGLR_LIBS) \
	$(TIDE_SUPPORT_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(ATERM_LIBS) \
	${CONFIG_SUPPORT_LIBS} \
	${PTABLE_SUPPORT_LIBS} 

UTILS=$(top_srcdir)/utils
GENFWD=$(UTILS)/gen-forward.sh
GENPRTS=$(UTILS)/gen-protos.sh
GENLNKTST=$(UTILS)/gen-link-test.sh

CLEANFILES+=builtin-forward.c asc-builtins.h builtin-link-test.c

BUILT_SOURCES=builtin-forward.c asc-builtins.h builtin-link-test.c

builtin-forward.c: asc-builtins.h $(BUILTIN_SOURCEFILES) Makefile
	$(GENFWD) "$(BUILTIN_NAMES_ARITY)" > $@

asc-builtins.h: $(BUILTIN_SOURCEFILES) Makefile
	$(GENPRTS) "$(BUILTIN_NAMES_ARITY)" > $@

builtin-link-test.c: asc-builtins.h $(BUILTIN_SOURCEFILES) Makefile 
	$(GENLNKTST) "$(BUILTIN_NAMES_ARITY)" > $@

# Developers only:
api: Library.def
	sdf2-to-c -i $< -P CO_ -o Library

api-clean:
	rm -f Library.[ch] Library_dict.* Library.adt 

LIBRARYLIST = \
$(foreach i,$(SDF_LIBRARY_MODULES),$(top_srcdir)/../sdf-library/library/$i.sdf) \
$(foreach i,$(ASF_LIBRARY_MODULES),$(top_srcdir)/../asf-library/library/$i.sdf)

Library.def:
	@(echo "definition" ; \
          cat $(LIBRARYLIST)) > \
	  $@
