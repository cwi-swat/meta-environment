bin_PROGRAMS = swipl-adapter  
bin_SCRIPTS  = tbswipl 

EXTRA_DIST   = swipl-adapter.guide.tex swipl.c.nw test.pl test.tb tbswipl 


swipl_SOURCES = swipl.c
swipl_LDADD   = $(SWIPL_LIBS) -L$(top_builddir)/libtb -ltb


SWIPL           = /home/olivierp/pl-2.7.8
ARCH            = sparc-solaris2.4

SWIPL_INCLUDES  = -I$(SWIPL)/include
SWIPL_LIBS      = -L$(SWIPL)/runtime/$(ARCH) -lpl -ldl \
                  -lelf -lreadline -ltermcap

INCLUDES     = $(SWIPL_INCLUDES) -I$(top_srcdir)/libtb


% %.tex : %.nw
	$(NOWEB) $<


