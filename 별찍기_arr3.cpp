#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	int i, j, a;
	char ar[100][100] = {};
	a = getch() - 48;
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++)
			if (i == 0 || j == 0 || i == a - 1 || j == a - 1) {
				ar[i][j] = '*';
			}
			else {
				ar[i][j] = 32;
			}
	}
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			printf("%c ", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}
