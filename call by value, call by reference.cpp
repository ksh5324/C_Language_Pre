#include<stdio.h>

void swap1(int, int);
void swap2(int*, int*);

int main() {
	int a = 5, b = 8;
	printf("a=%d, b=%d\n", a, b);
	swap1(a, b);
	printf("a=%d, b=%d\n", a, b);
	swap2(&a, &b);
	printf("a=%d, b=%d\n", a, b);
}

void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	printf("함수 안: a=%d, b=%d\n", a, b);
}

void swap2(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
	/*int temp = *a;
	*a = *b;
	*b = temp;
	*/
	printf("함수 안: a=%d, b=%d\n", *a, *b);
}