
bin_SCRIPTS	= test

RUBY_FILES	= $(wildcard *.rb)

pkgdata_DATA    = $(RUBY_FILES) environment.conf

EXTRA_DIST	= $(RUBY_FILES) environment.conf.src test.sh.src

CLEANFILES	= environment.conf test




% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g" < $< > $@ && chmod +x $@




%.conf : %.conf.src 
	sed "s@__CVS__@$(CVS)@g;\
		s@__SSH__@$(SSH)@g; \
		s@__SUBVERSION__@$(SUBVERSION)@g;" < $< > $@


if MAINTAINER_MODE

.PHONY: doc

doc:
	rdoc --op ../doc/html --inline --diagram 

endif


