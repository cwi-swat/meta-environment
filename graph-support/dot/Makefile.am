
bin_PROGRAMS = dot-adapter
pkgdata_DATA = dot-adapter.idef 

EXTRA_DIST = dot-adapter.idef dot.l dot.y

CLEANFILES = lex.yy.c y.tab.c y.tab.h y.output

YFLAGS = -d

INCLUDES = \
	-DDOT_COMMAND=\"${GRAPHVIZ}/bin/dot\" \
	-I${ATERM}/include \
        -I${top_srcdir}/lib \
	-I${TOOLBUSLIB}/include

noinst_HEADERS = dot.h
dot_adapter_SOURCES = dot-adapter.c dot-adapter.tif.c dot-adapter.tif.h
dot_adapter_LDADD = \
	lex.yy.o y.tab.o \
	-L${top_builddir}/lib -lGraph \
	-L${TOOLBUSLIB}/lib -lATB \
	-L$(ATERM)/lib -lATerm

y.tab.c y.tab.h: dot.y
	$(YACC) -v $(AM_YFLAGS) $(YFLAGS) $<

lex.yy.c : dot.l y.tab.h
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $<

IDEF=idef2tif
TIFS=tifstoc

tif:
	for i in `ls *.idef`; do \
          ${IDEF} $$i; \
          ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
        done

tif-clean:
	rm -f *.tifs *.tif.[ch]
