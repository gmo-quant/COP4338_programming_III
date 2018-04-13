#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>


#define MAX_COUNT 3
#define BUF_SIZE 100
#define STDOUT 1

void ChildProcess(char[], char[]);


// wait() blocks the calling process until one of its child processes exits or a signal is received.
// wait() take the address of an integer variable and returns the process ID of the completed process.

// the execution of wait() could have two possible situations
// if there are at least one child processes running when the call to wait() is made,
// the caller will be blocked until one of its child process exits.
// then the caller resumes its execution.

// if there is no child process running when the call to wait() is made, 
// then this wait() has no effect at all.
// that is, it is as if no wait() is there.
int main(void){
	pid_t pid1, pid2, pid;
	int status;
	int i;
	char buf[BUF_SIZE];

	printf("*** parent : %d is about to fork process 1 *** \n" , getpid());
	if ( (pid1 = fork()) < 0 ){
		printf("%s\n", "failed to fork process 1 \n" );
		return EXIT_FAILURE;
	}else if (pid1 == 0){
		printf("%s\n", );
		ChildProcess("first", "  ");
	}

	printf("parent : %d is about to fork process 2 *** \n", getpid() );
	if ( (pid2 = fork() ) < 0){
		printf("%s\n", "failed to fork process 2 \n");
		return EXIT_FAILURE;
	}else if (pid2 == 0){
		ChildProcess("second", "   ");
	}

	sprintf(buf, "*** parent : %d enters waiting status ..... \n\n", getpid());
	write(STDOUT, buf, strlen(buf));
	pid = wait(&status);
	sprintf(buf, "parent : %d  detects process %d was done ***\n\n",getppid(), pid );
	write(STDOUT, buf, strlen(buf));
	printf("%s\n", "+++ parent exits \n ");

	return EXIT_SUCCESS;


}

void ChildProcess(char *number, char *space){
	int i;
	char buf[BUF_SIZE];
	sprintf(buf, "%s%s child process starts (pid = %d ) \n", space, number, getpid());
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s%s child (pid = %d) is about to exit \n", space, number, getpid());
	write(STDOUT, buf, strlen(buf));
	return ;
}