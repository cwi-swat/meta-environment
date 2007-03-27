include $(top_srcdir)/Makefile.meta

EXTRA_DIST		+= hello.tb spawn-hello.tb
CLEANFILES		+= toolbus-adapter.[ch]

bin_PROGRAMS        	= toolbus-adapter
include_HEADERS		= toolbus-adapter.idef

INCLUDES            	= -DTBPROG="\"${prefix}/bin/toolbus\"" \
			$(TOOLBUSLIB_CFLAGS) \
			-I${top_srcdir}/aterm \
			-I${top_srcdir}/libdeprecated-toolbus-adapter \
			$(ATERM_CFLAGS) 

toolbus_adapter_SOURCES = toolbus-adapter.idef \
			main.c

toolbus_adapter_LDADD   = -L${top_builddir}/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter \
                         $(TOOLBUSLIB_LIBS) \
			 $(ATERM_LIBS) 

%.tb: %.tbi
	cp $< $@
	echo "process DUMMY is delta" >> $@
	echo "toolbus(DUMMY)" >> $@
