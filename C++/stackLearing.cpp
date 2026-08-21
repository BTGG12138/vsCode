#include<iostream>
#include<stack>
using namespace std;
void part1()
{
    stack<int>s1;
    for(int i=0;i<10;i++)
    {
        s1.push(i+1);
    }
    stack<int>s2(s1);
    if(!s2.empty())
    {
        cout<<"不是空的"<<endl;
        for(int j=0;j<s1.size();j++)
        {
            cout<<s2.top()<<" ";
            s2.pop();
        }
        cout<<endl;
    }
}
int main()
{
    part1();
    system("pause");
}