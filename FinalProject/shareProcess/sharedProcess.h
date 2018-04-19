#ifndef SHAREDPROCESS_H
#define SHAREDPROCESS_H

typedef enum {TRUE = 1, FALSE = 0} boolean ;

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 
#define GREEN   "\033[32m"      /* Green */
#define CYAN    "\033[36m"      /* Cyan */


// validation
#define MIN_ARG_AMT 1
#define MAX_ARG_AMT 7
#define MIN_INTEGER 0
#define MAX_INTEGER 9

boolean validArg(int argc, char* argv[]);
boolean validArgv(char* argv);

#define BUF_SIZE 100
#define STDOUT 1
#define STDERR 2
void childProcess(int* ShmPTR, int argc, int id);
#endif