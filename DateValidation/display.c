#include"validateDates.h"


/*-------------------------displayValidDates-------------------------------
 *   function: void displayValidDates()
 *
 *    Purpose: display the validated date entries piped from ./validDateMain
 * @param  none
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displayValidDates(){
	char buffer[BUFFERSIZE] = {};
	while(!feof(stdin)){
		buffer[0] = '\0'; // clean the buffer before using it.
		fgets(buffer, BUFFERSIZE, stdin);
		fprintf(stdout, "%s", buffer );
	}
}// displayValidDates

/*-------------------------displayOriginal-------------------------------
 *   function: void displayOriginal()
 *
 *    Purpose: display the original dates entry from "./dates.dat"
 * @param  none
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displayOriginal(){
	char buffer[BUFFERSIZE] = {};
	static const char filename[] = "./dates.dat";
	FILE *fp = fopen(filename, "r");
	while(!feof(fp)){
		fgets(buffer, BUFFERSIZE, fp);
		fprintf(stdout, "%s", buffer );
	}
}// displayOriginalr