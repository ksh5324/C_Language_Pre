#include<stdio.h>

int main() {
	int a[5] = { 0,1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%p %p\n", &a[0], &a[1]);
	printf("%d\n", &a[1] - &a[0]);
}