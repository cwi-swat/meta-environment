
include general-make

all: new-meta.ps

new-meta.ps: new-meta.dvi 
	dvips new-meta.dvi

new-meta.dvi: new-meta.ltx newarch.tex toolbus.ps future-debugging.ltx

toolbus.ps: toolbus.fig
	fig2dev -Lps toolbus.fig toolbus.ps
