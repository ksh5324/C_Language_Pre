#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct string {
	char string[100][100];
	char name[10];
	int cnt=0;
};

struct integer {
	int integer[100];
	int cnt=0;
	char name[10];
};

struct boolean {
	bool boolean[100];
	int cnt = 0;
	char name[10];
};

struct dou {
	double dou[100];
	int cnt = 0;
	char name[10];
};

typedef struct table_sturct {
	int cnt=0;
	char name[10];
	struct string string[5];
	int string_cnt=0;
	struct integer integer[5];
	int integer_cnt = 0;
	struct boolean boolean[5];
	int boolean_cnt = 0;
	struct dou dou[5];
	int double_cnt = 0;
}table_struct;

typedef struct database {
	table_struct n[100];
	int cnt=0;
	char name[10];
}database;

void show_database(int, database*);
void show_data(int, database*);

int main() {
	database data;
	int table_cnt = 0;
	printf("시작\n");
	int database_number = 0, table_number = 0;
	int i, j, k = 0;
	char n1[10] = { 0, };
	char n2[10] = { 0, };
	char n3[10] = { 0, };
	char n4[1][10] = { 0, };
	char n5[10] = { 0, };
	char comparison1[10][7] = { {"create"},{"alter"},{"drop"},{"select"},{"insert"},{"delete"},{"update"} };
	char comparison2_create[2][10] = { {"table"}, {"database"} };
	while (1) {
		scanf("%s", n1);
		for (i = 0; strcmp(n1, comparison1[i]) != 0; i++);
		if (i == 0) {
			scanf("%s", n2);
			for (j = 0; strcmp(n2, comparison2_create[j]) != 0; j++);
			scanf("%s", n3);
			strcpy(data.n[table_cnt].name, n3);
			if (j == 0) {
				printf("{\n");
				strcpy(n4[k], "\0");
				while (strcmp(n4[k], "};") != 0) {
					scanf("%s", n4[k]);
					if (strcmp(n4[k], "int") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[table_cnt].integer[data.n[table_cnt].integer_cnt].name, n5);
						data.n[table_cnt].integer_cnt++;
						data.n[table_cnt].cnt++;
					}
					if (strcmp(n4[k], "string") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[table_cnt].string[data.n[table_cnt].string_cnt].name, n5);
						data.n[table_cnt].string_cnt++;
						data.n[table_cnt].cnt++;
					}
					if (strcmp(n4[k], "double") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[table_cnt].dou[data.n[table_cnt].double_cnt].name, n5);
						data.n[table_cnt].double_cnt++;
						data.n[table_cnt].cnt++;
					}
					if (strcmp(n4[k], "bool") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[table_cnt].boolean[data.n[table_cnt].boolean_cnt].name, n5);
						data.n[table_cnt].boolean_cnt++;
						data.n[table_cnt].cnt++;
					}
				}
				table_cnt++;
				show_database(table_cnt, &data);
			}
			if (j == 1) {
				// database
			}
		}
		if (i == 1) {
			scanf("%s", n2);
			char table[30];
			scanf("%s", &table);
			for (j = 0; strcmp(table, data.n[j].name) != 0 && j < table_cnt; j++);
			if (j == 0) {
				printf("\n");
				int z;
				for (z = 0; z < data.n[z].cnt; z++) {
					if (data.n[z].integer_cnt > z) {
						printf("%s\n", data.n[z].integer[z].name);
					}
					if (data.n[z].string_cnt > z) {
						printf("%s\n", data.n[z].string[z].name);
					}
					if (data.n[z].double_cnt > z) {
						printf("%s\n", data.n[z].dou[z].name);
					}
					if (data.n[z].boolean_cnt > z) {
						printf("%s\n", data.n[z].boolean[z].name);
					}
				}
				printf("\n");
				printf("{\n");
				strcpy(n4[k], "\0");
				data.n[z].integer_cnt = 0;
				data.n[z].string_cnt = 0;
				data.n[z].double_cnt = 0;
				data.n[z].boolean_cnt = 0;
				data.n[z].cnt = 0;
				while (strcmp(n4[k], "};") != 0) {
					scanf("%s", n4[k]);
					if (strcmp(n4[k], "int") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[z].integer[data.n[z].integer_cnt].name, n5);
						data.n[z].integer_cnt++;
						data.n[z].cnt++;
					}
					if (strcmp(n4[k], "string") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[z].string[data.n[z].string_cnt].name, n5);
						data.n[z].string_cnt++;
						data.n[z].cnt++;
					}
					if (strcmp(n4[k], "double") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[z].dou[data.n[z].double_cnt].name, n5);
						data.n[z].double_cnt++;
						data.n[z].cnt++;
					}
					if (strcmp(n4[k], "bool") == 0) {
						printf(": ");
						scanf("%s", n5);
						strcpy(data.n[z].boolean[data.n[z].boolean_cnt].name, n5);
						data.n[z].boolean_cnt++;
						data.n[z].cnt++;
					}
				}
				show_database(table_cnt, &data);

			}
			if (j == 1) {
				// database
			}
		}
		if (i == 2) {
			scanf("%s", n2);
			show_database(table_cnt, &data);
			scanf("%s", n3);
			for (j = 0; strcmp(n3, data.n[j].name) != 0 && j < table_cnt; j++);
			for (; j < table_cnt; j++) {
				table_struct temp;
				temp = data.n[j];
				data.n[j] = data.n[j + 1];
				data.n[j + 1] = temp;
			}
			table_cnt--;
			show_database(table_cnt, &data);
		}
		if (i == 3) {
			// select
			printf("그만 입력하시려면 s이라고 입력하세요\n");
			char select[10][20] = { 0, };
			int l = 0;
			int p, j;
			for (p = 0; p < 10; p++) {
				scanf("%s", select[p]);
				if (strcmp(select[p], "s") == 0) {
					break;
				}
			}
			scanf(" %s", n2);
			if (strcmp(n2, "from") == 0) {
				scanf("%s", n3);
				for (j = 0; strcmp(n3, data.n[j].name) != 0 && j < table_cnt; j++);
				printf("where(y/n)");
				scanf(" %c", n4[k]);
				if (n4[k][0] == 'y') {

				}
				else {
					for (int u = 0; u < p; u++) {
						printf("------------");
					}
					printf("\n");
					for (int u = 0; u < p; u++) {
						printf("|%10s|", select[u]);
					}
					printf("\n");

					/*if (data.n[j].integer_cnt> 0) {
						for (int l = 0; l < data.n[j].integer_cnt; l++) {
							printf("%10s", data.n[j+l].integer[l].name);
						}
					}
					if (data.n[j].string_cnt > 0) {
						for (int l = 0; l < data.n[j].string_cnt; l++) {
							printf("%10s", data.n[j + l].string[l].name);
						}
					}
					if (data.n[j].double_cnt > 0) {
						for (int l = 0; l < data.n[j].double_cnt; l++) {
							printf("%10s", data.n[j + l].dou[l].name);
						}
					}
					if (data.n[j].boolean_cnt > 0) {
						for (int l = 0; l < data.n[j].boolean_cnt; l++) {
							printf("%10s", data.n[j + l].boolean[l].name);
						}
					}*/

					//for (int x = 0; x < data.n[j].integer_cnt|| x < data.n[j].string_cnt|| x < data.n[j].double_cnt|| x < data.n[j].boolean_cnt; x++) {
					//	// 값 출력
					//	if (data.n[j].integer[x].cnt > x) {
					//		for (int l = 0; l < data.n[j].integer[x].cnt; l++) {
					//			printf("%10s", data.n[j + l].integer[l].integer);
					//		}
					//	}
					//}
				}

				//미완성
			}

		}
		if (i == 4) {
			int z;
			int k = 0;
			scanf("%s", n2);
			if (strcmp(n2, "into") == 0) {
				scanf("%s", n3);
				for (j = 0; strcmp(n3, data.n[j].name) != 0 && j < table_cnt; j++);
				scanf("%s", n4[k]);
				if (strcmp(n4[k], "value") == 0) {
					int b[5];
					double c[5];
					bool d[5];
					char a[10][30] = { 0, };
					k = 0;
					for (z = 0;; z++) {
						if (data.n[j].integer_cnt - k > 0) {
							printf("int형: ");
							printf("%s\n", data.n[j].integer[j+k].name);
							k += 1;
						}
						else {
							break;
						}
					}
					for (z = 0; z < data.n[j].integer_cnt; z++) {
						scanf("%d", &b[z]);
					}
					k = 0;
					for (z = 0;; z++) {
						if (data.n[j].string_cnt - k > 0) {
							printf("string형: ");
							printf("%s\n", data.n[j].string[j + k].name);
							k += 1;
						}
						else {
							break;
						}
					}
					for (z = 0; z < data.n[j].string_cnt; z++) {
						scanf("%s", a[z]);
					}
					k = 0;
					for (z = 0;; z++) {
						if (data.n[j].double_cnt - k > 0) {
							printf("double형: ");
							printf("%s\n", data.n[j].dou[j + k].name);
							k += 1;
						} 
						else {
							break;
						}
					}
					for (z = 0; z < data.n[j].double_cnt; z++) {
						scanf("%lf", &c[z]);
					}
					k = 0;
					for (z = 0;; z++) {
						if (data.n[j].boolean_cnt - k > 0) {
							printf("boolean형: ");
							printf("%s\n", data.n[j].boolean[j + k].name);
							k += 1;
						}
						else {
							break;
						}
					}
					for (z = 0; z < data.n[j].boolean_cnt; z++) {
						scanf("%d", &d[z]);
					}
					printf("\n");
				}
			}
		}
	}
}

void show_database(int table_cnt, database* data){
	for (int i = 0; i < table_cnt; i++) {
		printf("--------------------\n");
		printf("|     %-12s |\n", data->n[i].name);
		printf("--------------------\n");
	}
	printf("\n");
}