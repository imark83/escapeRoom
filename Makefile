SUBDIRS = cesar
CC = gcc
ENCODERS = encode encode2
DOCS = factores poesia crucigrama
LATEX = pdflatex

.PHONY: clean all

all: $(ENCODERS) $(DOCS) softclean
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

encoders: $(ENCODERS)

docs: $(DOCS)

clean:
	rm $(ENCODERS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

softclean:
	rm -f *.aux *.log

%.pdf: %.tex
	$(LATEX) $<

$(DOCS) :
	$(MAKE) $@.pdf

%: %.c
	$(CC) -o $@ $<
