#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

typedef struct A
{
	int num;
	int data;
	int sum;
	struct A* next;
	struct A* prev;
}shop;
int main(int argc, char const *argv[])
{
	int n;
	int tmaxbegin, maxbegin, tmaxend, maxend;
	int tminbegin, minbegin, tminend, minend;
	int min, max;
	int curmaxsum, curminsum;
	int begin1, end1;
	int begin2, end2;
	int begin3, end3;
	int max1, max2, max3, max4;
	int min1, min2, min3, min4;
	int result = 0;
	curmaxsum = max = 0;
	curminsum = min = INT_MAX;
	scanf("%d", &n);
	shop *s = (shop*)malloc(n * sizeof(shop));
	s[0].num = 0;
	s[0].next = &s[1];
	s[0].prev = &s[n - 1];
	scanf("%d", &s[0].data);
	s[0].sum = s[0].data;
	tmaxbegin = maxbegin = tmaxend = maxend = tminbegin = minbegin = tminend = minend= 0;
	curmaxsum = s[0].data;
	curminsum = s[0].data;
	//对s[0]的情况进行判断
	if (curmaxsum > max)
		max = curmaxsum;
	if (curmaxsum < 0)
	{
		curmaxsum = 0;
		tmaxbegin ++;
		tminbegin ++;
	}
	if (curminsum < min)
		min = curminsum;
	if (curminsum > 0)
	{
		curminsum = 0;
		tminbegin ++;
		tminend ++;
	}
	//对末尾元素之前的情况进行判断
	for (int i = 1; i < n - 1; ++i)
	{	
		s[i].num = i;
		s[i].next = &s[i + 1];
		s[i].prev = &s[i - 1];
		scanf("%d", &s[i].data);
		s[i].sum = s[i - 1].sum + s[i].data;
		curmaxsum += s[i].data;
		curminsum += s[i].data;
		if (curmaxsum > max) 
		{
			max = curmaxsum;
			tmaxend = i;
			maxbegin = tmaxbegin;
			maxend = tmaxend;
		}
		if (curmaxsum < 0)
		{
			curmaxsum = 0;
			tmaxbegin = tmaxend = i + 1;
		}
		if (curminsum < min)
		{
			min = curminsum;
			tminend = i;
			minbegin = tminbegin;
			minend = tminend;
		}
		if (curminsum > 0)
		{
			curminsum = 0;
			tminbegin = tminend = i + 1;
		}
	}
	//对末尾元素进行判断
	s[n - 1].num = n - 1;
	s[n - 1].next = &s[0];
	s[n - 1].prev = &s[n - 2];
	scanf("%d", &s[n - 1].data);
	s[n - 1].sum = s[n - 2].sum + s[n - 1].data;
	curmaxsum += s[n - 1].data;
	curminsum += s[n - 1].data;
	if (curmaxsum > max) 
	{
		max = curmaxsum;
		tmaxend = n - 1;
		maxbegin = tmaxbegin;
		maxend = tmaxend;
	}
	if (curminsum < min)
	{
		min = curminsum;
		tminend = n - 1;
		minbegin = tminbegin;
		minend = tminend;
	}
	if (s[n - 1].sum - min > max)
	{
		begin1 = s[minend].next->num;
		end1 = s[minbegin].prev->num;
		max1 = s[n - 1].sum - min;
	}
	else 
	{
		begin1 = maxbegin;
		end1 = maxend;
		max1 = max;
	}
	result = max1;
	//找两个数组的最大/最小子数组。
	shop *itbig = &s[begin1];
	tminbegin = minbegin = begin1;
	tminend = minend = begin1;
	int cursum = 0;
	min2 = INT_MAX;
	while (itbig != s[end1].next)
	{
		cursum += itbig->data;
		if (cursum < min2)
		{
			min2 = cursum;
			tminend = itbig->num;
			minbegin = tminbegin;
			minend = tminend;
		}
		if (cursum > 0)
		{
			tminbegin = itbig->next->num;
			tminend = itbig->next->num;
			cursum = 0;
		}
		itbig = itbig->next;
	}
	shop *itsmall = s[end1].next;
	cursum = 0;
	max2 = 0;
	tmaxbegin = maxbegin = s[end1].next->num;
	tmaxend = maxend = s[end1].next->num;
	while (itsmall != &s[begin1])
	{
		cursum += itsmall->data;
		if (cursum > max2)
		{
			max2 = cursum;
			tmaxend = itsmall->num;
			maxbegin = tmaxbegin;
			maxend = tmaxend;
		}
		if (cursum < 0)
		{
			cursum = 0;
			tmaxbegin = itsmall->next->num;
			tmaxend = itsmall->next->num;
		}
		itsmall = itsmall->next;	
	}
	//判断跳哪个
	if (max2 <= 0 && min2 >= 0)	//如果两个都不用跳
	{
		int temp = 0;
		shop *tempit = &s[begin1];
		while (tempit != &s[end1])
		{
			tempit = tempit->next;
			temp++;
		}
		if (temp >= 2)
			printf("%d", result);
		else if (temp == 0)
		{
			int temp1, temp2;
			temp1 = temp2 = INT_MIN;
			tempit = s[end1].next;
			while (tempit != &s[begin1])
			{
				if (tempit->data > temp1)
				{
					temp2 = temp1;
					temp1 = tempit->data;
				}
				else if (tempit->data > temp2)
				{
					temp2 = tempit->data;
				}
				tempit = tempit->next;
			}
			printf("%d", result + temp1 + temp2);
			return 0;
		}
		else if (temp == 1)
		{
			int temp1 = INT_MIN;
			tempit = s[end1].next;
			while (tempit != &s[begin1])
			{
				if (tempit->data > temp1)
					temp1 = tempit->data;
				tempit = tempit->next;
			}
			printf("%d", result + temp1);
			return 0;
		}
	}
	//加大的
	if (max2 > -min2)
	{
		begin2 = maxbegin;
		end2 = maxend;
		result += max2;
	}
	//减小的（负）
	else if (max2 < -min2)
	{
		
		end2 = end1;
		end1 = s[minbegin].prev->num;
		begin2 = s[minend].next->num;
		result -= min2;
		//begin2 = minbegin;
		//end2 = minend;
	}
	//如果既需要加大的，又需要减小的，相当于两个都要跳，就用完了三次跳跃机会，直接输出即可。
	else
	{
		printf("%d", max + max2 + abs(min2));
		return 0;
	}
	//再从分好的四段中分别找出大的、小的
	int maxbegin2, maxend2, tmaxbegin2, tmaxend2, minbegin2, minend2, tminbegin2, tminend2;
	maxbegin2 = maxend2 = tmaxbegin2 = tmaxend2 = minbegin2 = minend2 = tminbegin2 = tminend2 = 0;
	//找小的，第一段
	itbig = &s[begin1];
	min3 = 0;
	cursum = 0;
	minbegin = tminbegin = begin1;
	minend = tminend = begin1;
	while (itbig != s[end1].next)
	{
		cursum += itbig->data;
		if (cursum < min3)
		{
			min3 = cursum;
			tminend = itbig->num;
			minbegin = tminbegin;
			minend = tminend;
		}
		if (cursum > 0)
		{
			cursum = 0;
			tminbegin = itbig->next->num;
			tminend = itbig->next->num;
		}
		itbig = itbig->next;
	}
	//找小的，第二段
	itbig = &s[begin2];
	min4 = 0;
	cursum = 0;
	minbegin2 = tminbegin2 = begin2;
	minend2 = tminend2 = end2;
	while (itbig != s[end2].next)
	{
		cursum += itbig->data;
		if (cursum < min4)
		{
			min4 = cursum;
			tminend2 = itbig->num;
			minbegin2 = tminbegin2;
			minend2 = tminend2;
		}
		if (cursum > 0)
		{
			cursum = 0;
			tminbegin2 = tminend2 = itbig->next->num;
		}
		itbig = itbig->next;
	}
	//找大的，第一段
	itsmall = s[end1].next;
	max3 = 0;
	cursum = 0;
	maxbegin = tmaxbegin = maxend = tmaxend = itsmall->num;
	while (itsmall != &s[begin2])
	{
		cursum += itsmall->data;
		if (cursum > max3)
		{
			max3 = cursum;
			tmaxend = itsmall->num;
			maxbegin = tmaxbegin;
			maxend = tmaxend;
		}
		if (cursum < 0)
		{
			cursum = 0;
			tmaxend = tmaxbegin = itsmall->next->num;
		}
		itsmall = itsmall->next;
	}
	//找大的，第二段
	itsmall = s[end2].next;
	max4 = 0;
	cursum = 0;
	maxbegin2 = tmaxbegin2 = maxend2 = tmaxend2 = itsmall->num;
	while (itsmall != &s[begin1])
	{
		cursum += itsmall->data;
		if (cursum > max4)
		{
			max4 = cursum;
			tmaxend2 = itsmall->num;
			maxbegin2 = tmaxbegin2;
			maxend2 = tmaxend2;
		}
		if (cursum < 0)
		{
			cursum = 0;
			tmaxend2 = tmaxbegin2 = itsmall->next->num;
		}
		itsmall = itsmall->next;
	}
	//比较四个值，决定跳哪一段
	if (max3 <= 0 && max4 <= 0 && min3 >= 0 && min4 >= 0)
	{
		shop *tempit = &s[begin1];
		int temp = 0;
		while (tempit != &s[end1])
		{
			temp++;
			tempit = tempit->next;
		}
		temp++;
		tempit = &s[begin2];
		while (tempit != &s[end2])
		{
			temp++;
			tempit = tempit->next;
		}
		temp++;
		if (temp > 2)
		{
			printf("%d", result);
		}
		else if (temp == 2)
		{
			int temp1 = INT_MIN;
			tempit = s[end1].next;
			while (tempit != &s[begin2])
			{
				if (tempit->data > temp1)
					temp1 = tempit->data;
				tempit = tempit->next;
			}
			tempit = s[end2].next;
			while (tempit != &s[begin1])
			{
				if (tempit->data > temp1)
					temp1 = tempit->data;
				tempit = tempit->next;
			}
			printf("%d", result + temp1);
			return 0;
		}
	}
	else if (max3 >= max4 && max3 >= -min3 && max3 >= -min4)
	{
		printf("%d", result + max3);
		return 0;
	}
	else if (max4 >= max3 && max4 >= -min3 && max4 >= -min4)
	{
		printf("%d", result + max4);
		return 0;
	}
	else if (-min3 >= max3 && -min3 >= max4 && -min3 >= -min4)
	{
		printf("%d", result - min3);
		return 0;
	}
	else if (-min4 >= max3 && -min4 >= max4 && -min4 >= -min3)
	{
		printf("%d", result - min4);
		return 0;
	}
	printf("max1:%d, min2:%d, max2:%d\n", max1, min2, max2);
	return 0;
}