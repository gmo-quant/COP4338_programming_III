#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validateDates.h"
int main(int argc, char * argv[]){


	char buffer[BUFFERSIZE];
	char str[BUFFERSIZE];
	int day;
	int month;
	int year;
	int i = 0;
	char ch = ' ';
	int date[3] ;
	while(!feof(stdin)){
		fgets(buffer, BUFFERSIZE, stdin);


		// i = sprintf(str, "%s", buffer);
		// printf("%s : %d \n", "string length", i  );
		// if (str[11] == '\n'){
		// 	printf("%s: %d\n", "string lengths ", i-2 );
		// }

		if (validFormat(buffer)){
			sscanf(buffer, "%d/%d/%d", &month, &day, &year );
			printf("the string is : %d/%d/%d \n", month, day, year);
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