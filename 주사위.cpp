#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int result = 0;

int f(char y) {
x:
	printf("주사위 게임을 하시겠습니까(y/n) ");
	scanf(" %c", &y);
	if (y == 'n' || y == 'N') {
		exit(1);
	}
	else if (y == 'y' || y == 'Y') {
		result = 0;
		return 0;
	}
	else {
		printf("잘못입력 하셨습니다.\n");
		goto x;
	}
}

int main() {
	srand(time(NULL));
	int i, j;
	char y=' ';
	f(y);
	while (1) {
	i = rand() % 6 + 1;
	j = rand() % 6 + 1;
		printf("주사위: %d %d\n", i, j);
		result = result + i + j;
		if (i == j) {
			printf("더블입니다.\n");
		}
		else {
			printf("%d칸 전진하세요\n", result);
			f(y);
		}
	}
	return 0;
}