#include<stdio.h>
#define SIDE 100

int arr[SIDE][SIDE];

void printarr(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

void makearr(int n) {
	int value = 1;
	int row = 0, col = -1;
	int inc = 1; // 증가 1 또는 -1
	int i, j;
	while (n > 0) {
		for (i = 0; i < n; i++) {
			col += inc;
			arr[row][col] = value++; // value는 배열 안의 값
		}
		n--;
		if (n == 0) break;
		for (i = 0; i < n; i++) {
			row += inc;
			arr[row][col] = value++;
		}
		inc *= -1; // 
	}
}

int mai_n() {
	int side;
	printf("달팽이 배열의 길이 : ");
	scanf("%d", &side);
	makearr(side);
	printarr(side);
	return 0;
}
