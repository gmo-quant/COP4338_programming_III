CC = gcc
STD = -std=c99
FILES = Card.c Deck.c MainHand.c
OUT_EXE = MainHand

build: $(FILES)
	$(CC) $(STD) -o $(OUT_EXE) $(FILES) 

clean:
	rm -rf *.o core 

rebuild: clean build

cleanAll:
	rm -rf *.o core $(OUT_EXE)