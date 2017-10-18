#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int m, n, l;
	cin >>m >> n >>l;
	int a[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = 0;
		}
	}
	int ti, tj, tv;
	for (int i = 0; i < l; ++i)
	{
			cin >>ti>>tj>>tv;
			a[ti][tj] = tv;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[j][i])
			{
				cout << i  << ' ' << j << ' ' << a[j][i] << endl;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j && a[i][j])
			{
				cout << i  << ' ' << j << ' ' << 2 *a[j][i] << endl;
			}
			else 
			{
				if(a[i][j] + a[j][i])
					cout << i << ' '<< j << ' '<< a[i][j] + a[j][i] << endl;;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int s = 0;
			for (int k = 0; k < m; ++k)
			{
				s += a[i][k] * a[j][k];
			}
			if (s)
				cout << i << ' '<< j << ' ' << s << endl;
		}
	}
	cout << endl;
	return 0;
}