#include<stdio.h>

int main() {
	int arr[100] = { 0, };
	int count = 0;
	int ar[8] = { 0 };
	int t = 150;
	for (int i = 0; arr[i-1]!=-99; i++) {
		scanf("%d,", &arr[i]);
		count++;
	}
	for (int i = 0; i <= count; i++) {
		switch (arr[i]/10)
		{
		case 15: if (arr[i] % 10 < 5) { ar[0]++; }
			   else ar[1]++; break;
		case 16: if (arr[i] % 10 < 5) { ar[2]++; }
			   else ar[3]++; break;
		case 17: if (arr[i] % 10 < 5) { ar[4]++; }
			   else ar[5]++; break;
		case 18: if (arr[i] % 10 < 5) { ar[6]++; } break;
		default: continue;
		}
	}
	printf("\n");
	for (int i = 0; i < 7; i++) {
		printf("%d - %d = %d\n", t, t+4,ar[i]);
		t += 5;
	}
	t = 150;
	printf("\n");
	for (int i = 0; i < 7; i++) {
		printf("%d - %d | ", t, t + 4);
		for (int j = 0; j < ar[i]; j++) {
			printf("бс");
		}
		printf("\n");
		t += 5;
	}
	return 0;
}