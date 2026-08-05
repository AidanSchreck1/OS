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

extern char **environ;

void execl_or_die (const char *path, 
		const char *arg1, 
		const char *arg2) {

	execl(path, arg1, arg2, (char *) NULL);
}
void execle_or_die (const char *path, 
		const char *arg1, 
		const char *arg2,
		char *const envp[]) {

	execle(path, arg1, arg2, (char *) NULL, envp);
}
void execlp_or_die (const char *file, const char *arg1, const char *arg2) {
	execlp(file, arg1, arg2, (char *) NULL);
}
void execv_or_die (const char *path, char *const argv[]) {
	execv(path, argv);
}
void execvp_or_die (const char *file, char *const argv[]) {
	execvp(file, argv);
}
void execve_or_die (const char *file,
		char *const argv[], 
		char *const envp[]) {

	execve(file, argv, envp);
}
int main(int argc, char *argv[]) {
	int rc = fork_or_die();
	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} 
	else if (rc == 0) { // child: redirect standard output to a file
		const char *path = "/bin/ls";
		const char *arg1 = "ls";
		const char *arg2 = "./";

		char *const args[] = {
			"ls",
			"./"
		};
			
		execve_or_die(path, args, environ);
	} 
	else { // parent goes down this path (main)
		int wc = wait(NULL);
	}
	return 0;
	
	

}
