## Makefile.am
##


EXTRA_DIST=httpd.tb *.c *.h
include_HEADERS=aterm-html.h utf8.h

##noinst_PROGRAMS=mod_toolbus
##mod_toolbus_SOURCES=mod_toolbus.c aterm-html.c utf8.c
##mod_toolbus_LDADD=-L${TOOLBUS}/lib -lATerm -lATB

CLEANFILES=*.la *.lo *.slo

AP_INCLUDES=-I$(APDEVELDIR)/os/unix -I$(APDEVELDIR)/include -I$(APDEVELDIR)/srclib/apr/include -I$(APDEVELDIR)/srclib/apr-util/include
TB_INCLUDES=-I$(TBDIR)/include
INCLUDES=$(AP_INCLUDES) $(TB_INCLUDES)

TB_LIBS=-L$(TBDIR)/lib -lATB -lATerm


GCCFLAGS=-Wall -pedantic $(INCLUDES)




# compile and installs mod_toolbus:
# - creates mod_toolbus.so
# - copies it into Apache's modules/ directory
# - updates Apache's httpd.conf file to register the module so will run
#   automatically next time APache is started
all:
	$(APDIR)/bin/apxs -i -a $(TB_INCLUDES) -c mod_toolbus.c aterm-html.c utf8.c  $(TB_LIBS)

# Makefile.am test target
test: 
	echo $(APDIR) $(TBDIR) $(TBINCLUDES)


# run Toolbus with --viewer
tbrunv:
	echo "use toolbus option -verbose if you like"
	toolbus -I. -viewer httpd.tb

# stop and start Apache
apstop:
	${AP_TARG_BASE}/bin/apachectl stop

aprun:
	${AP_TARG_BASE}/bin/apachectl start	
		
