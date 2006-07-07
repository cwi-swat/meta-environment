
SUBDIRS = building distribution model release updating utils versioning

noinst_SCRIPTS = test

RUBY_FILES = $(wildcard *.rb)

rubyfilesdir = $(pkgdatadir)

rubyfiles_DATA = $(RUBY_FILES)

EXTRA_DIST = $(RUBY_FILES) test.sh.src

CLEANFILES = test


% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g" < $< > $@ && chmod +x $@

if MAINTAINER_MODE

.PHONY: doc

doc:
	rdoc --op ../doc/html --inline --diagram 

endif


