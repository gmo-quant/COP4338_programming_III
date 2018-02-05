/* ===========================================================
|  
| 	 date: 2018-01-23 19:18:47
| Source code: assignment1.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  1  assignment1
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
|	gcc assignment1.c -o filename
|
| +---------------------------------------------------------------
|
| Description:
|
| 	Input: 
|		user input: 5
|		integer temperature step in the range [1-9]
|
|      Output:
|
|		Faherenheit & Celsius conversion table
|	ex.
|		Fahrenheit	Celsius		Celsius		Fahrenheit
|		-80.0		-62.2		-80.0		-112.0
|		-75.0		-59.4		-75.0		-103.0
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
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define True 1
#define False 0
#define FROMDEGREE -20.0
#define TODEGREE 280.0
#define NSIZE 2 // to simplify the validation, as step range from 1 to 9, it is 1 palce, 
				// if it is from 1 to 99, then change it to 2
#define MAX 99 // the max step

int getStep();
int rangeValidate(char* step);
float Faherenheit2Celsius(float F);
float Celsius2Faherenheit(float C);
void blankLine();

int main(){
	
	int step = 1;
	step = getStep();
	
	// print table head
	printf("%15s %15s %15s %15s","Faherenheit", "Celsius", "Celsius", "Faherenheit\n");
	blankLine();	

	int count = 0;
	float c = 0; // store converted Celsuis
	float f = 0; // store converted Faherenheit
	float degree = FROMDEGREE;
	for (degree = FROMDEGREE; degree < TODEGREE; degree += step){
		c = Faherenheit2Celsius(degree);
		f = Celsius2Faherenheit(degree);
		printf("%15.1f %15.1f %15.1f %15.1f \n", degree, c, degree, f);
		count++;
		if (count % 8 == 0){
			blankLine();
		}
	}
	
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
	for (i=0; i< 7; i++){
		printf("__________");
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
	int flag = False;
	do{
		printf("Please input a step range, from 1 to %d: \n", MAX);
		
		fflush(stdin);
		scanf("%s", step);
		fflush(stdin);
		flag = rangeValidate(step);
		if (True == flag){
			return atoi(step);
		}
	}while(True);

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
 *	True if it is valid input, 
 *	else False
 *---------------------------------------------------------------*/
int rangeValidate(char* step){

	int digit = False;
	int i = 0;
	for ( i = 0; i < NSIZE; i++){
		digit = isdigit(step[i]);
		if (!digit){
			break;
		}
	}
	if( strlen(step) != NSIZE || !digit ){
		printf("\nInput should be integer between 1 and %d \n", MAX);
		return False;
	}else if ( atoi(step)> 0){ 
		return True;
	}else{
		return False;
	}
}


/*-----------------------Faherenheit2Celsius(float F)---------------------------------
 *   function: Faherenheit2Celsius(float F)
 *
 *    Purpose: 
 *		
 *	convert a Fahertenheit temperture to a Celsius Temperture
 *
 * 	using formula :
 * 		C = (F-32) * 5.0/9.0
 * @param 
 *
 * @return 
 *
 *---------------------------------------------------------------*/
float Faherenheit2Celsius(float F){
	float c = -1;
	c = (F-32) * 5.0 / 9.0;
	return c;
}

/*--------------------------Celsius2Fahreheit(float C)------------------------------
 *   function: float Celsius2Fahrenheit(float C)
 *
 *    Purpose: 
 *
 * 	convert a Celsius to a Fahrenheit
 *
 * 	using formula
 * @param 
 *
 * @return 
 *
 *---------------------------------------------------------------*/
float Celsius2Faherenheit(float C){
	float f = 0;
	f = C * 9.0 / 5.0 + 32.0;
	return f;
}
