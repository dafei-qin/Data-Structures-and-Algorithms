#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef struct a
{
    int i, j;
    double c;

}node;

bool compare(node a, node b)
{
    if (a.i != b.i) return a.i < b.i;
    else return a.j < b.j;
}
void SWAP(double &a, double &b)
{
	double temp = b;
	b = a;
	a = temp;
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < 1020)
    {

        double M[1020][1020];
        double b[n];
        int s[n];
        double x[n];
        memset(M, 0, sizeof(M));
        int tempi, tempj;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &tempi, &tempj);
            scanf("%lf", &M[tempi][tempj]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf", &b[i]);
            x[i] = 0;
            s[i] = i;
        }
        double sub = 0;
        for (int i = 0; i < n; ++i)
        {
            if(M[i][i] == 0)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (M[j][i] != 0 && M[i][j] != 0)
                    {
                       	for (int k = 0; k < n; ++k)
                       	{
                       		int tempp = s[i];
                       		s[i] = s[j];
                       		s[j] = tempp;
                       		SWAP(M[i][k], M[j][k]);
                       	}
                       	SWAP(b[i], b[j]);
                        break;
                    }
                }
            }
        }
        for (int k = 0; k < n - 1; ++k)
        {
        	int tempnum = k;
            double temp = 0;

            for (int o = k; o < n; ++o)
            {
                if (fabs(M[o][k]) > temp)
                {
                    temp = fabs(M[o][k]);
                    tempnum = o;
                }
            }
            for (int o = 0; o < n; ++o)
            {
            	int tempp = s[k];
            	s[k] = s[tempnum];
            	s[tempnum] = tempp;
            	SWAP(M[k][o], M[tempnum][o]);
            }
            SWAP(b[k], b[tempnum]);

            for (int i = k + 1; i < n; ++i)
            {
                
                sub = M[i][k] / M[k][k];
                b[i] = b[i] - b[k] * sub;
                for (int j = k; j < n; ++j)
                {
                    M[i][j] = M[i][j] - sub * M[k][j];
                }
            }

        }
        x[n - 1] = b[n - 1] / M[n - 1][n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            sub = 0;
            for (int j = i + 1; j < n; ++j)
            {
                sub += M[i][j] * x[j];
            }
            x[i] = (b[i] - sub) / M[i][i];
        }
        for (int i = 0; i < n; ++i)
        {
            printf("%.10lf\n", x[i]);
        }

    }
    else
    {
        node *matrix = (node*)malloc(m * sizeof(node));
        double a = 0;
        int *s = (int *)malloc(n * sizeof(int));
        double *b= (double *)malloc(n * sizeof(double));
        double *angle = (double *)malloc(n * sizeof(double));
        double *x = (double *)malloc(n * sizeof(double));
        double *xx = (double *)malloc(n * sizeof(double));
        for (int i = 0; i < n; ++i)
        {
            i = i;
            b[i] = 0;
            x[i] = 0;
            xx[i] = 0;
        }
        
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%lf", &matrix[i].i, &matrix[i].j, &matrix[i].c);
            if (matrix[i].i == matrix[i].j) angle[matrix[i].i] = matrix[i].c;
        }
        sort(matrix, matrix+m, compare);

        for (int i = 0; i < n; ++i)
        {
            scanf("%lf", &b[i]);
        }
        /*
        for (int i = 0; i < n; ++i) //列选主元
        {
            temp1.i = i;
            temp1.j = i;
            if (matrix.find(temp1) == matrix.end())
            {
                for (int j = 0; j < n; ++j)
                {
                    temp2.i = j;
                    temp2.j = i;
                    if (matrix.find(temp2) != matrix.end() && matrix.find(temp1) != matrix.end())
                    {
                        i = j;
                        j = i;
                        break;
                    }
                }
            }
        }
        */
        int Max = 10000;
        double res = 0;
        double *sum = (double*)malloc(n * sizeof(double));
        double dis = 0.0;
        double dif = 1.0;  //相邻迭代的结果差
        double eps = 1.0e-10;
        for (int i = 0; i < n; ++i)
        {
            sum[i] = 0;
        }

        for (int k = 1;  (k < Max) && (dif > eps); ++k)
        {
            dif = 0;
            
            for (int i = 0; i < m; ++i)
            {
                if (matrix[i].j < matrix[i].i)
                    sum[matrix[i].i] += matrix[i].c * x[matrix[i].j];
                if (matrix[i].j > matrix[i].i)
                    sum[matrix[i].i] += matrix[i].c * xx[matrix[i].j];
            }
            for (int i = 0; i < n; ++i)
            {
                x[i] = (b[i] - sum[i]) / angle[i];
                sum[i] = 0;
            }
            
            res = 0;
            for (int i = 0; i < n; ++i)
            {
                dis = fabs(x[i] - xx[i]);
                if (dis > res) res = dis;
            }
            dif = res;

            for (int i = 0; i < n; ++i)
            {
                xx[i] = x[i];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            printf("%.10f\n", xx[i]);
        }

    }
    return 0;
}