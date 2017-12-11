#include <stdio.h>
#include <stdlib.h>
struct matx22
{
	int a00, a01, a10, a11;
};

struct matx22 multiply(struct matx22 A, struct matx22 B){
	struct  matx22 C;
	C.a00 = (A.a00 % 9973) * (B.a00 % 9973) + (A.a01 % 9973) * (B.a10 % 9973);
	C.a10 = (A.a10 % 9973) * (B.a00 % 9973) + (A.a11 % 9973) * (B.a10 % 9973);
	C.a01 = (A.a00 % 9973) * (B.a01 % 9973) + (A.a01 % 9973) * (B.a11 % 9973);
	C.a11 = (A.a10 % 9973) * (B.a01 % 9973) + (A.a11 % 9973) * (B.a11 % 9973);
	return C;
}


struct matx22 power(int n){
	struct matx22 m;
	struct matx22 p = {1,1,1,0};
	if (n == 0){
		struct matx22 f = {0, 0, 0, 0};
		return f;
	}
	if (n == 1)
	{
		m = p;
	}
	else if (n % 2 == 0){
		m = power(n/2);
		m = multiply(m, m);
	}
	else  if (n % 2 == 1){
		m = power((n-1) / 2);
		m = multiply(m, m);
		m = multiply(m, p);
	}
	return m;
}

int main(){
	struct matx22 a;
	int b;
	scanf("%d", &b);
	int *c = (int *)malloc(b * 4);
	for (int i = 0; i < b; ++i)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < b; ++i)
	{
		a = power(c[i]);
		printf("%d\n", (a.a01) % 9973) ;
	}
	return 0;
}