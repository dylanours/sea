#include <stdio.h>
#include <string.h>

void getInput(char*);
int htoi(char*, int);

int main() {
	char input[50] = "";
	char b[10] = "";
	printf("Base: ");
	getInput(b);
	int base = htoi(b, 10);
	while (input[0] != '-') {
		printf("Hex number: ");
		getInput(input);
		if ((input[0] == 'O' || input[0] == '0' || input[0] == 'o') && input[1] == 'x') {
			int converted = htoi(input, base);
			printf("\nDecimal: %d\n", converted);
		} else {
			printf("Invalid hex entry.\n");
		}
	}
	return 0;
}

void getInput(char* input) {
	int i=0;
	int c;
	while ((c = getchar()) != '\n')
		input[i++] = c;
	input[i] = '\0';
	return;
}

int ex(int x, int y) {
	int ret = 1;
	for (; y>0; y--)
		ret *= x;
	return ret;
}

int ctoi(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	return c - 'a' + 10;
}

int htoi(char* input, int base) {
	int convert = 0;
	int end = 1;
	while (input[++end] != '\0')
		;
	int pos = 0;
	for (int i=end-1; i>=2; i--)
		convert += (ex(base, pos++) * ctoi(input[i]));
	return convert;
}
