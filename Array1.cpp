#include<stdio.h>

int main() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		printf("%d번 학생의 프C 성적 : ", i+1);
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < 5; i++) {
		if (arr[0] <= arr[i]) {
			arr[0] = arr[i];
		}
	}
	printf("최고 점수 : %d", arr[0]);
	return 0;
}