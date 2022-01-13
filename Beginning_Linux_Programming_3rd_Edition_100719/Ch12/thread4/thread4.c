#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define	WORK_SIZE	1024

int time_to_exit = 0;
char work_area[WORK_SIZE];
pthread_mutex_t work_mutex;	/* protects both work_area and time_to_exit */

void *
thread_function(arg)
void *arg;
{
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while (strncmp("end", work_area, 3) != 0) {
		printf("You input %d characters: %s \n", strlen(work_area) - 1, work_area);
	/*	work_area[0] = '\0';	*/
		memset(&work_area, '\0', sizeof(char) * WORK_SIZE);
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while (work_area[0] == '\0') {
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}
	time_to_exit = 1;
/*	work_area[0] = '\0';	*/
	memset(&work_area, '\0', sizeof(char) * WORK_SIZE);
	pthread_mutex_unlock(&work_mutex);
	pthread_exit((void *)NULL);

	return (void *)NULL;
}

int main(void)
{
	int res = 0;
	pthread_t a_thread = 0UL;
	void *thread_result = (void *)NULL;

	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0) {
		perror("Mutex initialization failed!! \n");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
		perror("Mutex initialization failed!! \n");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_lock(&work_mutex);
	printf("Input some text. Enter 'end' to finish: \n");
	memset(&work_area, '\0', sizeof(char) * WORK_SIZE);
	while (time_to_exit == 0) {
		fgets(work_area, sizeof(char) * WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while (1) {
			pthread_mutex_lock(&work_mutex);
			if (work_area[0] != '\0') {
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}
			else
				break;
		}
	}

	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish.... \n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed!! \n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined. \n");
	pthread_mutex_destroy(&work_mutex);

	return 0;
}

/*
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
*/
