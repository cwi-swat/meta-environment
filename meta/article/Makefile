
include general-make

all: ps

ps: new-meta.ps 

new-meta.ps: new-meta.dvi newmeta.ps toolbus.ps
	dvips -o new-meta.ps new-meta.dvi

new-meta.dvi: new-meta.ltx newarch.tex toolbus.ltx editors.ltx newmeta.ps toolbus.ps

prev: new-meta.dvi
	xdvi new-meta.dvi &

print: new-meta.ps
	lpr new-meta.ps

toolbus.ps: toolbus.fig
	fig2dev -Lps toolbus.fig toolbus.ps
