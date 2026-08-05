#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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
	int rc = fork_or_die();
	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} 
	else if (rc == 0) { // child: redirect standard output to a file
		printf("Hello this is process: %d\n", (int) getpid());
		int wc = wait(NULL);
		printf("%d\n", wc);
		char *myargs[3];
		myargs[0] = strdup("wc"); // program: "wc" (word count)
		myargs[1] = strdup("../q4/q4.c"); // argument: file to count
		myargs[2] = NULL; // marks end of array
		execvp(myargs[0], myargs); // runs word count
		printf("this shouldn’t print out");
	} 
	else { // parent goes down this path (main)
		int wc = waitpid(-1, NULL, 0);
		printf("%d\n%d\n", wc, (int) getpid());
	}
	return 0;

}
