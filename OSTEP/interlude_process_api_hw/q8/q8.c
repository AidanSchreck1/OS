#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
	int fd[2];
	if (pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}
	pid_t p1 = fork();
	if (p1 == 0) {
		//dont need the read end of this pipe
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);


		execl("/bin/ls", "ls", "-l", NULL);
		exit(1);

	}

	pid_t p2 = fork();

	if (p2 == 0) {
		//dont need the write end
		close(fd[1]); 	
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);

		execl("/bin/wc", "wc", "-l", NULL);
		exit(1);
	}

	close(fd[0]);
	close(fd[1]);


	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);




}
