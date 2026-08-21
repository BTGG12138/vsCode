#include<iostream>
#include<queue>
using namespace std;
void part1()
{
    queue<int>q1;
    for(int i=0;i<10;i++)
    {
        q1.push(i+1);
    }
    if(!q1.empty())
    {
        cout<<"队列不为空"<<endl;
    }
    cout<<q1.size()<<endl;
    for(int j=0;j<10;j++)
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
}
int main()
{
    part1();
    system("pause");
}