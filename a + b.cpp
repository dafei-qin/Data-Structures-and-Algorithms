#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	long int len1, len2;
	len1 = a.length();
	len2 = b.length();
	int *x = new int[len1 + 1];
	int *y = new int[len2 + 1];
	cout << endl;
	x[0] = y[0] = 0;
	for (int i = 0; i < len1; ++i)
	{
		x[len1 - 1 - i] = a[i] - '0';
	}
	for (int i = 0; i < len2; ++i)
	{
		y[len2 - 1 - i] = b[i] - '0';
	}
	if (len1 > len2)
	{	
		for (int i = 0; i < len2 ; ++i)
		{
			x[i] = x[i] + y[i];
			if (x[i] > 9)
			{
				x[i] = x[i] - 10;
				x[i + 1] ++;
			}
		}
		if (x[len1] == 0)
		{
			for (int i = len1 - 1; i >= 0; --i)
			{
				cout << x[i];
			}
		}
		else{
			for (int i = len1; i >= 0; --i)
			{
				cout << x[i];
			}
		}
	}
	else{
		for (int i = 0; i < len1 ; ++i)
		{
			y[i] = x[i] + y[i];
			if (y[i] > 9)
			{
				y[i] = y[i] - 10;
				y[i + 1] ++;
			}
		}
		if (y[len2] == 0)
		{
			for (int i = len2 - 1; i >= 0; --i)
			{
				cout << y[i];
			}
		}
		else{
			for (int i = len2; i >= 0; --i)
			{
				cout << y[i];
			}
		}
	}
	return 0;
}