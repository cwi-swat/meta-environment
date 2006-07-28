SUBDIRS = sisyphus-model

RUBY_FILES = $(wildcard *.rb)

rubyfilesdir = $(pkgdatadir)

rubyfiles_DATA = $(RUBY_FILES)

EXTRA_DIST = $(RUBY_FILES)

if MAINTAINER_MODE

.PHONY: doc

doc:
	rdoc --op ../doc/html --inline --diagram 

endif


