CC = gcc
STD = -std=c99
FILES = validateMain.c 
FILES += validateDates.c
OUT_EXE = validateMain

FILES_D = displayMain.c
FILES_D += validateDates.c
OUT_EXE_DISPLAY= displayMain
EXE = validateMain
#EXE += displayMain
build: $(FILES)
	$(CC) $(STD) -o $(OUT_EXE) $(FILES) 
#	$(CC) $(STD) -o $(OUT_EXE_DISPLAY) $(FILES_D)
clean:
	rm -rf *.o core 
	rm  $(EXE)

rebuild: clean build

cleanAll:
	rm -rf *.o core $(OUT_EXE)