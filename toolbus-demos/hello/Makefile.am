noinst_PROGRAMS	= hello hello-gen printer producer store

INCLUDES		= $(TOOLBUSLIB_CFLAGS) $(ATERM_CFLAGS) 

EXTRA_DIST		= 	hello1.tb hello2.tb hello3.tb hello.tcl hello.perl \
					hello.pl hello.pl.tb pipe.tb PC.tb producer.c store.c \
					hello.py hello2py.tb no-pl.sh hello2java.tb \
					Hello.java HelloTool.java

hello_SOURCES		= hello.c
hello_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

hello_gen_SOURCES	= hello-gen.c hello.tif.c hello.tif.h
hello_gen_LDADD		= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS)

printer_SOURCES		= printer.c
printer_LDADD		= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

producer_SOURCES	= producer.c
producer_LDADD		= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

store_SOURCES		= store.c
store_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

%.tif.c %.tif.h: hello2.tifs
	$(top_builddir)/aterm/tifstoc -tool $* $<

%.tifs: %.tb
	${top_builddir}/toolbus/toolbus -gentifs $<
