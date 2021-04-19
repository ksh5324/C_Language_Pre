#include<stdio.h>

int func(int n) {
	static int a = 0;
	a++;
	printf("n=%d, a=%d\n", n, a);
	return 0;
}

int _main() {
	//static 변수를 사용하는 이유는?
	int n = 5;
	func(n);
	func(n);
	return 0;
}