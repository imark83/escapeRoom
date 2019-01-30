LATEX = pdflatex

FILES = cesar

all: $(FILES) softclean

.PHONY: clean softclean

clean:
	rm -f *.aux *.log *.pdf

softclean:
	rm -f *.aux *.log

%.pdf: %.tex
	$(LATEX) $<

$(FILES) :
	$(MAKE) $@.pdf
