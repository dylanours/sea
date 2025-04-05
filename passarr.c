#include <stdio.h>

void replaceChar(char str[], char f, char r);

int main() {
	char names[] = "Kennedy, Wrenley, Reagan";

	replaceChar(names, 'e', 'a');
	int i=-1;
	char c;
	while ((c=names[++i]) != '\0') printf("%c", c);
	printf("\n");
	return 0;
}

void replaceChar(char str[], char f, char r) {
	char c;
	int i=-1;
	while((c=str[++i]) != '\0') {
		if (c == f) str[i] = r;
	}
	return;
}
