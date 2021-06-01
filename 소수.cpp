//#include<stdio.h>
//
//int isPrime(int n) { //소수인지 여부 알려주는 함수
//	for (int i = 2; i * i <= n; i++) {
//		if (!(n % i)) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	while (1) {
//		int n;
//		printf("숫자: ");
//		scanf("%d", &n);
//		if (n < 2) return 0;
//		if (n >= 10000) {
//			printf("\n");
//			continue;
//		}
//		int primeCnt = 1;
//		for (int i = 2; i <= n; i++) {
//			if (isPrime(i)) {
//				printf("%d ", i);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}