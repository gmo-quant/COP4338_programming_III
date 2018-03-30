#include<stdio.h>
#include<stdlib.h>
#include"validateDates.h"

int main(){

	daysPerMonth day;
	day = jan;
	if (jan == 31){
		printf("%d\n", day.febl );
	}
	printf("%d ", day);
	// char buffer[BUFFERSIZE];
	// while(!feof(stdin)){
	// 	fgets(buffer, BUFFERSIZE, stdin);
	// 	if (validDate(buffer)){
	// 		fprintf(stdout, "read: %s", buffer);
	// 	}
	// }


	// // display original file


	// FILE * fp;
	// fp = fopen(DEFALT_FILE, "r" );
	// while(!feof(fp)){
	// 	fgets(buffer, BUFFERSIZE, fp);
	// 	if (validDate(buffer)){
	// 		fprintf(stderr, "read: %s", buffer);
	// 	}
	// }
	// fclose(fp);
	return EXIT_SUCCESS;
}