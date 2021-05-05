#include<stdio.h>
#include<stdlib.h>
/*
int main() {
	int a[20] = { 35,26,48,77,56,98,75,78,99,0,43,56,67,84,99,100,45,37,49,78 };
	int i, histo[11] = { 0 };
	for (i = 0; i < 20; i++) {
		histo[a[i] / 10]++;
	}
	for (i = 0; i < 10; i++) {
		printf("%3d : ", i * 10);
		for (int j = 0; j < histo[i]; j++) {
			printf("≠");
		}
		printf("\n");
	}
}
*/
int main() {
	int re = 0;
	int a[20] = { 35,26,48,77,56,98,75,78,99,0,43,56,67,84,99,100,45,37,49,78 };
	int i, histo[11] = { 0 };
	for (i = 0; i < 20; i++) {
		histo[a[i] / 10]++;
	}
	for (i = 20; i > 0; i--) {
		for (int j = 10; j >= 0; j--) {
			if (histo[j] == i) {
				printf("﹥");
				histo[j]--;
			}
			else {
				printf("  ");
				re++;
			}
			if (re == 10) {
				system("cls");
			}
		}
		re = 0;
		printf("\n");
	}
	printf("天天天天天天天天天天天\n");
	printf("10 9 8 7 6 5 4 3 2 1 0");
}