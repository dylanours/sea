#include <stdio.h>

int main() {
	int x = 10;
	int *p = &x;

	printf("*p: %p\n", (void*)p);
	return 0;
}
