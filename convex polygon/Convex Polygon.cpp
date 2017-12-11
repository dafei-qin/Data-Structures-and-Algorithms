#include <iostream>
#include <string>
using namespace std;

int ifclockwise(float a[3], float b[3], float c[3]){
	double temp = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
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

int main()
{
	int n;
	cin >> n;
	int * m = new int[n];
	string * s = new string[n];
	for (int i = 0; i < n; ++i)
	{
		s[i] = "";
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
		float (*a)[3] = new float[m[i]][3];
		bool flag = 0;
		for (int j = 0; j < m[i]; ++j)
		{
			cin >> a[j][0] >> a[j][1];
			a[j][2] = j;
		}
		for (int j = 0; j < m[i]; ++j)
		{
			if (j == 0)
			{
				if(ifclockwise(a[m[i] - 1], a[j], a[ j+ 1]) == -1){
					int temp = a[j][2];
					s[i] += to_string(temp);
					s[i] += " "; 
					flag = 1;
				}
			}
			else {
				if (ifclockwise(a[j - 1], a[j], a[j + 1]) == -1)
				{
					int temp = a[j][2];
					s[i] += to_string(temp);
					s[i] += " ";
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			s[i] = "y";
		}
		delete[]a;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}
	return 0;
}


