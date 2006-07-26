
# Just add a file ending with .pt to this directory and the dictonary
# will get updated

EXTRA_DIST=genTermsDict.sh.src $(wildcard *.pt)

check_LIBRARIES = libtestTerms.a
check_SCRIPTS = genTermsDict.sh

nodist_libtestTerms_a_SOURCES = terms_dict.c terms_dict.h
AM_CPPFLAGS=$(ATERM_CFLAGS)

terms_dict.c terms_dict.h : terms.dict
	$(ATERM_PREFIX)/bin/dicttoc -dict $< 

terms.dict: genTermsDict.sh $(srcdir)/*.pt
	./genTermsDict.sh $(srcdir)/*.pt > $@

%.sh: %.sh.src Makefile
	sed 's@__ATERM__@$(ATERM_PREFIX)@g' < $< > $@ && chmod +x $@	

CLEANFILES=terms_dict.c terms_dict.h terms.dict genTermsDict.sh
