#include<stdio.h>
#include<string.h>
#include<conio.h>
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		arr[i] = getche() - 48;
		putchar(32);
	}
	for (int k = 0; k < 4; k++) {
		for (int j = k + 1; j < 5; j++) {
			if (arr[k] > arr[j]) {
				swap(&arr[k], &arr[j]);
			}
		}
	}
	printf("\n");
	for (int z = 0; z < 5; z++) {
		printf("%d ", arr[z]);
	}
	return 0;
}