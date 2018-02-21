/* ===========================================================
|
|  
| 	 date: 2018-02-01 18:51:48
| Source code: babyloninanSqrt.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  2 babyloninanSqrt.c 
|      Course: COP 4338 (Advanced Programming) 
|    Section : U01 
|  Instructor: William Feild 
|    Due Date: 
|    
|      I hereby certify that this collcetive work is my own 
|      and none of it is the work of any other person or entiry. 
|      _________________________________________[Guangzhuan Mo]
|
|    Language: C
| Compile/Run:
|	gcc babylonianSqrt.c -o babylonianSqrt -lm
|
|	to run:
| 	chmod a+x baylonianSqrt
| 	./babylonianSqrt
|	-------------------------------
|
| +---------------------------------------------------------------
|
| Description:
|
| 	Input: no user input
|
|      Output: 	all of the perfect numbers between [1- 1000]
| 		along with  a list of their factors to confirm 
|		the factors sum to the number
|
|		formatted output:
|			Perfect number: 6 = 1 + 2 + 3;
|			Expected sqrt() of 6 = 2.4494897...
|			computted square root of 6 = 2.449489742783...
| 			reached in 8 interations
|
|     Process:
|	the program's steps are as follows:
| 		start from the START, which is 1 here
| 		check if the current number is a perfect number
| 		if if it a perfect number, 
|			print the perfect number in the 
| 			format of 
|			" perfect number = factor1 + factor2 + ...."
| 			print the expected sqrt of the perfect number
| 			print the calculated sqrt using babylonian method	
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
|
|	don't know if it is a bug or not, 
| 	whenever the accuracy set to 16 decimal place, 
| 	it seems to run into infinite loop 
| 	however, when the accuracy is set to the current one, 
| 	which is 11 decimal palces, it works fine. and some of the result 
| 	can meet the requirement of precision.
| 	no matter if i use a helper function babylonianGuess, 
|	which I use floor(sqrt(i)) as the guess 
 * ===========================================================*/

#include<stdio.h> //to use printf(); file stdio.h should be included
#include<math.h> // to use sqrt(), file math.h should be included

#define TRUE 1
#define FALSE 0
#define START 1
#define END 10000
// whenever try this accuracy, it will run into a infinite loop
//#define ACCURACY 0.0000000000000001
#define ACCURACY 0.00000000001   // determine the accuracy of the result
 
int isPerfectNumber(int i);	// decide if i is a perfect number, TRUE for perfect number
void printPerfectNubmer(int i); 
void expectedSqrt(int i ); 
void babylonianSqrt(int i);
int babylonianGuess(int i);

int main(void){
	printf("\n");
	int i = START;
	for (i = START; i < END; i++){
		if (isPerfectNumber(i)){
			printPerfectNumber(i);
			expectedSqrt(i);
			babylonianSqrt(i);
			printf("\n");
		}	
	}
	return 0;
}

/*-----------------isPerfectNumber(int )-------------------------
 *   function: int isPerfectNumber(int i)
 *
 *    Purpose: for a given i, decide if it is a pefect number
 * 	steps:
 *		key: if number i is exactly divisible by j, 
 *			j belongs to [1, i], 
 * 			then j is a factor of num
 *
 *			but for deciding if i is a perfect number, 
 *			i is not included
 *			therefore, j belongs to [1, i-1]
 *
 *		after getting one factor, addup to the current sum
 *
 *              decide if the sum == i, 
 *   		if yes, return TRUE
 * 		else return FALSE
 *
 * @param int i, a given number between (START) 1 to (END)1000
 *
 * @return  	return Ture if it is perfect number, 
 * 	 	return FALSE if it is not a perfect nubmer.
 *
 *---------------------------------------------------------------*/

int isPerfectNumber(int i){
	int sum = 0;
	int trialFactor = 0;
	
	for (trialFactor = 1; trialFactor < i-1; trialFactor++){
		// if i is exactly divisible by c, 
		// then c is a factor of sum
		if ( i % trialFactor == 0 ){
			sum += trialFactor;
		}
	}
	if ( sum == i){
		return TRUE;
	}else{
		return FALSE;
	}
}

/*-------------printPerfectNumberSeries(int i)-----------
 *   function: void printPerfectNumberSeries(int i)
 *
 *    Purpose: print the output series
 *		Perfect number: i = factor1 + factor2 + ....
 *	steps:
 * 		similar to isPerfecNumber,
 * 		was thinking to store the factor in 
 * 		an array while invoking isPerfecNumber,
 * 		but give it up, since in C is not 
 * 		convienent to manipulate dynamic array.
 *		
 * 		
 *		
 *
 * @param int i , the perfect number
 *
 * @return void
 *
 *---------------------------------------------------------------*/

 void printPerfectNumber(int i){
	int factor = 1;
	char * s = "Perfect number :";
	printf("%30s %5d = ",s, i);
	for (factor = 1; factor < i - 1; factor++){
		if (i % factor == 0){
			if (factor != 1){
				printf(" + ");
			}
			printf(" %d ", factor);
		}
	}

	printf("\n");
 }



/*------------------expectedSqrt(int )-------------------------
 *   function: void expectedSqrt(int i)
 *
 *    Purpose: print the expected sqrt of the given perfect number i
 *
 * @param  int i , perfect number
 *
 * @return void 
 *
 *---------------------------------------------------------------*/

 void expectedSqrt(int i){
	double result = 0.0;
	result = sqrt((double)i);
	char* s = "Expected sqrt() of";
	printf("%30s %5d = %.16lf \n" , s,i, result);
 }


/*-----------bayloninanSqrt-------------------------------
 *   function: babylonianSqrt(int i)
 *
 *    Purpose: for a given perfect number i , 
 *    		calculate the sqrt root for it.
 *     		set initial guess to 2;
 * 			set difference to the required accuracy
 *
 *			while is not yet reach the accuracy
 *			set tmp to be the result of dividing the 
 * 			perfect number by the guess root
 * 			get next guess root by setting it to the 
 *			average of the current guess root and tmp
 *   		get the difference between square guess root 
 * 			and the perfect number for the use of
 *			deciding the accuracy
 *			increments the counter for how many times 
  * 		it guess the square root.
 *
 * @param int i
 *
 * @return  the sqrt 
 *
 *---------------------------------------------------------------*/
void babylonianSqrt(int i){
	int c = 0;
	double guess = 2.0;
//	double guess = babylonianGuess(i);
//	printf("guess : %lf\n", guess);
	double difference = ACCURACY;
	double dig = 0;
	while (difference >= ACCURACY){
		dig = i/guess; // divide the perfect number by the guess
		guess = (guess+dig) / 2; // next guess
		difference = guess*guess -i;
		c++;
	}	
	char* s ="Computed square root of";
	printf("%30s %5d = %.16lf \n",s, i, guess);
	printf("\t\t\t       reached in %d iterations. \n", c);
}

/*-------------------------babylonianGuess-------------------------------
 *   function: double babylonianGuess()
 *
 *    Purpose: get the initial guess 
 *
 * @param the perfect number
 *
 * @return return the floor of the sqrt of the perfect number
 *
 *---------------------------------------------------------------*/
int babylonianGuess(int i){
	double guess = sqrt((double)i);
	return guess;
}
