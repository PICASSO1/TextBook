#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *);

char message[] = "Hello!! World!! \n";

int main(void)
{
	int res = 0;
	pthread_t a_thread = 0UL;
	void *thread_result = (void *)NULL;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed!! \n");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish.... \n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed!! \n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned: %s \n", (char *)thread_result);
	printf("Message is now: %s \n", message);

	return 0;
}

void *thread_function(void *arg)
{
	printf("Thread function is running. Argument was %s \n", (char *)arg);
	sleep(3);
	strcpy(message, "Bye!! ");
	pthread_exit((void *)"Thank you for the CPU time!! \n");

	return (void *)NULL;
}

/*
#include <pthread.h>

int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_function)(void *), void *arg);
int pthread_join(pthread_t th, void **thread_return);
int pthread_exit(void *retval);
*/
