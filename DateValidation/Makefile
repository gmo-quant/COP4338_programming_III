CC = gcc
STD = -std=c99
FILES = validateMain.c 
FILES += validateDates.c
VALID_EXE = validDateMain

FILES_D = displayMain.c 
FILES_D += display.c
DISPLY_EXE= displayMain

#EXE += displayMain
build: $(FILES)
	$(CC) $(STD) -o $(VALID_EXE) $(FILES) 
	$(CC) $(STD) -o $(DISPLY_EXE) $(FILES_D)
clean:
	rm -rf *.o core 
	rm  $(VALID_EXE) $(DISPLY_EXE) 

rebuild: clean build

cleanAll:
	rm -rf *.o core $(VALID_EXE) $(DISPLY_EXE) 