//Brandy Poag-Dorado

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <string>
#include <stdlib.h>

const int MAX_SIZE = 41;

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Enter the number (from 1 to 40) of values from the fibonacci \
			sequence to be printed from the command line\n.");
		return 0;
	}
	
	int num_fib = atoi(argv[1]);
	if (num_fib < 1 || num_fib > 40)
	{
		fprintf(stderr,"Enter a number from 1 to 40.");
		return 0;
	}

	struct shared_data
	{
		long fib_sequence[MAX_SIZE];
		int sequence_size;
	};

	
	int segment_id;
	if ((segment_id = shmget(IPC_PRIVATE, sizeof(shared_data), S_IRUSR | S_IWUSR)) < 0)
	{
		perror("Error shmget.");
	}

	shared_data * shared_memory;
	if ((shared_memory = (shared_data *) shmat(segment_id, NULL, 0)) == (shared_data *)-1)
	{
		perror("Error shmat.");
	}

	pid_t pid;
	pid = fork();
	if (pid < 0) 
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) //child
	{
		shared_memory->sequence_size = num_fib;
		shared_memory->fib_sequence[0] = 1;
		shared_memory->fib_sequence[1] = 1;
		for (int i = 0; i < num_fib - 2; i++)
		{
			shared_memory->fib_sequence[i+2] = shared_memory->fib_sequence[i+1] + 
			shared_memory->fib_sequence[i];
		}
	}
	else //parent
	{
		if (wait(NULL) < 0)
		{
			if (shmdt(shared_memory) < 0)
			{
				perror("Error shmdt");
			}
			if (shmctl(segment_id, IPC_RMID, NULL) < 0)
			{	
				perror("Error shmctl");
			}
			perror("Error wait.");
		}
		
		for (int i = 0; i < shared_memory->sequence_size; i++)
		{
			std::cout << shared_memory->fib_sequence[i] << ' ';
		}

		if (shmdt(shared_memory) < 0)
		{
			perror("Error shmdt");
		}
		if (shmctl(segment_id, IPC_RMID, NULL) < 0)
		{	
			perror("Error shmctl");
		}
	}
	
	return 0;
}
