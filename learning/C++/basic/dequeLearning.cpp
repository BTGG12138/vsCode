#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
void outPut(deque<int>&d)
{
    for(deque<int>::iterator i=d.begin();i!=d.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void part1()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i+1);
    }
    outPut(d1);
    deque<int>d2(d1.begin(),d1.end());
    outPut(d2);
    deque<int>d3(10,100);
    outPut(d3);
    deque<int>d4(d3);
    outPut(d4);
}
void part2()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i+1);
    }
    outPut(d1);
    deque<int>d2;
    d2=d1;
    outPut(d2);
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    outPut(d3);
    deque<int>d4;
    d4.assign(10,100);
    outPut(d4);
}
void part3()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i+1);
    }
    outPut(d1);
    if(!d1.empty())
    {
        cout<<"d1 不是空的"<<endl;
    }
    cout<<d1.size()<<endl;
    d1.resize(5);
    outPut(d1);
    d1.resize(15,6);
    outPut(d1);
}
void part4()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i+1);
    }
    outPut(d1);
    d1.push_front(6);
    d1.push_back(6);
    outPut(d1);
    d1.pop_front();
    d1.pop_back();
    outPut(d1);
    d1.insert(d1.begin(),6);
    d1.insert(d1.end(),6,6);
    outPut(d1);
    deque<int>d2(6,6);
    d1.insert(d1.end(),d2.begin(),d2.end());
    outPut(d1);
    d1.erase(d1.begin());
    outPut(d1);
    d1.clear();
    outPut(d1);
}
void part5()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i+1);
    }
    outPut(d1);
    for(int i=0;i<d1.size();i++)
    {
        cout<<d1[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<d1.size();j++)
    {
        cout<<d1.at(j)<<" ";
    }
    cout<<endl;
}
void part6()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_front(i+1);
    }
    outPut(d1);
    sort(d1.begin(),d1.end());
    outPut(d1);
}
int main()
{
    //part1();
    //part2();
    //part3();
    //part4();
    //part5();
    //part6();
    system("pause");
}