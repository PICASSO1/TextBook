#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <strings.h>	/* for bzero(); function.... */

#define	IF_ERROR(RET, FUNC) \
	if (RET != 0) { \
		fprintf(stderr, "Thread %s failed!! \n", FUNC); \
		exit(EXIT_FAILURE); \
	}

#define	NUM_THREADS	6

void *
thread_function(arg)
void *arg;
{
	int my_number = (int)arg;
	int rand_num = 0;

	printf("thread_function is running. Argument was %d \n", my_number);
	rand_num = 1 + (int)(9.0 * rand() / (RAND_MAX + 1.0));
	sleep(rand_num);
	printf("Bye from %d. \n", my_number);
	pthread_exit((void *)NULL);

	return (void *)NULL;
}

int 
main(void)
{
	int res = -9;
	pthread_t a_thread[NUM_THREADS];
	void *thread_result = (void *)NULL;
	int lots_of_threads = -1;

	bzero(&a_thread, sizeof(pthread_t) * NUM_THREADS);
	for (lots_of_threads = 0; lots_of_threads < NUM_THREADS; lots_of_threads++) {
		res = pthread_create(&(a_thread[lots_of_threads]), NULL, thread_function, (void *)lots_of_threads);
		IF_ERROR(res, "pthread_create");
		sleep(1);
	}

	printf("Waiting for threads to finished.... \n");
	for (lots_of_threads = NUM_THREADS - 1; lots_of_threads >= 0; lots_of_threads--) {
		res = pthread_join(a_thread[lots_of_threads], &thread_result);
		if (res == 0)
			printf("Picked up a thread!! \n");
		else
			perror("pthread_join failed!! \n");
	}
	printf("All done. \n");

	return 0;
}
