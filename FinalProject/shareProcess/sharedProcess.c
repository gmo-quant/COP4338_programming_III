#include"sharedProcess.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char* argv[]){
	fprintf(stdout, "%s\n", "Parent: starts");
	fprintf(stdout, "%s\n", "Parent: validate command line" );
	if (! validArg(argc, argv)){

		return EXIT_FAILURE;
	}

	fprintf(stdout, "%s\n", "Parent: forks (each) child process" );
	pid_t pid;
	pid_t wpid;
	char buf[BUF_SIZE];
	int status;
	for(int i = 0; i < 5; i++){
		if ( ( pid = fork())  < 0){
		fprintf(stderr, "%s\n", "fork() failed");
		return EXIT_FAILURE;
		} 
		if (pid == 0){
			childProcess();
			return EXIT_SUCCESS;

		}
		// else{
		// 	pid = wait(&status);
		// 	sprintf(buf, "%s%d\n", RED"Parent:  waits for child: "RESET, pid);
		// 	write(STDOUT, buf, strlen(buf));
		// 	sprintf(buf, YELLOW"parent :  detects child: %d completion\n"RESET, pid );
		// 	write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent:  display shared memory ");
			// write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent: detaches shared memory ");
			// write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent:  display shared memory ");
			// write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent: detaches shared memory ");
			// write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent:  removes shared memory ");
			// write(STDOUT, buf, strlen(buf));
			// sprintf(buf, "%s\n", "Parent: finished ");
			// write(STDOUT, buf, strlen(buf));
			
		// }
	}
	while ((wpid = wait(&status)) > 0){
		sprintf(buf, "%s%d\n", RED"Parent:  waits for child: "RESET, wpid);
		write(STDOUT, buf, strlen(buf));
		sprintf(buf, YELLOW"parent :  detects child: %d completion\n"RESET, wpid );
		write(STDOUT, buf, strlen(buf));
	}

	// if ( ( pid = fork())  < 0){
	// 	fprintf(stderr, "%s\n", "fork() failed");
	// 	return EXIT_FAILURE;
	// } 
	// if (pid == 0){
	// 	childProcess();
	// }else{
	// 	pid = wait(&status);
	// 	sprintf(buf, "%s%d\n", "Parent:  waits for child: ", pid);
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "parent :  detects child: %d completion\n", pid );
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent:  display shared memory ");
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent: detaches shared memory ");
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent:  display shared memory ");
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent: detaches shared memory ");
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent:  removes shared memory ");
	// 	write(STDOUT, buf, strlen(buf));
	// 	sprintf(buf, "%s\n", "Parent: finished ");
	// 	write(STDOUT, buf, strlen(buf));
		
	// }
	


	return EXIT_SUCCESS;
	
}