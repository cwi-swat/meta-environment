#! gmake

CENTER="Meta-Environment Documentation"
RELEASE="1.0"

target=sglr
files=${target}.7 ${target}.txt ${target}.html ${target}.bok

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

%.mf: %.pod
	-pod2mf $< > $@

%.ps: %.7
	-groff -man -etp -Tps -C $< > $@

clean:
	-rm -f ${files}
