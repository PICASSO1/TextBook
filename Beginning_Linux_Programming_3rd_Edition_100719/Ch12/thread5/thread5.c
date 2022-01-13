#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int thread_finished = 0;
char message[] = "Hello!! World!! ";

void *
thread_function(arg)
void *arg;
{
	printf("thread_function is running, the arguments was: %s \n", (char *)arg);
	sleep(4);
	printf("Second thread setting finished flag, and exiting now. \n");
	thread_finished = 1;
	pthread_exit((void *)NULL);

	return (void *)NULL;
}

int 
main()
{
	int res = -1;
	pthread_t a_thread = 0UL;
	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if (res != 0) {
		perror("Attribute creation failed!! \n");
		exit(EXIT_FAILURE);
	}

	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if (res != 0) {
		perror("Setting detached attribute failed!! \n");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, &thread_attr, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed!! \n");
		exit(EXIT_FAILURE);
	}

	pthread_attr_destroy(&thread_attr);
	while (thread_finished == 0) {
		printf("Waiting for thread to say it's finished.... \n");
		sleep(1);
	}

	printf("Other thread finished, bye!! \n");

	return 0;
}

/*
#include <pthread.h>

int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int detachstate);

int detachstate: PTHREAD_CREATE_JOINABLE (default) | PTHREAD_CREATE_DETACHED
*/
