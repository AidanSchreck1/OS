
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
	

	struct timeval start_time, end_time;
	// 1. Capture the starting time
	gettimeofday(&start_time, NULL);	



	for (int i = 0; i < 20; i++) {
		int fd = 0; // Standard Input (stdin)
	    
		// Perform the 0-byte read
		ssize_t bytes_read = read(fd, NULL, 0);

	
	}
	
	// 3. Capture the ending time
	gettimeofday(&end_time, NULL);
	// 4. Calculate total seconds and microseconds spent
	long seconds = end_time.tv_sec - start_time.tv_sec;
	long microseconds = end_time.tv_usec - start_time.tv_usec;

	// 5. Adjust for negative microsecond values
	if (microseconds < 0) {
		seconds--;
		microseconds += 1000000;
	}

	// 6. Convert total elapsed time to milliseconds
	double total_ms = (seconds * 1000.0) + (microseconds / 1000.0);
	double finaltime = total_ms/20;
	printf("Elapsed time: %.3f milliseconds\n", finaltime);

	return 0;
}
