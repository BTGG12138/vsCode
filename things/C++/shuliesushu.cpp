#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c=2,d,e;
	scanf("%d",&a);
	int sz[a+1]={}; 
	for(d=c;d<a+1;d++)
	{
		if(sz[d]==0)
		{
			c=d;
		}
	for(b=c+1;b<a+1;b++)
	{
		if(b%c==0)
		{
			sz[b]=1;
		}
	}
    }
    for(e=2;e<a+1;e++)
	{
		if(sz[e]==0)
		{
			printf("%d\t",e);
		} 
	}
	system("pause");
}
