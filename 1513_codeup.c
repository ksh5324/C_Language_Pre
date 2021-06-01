#include<stdio.h>
#include<math.h>
int main()
{
	int arr[100][100] = {};
	int num1;
	scanf("%d", &num1);
	int va = 0;
	int sum = 0;
	for (int y=0; y < num1; y++) {
		for (int x=0; x < num1; x++) {
			arr[y][x] = ++va;
		}
	}
	for(int i = 0; i<num1; i++)
	{
		for(int j = 0; j<num1; j++)
		{
			if(i == 0 || i == num1-1 || j == 0 || j == num1-1)
			{
				sum += arr[i][j];
			}
		}
	}
	
	printf("%d",sum);
	
	return 0;
}