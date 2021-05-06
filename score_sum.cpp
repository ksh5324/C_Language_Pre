#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j;
	int score[4][4] = { { 0 } };
	for (i = 0; i <= 3; i++) {
		printf("%d번 점수 ", i + 1);
		for (j = 0; j < 3; j++) {
			scanf("%d", &score[i][j]);
			score[i][3] += score[i][j];
			score[3][j] += score[i][j];
			score[3][3] += score[i][j];
		}
	}
	printf("     컴일  프C  수학  총점\n");
	for (i = 0; i < 4; i++) {
		if (i < 3) printf("  %d번", i + 1);
		else printf("합계");
		for (j = 0; j < 4; j++) {
			printf("%4d", score[i][j]);
		}
		printf("\n");
	}
	return 0;
}