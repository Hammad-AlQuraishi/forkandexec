#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	printf("Initiating strace on parents.\n");
	char buffer[20];
	int call = snprintf(buffer, 20 ,"strace -p %d\n", getpid());
	system(buffer);
	printf("I am the parent with pid: %d. I haven't spawned a child yet.\n", getpid());
	printf("Do stuff before fork(). Proof that fork clones from the line it's called from.\n");
	pid_t pid = fork();
	// fork() will returns child pid for the parent and 0 for the child process
	if (pid > 0) {
		printf("I am the parent (PID: %d)  returning the child id: %d\n",getpid(), pid);
	} else if (pid == 0) {
                printf("Initiated strace on myself.\n"); 
		printf("I am the child (PID: %d)  indicated by my return value of: %d\n",getpid(), pid);
		printf("As the child, I am not going to repeat what my father did.\n");
		printf("Child exiting.\n");
		exit(0);
 
	} else {
		perror("fork failed");
	}

	return 0;
}
