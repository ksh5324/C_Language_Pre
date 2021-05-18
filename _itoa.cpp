#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	char arr[50];
	printf("Enter a number: ");
	scanf("%d", &i);
	_itoa(i, arr, 10);
	printf("decimal: %s\n", arr);
	_itoa(i, arr, 16);
	printf("hexadecimal: %s\n", arr);
	_itoa(i, arr, 2);
	printf("binary: %s\n", arr);
}