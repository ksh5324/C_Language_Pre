#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int arr[4] = { 1,2,3,4 };
	// int 4byte : total 16byte
	int* pArr;
	pArr = (int*)malloc(16); // malloc()
	for (int i = 0; i < 4; i++) {
		pArr[i] = i*i;
		printf("pArr[%d]=%d\n", i, pArr[i]);
	}
	free(pArr);
	return 0;
}