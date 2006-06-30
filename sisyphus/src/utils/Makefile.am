
RUBY_FILES = $(wildcard *.rb)

utilsdir = $(pkgdatadir)/utils

utils_DATA = $(RUBY_FILES) environment.conf

EXTRA_DIST = $(RUBY_FILES) environment.conf.src

CLEANFILES = environment.conf


%.conf : %.conf.src 
	sed "s@__CVS__@$(CVS)@g;\
		s@__SSH__@$(SSH)@g; \
		s@__SUBVERSION__@$(SUBVERSION)@g;" < $< > $@




