#include <stdio.h>
#include <stdlib.h>
int EXP2(int x)
{
	int s = 1;
	for (int i = 0; i < x; ++i)
	{
		s *= 2;
	}
	return s;
}
void Haar(float *f, int i, int l)
{
	float *g = (float*)malloc(EXP2(l)*sizeof(float));
	for (int j = 0; j < EXP2(i - 1); ++j)
	{
		g[j] = (f[2*j] + f[2*j + 1]) / 2;
	}
	for (int j = 0; j < EXP2(i - 1); ++j)
	{
		g[EXP2(i - 1) + j] = -(f[2*j] - f[2*j + 1]) /2;
	}
	for (int  j = EXP2(i); j < EXP2(l); ++j)
	{
		g[j] = f[j];
	}
	free (f);
	if (i - 1) Haar(g, i - 1, l);
	else
		for (int j = 0; j < EXP2(l); ++j)
		{
			printf("%.4f ", g[j]);
		}

}

int main()
{
	int l;
	scanf("%d", &l);
	float *f = (float *)malloc(EXP2(l)*sizeof(float));
	for (int j = 0; j < EXP2(l); ++j)
	{
		scanf("%f", f + j);
	}
	Haar(f, l, l);
	return 0;
}