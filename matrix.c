#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
	int i, j, v;
	struct a *right, *down;
}node;

typedef struct b
{
	int m, n, l;
	node **row, **col;
}matrix;

void init(matrix *a)
{
	node *temp;
	node *pr, *pc;
	int i, j, v;
	scanf("%d", &a->m);
	scanf("%d", &a->n);
	scanf("%d", &a->l);
	a->row = (node**)malloc(a->m * sizeof(node*));
	a->col = (node**)malloc(a->n * sizeof(node*));
	for (int i = 0; i < a->m; ++i)
	{
		a->row[i] = NULL;
	}
	for (int i = 0; i < a->n; ++i)
	{
		a->col[i] = NULL;
	}
	for (int z = 0; z < a->l; ++z)
	{
		temp = (node*)malloc(sizeof(node));
		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &v);
		if (v == 0) continue;
			temp->i = i;
			temp->j = j;
			temp->v = v;
			pr = a->row[i];
			pc = a->col[j];
			if (a->row[i] == NULL || a->row[i]->j > j)
			{
				temp->right = a->row[i];
				a->row[i] = temp;
			}
			else 
			{
				while(pr->right && pr->right->j < j)
					pr = pr->right;
				temp->right = pr->right;
				pr->right = temp;
			}
			if (a->col[j] == NULL || a->col[j]->i > i)
			{
				temp->down = a->col[j];
				a->col[j] = temp;
			}
			else
			{
				while(pc->down && pc->down->i < i)
					pc = pc->down;
				temp->down = pc->down;
				pc->down = temp;
			}
	}		
}

void print(matrix *a)
{
	node *p;
	for (int i = 0; i < a->m; ++i)
	{
		p = a->row[i];
		while (p)
		{
			printf("%d %d %d\n", p->i, p->j,  p->v);
			p = p->right;
		}
	}
}

void printT(matrix *a)
{
	node *p;
	for (int i = 0; i < a->n; ++i)
	{
		p = a->col[i];
		while (p)
		{
			printf("%d %d %d\n", p->j, p->i,  p->v);
			p = p->down;
		}
	}
}

void plusT(matrix *a)
{
	node *p1;
	node *p2;
	int r_end, c_end;
	for (int i = 0; i < a->m; ++i)
	{
		r_end = 0;
		c_end = 0;
		p1 = a->row[i];
		p2 = a->col[i];
		if (p1 == NULL && p2 == NULL) continue;
		if (p1 == NULL)
			{
				while (p2)
				{
					printf("%d %d %d\n", p2->j, p2->i, p2->v);
					p2 = p2->down;
				}
				continue;
			}
		if (p2 == NULL)
		{
			while (p1)
			{
				printf("%d %d %d\n", p1->i, p1->j, p1->v);
				p1 = p1->right;
			}
			continue;
		}
		while (!(c_end == 1 && r_end == 1))
		{
			if (p1->j == p2->i)
			{
				if (p1->v + p2->v)
					printf("%d %d %d\n", p1->i, p1->j, p1->v + p2->v);
				if (p1->right)
					p1 = p1->right;
				else 
					r_end = 1;
				if (p2->down)
					p2 = p2->down;
				else 
					c_end = 1;
			}
			else if (p1->j > p2->i && c_end != 1)
			{
				printf("%d %d %d\n", p2->j, p2->i, p2->v);
				if (p2->down)
					p2 = p2->down;
				else 
					c_end = 1;	
			}
			else if (p1->j > p2->i && c_end == 1)
			{
				printf("%d %d %d\n", p1->i, p1->j, p1->v);
				if (p1->right)
					p1 = p1->right;
				else
					r_end = 1;
			}
			else if (p1->j < p2->i && r_end != 1)
			{
				printf("%d %d %d\n", p1->i, p1->j, p1->v);
				if (p1->right)
					p1 = p1->right;
				else 
					r_end = 1;	
			}
			else if (p1->j < p2->i && r_end == 1)
			{
				printf("%d %d %d\n", p2->j, p2->i, p2->v);
				if (p2->down)
					p2 = p2->down;
				else
					c_end = 1;
			}
		}
	}
}

void mutiplyT(matrix *a)
{
	node *p1, *p2;
	int r1_end, r2_end;
	int s;
	for (int i = 0; i < a->m; ++i)
	{
		if (a->row[i] == NULL) continue;
		for (int j = 0; j < a->n; ++j)
		{
			if (a->row[j] == NULL) continue;
			p1 = a->row[i];
			p2 = a->row[j];
			r1_end = 0;
			r2_end = 0;
			s = 0;
			while (r1_end == 0 && r2_end == 0)
			{
				if (p1->j == p2->j)
				{
					s += p1->v * p2->v;
					if (p1->right)
						p1 = p1->right;
					else
						r1_end = 1;
					if (p2->right)
						p2 = p2->right;
					else
						r2_end = 1;
				}
				else if (p1->j > p2->j)
				{
					if (p2->right)
						p2 = p2->right;
					else
						r2_end = 1;
				}
				else if (p1 ->j < p2->j)
				{
					if (p1->right)
						p1 = p1->right;
					else
						r1_end = 1;
				}
			}
			if (s)
				printf("%d %d %d\n", i, j, s);
		}
	}
} 
int main()
{
	matrix A;
	init(&A);
	printT(&A);
	plusT(&A);
	mutiplyT(&A);
	return 0;
}