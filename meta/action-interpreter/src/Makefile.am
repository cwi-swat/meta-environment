# $Id$

include $(top_srcdir)/make_rules

KERNEL_CONFIGURATION = "$(pkgdatadir)/meta-kernel.properties"
USER_CONFIGURATION = "./meta.buttons"
LIBRARY_PATH = 
API_VERSION=1.0

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I$(ATERM)/include \
        -I${ERROR_SUPPORT}/include
	-I$(PT_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include

bin_PROGRAMS = actioninterpreter
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
	actioninterpreter.h

include_HEADERS = \
	Actions.h \
	Actions_dict.h 

actioninterpreter_SOURCES = \
	actioninterpreter.c \
	action-interpreter.tif.c \
        Actions.c \
        Actions_dict.c

libActions_a_SOURCES = \
	Actions.c \
	Actions_dict.c 

actioninterpreter_LDADD = \
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
