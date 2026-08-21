#include<iostream>
#include<list>
using namespace std;
void outPut(list<int>&l)
{
    for(list<int>::iterator j=l.begin();j!=l.end();j++)
    {
        cout<<*j<<" "; 
    }
    cout<<endl;
}
void part1()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    outPut(l1);
    list<int>l2(l1);
    outPut(l2);
    list<int>l3(l2.begin(),l2.end());
    outPut(l3);
    list<int>l4(10,6);
    outPut(l4);
}
void part2()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    outPut(l1); 
    list<int>l2;
    l2=l1;
    outPut(l2);
    list<int>l3;
    l3.assign(l2.begin(),l2.end());
    outPut(l3);
    list<int>l4;
    l4.assign(10,6);
    outPut(l4);
    l3.swap(l4);
    outPut(l3);
    outPut(l4);
}
void part3()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    outPut(l1); 
    if(!l1.empty())
    {
        cout<<"容器不是空的"<<endl;
    }
    cout<<l1.size()<<endl;
    l1.resize(15,6);
    outPut(l1);
    l1.resize(5);
    outPut(l1);
}
void  part4()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    l1.push_back(6);
    l1.push_front(6);
    outPut(l1);
    l1.pop_back();
    l1.pop_front();
    outPut(l1);
    list<int>::iterator j=l1.begin();
    l1.insert(++j,6);
    outPut(l1);
    l1.erase(l1.begin());
    outPut(l1);
    l1.remove(10);
    outPut(l1);
}
void part5()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    outPut(l1);
    cout<<l1.front()<<endl;
    cout<<l1.back()<<endl;
}
bool compare(int i,int j)
{
    return i>j;
}
void part6()
{
    list<int>l1;
    for(int i=0;i<10;i++)
    {
        l1.push_back(i+1);
    }
    outPut(l1);
    l1.reverse();
    outPut(l1);
    l1.sort();
    outPut(l1);
    l1.sort(compare);
    outPut(l1);
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
