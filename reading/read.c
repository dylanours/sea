#include <stdio.h>
#define MAXLEN 13 

int main() {
	FILE* file = fopen("words.txt", "r");
	char c;
	int lineLength = 0;

	while((c=fgetc(file))!=EOF) {
		if (++lineLength > MAXLEN) {
			printf("\n    ");	
			lineLength = 5;
		}
		if(c=='\n') lineLength = 0;
		printf("%c", c);
	}
	return 0;
}
