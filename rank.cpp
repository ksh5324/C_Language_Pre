#include<stdio.h>
#include<stdlib.h>
/*
int main() {
	int a[20] = { 35,26,48,77,56,98,75,78,99,0,43,56,67,84,99,100,45,37,49,78 };
	int rank[20] = { 0 };
	int i, j;
	for (i = 0; i < 20; i++) {
		rank[i] = 1;
		for (j = 0; j < 20; j++) {
			if (a[i] < a[j]) {
				rank[i]++;
			}
		}
	}
	printf("학생 등수\n");
	for (i = 0; i < 20; i++) {
		printf("----------------------\n");
		printf("| 학번:%3d, 등수:%3d |\n", i + 1, rank[i]);
		printf("----------------------\n");

	}
}
*/

#include <stdio.h>
int main()
{
	int a[20] = { 56,34,33,51,24,3,45,32,32,11 ,2,55,84,37,97,36,89,23,78,45 };
	int rank[102] = { 0, };
	int i, j;
	for (i = 0; i < 20; i++)
	{
		rank[a[i]]++;
	}
	rank[101] = 1;
	for (i = 100; i >= 0; i--)
	{
		rank[i] = rank[i] + rank[i + 1];
	}
	printf("학생 등수 \n");
	for (i = 0; i < 20; i++)
	{
		printf("%3d %5d %3d\n", i + 1, a[i], rank[a[i] + 1]);
	}
	return 0;
}

int compare(const void* a, const void* b)    
{
	int num1 = *(int*)a;    
	int num2 = *(int*)b;    
	if (num1 < num2)    
		return -1;      
	if (num1 > num2)    
		return 1;       
	return 0;    
}

int main() {
	int j=0;
	int a[20] = { 35,26,48,77,56,98,75,78,99,0,43,56,67,84,99,100,45,37,49,78 };
	int rank[20];
	for (int i = 0; i < 20; i++) {
		rank[i] = a[i];
	}
	printf("성적순으로 정렬\n\n");
	qsort(a, sizeof(a) / sizeof(int), sizeof(int), compare);
	for (int i = 19; i >= 0; i--) {
		a:
		if (a[i] == rank[j]) {
			printf("| 학번%3d : %3d |\n", j+1, a[i]);
		}
		else {
		j++;
		goto a;
		}
		j = 0;
	}
}