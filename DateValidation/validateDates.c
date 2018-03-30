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


void convertDate(char * date_str, int* date){

	char day[2];
	char month[2];
	char year[4];

	int dd = 0;
	int mm = 0;
	int yy = 0;

	month[0] = date_str[0];
	month[1] =date_str[1];
	day[0] = date_str[3];
	day[1] = date_str[4];
	year[0] = date_str[6];
	year[1] = date_str[7];
	year[2] = date_str[8];
	year[3] = date_str[9];

	date[MONTH] = atoi(month);
	date[DAY]= atoi(day);			
	date[YEAR]= atoi(year);
}

boolean validDate(int* date){
	if (date[YEAR] > INT_MAX || date[YEAR] < INT_MIN){
		return FALSE;
	}
	if( date[MONTH] < JAN || date[MONTH] > DEC ){
		return FALSE;
	}
	if (date[DAY] < MIN_VALID_DD || date[DAY] > MAX_VALID_DD ){
		return FALSE;
	}
	// handle February month with leap year
	if (date[MONTH] == FEB){
		if (leapYear(date[YEAR])){
			return ( date[DAY] <= (daysPerMonth[FEB]+1) );
		}else{
			return ( date[DAY] <= (daysPerMonth[FEB]) );
		}
	}
	if ( date[MONTH] == APR || date[MONTH] == JUN || date[MONTH] == SEP || date[MONTH] == NOV){
		return ( date[DAY] <= daysPerMonth[APR]);
	}
	return TRUE;
}



