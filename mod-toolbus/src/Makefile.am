## Makefile.am
##

EXTRA_DIST=httpd.tb $(wildcard *.c) $(wildcard *.h)

CLEANFILES=*.la *.lo *.slo

INCLUDES=\
	`$(APACHE)/bin/apr-config --includes` \
	-I$(ATERM)/include \
	-I$(TOOLBUS)/include 

TB_LIBS=\
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm

GCCFLAGS=-Wall -pedantic $(INCLUDES)

include_HEADERS=aterm-html.h utf8.h
SOURCEFILES=\
	mod_toolbus.c\
	aterm-html.c\
	utf8.c

# compile and installs mod_toolbus:
# - creates mod_toolbus.so
# - copies it into Apache's modules/ directory
# - updates Apache's httpd.conf file to register the module so will run
#   automatically next time APache is started
all:
	$(APACHE)/bin/apxs -i -a $(INCLUDES) -c $(SOURCEFILES)  $(TB_LIBS)

# run Toolbus with --viewer
tbrunv:
	echo "use toolbus option -verbose if you like"
	toolbus -I. -viewer httpd.tb

# stop and start Apache
apstop:
	${AP_TARG_BASE}/bin/apachectl stop

aprun:
	${AP_TARG_BASE}/bin/apachectl start	
		
