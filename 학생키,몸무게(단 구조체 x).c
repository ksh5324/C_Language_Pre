//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//char name[5][20];
//int he[5];
//double we[5];
//void input() {
//	for (int i = 0; i < 5; i++) {
//		scanf("%s %d %lf", name[i], &he[i], &we[i]);
//	}
//}
//
//void sort() {
//	char tmp_name[20];
//	int tmp_he;
//	double tmp_we;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (he[i] > he[j]) {
//				tmp_he = he[i];
//				he[i] = he[j];
//				he[j] = tmp_he;
//				tmp_we = we[i];
//				we[i] = we[j];
//				we[j] = tmp_we;
//				strcpy(tmp_name, name[i]);
//				strcpy(name[i], name[j]);
//				strcpy(name[j], tmp_name);
//			}
//		}
//	}
//}
//
//void output() {
//	for (int i = 0; i < 5; i++) {
//		printf("%s %d %.lf \n", name[i], he[i], we[i]);
//	}
//}
//
//int main() {
//	input();
//	sort();
//	output();
//	return 0;
//}