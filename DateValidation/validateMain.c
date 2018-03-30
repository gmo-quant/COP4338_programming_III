#include<stdio.h>
#include<stdlib.h>
#include"validateDates.h"
int main(int argc, char * argv[]){


	char buffer[BUFFERSIZE];
	int date[3] ;
	while(!feof(stdin)){
		fgets(buffer, BUFFERSIZE, stdin);
		if (validFormat(buffer)){
			convertDate(buffer, date);
			if (validDate(date)){
				printf("valid date : %s", buffer);
				printf("\t %d %s %d\n",date[DAY],  months[date[MONTH]], date[YEAR] );
			}
		}
	}
	printf("%s\n","" );

	return 	EXIT_SUCCESS;

}