#include <stdio.h>

int power(int x, int y);

int main() {
	int userInput = 0;
	int y = 0;
	while(1) {
		scanf("%d %d", &userInput, &y);
		printf("%d^%d = %d\n", userInput, y, power(userInput, y));
	}
	return 0;
}

int power(int x, int y) {
	int ret = x;
	for(int i=1; i<y; ++i)
		ret *= x;
	return ret;
}
