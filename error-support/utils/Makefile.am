include $(top_srcdir)/Makefile.meta

SUBDIRS = lift-error lower-error error-diff

EXTRA_DIST = \
	error-support.idef.src

pkgdata_DATA = \
	error-support.idef

noinst_HEADERS = \
	error-support.tif.h

bin_SCRIPTS = $(PACKAGE)-config

bin_PROGRAMS = \
	error-support

AM_CPPFLAGS += \
	-I$(top_srcdir)/lib \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS)

error_support_SOURCES = \
	error-support.tif.c \
	error-support.c

error_support_LDADD = \
	-L../lib -lErrorAPI \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS)

CLEANFILES+=$(bin_SCRIPTS) error-support.idef

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@

$(PACKAGE)-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo $(prefix)/share/$(PACKAGE)/errorapi.jar:$(prefix)/share/$(PACKAGE)/locationapi.jar" \
	) > $@ && chmod +x $@

IDEF = idef2tif
TIFS = tifstoc

tif:
	for i in `ls *.idef`; do \
	  $(IDEF) $$i; \
	  $(TIFS) -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]

