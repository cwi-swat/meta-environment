.SUFFIXES: .tex .dvi .pic

.tex.dvi:
	latex $*
	bibtex $*
	latex $*
	latex $*

README.dvi: README.tex
