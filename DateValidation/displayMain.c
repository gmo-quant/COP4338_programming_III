#include<stdio.h>
#include<stdlib.h>
#include"validateDates.h"

int main(){

	char buffer[BUFFERSIZE];
	int day;
	int month;
	int year;

	while(!feof(stdin)){
		fgets(buffer, BUFFERSIZE, stdin);
		fprintf(stdout, "%s\n\n", buffer );
	}
	fprintf(stdout, "\n" );

	static const char filename[] = "./dates.dat";
	FILE *fp = fopen(filename, "r");
	while(!feof(fp)){
		fgets(buffer, BUFFERSIZE, fp);
		fprintf(stdout, "%s", buffer );
	}
	fprintf(stdout, "\n" );
	return EXIT_SUCCESS;
}