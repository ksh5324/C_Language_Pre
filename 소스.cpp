#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main() {
	int arr[10] = { 0 };
	int s=0;
	int temp=0;
	for (int i = 0; i < 10; i++) {
		arr[i] = _getche() - 48;
		s++;
		if (arr[i] == -35) {
			break;
		}
	}
	for (int j = 0; j < (s-2); j++) {
		for (int k = j + 1; k < s-1; k++) {
			if(arr[j] < arr[k]) {
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}
	for (int t = 0; t < s-1; t++) {
			printf("%d", arr[t]);
	}
	return 0;
}