SUBDIRS = cesar
CC = gcc
ENCODERS = encode encode2

.PHONY: clean all

all: $(ENCODERS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

encoders: $(ENCODERS)

clean:
	rm $(ENCODERS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done


%.pdf: %.tex
	$(LATEX) $<

# poesia:
# 	$(MAKE) poesia.pdf


%: %.c
	$(CC) -o $@ $<
