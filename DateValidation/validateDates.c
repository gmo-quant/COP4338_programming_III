#include"validateDates.h"
#include<stdlib.h>
#include<string.h>
#include<limits.h>



/*-------------------------validArg-------------------------------
 *   function: boolean validArg(const int argc,  char* const argv[])
 *
 *    Purpose: determine whether the cmd of the user is valide 
 *				argc should be ARG_AMT
 *
 * @param  argc, argv[]
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean validArg(const int argc,  char* const argv[]){
	char* instruction = "\n \t please use the following  command:  \n\n\
	\t./validDateMain < dates.dat <number of valid entry> | ./displayMain > output.dat\n\n\
	to start ,\n\n\
	number of valid entry should be no less than 0\n\n\
	if it is 0, it will handle the whole list\n\n\
	for example : \n\n\
		./validDateMain < dates.dat 0 | ./displayMain > output.dat \n\n\
	indicates input all valid entries from the dates input file\n\n\
		./validDateMain < dates.dat 5 | ./displayMain > output.dat \n\n\
	indicates input 5 valid entries from the dates input file \n";

	char warning[BUFF_LEN] ; 
	sprintf(warning, 
		RED"\n \tWARNING: \n\n \tnumber of players should be no less than 0 \n"RESET);

	// check if the argument count is equal to ARG_AMT as required.
	if (argc != ARG_AMT){
		fprintf(stderr, "%s\n", instruction );
		return FALSE;
	}
	if (atoi(argv[ARG_DATES_LIMIT]) >= 0 ){
		return TRUE;
	}else{
		// warn the user that 
		fprintf(stderr, " %s\n", warning);
		return FALSE;
	}
} // validArg


/*-------------------------boolean validFormat-------------------------------
 *   function: boolean validFormat(char * date)
 *    Purpose: determine whether the date entry is valid 
 *			the dates entry should be in the format of "mm/dd/yyyy"
 * @param  playerAmt
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean validFormat(char * date){
	int month, day, year;
	if ( ! sscanf(date, "%d/%d/%d", &month, &day, &year )){
		return FALSE;
	}else{
		return TRUE;
	}
}// validFormat

/*-------------------------leapYeart-------------------------------
 *   function: boolean leapYear(int yy)
 *    Purpose: determine whether it is a leap year
 * @param  yy
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean leapYear(int yy){
	return (((yy%4==0) && (yy%100!=0)) || (yy%400==0));
}


/*-------------------------validDate-------------------------------
 *   function: boolean validDate(int month, int day, int year)
 *    Purpose: determine whether it is month, day, year is valid of 
 * 				common sense.
 * @param  month, day, year
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
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
} // validDate

/*-------------------------convertDate-------------------------------
 *   function: void convertDate(int limit)
 *    Purpose: convert the validated dates in the month/day/year format 
 *	to the day, abbreviated month year format
 * @param  limit, limit of validated date entry to convert
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
void convertDate(int limit){

	char buffer[BUFFERSIZE] ={};
	int day;
	int month;
	int year;
	int counter = 0; // track the amount of date entry converted.
	if (limit == READ_ALL_ENTRIES ){
		while(!feof(stdin)){
			buffer[0] = '\0'; // clean the buffer before using it.
			fgets(buffer, BUFFERSIZE, stdin);
			if (validFormat(buffer)){
				sscanf(buffer, "%d/%d/%d", &month, &day, &year );
				if (validDate(month, day, year)){
					fprintf(stdout, "%d %s %d\n",day,  months[month], year );
				} // if validDate
			}// if validFormat
		}// while 
	}// if READ_ALL_ENTRIES
	else{
		while(!feof(stdin) && counter < limit ){
			buffer[0] = '\0'; // clean the buffer before using it.
			fgets(buffer, BUFFERSIZE, stdin);
			if (validFormat(buffer)){
				sscanf(buffer, "%d/%d/%d", &month, &day, &year );
				if (validDate(month, day, year)){
					counter++;
					fprintf(stdout, "%d %s %d\n",day,  months[month], year );
				} // if validDate
			}// if validFormat
		} // while 
	}// if have limit 
}// end converDate(int limit)



