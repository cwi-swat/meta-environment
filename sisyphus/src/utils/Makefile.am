
RUBY_FILES = $(wildcard *.rb)

utilsdir = $(pkgdatadir)/utils

utils_DATA = $(RUBY_FILES) environment.conf

EXTRA_DIST = $(RUBY_FILES) environment.conf.src

CLEANFILES = environment.conf


%.conf : %.conf.src Makefile
	sed "s@__CVS__@$(CVS_PREFIX)@g;\
		s@__SSH__@$(SSH_PREFIX)@g; \
		s@__SUBVERSION__@$(SUBVERSION_PREFIX)@g;" < $< > $@




