
include general-make

INPUTS = editors.ltx new-meta.ltx toolbus.ltx ui.ltx \
         interpreter.ltx repos.ltx treerepr.ltx newarch.tex 

PICTURES = newmeta.ps toolbus.ps

all: ps

ps: new-meta.ps 

new-meta.ps: new-meta.dvi 
	dvips -o new-meta.ps new-meta.dvi

new-meta.dvi: $(INPUTS) $(PICTURES)

prev: new-meta.dvi
	xdvi new-meta.dvi &

print: new-meta.ps
	lpr new-meta.ps

toolbus.ps: toolbus.fig
	fig2dev -Lps toolbus.fig toolbus.ps
