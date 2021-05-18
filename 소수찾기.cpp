#include<stdio.h>
#include<stdlib.h>

int isPrime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (!(n % i)) { //if(n%i==0)
			return 0;
		}
	}
	return 1;
}

int main() {
	int k, count = 0;
	while (1)
	{
		count = 0;
		printf("¼ýÀÚ: ");
		scanf("%d", &k);
		if (k < 2) {
			break;
		}
		if (k >= 1000) {
			printf("\n");
			continue;
		}
		for (int i = 2; i < k; i++) {
			if (isPrime(i)) {
				printf("%4d", i);
				count++;
			}
			if (count == 10) {
				printf("\n");
				count = 0;
			}
		}
		if (count == 0) {
			printf("\n");
		}
		else {
			printf("\n\n");
		}
	}
	return 0;
}