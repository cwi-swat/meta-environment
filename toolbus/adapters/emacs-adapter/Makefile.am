bin_PROGRAMS          = emacs-adapter

bin_SCRIPTS           = start-emacs

data_DATA             = tb.el

EXTRA_DIST            = start-emacs.src tb.el

CLEANFILES            = start-emacs

emacs_adapter_SOURCES = emacs-adapter.c
emacs_adapter_LDADD   = -L$(top_builddir)/libtb -ltb

INCLUDES              = -I$(top_srcdir)/libtb

start-emacs : start-emacs.src Makefile
	sed 's#__DATADIR__#$(datadir)#g' < $< > $@

