#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int main() {
	int arr[100][100] = { 0 };
	int a, b;
	int value = 1;
	int j=0;
	int k = 0;
	int row = 0, col = -1;
	scanf("%d %d", &a, &b);
	while (1) {
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {				
				if (i + j == k) {
					arr[j][i] = value++;
				}
			}
		}
		k++;
		if (value-1==a*b) {
			break;
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}