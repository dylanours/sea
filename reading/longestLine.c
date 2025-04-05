#include <stdio.h>

#define MAXSTRING 1000

int getNextLine(char newLine[], int stringLength, FILE** filepointer);
void replaceString(char source[], char destination[]);
void printString(char str[]);

int main() {
	FILE* filepointer = fopen("words.txt", "r");
	int tempLen = 0, maxLen = 0;
	char temp[MAXSTRING];
	char maxi[MAXSTRING];

	while((tempLen = getNextLine(temp, MAXSTRING, &filepointer)) > 0) {
		if (tempLen > maxLen) {
			maxLen = tempLen;
			replaceString(temp, maxi);
		}
	}

	printString(maxi);
}

void printString(char str[]) {
	int i = 0;
	char c;

	while((c = str[i]) != '\0') {
		printf("%c", str[i]);
		i++;
	}
}

void replaceString(char source[], char destination[]) {
	int i = 0;
	char c = source[0];
	do {	
		destination[i++] = c;
	} while((c = source[i]) != '\0');
}

int getNextLine(char newLine[], int stringLength, FILE** filepointer) {
	char c;	
	int newStringLength = 0;
	while(((c = fgetc(*filepointer)) != EOF) && (newStringLength < stringLength)) {
		newLine[newStringLength] = c;	
		newStringLength++;
		if (c == '\n') {
			newLine[newStringLength++] = '\0';	
			return newStringLength;
		}
	}
	newLine[newStringLength] = '\0';	
	return newStringLength;
}
