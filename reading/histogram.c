//Histogram, length of words

#include <stdio.h>

int main() {
	FILE *file = fopen("words.txt", "r");
	int hist[11] = {0};
	int i=0, max=0;
	char c;
	while ((c=fgetc(file)) != EOF) {
		if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
			i++;
		} else {
			if (i>0 && i<=10) hist[i-1]+=1;	
			else if (i>10) hist[10]+=1;
			if (hist[i-1] > max) max = hist[i-1];
			i=0;
		}
	}

	for(i=max; i>0; i--) {
		for(int j=0; j<11; j++) {
			if(hist[j]>=i) printf(" • ");
			else printf("   ");
		}
		printf("\n");
	}
	for(i=1;i<=10;i++){
		printf("%02d ", i);
	}
	printf("\n");
	return 0;
}
