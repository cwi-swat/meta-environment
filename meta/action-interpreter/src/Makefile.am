# $Id$

include $(top_srcdir)/make_rules

KERNEL_CONFIGURATION = "$(pkgdatadir)/meta-kernel.properties"
USER_CONFIGURATION = "./meta.buttons"
LIBRARY_PATH = 
API_VERSION=1.0

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I$(PT_SUPPORT)/include \
        -I${ERROR_SUPPORT}/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

bin_PROGRAMS = action-interpreter
#bin_SCRIPTS = metaconfig-config
#noinst_SCRIPTS = metaconfig-config.local
noinst_LIBRARIES = libActions.a

pkgdata_DATA = \
	action-interpreter.idef

CLEANFILES = \
	${noinst_SCRIPTS} \
	${bin_SCRIPTS}

EXTRA_DIST = \
	action-interpreter.idef 

noinst_HEADERS = \
	action-interpreter.tif.h \
	action-interpreter.h

include_HEADERS = \
	Actions.h \
	Actions_dict.h 

action_interpreter_SOURCES = \
	action-interpreter.c \
	action-interpreter.tif.c \
        Actions.c \
        Actions_dict.c

libActions_a_SOURCES = \
	Actions.c \
	Actions_dict.c 

action_interpreter_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	-L$(PT_SUPPORT)/lib -lmept \
	$(SOCKLIBS)

absolute_srcdir=$(shell cd ${srcdir}; pwd)

%.local: %.src Makefile
	sed     's@__VERSION__@${API_VERSION}@g;\
	        s@__PREFIX__@${absolute_srcdir}@g' \
	< $< > $@ && chmod +x $@

%: %.src Makefile
	sed     's@__VERSION__@${API_VERSION}@g;\
                 s@__PREFIX__@${prefix}/share/meta@g' \
        < $< > $@ && chmod +x $@

%.tb: %.tb.src Makefile
	sed 's@__KERNEL_CONFIGURATION__@$(KERNEL_CONFIGURATION)@g;\
	    s@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@

api:
	adt-to-c \
		--input actions.adt \
		--name Actions \
		--prefix AC_ \
		--output . 
