/* ===========================================================
|  
| 	 date: 2018-01-23 19:18:47
| Source code: FaherenheitAndCelsiusConvertionTable.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  1  FaherenheitAndCelsiusConvertionTable
|      Course: COP 4338 (Advanced Programming) 
|    Section : U01 
|  Instructor: William Feild 
|    Due Date: 30 January, 2018
|    
|      I hereby certify that this collcetive work is my own 
|      and none of it is the work of any other person or entiry. 
|      _________________________________________[Guangzhuan Mo]
|
|    Language: C
| Compile/Run:
|	gcc FaherenheitAndCelsiusConvertionTable.c -o FaherenheitAndCelsiusConvertionTable
| to run:
|	chmod a+x FaherenheitAndCelsiusConvertionTable
|	./FaherenheitAndCelsiusConvertionTable
|
| +---------------------------------------------------------------
|
| Description:
|
| 	Input: 
|		user input: 
|
|			integer temperature step in the range [1-9]
| 	ex. 
| 		5
|
|      Output:
|
|			Faherenheit & Celsius conversion table
|	ex.
|		Fahrenheit	Celsius		Celsius		Fahrenheit
|		-80.0		-62.2		-80.0		-112.0
|		-75.0		-59.4		-75.0		-103.0
|		....
|		280.0		...			...			...
|
|     Process:
|	the program's steps are as follows:
|
|	accept user input for the step
|
|		int step = getStep();
|
|	validate the step fall within range [1-9]
|
|		rangeValidate(int step);
|
|	loop: start from -80.0 to +320.0
		modification : 
			start from -20 to +280

		only change the macro FROMDEGREE, TODEGREE
|		convert F to C
|
|			float C = Faherenheit2Celsius(float F);
|
|		convert C to F
|
|			float F = Celsius2Faherenheit(float C);
|
|		print a record	
|					
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	None;
|	the program operates correctly
|
 * ===========================================================*/
#include<stdio.h>	// to use printf();, scanf should include file stdio.h
#include<stdlib.h>	// to use fflush();, 
#include<ctype.h> 	// to use atoi();
#include<string.h>	// to use atoi();

#define TRUE 1
#define FALSE 0
#define FROMDEGREE -20.0
#define TODEGREE 280.0
#define SECTION_MEMRS 8 // determine how many lines of conversion in a section
#define NSIZE 1 // to simplify the validation, as step range from 1 to 9, it is 1 palce, 
				// if it is from 1 to 99, then change it to 2
#define MAX 9 // the max step

int getStep();		// get the step from the user input
int rangeValidate(char* step); 	//validate if the step fall into the range of [ 1 to MAX], here MAX = 9
float Faherenheit2Celsius(float F); // convert faherenheit degree to Celsius degree
float Celsius2Faherenheit(float C); // convert celsius degree to faherenheit degree
void blankLine(); // print  a blank line 

int main(){
	
	int step = 1; 
	step = getStep();
	
	// print table head
	printf("%15s %15s %15s %15s","Faherenheit", "Celsius", "Celsius", "Faherenheit\n");
	blankLine();	

	int count = 0;
	float celsius = 0; // store converted Celsuis degree
	float faherenheit = 0; // store converted Faherenheit degree
	float degree = FROMDEGREE;
	for (degree = FROMDEGREE; degree <= TODEGREE; degree += step){
		celsius = Faherenheit2Celsius(degree);
		faherenheit = Celsius2Faherenheit(degree);
		printf("%15.1f %15.1f %15.1f %15.1f \n", degree, celsius, degree, faherenheit);
		count++;
		if (count % SECTION_MEMRS == 0){ // if printed SECTION_MEMRS lines of record, print a blank line to 
										// separate as a section.
			blankLine();
		}
	}
	return 0;
}


/*-----------------------blankLine---------------------------------
 *   function: void blankLine()
 *
 *    Purpose: 
 *    	output the blank line;
 *
 * @param 
 *	none
 * @return 
 * 	none
 *
 *---------------------------------------------------------------*/
void blankLine(){
	int i = 0;
	int count = 7; // amount of blank line units.
	for (i=0; i< count; i++){
		printf("__________"); // print a blank line unit
	}
	printf("\n\n");
}


/*-------------------------int getStep()-------------------------------
 *   function: int getStep();
 *
 *    Purpose: 
 *    	get user input as a step for the convertion table
 *    	validate and prompt the user that step should be within [1,9],
 *    	if user input invalid data.
 *
 * @param 
 *
 * @return 
 * 	step from 1 to 9
 *
 *---------------------------------------------------------------*/
int getStep(){
	char step[NSIZE];
	int flag = FALSE;
	do{
		printf("Please input a step range, from 1 to %d: \n", MAX);
		
		fflush(stdin);
		scanf("%s", step);
		fflush(stdin);
		flag = rangeValidate(step);
		if (TRUE == flag){
			return atoi(step);
		}
	}while(!flag);

}


/*-------------------------rangeValidate-------------------------------
 *   function: int rangeValidate(int step)
 *
 *    Purpose: 
 *    	a helper function to validate user input, 
 *    	to make sure the input fall between 1 and 9
 *
 * @param 
 * 	user input as step
 *
 * @return 
 *	TRUE if it is valid input, 
 *	else FALSE
 *---------------------------------------------------------------*/
int rangeValidate(char* step){

	int digit = FALSE; // assume input is not a digit
	int i = 0;
	
	for ( i = 0; i < NSIZE; i++){
		digit = isdigit(step[i]);
		if (!digit){
			 // whenever encount a non-digit, it is a invalid input, 
			printf("\nInput should be integer between 1 and %d \n", MAX);
			return FALSE;
		}
	}
	
	// step will be a digit, if execution comes here
	if( strlen(step) != NSIZE ){
		printf("\nInput should be integer between 1 and %d \n", MAX);
		return FALSE;
	}else if ( atoi(step)> 0){ // it is valid input
		return TRUE;
	}else{
		return FALSE;
	}
}


/*-----------------------Faherenheit2Celsius(float F)---------------------------------
 *   function: Faherenheit2Celsius(float F)
 *
 *    Purpose: 
 *		
 *		convert a Fahertenheit temperture to a Celsius Temperture
 *
 * 	using formula :
 * 		celsius = (faherenheit-32) * 5.0/9.0
 * @param faherenheit degree
 *
 * @return celsius degree converted from faherenheit degree
 *
 *---------------------------------------------------------------*/
float Faherenheit2Celsius(float faherenheit){
	float celsius = (faherenheit-32) * 5.0 / 9.0;
	return celsius;
}

/*--------------------------Celsius2Fahreheit(float C)------------------------------
 *   function: float Celsius2Fahrenheit(float C)
 *
 *    Purpose: 
 *
 * 		convert a Celsius degree to a Fahrenheit degree
 *
 * 	using formula
 *		faherenheit = celsius * 9.0/ 5.0 + 32.0;
 * @param celsius degree
 *
 * @return faherenheit degree converted from celsius degree
 *
 *---------------------------------------------------------------*/
float Celsius2Faherenheit(float celsius){
	float faherenheit = celsius * 9.0 / 5.0 + 32.0;
	return faherenheit;
}
