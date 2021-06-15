#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int* pArr;
	int n;
	scanf("%d", &n);
	pArr = (int*)malloc(sizeof(int) * n);
	if (pArr == NULL) {
		printf("메모리 공간 초과");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		pArr[i] = i * i;
		printf("pArr[%d]=%d\n", i, pArr[i]);
	}
	return 0;
}