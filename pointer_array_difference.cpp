#include<stdio.h>

int main() {
	int a[5] = { 0,1,2,3,4 };
	int* p;
	int b = 10;
	a = &a; // 식시 수정할수있는 lvalue여야 합니다.
	b = &b;
}