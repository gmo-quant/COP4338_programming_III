

// using fork(), 
// a parent and its children have separate address spaces.
// while this would provide a more secured way of executing parent
// and children processes(because they will not interfere each other)
// they shared nothing and have no way to communicate each other.

// a shared memory is a piece of memory 
// that is attatched to some address spaces.
// in some sense, the original address space 
// is "extended" by attaching this shared memory

// one process must explicitly ask for an area, using a key, 
// to be shared by other processes
// this process will be called the server.
// all other processes, the clients. 
// that know the shared area can access it. 


// however, there is no protection to a shared memory 
// and any process that know it can access it freely.
// to protect a shared memory from being accessed at 
// the same time by several processes
// a synchronization protocol must be setup.

// a shared memory segment is identified by a unique integer,
// the shared memory ID
// the shared memory itself is described by a structure of type shmid_ds 
// 

// a general scheme of using shared memory is the following
// For a server, it should be started before any client.
// The server should perform the following tasks:
// 		Ask for a shared memory with a memory key 
// 		and memorize the returned shared memory ID. 
// 		This is performed by system call shmget().
//
// 		Attach this shared memory to the server's address space with system call shmat().
//
// 		Initialize the shared memory, if necessary.
//
// 		Do something and wait for all clients' completion.
// 		
//		Detach the shared memory with system call shmdt().
// 
// 		Remove the shared memory with system call shmctl().
// 
// For the client part, the procedure is almost the same:
// 		
//		Ask for a shared memory with the same memory key 
//		and memorize the returned shared memory ID.
// 
// 		Attach this shared memory to the client's address space.
// 
// 		Use the memory.
// 
// 		Detach all shared memory segments, if necessary.
// 		Exit.


// keys
// unix requires a key of type key_t defined in sys/types.h for requesting resources
// such as shared memory segments, message queues and semaphores.
// a key is simply an integer of type key_t

// There are three different ways of using keys, namely:

// a specific integer value (e.g., 123456)
// a key generated with function ftok()
// a uniquely generated key using IPC_PRIVATE (i.e., a private key).

//
// asking for a shared memory segment - shmget()
// 

// Suppose process 1, a server, 
// uses shmget() to request a shared memory segment successfully. 
// That shared memory segment exists somewhere in the memory, 
// but is not yet part of the address space of process 1 (shown with dashed line below). 
// Similarly, if process 2 requests the same shared memory segment with the same key value, 
// process 2 will be granted the right to use the shared memory segment; 
// but it is not yet part of the address space of process 2. 
// To make a requested shared memory segment part of the address space of a process, use shmat().

// 
// attaching a shared memory segment to an address space - shmat()
//

// After a shared memory ID is returned, 
// the next step is to attach it to the address space of a process. 
// This is done with system call shmat().


// communicating between parent and child.

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void ClientProcess(int[]);

int main(int argc, char *argv[]){
	int ShmID;
	int *ShmPTR;
	pid_t pid;
	int status;

	if (argc != 5){
		printf("use : %s #1 #2 #3 #4\n", argv[0] );
		return EXIT_FAILURE;
	}

	ShmID = shmget(IPC_PRIVATE, 4*sizeof(int), IPC_CREAT |0666);
	if (ShmID < 0){
		printf("*** shmget error (server) ***\n");
		return EXIT_FAILURE;
	}
	printf("Server has received a shared memory of four integer...\n");

	ShmPTR  = (int*) shmat(ShmID, NULL, 0);
	if ( (int)*ShmPTR == -1 ){
		printf("*** shmat error (server) ***\n");
		return EXIT_FAILURE;
	}
	printf("Server has attached the shared memory\n", );

	ShmPTR[0] = atoi(argv[1]);
	ShmPTR[1] = atoi(argv[2]);
	ShmPTR[2] = atoi(argv[3]);
	ShmPTR[3] = atoi(argv[4]);

	printf("Server has filled %d, %d, %d, %d in shared memory,,,,, 0\n", 
		ShmPTR[0], ShmPTR[1], ShmPTR[2], ShmPTR[3]);
	if ( (pid = fork()) < 0){
		printf("*** fork error (server) *** \n");
		return EXIT_FAILURE;
	}else if( pid == 0){
		ClientProcess(ShmPTR);
		return EXIT_SUCCESS;
	}
	wait(&status);
	printf("Server ahs detected the completion of its child ... \n");
	shmdt( (void*) ShmPTR);
	printf("Server has detached its shared memory .... \n");
	shmctl(ShmID, IPC_RMID, NULL);
	printf("Server has removed its shared memory .... \n");
	printf("Server exit....\n");
	return EXIT_SUCCESS;
}

void ClientProcess(int sharedMem[]){
	printf("client process started \n");
	printf("client found %d %d %d %d in shared memory\n", 
		sharedMem[0], sharedMem[1], sharedMem[2], sharedMem[3] );
	printf("client is about to exit ... \n");
}
