#include <stdio.h>

int main() {
	int number = 13; 
	int bitCount = sizeof(number) * 8;
	int mask = 1;
	char bits[bitCount];

	for(int i=1; i<=bitCount; i++) {
		int out = mask & number;
		bits[bitCount-i-1] = out > 0 ? '1':'0';
		mask = mask << 1;
	}

	printf("%d = %s\n", number, bits);
	return 0;
}
