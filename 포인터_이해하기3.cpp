#include<stdio.h>

int main() {
	int a[5] = { 0,1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%d %d\n", &a[0], &a[1]);
	printf("a林家=%d a[0]林家=%d\n", a, &a[0]);
	int* p = a;
	printf("a林家=%d\n", p);
	return 0;
}