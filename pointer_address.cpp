#include<stdio.h>

int main() {
	char Arr[3][10] = { "kim","Hong","Lee" };
	char* pArr[3] = { Arr[0], Arr[1], Arr[2] };
	printf("%s \n", pArr[0]);
	printf("%s \n", pArr[1]);
	printf("%s \n", pArr[2]);
	printf("%s \n", *pArr);
	printf("%s \n", (*pArr+1));
	printf("%s \n", (*pArr+2));
	printf("%s \n", *pArr);
	printf("%s \n", *(pArr+1));
	printf("%s \n", *(pArr+2));

}