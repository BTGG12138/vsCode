#include<iostream>
#include<map>
using namespace std;
void inPut(map<int,int>&m)
{
    for(int i=10;i>0;i--)
    {
    m.insert(pair<int,int>(i,i*10));
    }
}
void outPut(map<int,int>&m)
{
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
    {
        cout<<(*i).first<<" "<<(*i).second<<"  ";
    }
    cout<<endl;
}
void part1()
{
    map<int,int>m1;
    inPut(m1);
    outPut(m1);
    map<int,int>m2(m1);
    outPut(m2);
    map<int,int>m3;
    m3=m2;
    outPut(m3);
}
void part2()
{
    map<int,int>m1;
    inPut(m1);
    outPut(m1);
    if(!m1.empty())
    {
        cout<<"容器不为空"<<endl;
    }
    cout<<m1.size()<<endl;
    map<int,int>m2;
    for(int i=0;i<10;i++)
    {
    m2.insert(pair<int,int>(i,i*10));
    }
    m1.swap(m2);
    outPut(m1);
    outPut(m2);
}
void part3()
{
    map<int,int>m1;
    inPut(m1);
    outPut(m1);
    m1.insert(make_pair(11,66));
    m1.insert(map<int,int>::value_type(12,66));
    m1[13]=(13,66);
    cout<<m1[14]<<endl;
    outPut(m1);
    m1.erase(--m1.end());
    m1.erase(66);
    outPut(m1);
}
void part4()
{
    map<int,int>m1;
    inPut(m1);
    outPut(m1);
    if(m1.end()!=m1.find(6))
    {
        cout<<"找到了"<<endl;
        cout<<(*m1.find(6)).first<<" "<<(*m1.find(6)).second<<endl;
    }
    cout<<m1.count(6)<<endl;
}
struct myCompare
{
    bool operator()(int v1,int v2)const
    {
        return v1>v2;    
    }
}
;
void part5()
{
    map<int,int,myCompare>m1;
    for(int i=10;i>0;i--)
    {
    m1.insert(pair<int,int>(i,i*10));
    }
    for(map<int,int>::iterator i=m1.begin();i!=m1.end();i++)
    {
        cout<<(*i).first<<" "<<(*i).second<<"  ";
    }
    cout<<endl;
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