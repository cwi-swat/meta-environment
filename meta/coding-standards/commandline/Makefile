#! gmake

CENTER="Meta-Environment Documentation"
RELEASE="Meta-Conventions 1.0"

target=commandline
files=meta-skel ${target}.7 ${target}.txt ${target}.html ${target}.bok

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
