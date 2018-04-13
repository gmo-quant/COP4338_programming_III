#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_COUNT 3
#define BUF_SIZE 100
#define STDOUT 1

void childProcess(void);
void parentProcess(void);

int main(void){
	pid_t pid; 
	int i;
	char buf[BUF_SIZE];
	// getpid() retrieve the process ID assigned to this process
	sprintf(buf, "process id of the main program: %d \n parent pid of the main program %d  \n",  getpid(), getppid());
	write(1, buf, strlen(buf));

	// if fork returns a negative value, 
	// the creation of a child process was unsuccessful

	if (( pid = fork()) < 0 ){
		sprintf(buf, "fork fialed");
		write(1, buf, strlen(buf));
	}else if(pid == 0){
		// fork returns a zero to the newly created child process
		// that is if pid == 0, it is in the child process address space.
		for (int i = 1; i <= MAX_COUNT; i++){
			sprintf(buf, "child:: pid : %d \n, gpid : %d \n, ppid: %d, \n",  pid, getpid(), getppid());
			write(STDOUT, buf, strlen(buf));
		}
		childProcess();
	}else{
		// fork returns a positive value, the process ID of the child process, 
		// to the parent.
		gpid = getpid();
		ppid = getppid();
		for (int i = 1; i <= MAX_COUNT; i++){
			sprintf(buf, "parent:: pid : %d \n , gpid : %d \n, ppid: %d, \n",  pid, getpid(), getppid());
			write(STDOUT, buf, strlen(buf));
		}
		parentProcess();
	}

	return EXIT_SUCCESS;
}

void childProcess(void){
	int i = 0;
	for (i = i; i < MAX_COUNT; i++){
		fprintf(stdout, "%s %d\n", " this line is from child, value =  " ,i );
	}
}

void parentProcess(void){
	int i = 0;
	for (i = i; i < MAX_COUNT; i++){
		fprintf(stdout, "%s %d\n", " this line is from parent, value =  " ,i );
	}
}