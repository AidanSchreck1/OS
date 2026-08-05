#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

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
	int x = 100;
	fork_or_die();
	x = 2;
	printf("Value of x: %d\n My PID is: %d\n", x, (int) getpid());
		
	return 0;

}

