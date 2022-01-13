#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char **envp)
{
	int nArgv = atoi(argv[1]);
	char *szArgv[] = {"ls", "-al", "/etc/passwd", (char *)NULL};

	if (nArgv == 0)
		execl("/bin/ls", "ls", "-al", "/etc/passwd", (char *)NULL);
	else if (nArgv == 1)
		execlp("ls", "ls", "-al", "/etc/passwd", (char *)NULL);
	else if (nArgv == 2)
		execle("/bin/ls", "ls", "-al", "/etc/passwd", (char *)NULL, envp);
	else if (nArgv == 3)
		execv("/bin/ls", szArgv);
	else if (nArgv == 4)
		execvp("ls", szArgv);
	else	/* if (nArgv == 5) */
		execve("/bin/ls", szArgv, envp);
	printf("DONE. \n");

	return 0;
}

/*
Differences:
1. "execl*()"和"execv*()"的差異在於："execv*()"系列是把*argv[]以字串陣列的方式傳進去；
2. execlp()和execvp()會在環境變數的目錄中去尋找"ls"這一支程式在哪裡；這裡「環境變數的目錄」指的是："echo $PATH"所列出的目錄。
3. execle()和execve()會把原本這一支程式的環境變數 (Environments)傳給新的程式"ls"來使用。
4. 基本概念：execl("/bin/ls", "ls", "-al", "/etc/passwd", (char *)NULL);
	"/bin/ls": 這一支程式的絕對路徑在哪裡；
	"ls": argv[0];
	"-al": argv[1];
	"/etc/passwd": argv[2];
5. 這些程式最後面一定要加一個結束字元：(char *)NULL
6. exec*()系列的程式和system()的差別在於exec*()會取代原本的程式 (所以不會執行到printf())；而system()則是執行完之後會回到原本的
程式。
*/
