#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>

#include "shm_com.h"

int main(void)
{
	int running = 1;
	void *shared_memory = (void *)NULL;
	struct shared_use_st *shared_stuff = NULL;
	char buffer[BUFSIZ];	// Added!!
	int shmid = 0;

//	srand((unsigned int)getpid());
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1) {
		fprintf(stderr, "shmget failed!! \n");
		exit(EXIT_FAILURE);
	}

	shared_memory = shmat(shmid, (void *)NULL, 0);
	if (shared_memory == (void *)(-1)) {
		fprintf(stderr, "shmat failed!! \n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at 0x%X \n", (int)shared_memory);

	shared_stuff = (struct shared_use_st *)shared_memory;
//	shared_stuff->written_by_you = 0;
	while (running) {
		while (shared_stuff->written_by_you == 1) {
			sleep(1);
			printf("Waiting for client.... \n");
		}
		memset(&buffer, '\0', sizeof(char) * BUFSIZ);
		printf("Enter some text: ");
		fgets(buffer, sizeof(char) * BUFSIZ, stdin);

		strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
		shared_stuff->written_by_you = 1;
		if (strncmp(buffer, "end", 3) == 0)
			running = 0;
	}

	if (shmdt(shared_memory) == -1) {
		fprintf(stderr, "shmdt failed!! \n");
		exit(EXIT_FAILURE);
	}
	/*
	if (shmctl(shmid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "shmctl(IPC_RMID) failed!! \n");
		exit(EXIT_FAILURE);
	}
	*/
	return 0;
}
