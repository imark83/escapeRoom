SUBDIRS = cesar
CC = gcc
ENCODERS = encode encode2
LATEX = pdflatex

.PHONY: clean all

all: $(ENCODERS) poesia softclean
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

encoders: $(ENCODERS)

clean:
	rm $(ENCODERS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

softclean:
	rm -f *.aux *.log

%.pdf: %.tex
	$(LATEX) $<

poesia:
	$(MAKE) poesia.pdf


%: %.c
	$(CC) -o $@ $<
