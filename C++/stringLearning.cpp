#include<iostream>
#include<string>
using namespace std;
void part1()
{
    string s1;
    const char *str="See You Again";
    //str用于储存S的地址
    //string用于只读S的地址直到\0停止
    string s2(str);
    string s3(s2);
    string s4(10,'a');
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
}
void  part2()
{
    string s1;
    s1.assign("See You Again");
    string s2;
    s2.assign("See You Again",7);
    string s3;
    s3.assign(10,'a');
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
}
void part3()
{
    string s1;
    s1="See";
    s1.append(" You");
    s1.append(" Again ",6);
    string s2="Who Forever";
    s1.append(s2,3,8);
    //从第3+1个开始，往后8个字符
    cout<<s1<<endl;
}
void part4()
{
    string s1="See You Again You";
    int i=s1.find("You");
    if(i==-1)
    {
        cout<<"未找到指定字符串"<<endl;
    }
    else
    {
        cout<<i<<endl;
    }
    int j=s1.rfind("You");
    if(j==-1)
    {
        cout<<"未找到指定字符串"<<endl;
    }
    else
    {
        cout<<j<<endl;
    }
}
void part5()
{
    string s1="See You Again";
    s1.replace(8,5,"Tomorrow");
    cout<<s1<<endl;
}
void part6()
{
    string s1="See";
    string s2="You";
    if(s1.compare(s2)==0)
    {
        cout<<"相等"<<endl;
    }
    else
    {
        cout<<"不相等"<<endl;
    }
}
void part7()
{
    string s1="See You Again";
    for(int i=0;i<s1.size();i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<s1.size();j++)
    {
        cout<<s1.at(j)<<" ";
    }
    cout<<endl;
    s1[1]='E';
    s1.at(2)='E';
    cout<<s1<<endl;
}
void part8()
{
    string s1="See Again";
    s1.insert(4,"You ");
    //从第4个位置的后面往后
    cout<<s1<<endl;
    s1.erase(4,4);
    cout<<s1<<endl;
}
void part9()
{
    string s1="See You Again";
    string s2=s1.substr(4,3);
    cout<<s2<<endl;
    int i=s1.find('u');
    s2=s1.substr(0,i+1);
    cout<<s2<<endl;
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
    //part8();
    //part9();
    system("pause");
}