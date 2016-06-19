MAIN=ppt
LATEX=pdflatex
BIBTEX=bibtex
RM=rm -f

.SUFFIXES: .tex

all: $(MAIN).pdf

$(MAIN).pdf: *.tex
	$(LATEX) $(MAIN)

clean:
	$(RM) *.log *.aux *.dvi *.lof *.lot *.toc *.bbl *.blg *.nav *.snm *.out

clean-pdf: 
	$(RM) *.pdf

clean-all: clean clean-pdf
