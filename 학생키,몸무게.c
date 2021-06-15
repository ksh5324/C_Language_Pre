#include<stdio.h>
#include<string.h>

typedef struct _p {
	char name[20];
	int he;
	double we;
}Student;

Student s[5];

void input() {
	for (int i = 0; i < 5; i++) {
		scanf("%s %d %lf", s[i].name, &s[i].he, &s[i].we);
	}
}

void sort() {
	Student tmp;
	int i;
	int j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (s[i].he < s[j].he) {
				memcpy(&tmp, &s[i], sizeof(Student));
				memcpy(&s[i], &s[j], sizeof(Student));
				memcpy(&s[j], &tmp, sizeof(Student));
			}
		}
	}
}


void output() {
	for (int i = 0; i < 5; i++) {
		printf("%s %d %.lf \n", s[i].name, s[i].he, s[i].we);
	}
}

int main() {
	input();
	sort();
	output();
	return 0;
}