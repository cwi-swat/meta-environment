
# Just add a file ending with .pt to this directory and the dictonary
# will get updated

EXTRA_DIST=genTermsDict.sh.src $(wildcard *.pt)

noinst_LIBRARIES=libtestTerms.a
noinst_SCRIPTS=genTermsDict.sh

noinst_HEADERS=terms_dict.h
libtestTerms_a_SOURCES=terms_dict.c

INCLUDES=-I$(ATERM)/include

terms_dict.c: terms.dict
	$(ATERM)/bin/dicttoc -dict $< 

terms.dict: genTermsDict.sh ${srcdir}/*.pt
	./genTermsDict.sh ${srcdir}/*.pt > $@

%.sh: %.sh.src Makefile
	sed 's@__ATERM__@$(ATERM)@g' < $< > $@ && chmod +x $@	

CLEANFILES=*.[ch] *.dict *.sh
