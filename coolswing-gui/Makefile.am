include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

SUBDIRS	= lib

TOOLNAME = swixml-gui

pkgdata_DATA = $(TOOLNAME).idef

EXTRA_DIST += $(TOOLNAME).idef.src

CLEANFILES += $(TOOLNAME).idef

%.idef: %.idef.src Makefile
	sed -e 's@__PKGDATA__@$(datadir)@g'\
            -e 's@__LOCAL_JARS__@$(prefix)/share/j2h.jar:$(prefix)/share/jdom.jar:$(prefix)/share/junit.jar:$(prefix)/share/swixml-gui.jar:$(prefix)/share/swixml.jar:$(prefix)/share/ui.jar@g'\
            -e "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g"\
            -e 's@__JARFILE__@$(JAVA_JAR)@g'\
             < $< > $@

