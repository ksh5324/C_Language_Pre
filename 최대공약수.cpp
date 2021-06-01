//#include<stdio.h>
//
//int main() {
//	int x, y, xy, z;
//	int gcd = 0, lcm = 0;
//	do {
//		x = 0, y = 0;
//		printf("두발을 심어주세요 : ");
//		scanf("%d %d", &x, &y);
//		xy = x * y; 
//		if (x > 0 && y > 0) {
//			while (1) {
//				z = x % y;
//				if (z == 0) {
//					gcd = y;
//					lcm = xy / y;
//					break;
//				}
//				else {
//					x = y;
//					y = z;
//				}
//
//			}
//			printf("GCD : %d, LCM : %d\n\n", gcd, lcm);
//		}
//		else if (x != 0 || y != 0) {
//			printf("\n양의 정수를 입력하세요. Quit(0,0)\n\n");
//		}
//	} while (x != 0 || y != 0);
//	return 0;
//}