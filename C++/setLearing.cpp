#include<iostream>
#include<set>
#include<string>
using namespace std;
void inPut(set<int> &s)
{
    s.insert(20);
    s.insert(40);
    s.insert(20);
    s.insert(50);
    s.insert(10);
}
void outPut(set<int> &s)
{
    for(set<int>::iterator i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void part1()
{
    set<int> s1;
    inPut(s1);
    outPut(s1);
    set<int> s2(s1);
    outPut(s2);
    set<int> s3;
    s3=s2;
    outPut(s3);
}
void part2()
{
    set<int> s1;
    inPut(s1);
    outPut(s1);
    if(!s1.empty())
    {
        cout<<"不为空"<<endl;
    }
    set<int>s2;
    inPut(s2);
    s2.insert(60);
    s1.swap(s2);
    outPut(s1);
    outPut(s2);
}
void part3()
{
    set<int> s1;
    inPut(s1);
    outPut(s1);
    s1.clear();
    outPut(s1);
    inPut(s1);
    s1.erase(s1.begin());
    outPut(s1);
    inPut(s1);
    set<int> ::iterator i=s1.end();
    s1.erase(s1.begin(),--i); 
    outPut(s1);
    s1.erase(50);
    outPut(s1);
}
void part4()
{
    set<int> s1;
    inPut(s1);
    outPut(s1);
    set<int>::iterator p=s1.find(10);
    if(p==s1.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到了"<<endl;
    }
    int q=s1.count(10);
    cout<<q<<endl;
}
void part5()
{
    set<int> s1;
    pair<set<int>::iterator ,bool>isCha1;
    isCha1=s1.insert(10);
    if(isCha1.second)
    {
        cout<<"插入成功"<<endl;
    }
    isCha1=s1.insert(10);
    if(!isCha1.second)
    {
        cout<<"插入失败"<<endl;
    }
    multiset<int>s2;
    s2.insert(10);
    s2.insert(10);
    s2.insert(10);
    for(multiset<int>::iterator i=s2.begin();i!=s2.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void part6()
{
    pair<string,int> p("间桐樱",100);
    cout<<p.first<<" "<<p.second<<endl;
    pair<string,int> q=make_pair("老爷爷",100);
    cout<<q.first<<" "<<q.second<<endl;
}
struct myCompare
{
    bool operator()(int a,int b) const
    {
        return a>b;
    }
}
;
void part7()
{
    set<int,myCompare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    for(set<int,myCompare>::iterator i=s1.begin();i!=s1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
struct myPerson
{
    int age;
    int damage;
}
;
struct youCompare
{
    bool operator()(const myPerson&p1,const myPerson&p2) const
    {
        return p1.age>p2.age;
    }
}
;
void part8()
{
    set<myPerson,youCompare> s1;
    myPerson p1={10,100};
    myPerson p2={20,50};
    myPerson p3={50,20};
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    for(set<myPerson,youCompare>::iterator i=s1.begin();i!=s1.end();i++)
    {
        cout<<i->age<<" "<<i->damage<<endl;
        //"*i.age"的优先访问顺序是. 应加上括号。或者使用i->这种简略表达方式，等同于(*i).age
    }
    cout<<endl;
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