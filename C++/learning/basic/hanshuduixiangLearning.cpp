#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
struct myAdd
{
    int count;
    myAdd()
    {
        this->count=0;
    } 
    int operator()(int v1,int v2)
    //重载了函数运算符()
    {
        this->count++;
        return v1+v2;
    }
}
;
void part1()
{
    myAdd myAdd1;
    for(int i=10;i<50;i+=10)
    {
        cout<<myAdd1(i,i)<<endl;
    }
    cout<<myAdd1.count<<endl;
}
struct mySort
{
    bool operator()(int Num)
    {
        return Num>5;
    }
}
;
void part2()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    vector<int>::iterator j=v1.begin();
    while((j=find_if(j,v1.end(),mySort()))!=v1.end())
    {
        cout<<*j<<" ";
        j++;
    }
    cout<<endl;
}
struct youSort
{
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
}
;
void part3()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    sort(v1.begin(),v1.end(),youSort());
    for(vector<int>::iterator i=v1.begin();i!=v1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void part4()
{
    negate<int>n1;
    cout<<n1(100)<<endl;
    multiplies<int>p1;
    cout<<p1(100,100)<<endl;
}
void part5()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    sort(v1.begin(),v1.end(),greater<int>());
    for(vector<int>::iterator i=v1.begin();i!=v1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    //logical_not,logical_and,logical_or 逻辑仿函数
}
int main()
{
    //part1();
    //part2();
    //part3();
    //part4();
    part5();
    system("pause");
}