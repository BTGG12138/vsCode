#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include <random>
#include<numeric>
using namespace std;
void inPut(vector<int>&v)
{
    for(int i=0;i<10;i++)
    {
        v.push_back(i+1);
    }
}
void outPut1(int Num)
{
    cout<<Num<<" ";
}
struct outPut2
{
    void operator()(int Num)
    {
        cout<<Num<<" ";
    }
}
;
void part1()
{
    vector<int>v1;
    inPut(v1);
    for_each(v1.begin(),v1.end(),outPut1);
    cout<<endl;
    for_each(v1.begin(),v1.end(),outPut2());
    cout<<endl;
}
void outPut(vector<int>&v)
{
    for(vector<int>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
struct transForm
{
    int operator()(int Num)
    {
        if(Num>5)
        {
            return Num;
        }
        else
        {
            return Num+5;
        }
    }
}
;
void part2()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    vector<int>v2;
    v2.assign(10,6);
    transform(v1.begin(),v1.end(),v2.begin(),transForm());
    outPut(v1);
    outPut(v2);
}
struct myFind
{
    bool operator()(int v)const
    {
        return v>5;
    }
}
;
void part3()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    vector<int>::iterator i=find(v1.begin(),v1.end(),6);
    if(i!=v1.end())
    {
        cout<<"找到了"<<endl<<*i<<endl; 
    }
    vector<int>::iterator j=find_if(v1.begin(),v1.end(),myFind());
    if(j!=v1.end())
    {
        cout<<"找到了"<<endl<<*j<<endl; 
    }
    v1.insert(v1.begin(),4,6);
    vector<int>::iterator k=adjacent_find(v1.begin(),v1.end());
    if(k!=v1.end())
    {
        cout<<"找到了"<<endl<<*k<<endl; 
    }
    for(int i=0;i<4;i++)
    {
        v1.erase(v1.begin());
    }
    if(binary_search(v1.begin(),v1.end(),6))
    {
        cout<<"找到了"<<endl;
    }
}
struct myCount
{
    bool operator()(int Num)
    {
        return Num>5;
    }
}
;
void part4()
{
    vector<int>v1;
    inPut(v1);
    for(int i=0;i<5;i++)
    {
        v1.push_back(10);
    }
    outPut(v1);
    cout<<count(v1.begin(),v1.end(),10)<<endl;
    cout<<count_if(v1.begin(),v1.end(),myCount())<<endl;
}
void part5()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    sort(v1.begin(),v1.end(),greater<int>());
    outPut(v1);
    shuffle(v1.begin(), v1.end(), mt19937(random_device()()));
    //random_device()调用随机设备数据()重载小括号，mt19937()调用打乱算法
    //要加上#include <random>
    outPut(v1);
    sort(v1.begin(),v1.end(),less<int>());
    vector<int>v2;
    inPut(v2);
    vector<int>v3;
    v3.resize(v1.size()+v2.size());
    //空容器不能生塞数据
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    outPut(v3);
    reverse(v3.begin(),v3.end());
    outPut(v3);
}
struct myReplace
{
    bool operator()(int Num)
    {
        return Num%2==0;
    }
}
;
void part6()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    outPut(v2);
    replace(v2.begin(),v2.end(),6,666);
    outPut(v2);
    replace_if(v2.begin(),v2.end(),myReplace(),666);
    outPut(v2);
    swap(v1,v2);
    outPut(v1);
    outPut(v2);
}
void part7()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    int Num=accumulate(v1.begin(),v1.end(),0);
    cout<<Num<<endl;
    fill(v1.begin(),v1.end(),66);
    outPut(v1);
}
void myPrint(int Num)
{
    cout<<Num<<" ";
}
void part8()
{
    vector<int>v1;
    inPut(v1);
    outPut(v1);
    vector<int>v2;
    v2.push_back(5);
    v2.push_back(10);
    v2.push_back(100);
    vector<int>v3;
    v3.resize(v1.size()+v2.size());
    vector<int>::iterator i=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),i,myPrint);
    cout<<endl;
    vector<int>::iterator j=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),j,myPrint);
    cout<<endl;
    vector<int>::iterator k=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),k,myPrint);
    cout<<endl;
    vector<int>::iterator l=set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),v3.begin());
    for_each(v3.begin(),l,myPrint);
    cout<<endl;
    //对称差集set_symmetric_difference输出以上两个差集的并集
}
int main()
{
    //part1();
    //part2();
    //part3();
    //part4();
    //part5();
    //part6();
    //part7();
    part8();
    system("pause");
}