#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define	WORK_SIZE	1024

sem_t bin_sem;
char work_area[WORK_SIZE];

void *thread_function(void *);

int main(void)
{
	int res = 0;
	pthread_t a_thread = 0UL;
	void *thread_result = (void *)NULL;

	res = sem_init(&bin_sem, 0, 0);
	if (res != 0) {
		perror("Semaphore initialization failed!! \n");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
		perror("Thread creation failed!! \n");
		exit(EXIT_FAILURE);
	}

	printf("Input some text. Enter 'end' to finish. \n");
	memset(&work_area, '\0', sizeof(char) * WORK_SIZE);
	do {
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(&bin_sem);
	} while (strncmp("end", work_area, 3) != 0);

/*	while (strncmp("end", work_area, 3) != 0) {
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(&bin_sem);
	}
*/
	printf("\nWaiting for thread to finish.... \n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed!! \n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined!! \n");
	sem_destroy(&bin_sem);

	return 0;
}

void *thread_function(void *arg)
{
	sem_wait(&bin_sem);
	while (strncmp("end", work_area, 3) != 0) {
		printf("You input %d characters. \n", strlen(work_area) - 1);
		sem_wait(&bin_sem);
	}
	pthread_exit((void *)NULL);

	return (void *)NULL;
}

/*
#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_wait(sem_t *sem);
int sem_post(sem_t *sem);
int sem_destroy(sem_t *sem);

/usr/include/bits/pthreadtypes.h: 
typedef unsigned long int pthread_t;
*/