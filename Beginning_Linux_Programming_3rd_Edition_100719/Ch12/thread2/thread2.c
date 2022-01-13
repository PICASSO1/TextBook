#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int run_now = 1;

void *thread_function(void *);

char message[] = "Hello!! World!! \n";

int main(void)
{
	int res = 0;
	pthread_t a_thread = 0UL;
	void *thread_result = (void *)NULL;
	int print_count1 = 0;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed!! \n");
		exit(EXIT_FAILURE);
	}
	while (print_count1++ < 20) {
		if (run_now == 1) {
			printf("1");
			run_now = 2;
		}
		else
			sleep(1);
	}
	printf("\nWaiting for thread to finish.... \n");
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
	int print_count2 = 0;

/*	printf("Thread function is running. Argument was %s \n", (char *)arg);	*/
/*	sleep(3);	*/
	while (print_count2++ < 20) {
		if (run_now == 2) {
			printf("2");
			run_now = 1;
		}
		else
			sleep(1);
	}
	strcpy(message, "Bye!! ");
	pthread_exit((void *)"Thank you for the CPU time!!");

	return (void *)NULL;
}