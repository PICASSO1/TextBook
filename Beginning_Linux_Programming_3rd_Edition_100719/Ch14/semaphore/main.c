#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/sem.h>

#include "semun.h"

#define SEM_P(SEM_ID) \
if (semaphore_p(SEM_ID) == 0) \
	exit(EXIT_FAILURE) \

#define SEM_V(SEM_ID) \
if (semaphore_v(SEM_ID) == 0) \
	exit(EXIT_FAILURE) \

static int set_semvalue();
static void del_semvalue();
static int semaphore_p(int);
static int semaphore_v(int);
static int semidTest = -1;

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int i = -1;
	int pause_time = 0;
	char op_char = 'O';

	srand((unsigned int)getpid());

	semidTest = semget((key_t)SEM_KEY_TEST, 1, 0666 | IPC_CREAT);
	if (argc > 1) {
		if (set_semvalue() == 0) {
			fprintf(stderr, "Failed to initialize semaphore!! \n");
			exit(EXIT_FAILURE);
		}
		op_char = 'X';
		sleep(2);
	}

	for (i = 0; i < 10; i++) {
	/*	if (semaphore_p(semidTest) == 0)
			exit(EXIT_FAILURE);
	*/	SEM_P(semidTest);
		printf("%c", op_char);
		fflush(stdout);
		pause_time = rand() % 3;
		sleep(pause_time);
		printf("%c", op_char);
		fflush(stdout);

	/*	if (semaphore_v(semidTest) == 0)
			exit(EXIT_FAILURE);
	*/	SEM_V(semidTest);
		pause_time = rand() % 2;
		sleep(pause_time);
	}
	printf("\n%d - finished\n", getpid());
	if (argc > 1) {
		sleep(10);
		del_semvalue();
	}
	exit(EXIT_SUCCESS);

	return 0;
}

static int 
set_semvalue(void)
{
	union semun sem_union;

	sem_union.val = 1;
	if (semctl(semidTest, 0, SETVAL, sem_union) == -1)
		return 0;
	return 1;
}

static void 
del_semvalue(void)
{
	union semun sem_union;

	sem_union.val = 1;
	if (semctl(semidTest, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete semaphore!! \n");
	return;
}

static int 
semaphore_p(sem_id)
int sem_id;
{
	struct sembuf sem_b;

	bzero(&sem_b, sizeof(struct sembuf));
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;	// P()
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1) {
		fprintf(stderr, "semaphore_p failed!! \n");
		return 0;
	}
	return 1;
}

static int 
semaphore_v(sem_id)
int sem_id;
{
	struct sembuf sem_b;

	bzero(&sem_b, sizeof(struct sembuf));
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;	// V()
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1) {
		fprintf(stderr, "semaphore_v failed!! \n");
		return 0;
	}
	return 1;
}
