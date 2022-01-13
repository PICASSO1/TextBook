#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

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
	int max_priority = 0;
	int min_priority = 0;
	struct sched_param scheduling_value;

	res = pthread_attr_init(&thread_attr);
	if (res != 0) {
		perror("Attribute creation failed!! \n");
		exit(EXIT_FAILURE);
	}

	res = pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);
	if (res != 0) {
		perror("Setting scheduling policy failed!! \n");
		exit(EXIT_FAILURE);
	}

	max_priority = sched_get_priority_max(SCHED_OTHER);
	min_priority = sched_get_priority_min(SCHED_OTHER);
	bzero((void *)&scheduling_value, sizeof(struct sched_param));
	scheduling_value.sched_priority = min_priority;
	res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
	if (res != 0) {
		perror("Setting scheduling priority failed!! \n");
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

int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int policy);

int policy: SCHED_OTHER (default) | SCHED_RR | SCHED_FIFO

int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);
int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param);
*/
