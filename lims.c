#include <limits.h>
#include <stdio.h>

int exponent(int base, int power); 

int main() {
	int x;
	printf("max int: %d, min int: %d\n", INT_MAX, INT_MIN);

	int maxInt = exponent(2, (sizeof(x) * 8)-1)-1;
	//int minInt = exponent(2, (sizeof(x) * 8)-1)-1;

	printf("calc max int: %d\n", maxInt);

	x = 1;
	int i = 0;
	do{
		//x = (x << 1) & 1;
		x <<= 1;
		i++;
		printf("%d: %d\n", i, x);
	} while(i<=36);

	return 0;
}

int exponent(int base, int power) {
	int ret = 1;
	for(; power >= 1; power--) {
		ret *= base;
	}
	return ret;
}
