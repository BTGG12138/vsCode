#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	for(int a=1;a<=9;a++)
	{
		for(int b=1;b<=a;b++)
		{
			c=a*b;
			printf("%d*%d=%d ",b,a,c);
		}
		printf("\n");
	}
	system("pause");
} 
