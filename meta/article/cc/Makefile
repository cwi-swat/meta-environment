
FIG	= evalexp-mlin.fig evalexp-tlog.fig evalsym-tlog.fig evaltree-tlin.fig \
	evalexp-tlin.eps evalsym-tlin.fig evaltree-mlin.fig evaltree-tlog.fig

EPS	= evalexp-mlin.eps evalexp-tlog.eps evalsym-tlog.eps evaltree-tlin.eps \
    evalexp-tlin.eps evalsym-tlin.eps evaltree-mlin.eps evaltree-tlog.eps

include general-make

all: format.ps

%.eps: %.fig
	fig2dev -Lps $< $@

format.ps: format.dvi
	dvips -o format.ps format.dvi

format.dvi: format.ltx ${EPS}
