include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

SUBDIRS = lib

bin_SCRIPTS = toolbus toolbus-viewer

CLEANFILES += toolbus toolbus-viewer

EXTRA_DIST += $(wildcard *.src)

LOCAL_INSTALLED_JARS=`echo $(JAVA_LOCAL_JARS) | sed "s@lib/@$(prefix)/share/@g;"`

% : %.sh.src Makefile
	sed "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g;\
	s@__LOCAL_JARS__@$(LOCAL_INSTALLED_JARS)@g;\
	s@__TOOLBUS_JAR__@$(prefix)/share/$(JAVA_JAR)@g;" < $< > $@ && chmod +x $@
