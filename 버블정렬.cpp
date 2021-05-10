#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int arr[], int len);

int main() {
	int arr[5] = { 4,6,1,3,9 };
	int i;
	BubbleSort(arr, 5);
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}

void BubbleSort(int arr[], int len) {
	int i, j;
	int temp;
	for (j = 0; j < len-1; j++) {
		for (i = 0; i < len-j-1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}