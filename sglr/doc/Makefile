#! gmake
# $Id$

CENTER="Meta-Environment Documentation"
RELEASE="1.0"

target=a2toa1 sglr tree2dot
files=	${addsuffix .7,${target}} ${addsuffix .txt,${target}} \
	${addsuffix .html,${target}} ${addsuffix .bok,${target}}

all:	${files}

# Unit test target
test:	all
	@echo "Unit test not yet implemented for: ${BINFILES}"; false

%.7:	%.pod
	-pod2man --center=${CENTER} --release=${RELEASE} --section=7 $< > $@
		
%.txt: %.pod
	-pod2text $< > $@

%.html: %.pod
	-pod2html $< > $@
	-rm -f pod2html-*


%.bok: %.pod
	-pod2docbook $< > $@

clean:
	-rm -f ${files}
