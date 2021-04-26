#include<stdio.h>

// 포인터(Pointer)란?
// 메모리 주소값을 저장하는 변수
// 

int main() {
	int n1 = 100, n2 = 200;
	int* p;
	p = &n1;
	printf("%p\n", p); // 00F5FD3C
	printf("%d\n", *p); // 100
	printf("%d\n", n1); // 100
	(*p) = 300;
	printf("%d\n", *p);
	return 0;
}