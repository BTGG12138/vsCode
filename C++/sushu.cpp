#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,a=0;
	scanf("%d",&x);
	for(int m=2;m<=x;m++)
	{
		for(int n=2;n<m;n++)
		{
			if(m%n==0)
			{
				a++;
				break; 
			}
		}
		if(a==0)
		{
			printf("%d\n",m);
		}
		else
		{
		    a--;
		} 
	}
	system("pause");
}
