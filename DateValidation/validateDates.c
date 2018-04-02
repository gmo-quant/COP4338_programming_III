#include"validateDates.h"
#include<stdlib.h>
#include<string.h>
#include<limits.h>


boolean validFormat(char * date){
	// date entry with the format of 
	// mm/dd/yyyy
	// that is the 3rd and  6th element in the date string 
	// should be "/"
	if(date[2] == '/' && date[5] == '/'){
		return TRUE;
	}else{
		return FALSE;
	}
}

boolean leapYear(int yy){
	return (((yy%4==0) && (yy%100!=0)) || (yy%400==0));
}

boolean validDate(int month, int day, int year){
	if (year > MAX_VALID_YR || year < INT_MIN){
		return FALSE;
	}
	if( month < JAN || month > DEC ){
		return FALSE;
	}
	if (day < MIN_VALID_DD || day > MAX_VALID_DD ){
		return FALSE;
	}
	// handle February month with leap year
	if (month == FEB){
		if (leapYear(year)){
			return ( day <= (daysPerMonth[FEB]+1) );
		}else{
			return ( day <= (daysPerMonth[FEB]) );
		}
	}
	if ( month == APR || month == JUN || month == SEP || month == NOV){
		return ( day <= daysPerMonth[APR]);
	}
	return TRUE;

}

void convertDate(){

	char buffer[BUFFERSIZE];
	int day;
	int month;
	int year;

	while(!feof(stdin)){
		fgets(buffer, BUFFERSIZE, stdin);
		if (validFormat(buffer)){
			sscanf(buffer, "%d/%d/%d", &month, &day, &year );
			if (validDate(month, day, year)){
				fprintf(stdout, "%d %s %d\n",day,  months[month], year );
			}
		}
	}
}



