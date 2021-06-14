#include<stdio.h>
#include<string.h>
typedef struct score {
	char name[20];
	int kor;
	int eng;
	int math;
} Student;

void score(Student s1, Student s2, Student* sum) {
	sum->kor = s1.kor + s2.kor;
	sum->eng = s1.eng + s2.eng;
	sum->math = s1.math + s2.math;
}

int main() {
	Student s1, s2, sum;
	scanf("%s %d %d %d", s1.name, &s1.kor, &s1.eng, &s1.math);
	scanf("%s %d %d %d", s2.name, &s2.kor, &s2.eng, &s2.math);
	strcpy(sum.name, "รัวี");
	score(s1, s2, &sum);
	printf("%s %d %d\n", s1.name, s1.kor, s1.eng, s1.math);
	printf("%s %d %d\n", s2.name, s2.kor, s2.eng, s2.math);
	printf("%s %d %d\n", sum.name, sum.kor, sum.eng, sum.math);
	return 0;
}