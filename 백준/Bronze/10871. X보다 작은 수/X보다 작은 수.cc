#include <stdio.h>

int main()
{
    int n, x,m;
    int arr[10000];

    scanf("%d %d", &n, &x);

    for (m = 0; m < n; m++)
    {
        scanf("%d", &arr[m]);
        if (arr[m]<x )
            printf("%d ", arr[m]);
    }

    return 0;
}
