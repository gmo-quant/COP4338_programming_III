#ifndef SHAREDPROCESS_H
#define SHAREDPROCESS_H

typedef enum {TRUE = 1, FALSE = 0} boolean ;

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 


// validation
#define MIN_ARG_AMT 1
#define MAX_ARG_AMT 7
#define MIN_INTEGER 0
#define MAX_INTEGER 9

boolean validArg(int argc, char* argv[]);
boolean validArgc(int argc);// accept a number of argument [MIN_ARG_AMT, MAX_ARG_AMT]
boolean validArgv(char* argv);

#define BUF_SIZE 100
#define STDOUT 1
void childProcess();
#endif