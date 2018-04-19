#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include"sharedProcess.h"

/*-------------------------validArgv-------------------------------
 *   function: validArgv(int argc, char* argv[])
 *
 *    Purpose: 	validate the amount of argument from the cmd line,
 *				make sure is in the range of [MIN_ARG_AMT, MAX_ARG_AMT]
 *
 * @param  argc, char* argv[] from main
 *
 * @return void
 *
 *---------------------------------------------------------------*/
boolean validArgv(int argc, char* argv[]){
	// validate the amount of argument from the cmd line,
	// make sure is in the range of [MIN_ARG_AMT, MAX_ARG_AMT]
	if (argc < MIN_ARG_AMT+1 || argc > MAX_ARG_AMT+1){
		fprintf(stderr, "%s [ %d - %d ]\n", RED"the amount of argument should be in the range of "RESET, 	MIN_ARG_AMT, MAX_ARG_AMT );
		return FALSE;
	}
	//validate each arg is a unique integer in the range of [MIN_INTEGER, MAX_INTEGER]
	int arg = 1;
	for (arg = 1; arg < argc; arg++){
		if(! validArgvv(argv[arg]) ){
			return FALSE;
		}
	}
	return TRUE;
}

/*-------------------------validArgv-------------------------------
 *   function: validArgvv(char* argv)
 *
 *    Purpose: 	validate the argv, 
 *
 * @param  argc, char* argv[] from main
 *
 * @return void
 *
 *---------------------------------------------------------------*/
boolean validArgvv(char* argv){
	int amt = atoi(argv);
	if (amt < MIN_INTEGER || amt > MAX_INTEGER){
		fprintf(stderr, "%s [ %d - %d ]\n", RED"Each argument should be in the range of "RESET, MIN_INTEGER, MAX_INTEGER);
		return FALSE;
	}
	return TRUE;
}



/*-------------------------validArgv-------------------------------
 *   function: childProcess(int* ShmPTR, int argc, int id){
 *
 *    Purpose: 	print private shared memory of each child process.
 *
 * @param  int* ShmPTR, int argc, int id)
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void childProcess(int* ShmPTR, int argc, int id){
	char buf[BUF_SIZE];
	sprintf(buf, "\n\t%s%d %s\n", "Child ID: ", getpid(),  "starts" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "\t%s%d %s%d\n", "Child ID: ", getpid(),  "displays private shared memory : ", ShmPTR[id-1] );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "\t%s%d %s%d\n", "Child ID: ", getpid(),  "displays private unique ID : ", id );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "\t%s%d %s\n", "Child ID: ", getpid(),  "updates shared memory" );
	write(STDOUT, buf, strlen(buf));
	ShmPTR[id-1] *= id;
	sprintf(buf, "\t%s%d %s%d\n", "Child ID: ", getpid(),  "displays private shared memory: ",  ShmPTR[id-1]);
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "\t%s%d %s%d\n", "Child ID: ", getpid(),  "exits with code: ", 0);
	write(STDOUT, buf, strlen(buf));
	return;
}
