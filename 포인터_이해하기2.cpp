#include<stdio.h>

int main() {
	int n1 = 100;
	int* p;
	p = &n1;// 林家客 林家 历厘
	printf("%p, %p\n", p, &n1);
	printf("郴侩, 蔼: %d, %d\n", *p, n1);
	for (int i = 0; i < 5; i++) {
		printf("%4d", (*p)++);
	}
	return 0;
}