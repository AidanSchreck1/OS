#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int *data = (int *) malloc(100 * sizeof(int));	
	free(data);
	int a = data[1];
	printf("%d\n", a);
	return 0;
}
