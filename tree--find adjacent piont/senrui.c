#include <stdio.h>
#include <stdlib.h>

typedef struct A
{
	int x;
	int y;
	struct A* next;
}data;
typedef struct B
{
	//int x;
	//int y;
	int num;
	data *p;
	int fsum;
	//data *pend;
}block;

block a[1001][1001];
block asp;

void init(int n){
	
	data *tempp;
	int tempx, tempy;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &tempx, &tempy);
		if (tempx == 1000000 || tempy == 1000000)
		{
			if (a[1000][1000].num == 0)
			{
				a[1000][1000].p = (data*)malloc(sizeof(data));
				a[1000][1000].p->x = tempx;
				a[1000][1000].p->y = tempy;
				a[1000][1000].p->next = NULL;
				a[1000][1000].num++;
				continue;
			}
			else 
			{
				tempp = a[1000][1000].p;
				while (tempp ->next)
					tempp = tempp->next;
				tempp->next = (data*)malloc(sizeof(data));
				tempp->next->x = tempx;
				tempp->next->y = tempy;
				tempp->next->next = NULL;
				a[1000][1000].num++;
				continue;
			}
		}
		if (a[tempx/1000][tempy/1000].num == 0)
		{
			a[tempx/1000][tempy/1000].p = (data*)malloc(sizeof(data));
			a[tempx/1000][tempy/1000].p->x = tempx;
			a[tempx/1000][tempy/1000].p->y = tempy;
			a[tempx/1000][tempy/1000].p->next = NULL;
			//a[tempx/1000][tempy/1000].pend = a[tempx/1000][tempy/1000].p;
		}
		else
		{
			tempp = a[tempx/1000][tempy/1000].p;
			while (tempp ->next)
				tempp = tempp->next;
			tempp->next = (data*)malloc(sizeof(data));
			tempp->next->x = tempx;
			tempp->next->y = tempy;
			tempp->next->next = NULL;
			//a[tempx/1000][tempy/1000].pend = tempp->next;
		}
		a[tempx/1000][tempy/1000].num++;
	}
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			if (j == 0)
			{
				a[j][i].fsum = a[j][i].num;
			}
			else
			{
				a[j][i].fsum = a[j - 1][i].fsum + a[j][i].num;
			}
		}
	}
}
int search(int xl, int xh, int yl, int yh)
{
	int result = 0;
	int xlb = xl / 1000 + 1;
	int xhb = xh / 1000 - 1;
	int ylb = yl / 1000 + 1;
	int yhb = yh / 1000 - 1;
	data *pp;
	//printf("0\n");
	if (xhb >= xlb)
	{
		for (int i = ylb; i <= yhb; ++i)
		{
			//printf("%d %d %d %d", xlb, xhb, ylb, yhb);
			//printf("1\n");
			result += a[xhb][i].fsum - a[xlb][i].fsum + a[xlb][i].num;
		}
	}
	for (int i = ylb; i <= yhb; ++i)
	{
		//printf("2\n");
		pp = a[xlb - 1][i].p;
		for (int j = 0; j < a[xlb - 1][i].num; ++j)
		{
			if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			pp = pp->next;
		}
	}
	if((xlb - 1) != (xhb + 1))
	{
		for (int i = ylb; i <= yhb; ++i)
		{
			//printf("3\n");
			pp = a[xhb + 1][i].p;
			for (int j = 0; j < a[xhb + 1][i].num; ++j)
			{
				if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
				{
					result++;
				}
				pp = pp->next;
			}
		}
	}
	for (int i = xlb; i <= xhb; ++i)
	{
		//printf("4\n");
		pp = a[i][ylb - 1].p;
		for (int j = 0; j < a[i][ylb - 1].num; ++j)
		{
			if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			pp = pp->next;
		}
	}		
	if ((ylb - 1) != (yhb + 1))
	{
		for (int i = xlb; i <= xhb; ++i)
		{
			//printf("5\n");
			pp = a[i][yhb + 1].p;
			for (int j = 0; j < a[i][yhb + 1].num; ++j)
			{
				if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
				{
					result++;
				}
				pp = pp->next;
			}
		}
	}
	pp = a[xlb - 1][ylb - 1].p;
	for (int i = 0; i < a[xlb - 1][ylb - 1].num; ++i)
	{
		//printf("6\n");
		if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
		{
			//printf("%d  %d", pp->x, pp->y);
			result++;
		}
		pp = pp->next;
	}
	if ((xlb - 1) != (xhb + 1))
	{ 
		//printf("7\n");
		pp = a[xhb + 1][ylb - 1].p;
		for (int i = 0; i < a[xhb + 1][ylb - 1].num; ++i)
		{
			if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			pp = pp->next;
		}
	}
	if ((ylb - 1) != (yhb + 1))
	{
		//printf("8\n");
		pp = a[xlb - 1][yhb + 1].p;
		for (int i = 0; i < a[xlb - 1][yhb + 1].num; ++i)
		{
			if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			pp = pp->next;
		}
	}
	if ((xlb - 1) != (xhb + 1) && (ylb - 1) != (yhb + 1))
	{
		//printf("9\n");
		pp = a[xhb + 1][yhb + 1].p;
		for (int i = 0; i < a[xhb + 1][yhb + 1].num; ++i)
		{
			if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			pp = pp->next;
		}
	}
	pp = a[1000][1000].p;
	//printf("%d", a[1000][1000].num);
	
	for (int i = 0; i < a[1000][1000].num; ++i)
	{
		//printf("%d%d", pp->x, pp->y);

		if (pp->x >= xl && pp->y >= yl && pp->x <= xh && pp->y <= yh)
			{
				result++;
			}
			if (pp->x == 1000000 && pp->y == 1000000)
				result--;
		pp = pp->next;
	}
	
	return result;
}

int main()
{
	
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			//a[i][j].x = i;
			//a[i][j].y = j;
			a[i][j].num = 0;
			a[i][j].p = NULL;
			a[i][j].fsum = 0;
			//a[i][j].pend = NULL;
		}
	}
	asp.num = 0;
	asp.p = NULL;
	asp.fsum = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	//printf("-3");
	int b[m][3];
	for (int i = 0; i < m; ++i)
	{
		//printf("-4");
		scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
		//printf("-5\n");
	}
	
	int xl = 0;
	int xh = 0;
	int yl = 0;
	int yh = 0;
	//printf("-2\n");
	
	for (int i = 0; i < m; ++i)
	{
		if (b[i][0] - b[i][2] > 0)
			xl = b[i][0] - b[i][2];
		else xl = 0;
		if (b[i][0] + b[i][2] < 1000000)
			xh = b[i][0] + b[i][2];
		else xh = 1000000;
		if (b[i][1] - b[i][2] > 0)
			yl = b[i][1] - b[i][2];
		else yl = 0;
		if (b[i][1] + b[i][2] < 1000000)
			yh = b[i][1] + b[i][2];
		else yh = 1000000;
		//printf("-1\n");
		printf("%d\n", search(xl, xh, yl, yh));
	}
	
	return 0;
}