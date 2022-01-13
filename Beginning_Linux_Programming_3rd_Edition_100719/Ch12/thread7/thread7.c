#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>	/* for fprintf(); function.... */

#define	IF_ERROR(RET, FUNC) \
	if (RET != 0) { \
		fprintf(stderr, "Thread %s failed!! \n", FUNC); \
		exit(EXIT_FAILURE); \
	}

void *
thread_function(arg)
void *arg;
{
	int i = -2, res = -1;

	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, (int *)NULL);
	IF_ERROR(res, "pthread_setcancelstate");

	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, (int *)NULL);
	IF_ERROR(res, "pthread_setcanceltype");

	printf("thread_function is running. \n");
	for (i = 0; i < 10; i++) {
		printf("The thread is still running (%d).... \n", i);
		sleep(1);
	}
	pthread_exit((void *)NULL);

	return (void *)NULL;
}

int 
main(void)
{
	int res = 0;
	pthread_t a_thread = 0UL;
	void *thread_result = (void *)NULL;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)NULL);
	IF_ERROR(res, "pthread_create");
	
	sleep(3);
	printf("Canceling thread.... \n");
	res = pthread_cancel(a_thread);
	IF_ERROR(res, "pthread_cancel");

	printf("Waiting for thread to finish.... \n");
	res = pthread_join(a_thread, &thread_result);
	IF_ERROR(res, "pthread_join");

	return 0;
}

/*
#include <pthread.h>

1. int pthread_cancel(pthread_t thread);

2. int pthread_setcancelstate(int type, int *oldtype);
    int type: 
    PTHREAD_CANCEL_ENABLE (default)：讓執行緒可以收到結束的要求；
    PTHREAD_CANCEL_DISABLE：讓執行緒忽略結束的要求。

3. int pthread_setcanceltype(int type, int *oldtype);
    int type: 
    PTHREAD_CANCEL_ASYNCHRONOUS：立刻實現結束的請求；
    PTHREAD_CANCEL_DEFERRED (default)：當執行緒執行到pthread_join, pthread_cond_wait, pthread_cond_timewait, 
    pthread_testcancel, sem_wait, sigwait函數時，才會執行結束的請求。
*/
