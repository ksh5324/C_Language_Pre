#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct node { char data; node* next; }Node;


int main() {
	srand(time(NULL));
	Node num[2] = { 0, };
	int st = 0, ba = 0;
	num[0].data = (int)(rand() % 10) + 48;
	num[1].data = (int)(rand() % 10) + 48;
	num[2].data = (int)(rand() % 10) + 48;
	num[0].next = &num[1];
	num[1].next = &num[2];
	num[2].next = &num[0];
	char num_[5] = { 0, };
	while (1) {
		scanf("%s", num_);
		for (int i = 0; i < 3; i++) {
			if (strncmp(&num[i].data, &num_[i],1) == 0) {
				st++;
			}
			else if (strncmp(&num[i].next->data, &num_[i],1) == 0) {
				ba++;
			}
			else if (strncmp(&num[i].next->next->data, &num_[i],1) == 0) {
				ba++;
			}
		}
		printf("st: %d ba: %d\n", st, ba);
		if (st == 3) {
			exit(1);
		}
		st = 0;
		ba = 0;
	}
	return 0;
}