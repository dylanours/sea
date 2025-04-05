#include <stdio.h>

int main() {
	//0-300 in steps of 20
	//C = (5/9)*(F-32)
	printf("f\tc\n");
	for (int i=0; i<=300; i+=20) {
		printf("%d\t%d\n", i, (5*(i-32)/9));
	}
	return 0;
}
