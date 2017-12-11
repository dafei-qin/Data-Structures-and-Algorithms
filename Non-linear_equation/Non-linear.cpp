#include <cstdio>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

complex<long double> pow(complex<long double> &a, int &b, bool c)
{
	if (b == 0)
	{
		return 1;
	}
	else return pow(a, b);
}
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	long double A1[4][4], A2[4][4];
	complex<long double> x[2];
	x[0] = complex<double>(1, 1);
	x[0] = complex<double>(1, 1);
	complex<long double> dx[2] = {0, 0};
	complex<long double> fx[2] = {0, 0};
	complex<long double> fdx[2][2] = {0, 0, 0, 0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%Lf", &A1[i][j]);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%Lf", &A2[i][j]);
		}
	}
	complex<long double> j11[3][4], j12[4][3], j21[3][4], j22[4][3];
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			j11[i - 1][j] = A1[i][j] * i;
			j21[i - 1][j] = A2[i][j] * i;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			j12[i][j - 1] = A1[i][j] * j;
			j22[i][j - 1] = A2[i][j] * j;
		}
	}
	for (int m = 0; m < 10000; m++)
	{
		for (int k = 0; k < 1000; k++)
		{
			fdx[0][0] = 0;
			fdx[0][1] = 0;
			fdx[1][0] = 0;
			fdx[1][1] = 0;
			fx[0] = 0;
			fx[1] = 0;
			dx[0] = 0;
			dx[1] = 0;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 4; ++j)
					{
						fdx[0][0] += j11[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
						fdx[1][0] += j21[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
					}	
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 3; ++j)
					{
						fdx[0][1] +=  j12[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
						fdx[1][1] +=  j22[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
					}	
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					fx[0] += A1[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					fx[1] += A2[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
				}
			}
			fx[0] = -fx[0];
			fx[1] = -fx[1];
		
			complex<long double> sub = fdx[1][0] / fdx[0][0];
			fdx[1][1] = fdx[1][1] - fdx[0][1] * sub;
			fx[1] = fx[1] - fx[0] * sub;
			dx[1] = fx[1] / fdx[1][1];
			sub = fdx[0][1] * dx[1];
			dx[0] = (fx[0] - sub) / fdx[0][0];
			x[0] += dx[0];
		 	x[1] += dx[1];
		}
		for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					fx[0] += A1[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					fx[1] += A2[i][j] * pow(x[0], i, 1) * pow(x[1], j, 1);
				}
			}
		if (abs(fx[0]) < 1e-6 && abs(fx[1]) < 1e-6) break;
		else
		{
			x[0] = complex<long double>((rand() / double(RAND_MAX) * 100000 - 50000), (rand() / double(RAND_MAX) * 100000 - 50000));
			x[1] = complex<long double>((rand() / double(RAND_MAX) * 100000 - 50000), (rand() / double(RAND_MAX) * 100000 - 50000));

		}
	}
	printf("%.18Lf %.18Lf\n%.18Lf %.18Lf", x[0].real(), x[0].imag(), x[1].real(), x[1].imag());
		printf("\n");
	return 0;
}