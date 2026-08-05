#include <stdlib.h>
int main() {
	int* a = (int *) malloc(sizeof(int));
	*a = 42;
	return *a;
}
