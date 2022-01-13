#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/msg.h>

#define MAX_TEXT	512

struct my_msg_st {
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main(void)
{
	int running = 1;
	int msgid = -1;
	struct my_msg_st some_data;
	char buffer[BUFSIZ];

	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		fprintf(stderr, "msgget failed with error: %d \n", errno);
		exit(EXIT_FAILURE);
	}

	while (running) {
		memset(&buffer, '\0', sizeof(char) * BUFSIZ);
		printf("Enter some text: ");
		fgets(buffer, sizeof(char) * BUFSIZ, stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text, buffer);
		if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) {
			fprintf(stderr, "msgsnd failed. \n", errno);
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "end", 3) == 0)
			running = 0;
	}
/*
	if (msgctl(msgid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "msgctl (IPC_RMID) failed with error: %d \n", errno);
		exit(EXIT_FAILURE);
	}
*/
	return 0;
}
