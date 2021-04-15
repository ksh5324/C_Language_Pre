#include<stdio.h>

int main(){
	int i=0, j=0;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (i == j) {
				printf("*");
			}
			else if (i + j == 6) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}