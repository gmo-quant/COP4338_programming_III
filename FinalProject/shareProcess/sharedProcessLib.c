#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include"sharedProcess.h"


boolean validArg(int argc, char* argv[]){
	fprintf(stdout, "%s\n", argv[0] );
	fprintf(stdout, "%d\n", argc );
	if (argc < 2 || argc > 8){
		fprintf(stderr, "%s [ %d - %d ]\n", "argument not enough ", 	MIN_ARG_AMT, MAX_ARG_AMT );
		return FALSE;
	}
	int counter = 1;
	for (counter = 1; counter < argc; counter++){
		if(! validArgv(argv[counter]) ){
			return FALSE;
		}
	}
	return TRUE;
}
boolean validArgc(int argc){

}
boolean validArgv(char* argv){
	int amt = atoi(argv);
	if (amt < MIN_INTEGER || amt > MAX_INTEGER){
		fprintf(stderr, "%s [ %d - %d ]\n", "should be in range ", MIN_INTEGER, MAX_INTEGER);
		return FALSE;
	}
	return TRUE;
}

void childProcess(){
	char buf[BUF_SIZE];
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "starts" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "displays shared memory" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "displays private unique ID" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "updates shared memory" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "updates shared memory" );
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%d %s\n", "Child ID: ", getpid(),  "exits with code" );
	write(STDOUT, buf, strlen(buf));

	return ;
}