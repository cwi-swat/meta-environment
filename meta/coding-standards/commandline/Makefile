#! gmake

CENTER="Meta-Environment Documentation"
RELEASE="Meta-Conventions 1.0"

doc=commandline
files=${doc}.7 ${doc}.txt ${doc}.html ${doc}.bok

all:	${files}

%.7:	%.pod
	pod2man --center=${CENTER} --release=${RELEASE} --section=7 $< > $@
		
%.txt: %.pod
	pod2text $< > $@

%.html: %.pod
	pod2html $< > $@
	rm -f pod2html-*


%.bok: %.pod
	pod2docbook $< > $@

clean:
	rm -f ${files}
