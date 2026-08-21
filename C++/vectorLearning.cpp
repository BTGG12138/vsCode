#include<iostream>
#include<vector>
using namespace std;
void outPut(vector<int>&v)
{
    for(vector<int>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void part1()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    outPut(v1);
    vector<int>v2(v1.begin(),v1.end());
    outPut(v2);
    vector<int>v3(10,100);
    outPut(v3);
    vector<int>v4(v3);
    outPut(v4);
}
void part2()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    outPut(v1);
    vector<int>v2;
    v2=v1;
    outPut(v2);
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    outPut(v3);
    vector<int>v4;
    v4.assign(10,100);
    outPut(v4);
}
void part3()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    outPut(v1);
    if(!v1.empty())
    {
        cout<<"不是空的"<<endl;
    }
    cout<<v1.capacity()<<endl;
    cout<<v1.size()<<endl;
    v1.resize(15);
    outPut(v1);
    v1.resize(5);
    outPut(v1);
    v1.resize(15,6);
    outPut(v1);
}
void part4()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    outPut(v1);
    v1.pop_back();
    outPut(v1);
    v1.insert(v1.begin(),6);
    outPut(v1);
    v1.insert(v1.begin(),4,6);
    outPut(v1);
    v1.erase(v1.end());
    outPut(v1);
    v1.clear();
    outPut(v1);
}
void part5()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    for(int i=0;i<10;i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    cout<<v1.front()<<endl;
    cout<<v1.back()<<endl;
}
void part6()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    cout<<v1.capacity()<<endl;
    cout<<v1.size()<<endl;
    v1.resize(5);
    vector<int>(v1).swap(v1);
    //通过创建匿名的v1，交换后直接删去匿名对象
    cout<<v1.capacity()<<endl;
    cout<<v1.size()<<endl;
}
void part7()
{
    vector<int>v1;
    int*p=NULL;
    int Num1=0,j=v1.capacity();
    for(int i=0;i<10;i++)
    {
        j=v1.capacity();
        v1.push_back(i+1);
        if(&v1[0]!=p&&j!=v1.capacity())
        {
            p=&v1[0];
            Num1++;
            cout<<v1.capacity()<<endl;
        }
    }
    cout<<Num1<<endl;
    vector<int>v2;
    int*q=NULL;
    int Num2=0,k=v2.capacity();
    v2.reserve(100);
    for(int i=0;i<10;i++)
    {
        k=v2.capacity();
        v2.push_back(i+1);
        if(&v2[0]!=q&&k!=v2.capacity())
        {
            q=&v2[0];
            Num2++;
            cout<<v2.capacity()<<endl;
        }
    }
    cout<<Num2<<endl;
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
    system("pause");
}