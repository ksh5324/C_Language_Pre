#include<stdio.h>

int main() {
	int arr[10] = { 0 };
	int student_num, result=0;
	scanf("%d", &student_num);
	for (int i = 0; i < student_num; i++) {
		scanf("%d", &arr[i]);
		result += arr[i];
	}
	printf("%.2lf", (double)result / 3);
	return 0;
}