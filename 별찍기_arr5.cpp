
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	int i, j, a;
	char ar[100][100] = {};
	a = getch() - 48;
	for (i = 0; i < a * 2 - 1; i++) {
		for (j = 0; j < a * 2 - 1; j++)
			if (i == j || i + j == a * 2 - 2 || i == 0) {
				if (i >= 5) {
					ar[i][j] = 32;
					continue;
				}
				ar[i][j] = '*';
			}
			else {
				ar[i][j] = 32;
			}

	}
	for (i = 0; i < (a * 2); i++) {
		for (j = 0; j < (a * 2); j++) {
			printf("%c", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}
