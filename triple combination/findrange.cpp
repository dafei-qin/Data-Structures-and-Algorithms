#include <iostream>
#include <stdio.h>
#include <algorithm>
int main()
{
    int n, a, b;
    long long int result = 0;
    scanf("%d%d%d", &n, &a, &b);
    int *A = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", A + i);
    }
    std::sort(A, A + n);
    for (int i = 0; i < n; ++i)
    {
        if(A[i] > b) break;
        int *p1 = &A[n - 1];
        int *p2 = &A[n - 1];
        for (int j = i + 1; j < n - 1; ++j)
        {
        	if(A[i] + A[j] > b) break;
        	//if(A[j] >= *p1) break;
            while(A[i] + A[j] + *(p1 - 1) >= a &&p1 != &A[0] && p1 > &A[j])
            {
                p1--;
            }
            while (p1 <= &A[j]) p1 ++;
            if(A[i] + A[j] + *p1 > b) break;

            while(A[i] + A[j] + *p2 > b && p2 != &A[0] && p2 > &A[j])
            {
                p2--;
            }
            while (p2 <= &A[j]) p2 ++;
            if (A[i] + A[j] + *p1 >= a && A[i] + A[j] + *p2 <= b)
           		 result+= p2 - p1 + 1;
        }
    }
    printf("%lld", result);
}