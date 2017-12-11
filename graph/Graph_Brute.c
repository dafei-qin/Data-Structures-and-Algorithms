#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int aa, bb;
typedef struct C
{
	short ch;
	struct C * next;
	struct C * end;
}charlist;
charlist B;

void find_road(int n, int a, int b, int abefore, short **A)
{
	for (int i = 0; i < n; ++i)
	{
		if (A[a][i] == 1 && i != b && i != abefore && i != aa)
		{
			A[a][i] = 0;
			find_road(n, i, b, a, A);
		}
		if (A[a][i] == 1 && i != b && i != abefore && i == aa)
			return;
		if (A[a][b] == 1) flag = 1;	
		if (flag == 1 && abefore != a)
		{
			B.end->ch = a; 
			B.end->next = (charlist *)malloc(sizeof(charlist)); 
			B.end->next->next = NULL; 
			B.end = B.end->next;
			break;
		}
		if (flag == 1 && abefore == a)
		{
			B.end->ch = a;
			break;
		}
	}
	if (flag == 0) 
		{
			printf("-1");
			flag = -1;
		}

}
void print(charlist * B)
{
	if (B->next) print(B->next);
	printf("%hd ", B->ch);
}
int main()
{
	B.next = NULL;
	B.end = &B;
	B.ch = 0;
	int n;
	scanf("%d", &n);
	short **A = (short **)malloc(sizeof(short *) * n);

	for (int i = 0; i < n; ++i)
	{
		A[i] = (short *)malloc(sizeof(short)* n );
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%hd", &A[i][j]);
		}
	}
	int temp = 0;
	scanf("%d%d", &aa, &bb);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp = 0;
			if (i == j) {printf("0 "); continue;}
			if (A[i][j] == 1) {printf("0 ");continue;}
			for (int k = 0; k < n; ++k)
			{
				if (A[i][k] + A[j][k] == 2)
				{
					temp ++;
				}
			}
			if (temp >= 3) printf("1 ");
			else printf("0 ");
		} 
		printf("\n");
	}
	find_road(n, aa, bb, aa, A);
	if (flag == 1){
	print(&B);
	printf("%d", bb);
	}
}
