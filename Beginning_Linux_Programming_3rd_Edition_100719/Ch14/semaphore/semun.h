#ifndef _SEMUN_H_
#define _SEMUN_H_

#define	SEM_KEY_TEST		1234

union semun {
	int val;				// Value for SETVAL
	struct semid_ds *buf;	// Buffer for IPC_STAT, IPC_SET
	unsigned short *array;	// Array for GETALL, SETALL
	struct seminfo *__buf;	// Buffer for IPC_INFO (Linux-specific)
};

#endif
