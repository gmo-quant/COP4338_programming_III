#ifndef VALIDATEDATES_H
#define VALIDATEDATES_H

#include<stdio.h>

#define ARG_AMT 1
#define ARG_DATES_LIMIT 1 
#define BUFFERSIZE	50
#define IDX_DAY 0
#define IDX_MONTH 3
#define IDX_YEAR 6
#define SEPARATOR "/"

#define READ_ALL_ENTRIES 0

#define DEFALT_FILE "./dates.dat"


// month year abbreviation
#define JAN_ABBR "JAN"
#define FEB_ABBR "FEB"
#define MAR_ABBR "MAR"
#define APR_ABBR "APR"
#define MAY_ABBR "MAY"
#define JUN_ABBR "JUN"
#define JUL_ABBR "JUL"
#define AUG_ABBR "AUG"
#define SEP_ABBR "SEP"
#define OCT_ABBR "OCT"
#define NOV_ABBR "NOV"
#define DEC_ABBR "DEC"

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12


#define MAX_VALID_YR 9999
#define MIN_VALID_YR 1800
#define MAX_VALID_DD 31
#define MIN_VALID_DD 1

#define MONTH 0
#define DAY 1
#define YEAR 2

typedef enum {TRUE = 1, FALSE = 0} boolean ;


static char*  months[] = {" ", JAN_ABBR, FEB_ABBR, MAR_ABBR, APR_ABBR, MAY_ABBR, JUN_ABBR, JUL_ABBR, AUG_ABBR, SEP_ABBR, OCT_ABBR, NOV_ABBR, DEC_ABBR};
static int daysPerMonth[] = {0, 31, 28,  31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



boolean validFormat(char * date);

boolean leapYear(int yy);	// if it is leap year
// boolean validDate(int * date);
boolean validDate(int month, int day, int year);
void convertDate(char * date_str, int* date);



#endif