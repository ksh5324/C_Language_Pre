#include<stdio.h>
#include<math.h>
int main()
{
    int arr[20][20] = {};
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i][0]);
    }
    for (int i = 1; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if (i < j) { break; } arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++)
        {
            if (i < j) { break; } printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}