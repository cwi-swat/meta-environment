#
# $Id$
#

KINDS = meta-header sglr-header pgen-header asc-header
EXTS = .c-style .sh-style .autoconf .tex-style .html

ALLHEADERS = $(foreach ext, $(EXTS), $(addsuffix $(ext), $(KINDS)))


all: $(ALLHEADERS)

clean:
	rm -f $(ALLHEADERS)

meta-header.base: header.base
	sed 's/TOOLDESC/Meta-Environment - An environment for language prototyping./' < $< > $@

sglr-header.base: header.base
	sed 's/TOOLDESC/SGLR - the Scannerless Generalized LR parser./' < $< > $@

pgen-header.base: header.base
	sed 's/TOOLDESC/PGEN - the SDF2 parse table generator./' < $< > $@

asc-header.base: header.base
	sed 's/TOOLDESC/Asf Sdf Compiler Runtime Library/' < $< > $@

# for .c and .tb
%.c-style: %.base
	( echo '/*'; \
	  cat $<; \
	  echo '*/'; \
	) > $@

# for makefiles, shellscripts and pod
%.sh-style: %.base
	sed 's/^/#/g' < $< > $@

%.autoconf: %.base
	sed 's/^/dnl/g' < $< > $@

# for asf+sdf spec and tex files
%.tex-style: %.base
	sed 's/^/%%/g' < $< > $@

%.html: %.base
	( echo '<!--'; \
	  cat $<; \
	  echo '-->'; \
	) > $@

