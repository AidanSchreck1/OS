#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

void wait_or_die() {
	int rc = wait(NULL);
	assert(rc > 0);
}

int fork_or_die() {
	int rc = fork();
	assert(rc >= 0);
	return rc;
}

int main(int argc, char *argv[]) {
	close(STDOUT_FILENO);
	open("./q3.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork_or_die();
	if (rc == 0) {
		printf("hello PID: %d\n", (int) getpid());
	}
	else {
		sleep(1);
		printf("goodbye PID: %d\n", (int) getpid());
	}

}
