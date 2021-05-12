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
	int temp; // 두 변수에 값을 교체하기위한 변수
	for (j = 0; j < len-1; j++) {
		for (i = 0; i < len-j-1; i++) {
			if (arr[i] > arr[i + 1]) { // 두 인덱스에 값을 비교하고 조건에 만족하면 교체
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}