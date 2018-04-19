/* ===========================================================
|
|  
| 	 date: 2018-04-09 10:17:58
| Source code: sharedProcess.c.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  3  sharedProcess.c.c 
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
| 	use make file:
| 		go to the folder shareProcess
| 		$ make
|	or use gcc cmd:
|		$gcc -std=c99 -D_SVID_SOURCE -o sharedProcess sharedProcess.c sharedProcessLib.c 
|	to run the program:
|		$ ./sharedProcess <arg list>
|		for example:
| 		$ ./sharedProcess 2 4 5
|		it will spawn 3 childprocess, and fills the shared memory 
|
| +---------------------------------------------------------------
|
| Description:
|	The program(parent process) will 
|	request shared memory for these integers, 
|	attach the shared memory to its own address space  
|	fill the space (using an array )with the integers from the cmd
|	the parent will display the initial state of the shared memory
|	spawn a number of child processes equal to the number of cmd arguments,
|	all at once, the parent wait for each and every child to complete its tasks.
|	upon completion of all children, the parent will acknowledge said completion
|	display therir respective exit codes.
|	display the final state of the shared memory, 
|	detach the shared memory
|	remove the shared memory
|	terminate
| 	each child process will receive a unique ID upon initiation - an integer between and 
|		the number of cmd arguments (maximum 7).
|	each child will dispaly the initial state of the shared memory and their pirvate memory,
|	each child will locate the array element (index) associated with their unique ID 
|	multiply that array element by their unique ID, storing the reslut in the same array element, 
| 	each child will then display the current state of the shared memory, provide their exit
|		code/status, and exit.
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	None;
|	the program operates correctly
|
 * ===========================================================*/

#include<stdio.h> // sprintf(), write(), printf() 
#include<stdlib.h> // sprintf(), write(), printf() 
#include<sys/types.h> //atoi(), strlen(), shm**()
#include<sys/ipc.h> // shmget(), shmat(), shmdt(), shmctl()
#include<sys/shm.h> //shmget(), shmat(), shmdt(), shmctl()
#include<sys/wait.h> // wait() child process
#include<string.h> // atoi(), strlen(), 
#include<unistd.h> // wait(), 
#include"sharedProcess.h"

int main(int argc, char* argv[]){
	int *ShmPTR; //  pointer to shared memory
	int ShmID; // shared memory ID
	char buf[BUF_SIZE]; 

	sprintf(buf, "%s\n", GREEN" Parent: starts"RESET);
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s\n", GREEN" Parent: validate command line"RESET );
	write(STDOUT, buf, strlen(buf));
	// validate if arg from cmd line is in the range of [MIN_ARG_AMT, MAX_ARG_AMT]
	// each a unique integer in the range of [MIN_INTEGER, MAX_INTEGER]
	if (! validArg(argc, argv)){
		return EXIT_FAILURE;
	}

	sprintf(buf, "%s\n", GREEN" Parent: requests  shared memory"RESET);
	write(STDOUT, buf, strlen(buf));
	ShmID = shmget(IPC_PRIVATE, (argc-1)*sizeof(int), IPC_CREAT |0666);
	if (ShmID < 0){
		printf("*** shmget error (server) ***\n");
		return EXIT_FAILURE;
	}else{
		sprintf(buf, "%s\n", GREEN" Parent: receives shared memory"RESET );
		write(STDOUT, buf, strlen(buf));
	}

	sprintf(buf, "%s\n", GREEN" Parent: attaches  shared memory"RESET);
	write(STDOUT, buf, strlen(buf));
	ShmPTR  = (int*) shmat(ShmID, NULL, 0);
	if ( (int)*ShmPTR == -1 ){
		printf("*** shmat error (server) ***\n");
		return EXIT_FAILURE;
	}

	sprintf(buf, "%s\n", GREEN" Parent: fills shared memory"RESET );
	write(STDOUT, buf, strlen(buf));
	int position = 0;
	for (position = 0; position < argc - 1; position++){
		ShmPTR[position] = atoi(argv[position+1]);
	}

	sprintf(buf, "%s\n\t", GREEN" Parent: displays shared memory"RESET );
	write(STDOUT, buf, strlen(buf));
	for (position = 0; position < argc - 1; position++){
		sprintf(buf, YELLOW"%d "RESET,  ShmPTR[position] );
		write(STDOUT, buf, strlen(buf));
	}

	sprintf(buf, "\n%s\n\n", GREEN" Parent: forks (each) child process"RESET);
	write(STDOUT, buf, strlen(buf));

	pid_t pid = -1;
	pid_t wpid = -1;
	int status = -1;
	int childAmt = 0;
	for(childAmt = 1; childAmt < argc; childAmt++){
		if ( ( pid = fork())  < 0){
			sprintf(buf, "%s\n", "fork() failed");
			write(STDOUT, buf, strlen(buf));
			return EXIT_FAILURE;
		} 
		if (pid == 0){
			childProcess(ShmPTR, argc, childAmt);
			return EXIT_SUCCESS;
		}
	}
	// wait for each child process
	while ((wpid = wait(&status)) > 0){
		sprintf(buf, "\n%s%d\n", RED"Parent:  waits for child: "RESET, wpid);
		write(STDOUT, buf, strlen(buf));
		sprintf(buf, YELLOW"parent :  detects child: %d completion\n"RESET, wpid );
		write(STDOUT, buf, strlen(buf));
		sprintf(buf, YELLOW"parent :  displays child: %d exit code: %d\n"RESET, wpid, status );
		write(STDOUT, buf, strlen(buf));
	}

	sprintf(buf, "\n%s\n \t", "Parent:  display shared memory ");
	write(STDOUT, buf, strlen(buf));
	for (position = 0; position < argc - 1; position++){
		sprintf(buf, YELLOW"%d "RESET,  ShmPTR[position] );
		write(STDOUT, buf, strlen(buf));
	}
	sprintf(buf, "\n%s\n", "Parent: detaches shared memory ");
	write(STDOUT, buf, strlen(buf));
 	shmdt( (void*) ShmPTR);
	sprintf(buf, "%s\n", "Parent:  removes shared memory ");
 	shmctl(ShmID, IPC_RMID, NULL);
	write(STDOUT, buf, strlen(buf));
	sprintf(buf, "%s\n", "Parent: finished ");
	write(STDOUT, buf, strlen(buf));

	return EXIT_SUCCESS;
}