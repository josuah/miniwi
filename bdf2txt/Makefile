CC=gcc
CFLAGS=-Wall -ansi -O3 -s

all: bdf2txt txt2bdf

bdf2txt: bdf2txt.c
	$(CC) $(CFLAGS) -o $@ $<

txt2bdf: txt2bdf.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) bdf2txt txt2bdf
