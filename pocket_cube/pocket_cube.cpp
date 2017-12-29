#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
//#include <utility>
using namespace std;
class cube;
class status;
typedef unsigned long long int type;
typedef map<cube, status> my_map;
typedef pair<cube, status> my_pair;
typedef map<cube, status>::iterator it;
typedef queue<pair<cube, status>> my_queue;
string int_operate(const int operate_type, bool if_inverse)
{
	if (if_inverse == 0)
	{
		switch(operate_type)
			{
				case 0:{return "F+"; break;}
				case 1:{return "F2"; break;} 
				case 2:{return "F-"; break;} 
				case 3:{return "R+"; break;} 
				case 4:{return "R2"; break;} 
				case 5:{return "R-"; break;} 
				case 6:{return "U+"; break;} 
				case 7:{return "U2"; break;} 
				case 8:{return "U-"; break;} 
			}
	}
	else if (if_inverse == 1)
	{
		switch(operate_type)
			{
				case 0:{return "F-"; break;}
				case 1:{return "F2"; break;} 
				case 2:{return "F+"; break;} 
				case 3:{return "R-"; break;} 
				case 4:{return "R2"; break;} 
				case 5:{return "R+"; break;} 
				case 6:{return "U-"; break;} 
				case 7:{return "U2"; break;} 
				case 8:{return "U+"; break;} 
			}
	}
	cout << "operate_type err !" << endl;
	exit(-1);
}
int int_int(const int operate_type, bool if_inverse)
{
	if (if_inverse == 0)
	{
		return operate_type;
	}
	else if (if_inverse == 1)
	{
		switch(operate_type)
			{
				case 0:{return 2; break;}
				case 1:{return 1; break;} 
				case 2:{return 0; break;} 
				case 3:{return 5; break;} 
				case 4:{return 4; break;} 
				case 5:{return 3; break;} 
				case 6:{return 8; break;} 
				case 7:{return 7; break;} 
				case 8:{return 6; break;} 
			}
	}
	cout << "operate_type err !" << endl;
	exit(-1);
}
class cube
{
public:
	type a;
	//static bool *is_expanded;
	cube()
	{
		int temp = 0;
		a = 0;
		//*is_expanded = 0;
		for (int i = 0; i < 24; ++i)
		{
			cin >> temp;
			if (temp < 0 || temp > 5) 
			{
				cerr << "Data Error!";
				exit(-1);
			}
			a += (type)temp * (type)pow(6, i);
		}
	}
	cube(int * color_series, size_t length)
	{
		a = 0;
	//	*is_expanded = 0;
		if (length != 24 * sizeof(int))
		{
			cerr << "segmation fault!!" << endl;
			exit(-1);
		}
		for (int i = 0; i < 24; ++i)
		{
			a += (type)color_series[i] * (type)pow(6, i);
		}
	}
	static int color_relation(int color)
	{
		if (color == 0) return 5;
		if (color == 1) return 3;
		if (color == 2) return 4;
		if (color == 3) return 1;
		if (color == 4) return 2;
		if (color == 5) return 0;
		else
		{
			cerr << "color override!" << endl;
			exit(-1);
		}
	}
	int value(int num) const
	{
		
		return (a % (type)pow(6, num + 1)) / (type)pow(6, num);
	}
	void changevalue(int num, int color)
	{
		a -= (type)value(num) * (type)pow(6, num);
		a += (type)color * (type)pow(6, num);
	}
	cube operate(int operate_type) const
	{
		cube b = *this;
		string op = int_operate(operate_type, 0);
		int temp[24];
		for (int i = 0; i < 24; ++i)
		{
			temp[i] = b.value(i);
		}
		if (op == "F+")
		{
			b.changevalue(7, temp[6]);
			b.changevalue(15, temp[7]);
			b.changevalue(14, temp[15]);
			b.changevalue(6, temp[14]);
			b.changevalue(8, temp[2]);
			b.changevalue(16, temp[3]);
			b.changevalue(21, temp[8]);
			b.changevalue(20, temp[16]);
			b.changevalue(13, temp[21]);
			b.changevalue(5, temp[20]);
			b.changevalue(2, temp[13]);
			b.changevalue(3, temp[5]);
		}
		if (op == "F2")
		{
			b.changevalue(7, temp[14]);
			b.changevalue(15, temp[6]);
			b.changevalue(14, temp[7]);
			b.changevalue(6, temp[15]);
			b.changevalue(2, temp[21]);
			b.changevalue(3, temp[20]);
			b.changevalue(8, temp[13]);
			b.changevalue(16, temp[5]);
			b.changevalue(21, temp[2]);
			b.changevalue(20, temp[3]);
			b.changevalue(13, temp[8]);
			b.changevalue(5, temp[16]);
		}
		if (op == "F-")
		{
			b.changevalue(7, temp[15]);
			b.changevalue(15, temp[14]);
			b.changevalue(14, temp[6]);
			b.changevalue(6, temp[7]);
			b.changevalue(2, temp[8]);
			b.changevalue(3, temp[16]);
			b.changevalue(8, temp[21]);
			b.changevalue(16, temp[20]);
			b.changevalue(21, temp[13]);
			b.changevalue(20, temp[5]);
			b.changevalue(13, temp[2]);
			b.changevalue(5, temp[3]);
		}
		if (op == "R+")
		{
			b.changevalue(8, temp[16]);
			b.changevalue(9, temp[8]);
			b.changevalue(17, temp[9]);
			b.changevalue(16, temp[17]);
			b.changevalue(1, temp[7]);
			b.changevalue(3, temp[15]);
			b.changevalue(7, temp[21]);
			b.changevalue(15, temp[23]);
			b.changevalue(21, temp[18]);
			b.changevalue(23, temp[10]);
			b.changevalue(10, temp[3]);
			b.changevalue(18, temp[1]);
		}
		if (op == "R2")
		{
			b.changevalue(8, temp[17]);
			b.changevalue(9, temp[16]);
			b.changevalue(17, temp[8]);
			b.changevalue(16, temp[9]);
			b.changevalue(1, temp[21]);
			b.changevalue(3, temp[23]);
			b.changevalue(7, temp[18]);
			b.changevalue(15, temp[10]);
			b.changevalue(21, temp[1]);
			b.changevalue(23, temp[3]);
			b.changevalue(10, temp[15]);
			b.changevalue(18, temp[7]);
		}
		if (op == "R-")
		{
			b.changevalue(8, temp[9]);
			b.changevalue(9, temp[17]);
			b.changevalue(17, temp[16]);
			b.changevalue(16, temp[8]);
			b.changevalue(1, temp[18]);
			b.changevalue(3, temp[10]);
			b.changevalue(7, temp[1]);
			b.changevalue(15, temp[3]);
			b.changevalue(21, temp[7]);
			b.changevalue(23, temp[15]);
			b.changevalue(10, temp[23]);
			b.changevalue(18, temp[21]);
		}
		if (op == "U+")
		{
			b.changevalue(0, temp[2]);
			b.changevalue(1, temp[0]);
			b.changevalue(3, temp[1]);
			b.changevalue(2, temp[3]);
			b.changevalue(4, temp[6]);
			b.changevalue(5, temp[7]);
			b.changevalue(6, temp[8]);
			b.changevalue(7, temp[9]);
			b.changevalue(8, temp[10]);
			b.changevalue(9, temp[11]);
			b.changevalue(10, temp[4]);
			b.changevalue(11, temp[5]);
		}
		if (op == "U2")
		{
			b.changevalue(0, temp[3]);
			b.changevalue(1, temp[2]);
			b.changevalue(3, temp[0]);
			b.changevalue(2, temp[1]);
			b.changevalue(4, temp[8]);
			b.changevalue(5, temp[9]);
			b.changevalue(6, temp[10]);
			b.changevalue(7, temp[11]);
			b.changevalue(8, temp[4]);
			b.changevalue(9, temp[5]);
			b.changevalue(10, temp[6]);
			b.changevalue(11, temp[7]);
		}
		if (op == "U-")
		{
			b.changevalue(0, temp[1]);
			b.changevalue(1, temp[3]);
			b.changevalue(3, temp[2]);
			b.changevalue(2, temp[0]);
			b.changevalue(4, temp[10]);
			b.changevalue(5, temp[11]);
			b.changevalue(6, temp[4]);
			b.changevalue(7, temp[5]);
			b.changevalue(8, temp[6]);
			b.changevalue(9, temp[7]);
			b.changevalue(10, temp[8]);
			b.changevalue(11, temp[9]);
		}
		return b;
	}
	cube goal()
	{
		int color_left = value(12);
		int color_down = value(22);
		int color_back = value(19);
		int color_up = color_relation(color_down);
		int color_right = color_relation(color_left);
		int color_front = color_relation(color_back);
		int temp[24] = {color_up, color_up, color_up, color_up, 
						color_left, color_left, color_front, color_front,
						color_right, color_right, color_back, color_back,
						color_left, color_left, color_front, color_front,
						color_right, color_right, color_back, color_back,
						color_down, color_down, color_down, color_down};
		return cube(temp, sizeof(temp));
	}
	bool operator<(const cube &b) const
	{
		return this->a < b.a;
	}
};
class status
{
public:
	type s;
	int num;
	status(){ s = 0; num = 0;}
	status update(int a)
	{
		status temp;
		temp.s = s;
		temp.s += a * (type)pow(10, num);
		temp.num = num + 1;
		return temp;
	}
	void output(int if_inverse)
	{
		type temp;
		if (if_inverse == 0)
		{
			for (int i = 0; i < num; ++i)
			{
					//cout << s << endl;
					temp = s / (type)pow(10, i);
					//cout << temp << endl;
					temp = temp % 10;
					switch(temp)
					{
						case 0:{cout << "F+\n"; break;}
						case 1:{cout << "F2\n"; break;}
						case 2:{cout << "F-\n"; break;}
						case 3:{cout << "R+\n"; break;}
						case 4:{cout << "R2\n"; break;}
						case 5:{cout << "R-\n"; break;}
						case 6:{cout << "U+\n"; break;}
						case 7:{cout << "U2\n"; break;}
						case 8:{cout << "U-\n"; break;}
					}
			}
		}
		else if (if_inverse == 1)
		{
			for (int i = num - 1; i >= 0; --i)
			{
					//cout << s << endl;
					temp = s / (type)pow(10, i);
					//cout << temp << endl;
					temp = temp % 10;
					switch(temp)
					{
						case 0:{cout << "F+\n"; break;}
						case 1:{cout << "F2\n"; break;}
						case 2:{cout << "F-\n"; break;}
						case 3:{cout << "R+\n"; break;}
						case 4:{cout << "R2\n"; break;}
						case 5:{cout << "R-\n"; break;}
						case 6:{cout << "U+\n"; break;}
						case 7:{cout << "U2\n"; break;}
						case 8:{cout << "U-\n"; break;}
					}
			}
		}
	}
};
int main()
{
	cube a;
	cube b = a.goal();
	my_map map_up;
	my_map map_down;
	my_queue queue_up;
	my_queue queue_down;
	my_map map_up_expanded;
	my_map map_down_expanded;
	map_up.insert(my_pair(a, status()));
	map_down.insert(my_pair(b, status()));
	map_up_expanded.insert(my_pair(a, status()));
	map_down_expanded.insert(my_pair(b, status()));
	if (b.a == a.a)
	{
		cout << 0 << endl;
		return 0;
	}
	while (1)
	{
		it it_up = map_up.begin();
		it it_down = map_down.begin();
		it it_up_ex = map_up_expanded.begin();
		it it_down_ex = map_down_expanded.begin();
		while (it_up != map_up.end())
		{
			if (map_down.find(it_up->first) != map_down.end())
			{
				cout << it_up->second.num + map_down.find(it_up->first)->second.num << endl;
				it_up->second.output(0);
				map_down.find(it_up->first)->second.output(1);
				return 0;
			}
			it_up++;
		}
		while(it_up_ex != map_up_expanded.end())
		{
			it temp = it_up_ex;
			queue_up.push(make_pair(it_up_ex->first, it_up_ex->second));
			it_up_ex++;
			map_up_expanded.erase(temp->first);
		}
		//map_up_expanded.clear();
		while(!queue_up.empty())
		{
			my_pair temp = queue_up.front();
			for (int i = 0; i < 9; ++i)
			{

				my_pair temp2 = my_pair(temp.first.operate(i), temp.second.update(int_int(i, 0)));
				map_up_expanded.insert(temp2);
				map_up.insert(my_pair(temp2));
			}
			queue_up.pop();
		}
		while (it_down != map_down.end())
		{
			if (map_up.find(it_down->first) != map_up.end())
			{
				cout << it_down->second.num + map_up.find(it_down->first)->second.num << endl;
				map_up.find(it_down->first)->second.output(0);
				it_down->second.output(1);
				return 0;
			}
			it_down++;
		}
		while (it_down_ex != map_down_expanded.end())
		{
			it temp = it_down_ex;
			queue_down.push(make_pair(it_down_ex->first, it_down_ex->second));
			it_down_ex++;
			map_down_expanded.erase(temp->first);
		}
		//map_down_expanded.clear();
		while(!queue_down.empty())
		{
			my_pair temp = queue_down.front();
			for (int i = 0; i < 9; ++i)
			{
				my_pair temp2 = my_pair(temp.first.operate(i), temp.second.update(int_int(i, 1)));
				map_down.insert(temp2);
				map_down_expanded.insert(temp2);
			}
			queue_down.pop();
		}
	}
	return 0;
}