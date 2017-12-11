#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>

int N, M;
typedef struct D
{
	int x;
	int y;
}data;
typedef struct E
{
	int y;
	//E* lefty;
	//E* righty;
}ylist;

class Node
{
public:
	int x;
	Node* left, *right;
	ylist* py;
	int pylength;
};

class BST
{
private:
	Node *root;
public:
	BST()
	{
		root = NULL;
	}
	BST(data *L, int n)
	{
		root = init(L, n, 0);
	}
	Node* init(data *L, int n, int k)
	{

		Node *a = (Node *)malloc(sizeof(Node));
		a->left = NULL;
		a->right = NULL;
		int temp = (int)pow(2, ceil(log2(n)) - 1);
		//printf("N%d", n);
		//printf("K%d\n", k);
		a->x = L[k + temp - 1].x;
		printf("X%d", a->x);
		if (n == 1)	
		{
			a->x = L[k].x;
			a->py = (ylist*)malloc(sizeof(ylist));
			a->py[0].y = L[k].y;
			printf("Y%d\n", a->py->y);
			a->pylength = 1;
			return a;
		}
		else
		{

			a->left = init(L, temp, k);
			if (k + temp < N)
				a->right = init(L, temp, k + temp);
			if (a->right)
			{
				a->py = (ylist*)malloc(sizeof(ylist)*(a->left->pylength + a->right->pylength));
				int temp1, temp2;
				temp1 = temp2 = 0;
				while(temp1 < a->left->pylength && temp2 < a->right->pylength)
				{
					if (a->left->py[temp1].y < a->right->py[temp2].y)
						{ a->py[temp1 + temp2].y = a->left->py[temp1].y; temp1++;}
					else
						{ a->py[temp1 + temp2].y = a->right->py[temp2].y; temp2++;}
				}
				while (temp1 < a->left->pylength)
				{ 	a->py[temp1 + temp2].y = a->left->py[temp1].y; temp1++;}
				while (temp2 < a->right->pylength)
				{	a->py[temp1 + temp2].y = a->right->py[temp2].y; temp2++;}
				a->pylength = a->left->pylength + a->right->pylength;
			}
			else 
			{
				a->py = a->left->py;
				a->pylength = a->left->pylength;
			}
			/*
			for (int i = 0; i < a->pylength; ++i)
			{
				temp1 = temp2 = 0;
				while (temp1 < a->left->pylength)
				{
					if (a->py[i].y >= a->left->py[temp1].y)
					{	a->py[i].lefty = &(a->left->py[temp1]); break;}
					else temp1++;
				}
				while (temp2 < a->right->pylength)
				{
					if (a->py[i].y >= a->right->py[temp2].y)
					{	a->py[i].righty = &(a->right->py[temp2]); break;}
					else temp2++;
				}
				if (temp1 == a->left->pylength)
					a->py[i].lefty = NULL;
				if (temp2 == a->right->pylength)
					a->py[i].righty = NULL;
			}
			*/
		}
		return a;
	}

	int searchy(ylist *L,int ylength, int yl, int yh)
	{
		int a = 0;
		int b = ylength - 1;
		int c2 = ylength / 2;
		int c1 = ylength / 2;
		while (a <= b)
		{
			if (yl <= L[c1].y)
				b = c1 - 1;
			else
				a = c1 + 1;
			c1 = (a + b + 1) /2;
		}
		a = 0;
		b = ylength - 1;
		while (a <= b)
		{
			if (yh < L[c2].y)
				b = c2 - 1;
			else
				a = c2 + 1;
			c2 = (a + b + 1) / 2;
		}
		return c2 - c1;
	}
	
	int searchx(int xl, int xh, int yl, int  yh)
	{
		Node *a = root;
		int result = 0;
		Node *split = NULL;
		ylist *set = NULL;
		while (a)
		{
			if (a->x >= xl && a->x <= xh)
			{
				split = a;
				break;
			}
			else if (a->x < xl && a->right)
			{
				a = a->right;
			}
			else if (a->x < xl && a->right == NULL)
				return result;
			else if (a->x > xh && a->left)
			{
				a = a->left;
			}
			else if (a->x > xh && a->left == NULL)
				return result;
		}
		
		if (!split->left)
		{
			a = split;
			if ((a->py->y >= yl) && (a->py->y <= yh))
				result++;
			return result;
		}
		a = split->left;
		while (a)
		{
			if (a->x >= xl && a->right)
			{
				set = a->right->py;
				//printf("%d", set->y);
				//printf("%d", result);
				//printf("%d%d%d", a->right->pylength, yl, yh);
				result += searchy(set, a->right->pylength, yl, yh);
				//printf("%d", result);
				a = a->left;
			}
			else if (a->x >= xl && a->left == NULL)
			{
				if ((a->py->y >= yl) && (a->py->y <= yh))
					{result++; a = NULL;}
				else a = NULL;
			}
			else
				a = a->right;
		}
		//printf("%d", result);
		a = split->right;
		while (a)
		{
			if (a->x <= xh && a->left)
			{
				set = a->left->py;
				result += searchy(set, a->left->pylength, yl, yh);
				a = a->right;
			}
			else if (a->x <= xh && a->right == NULL)
			{
				if ((a->py->y >= yl) && (a->py->y <= yh))
					{result++; a = NULL;}
				else a = NULL;
			}
			else
				a = a->left;
		}
		return result;
	}
	
};
bool compare(data a, data b)
{
	return (a.x < b.x); 
}
int main()
{

	scanf("%d%d", &N, &M);
	if (N && M)
		{
		data* A = (data *)malloc(N * sizeof(data));
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d", &A[i].x, &A[i].y);
		}
		std::sort(A, A+N, compare);
		BST a = BST(A, N);
		free(A);
		int B[M][3];
		for (int i = 0; i < M; ++i)
		{
			scanf("%d%d%d",&B[i][0], &B[i][1],&B[i][2]);
		}
		int xl = 0;
		int xh = 0;
		int yl = 0;
		int yh = 0;
		for (int i = 0; i < M; ++i)
		{
			if (B[i][0] - B[i][2] > 0)
				xl = B[i][0] - B[i][2];
			else xl = 0;
			xh = B[i][0] + B[i][2];
			if (B[i][1] - B[i][2] > 0)
				yl = B[i][1] - B[i][2];
			else yl = 0;
			yh = B[i][1] + B[i][2];
			printf("%d\n", a.searchx(xl, xh, yl, yh));
		}
	}
	return 0;
}