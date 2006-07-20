
# Just add a file ending with .pt to this directory and the dictonary
# will get updated

EXTRA_DIST=genTermsDict.sh.src $(wildcard *.pt)

check_LIBRARIES=libtestTerms.a
check_SCRIPTS=genTermsDict.sh
check_HEADERS=terms_dict.h

libtestTerms_a_SOURCES=terms_dict.c

INCLUDES=-I$(ATERM)/include

terms_dict.c terms_dict.h : terms.dict
	$(ATERM)/bin/dicttoc -dict $< 

terms.dict: genTermsDict.sh ${srcdir}/*.pt
	./genTermsDict.sh ${srcdir}/*.pt > $@

%.sh: %.sh.src Makefile
	sed 's@__ATERM__@$(ATERM)@g' < $< > $@ && chmod +x $@	

CLEANFILES=*.[ch] *.dict *.sh
