#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int A[n][2];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &A[i][0], &A[i][1]);
	}
	int B[m][3];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d",&B[i][0], &B[i][1],&B[i][2]);
	}
	int num;
 	for (int j = 0; j < m; ++j)
	{
		num = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((abs(B[j][0] - A[i][0]) <= B[j][2]) && (abs(B[j][1] - A[i][1]) <= B[j][2]))
			{
				num++;
			}
		}
		printf("%d\n", num);
	}
}