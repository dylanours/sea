#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int rightrot(int, int);
int innerrightrot(int, int, int, int);
void printBits(int);
void setBit(int*, int, bool);

int main() {
	int x, s, e, n;
	printf("Right Rotate some bits, \n");
	while (1==1) {
		printf("Value, start, end, rotate count: ");
		scanf("%d %d %d %d", &x, &s, &e, &n);	
		printBits(x);
		x = innerrightrot(x, s, e, n);
		printBits(x);
	}
	return 0;
}

void setBit(int *x, int pos, bool val) {
	unsigned mask = ~( 01 << pos);
	*x &= mask;
	if (val) *x |= ~(mask);
}

int innerrightrot(int x, int sPos, int ePos, int n) {
	size_t len = sizeof(x) * 8;
	unsigned mask = 00;
	for(int i=0; i<=(sPos - ePos); i++)
		mask = (mask << 1) | 01;
	mask <<= ePos;
	for(int i=0; i<n; i++) {	
		int x_masked = x & mask;
		bool val = ((01 << ePos) & x) > 0;
		x_masked >>= 1;
		setBit(&x_masked, sPos, val);
		x_masked &= mask;
		x = x_masked | (x & ~mask);
		printBits(x);
	}
	return x;
}

int rightrot(int x, int n) {
	size_t len = sizeof(x) * 8;
	unsigned mask = 01;
	for(int j = 0; j<n; j++) {
		unsigned bit = x & mask;
		x >>= 1;
		x = (x & ~(01 << (len-1))) | (bit << (len-1));
	}
	return x;
}

void printBits(int x) {
	size_t len = sizeof(x);
	len *= 8;
	char bits[len];
	unsigned mask = 01;	
	int i = 0;	
	while(i<len) {
		if ((mask & x) > 0) bits[i] = '1';
		else bits[i] = '0'; 
		i++;
		mask <<= 1;
	}
	for(int j=len-1; j>=0; j--)
		printf("%c", bits[j]);
	printf("\n");	
}
