#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

void Push(int Data);
int Pop();
int *pStack = NULL;

int main(){
	pStack = (int*)malloc((sizeof(int)) * STACK_SIZE);
	for (int i = 0; i < STACK_SIZE; i++){
		pStack[i] = NULL;
	}
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	for (int i = 0; i < STACK_SIZE; i++){
		printf("%d\n", Pop());
	}
	return 0;
}

void Push(int Data){
	int Count = 0;
	for (int i = 0; i < STACK_SIZE; i++){
		if (pStack[i] == NULL)
		{
		 break;
		}
		Count++;
	}

	if (Count != STACK_SIZE){
		pStack[Count] = Data;
	}
}
int Pop(){
	int Count = STACK_SIZE-1;
	int Result = 0;
	for (int i = STACK_SIZE-1; i >0; i--){
		if (pStack[i] != NULL)
		{
			break;
		}
		Count--;
	}
	if (Count != -1){
		Result = pStack[Count];
		pStack[Count] = NULL;
	}
	return Result;
}