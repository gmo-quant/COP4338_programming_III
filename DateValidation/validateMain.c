#include<stdio.h> // exit, EXIT_SUCCESS
#include<stdlib.h>
#include<string.h> // atoi
#include"validateDates.h"

/* ===========================================================
|
|  
| 	 date: 2018-4-3 10:17:58
| Source code: validateMain.c
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  5  validateMain.c
|      Course: COP 4338 (Advanced Programming) 
|    Section : U01 
|  Instructor: William Feild 
|    Due Date: 
|    
|      I hereby certify that this collcetive work is my own 
|      and none of it is the work of any other person or entiry. 
|      _________________________________________[Guangzhuan Mo]
|
|    Language: C
| Compile/Run:
| 	use make file:
| 		go to the folder DateValidation
| 		$ make
|	use gcc cmd:
|		gcc -std=c99 -o validDateMain validateMain.c  validateDates.c
|		gcc -std=c99 -o displayMain displayMain.c  display.c
|
|	to run the program:
|		$ /validDateMain < dates.dat <number of valid entry> | ./displayMain > output.dat
|		for example:
| 		for example : \n\n\
|			./validDateMain < dates.dat 0 | ./displayMain > output.dat 
|		indicates input all valid entries from the dates input file
|			./validDateMain < dates.dat 5 | ./displayMain > output.dat 
|		indicates input 5 valid entries from the dates input file 
|
| +---------------------------------------------------------------
|
| Description:
|	accept input for ./validDateMain via the command-line arguments
| 	command line input will be the number of valid entries (>= 0)
|	a zero indicates to input all valid entries from the dates.dat
|  	the command line input is validated
|   
|	./validDateMain will validate dates only in valid month/day/year format, 
|	skipping any corrupt dates in the dates.dat file.
|
|	./displayMain will accept those validated dates in the month/day/year format 
|	and will convert each of them to the day, abbreviated month & year format
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	the date entry in the dates.dat file should be well formatted
| 	you can't have empty line 
|	the program operates correctly
|
 * ===========================================================*/
int main(int argc, char * argv[]){
	if (!validArg(argc, argv)){
		 exit(EXIT_FAILURE);
	}
	convertDate(atoi(argv[ARG_DATES_LIMIT]) );
	return 	EXIT_SUCCESS;

}