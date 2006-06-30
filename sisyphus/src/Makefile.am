
SUBDIRS = building distribution model updating utils versioning

bin_SCRIPTS = test

RUBY_FILES = $(wildcard *.rb)

srcdir = $(pkgdatadir)

src_DATA = $(RUBY_FILES)

EXTRA_DIST = $(RUBY_FILES) test.sh.src

CLEANFILES = test


% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g" < $< > $@ && chmod +x $@





if MAINTAINER_MODE

.PHONY: doc

doc:
	rdoc --op ../doc/html --inline --diagram 

endif


