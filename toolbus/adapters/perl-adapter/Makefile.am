bin_PROGRAMS         = perl-adapter
data_DATA            = tb.perl

EXTRA_DIST           = perl-adapter.guide.tex tb.perl

perl_adapter_SOURCES = perl-adapter.c
perl_adapter_LDADD   = -L$(top_builddir)/libtb -ltb

PERL_DEFS            = -DTBPERL=\"$(libdir)/tb.perl\"

INCLUDES             = -I$(top_srcdir)/libtb $(PERL_DEFS)

