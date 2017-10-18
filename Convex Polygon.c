#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	double x, y;
	int n;
}node;


int ifclockwise(node a, node b, node c){
	double temp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (temp > 0)
	{
		return -1;
	}
	else if (temp == 0)
	{
		return 0;
	}
	else return 1;
}

char* fnc(node a[], int n){
	int flag = 0;
	char result[] = "";
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			if (ifclockwise(a[n], a[i], a[i + 1]) == -1){
				strcat(result, a[i].n);
				strcat(result, " ");
				flag = 1;
				i++;
			}
		}
		else{
			if (ifclockwise(a[i - 1], a[i], a[i + 1]) == -1)
			{
				strcat(result, a[i].n);
				strcat(result, " ");
				flag = 1;
				i++;
			}
		}
	}
	if (flag == 0) return 'y';
	return result;
}

int main(){
	int n;
	char result[] = "";
	scanf("%d", &n);
	int *m = (int*)malloc(n * 4);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &m[i]);
		node * a = (node*)malloc(sizeof(node) * m[i]);
		for (int j = 0; j < m[i]; ++j)
		{
			scanf("%lf", &a[j].x);
			scanf("%lf", &a[j].y);
			a[j].n = j;
		}
		strcat(result, fnc(a, m[i]));
		strcat(result, "\n");
		free(a);
	}
	printf("%s", result);
	return 0;
}


