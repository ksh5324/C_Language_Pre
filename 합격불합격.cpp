#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	int arr[3][4] = { 0 };
	int count[3] = { 0 }, j=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
			count[i] += arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		if ((count[i] / 4) >= 80) {
			printf("pass\n");
			j++;
		}
		else {
			printf("fail\n");
		}
	}
	printf("гу╟щ: %d", j);
	return 0;
}