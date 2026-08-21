#include<iostream>
using namespace std;
int *fun1()
{
    int *p=new int(10);
    return p;
}
int *fun2()
{
    int *arr=new int[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=i+1;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return arr;
}
void part1()
{
    int *q1=fun1();
    cout<<*q1<<endl;
    cout<<*q1<<endl;
    cout<<*q1<<endl;
    delete q1;
}
void part2()
{
    int *q2=fun2();
    for(int i=0;i<10;i++)
    {
        cout<<q2[i]<<" ";
        //下标运算符[]是指针加上解引用的缩写
    }
    cout<<endl;
    delete q2;
}
void part3()
{
    int a=10;
    int &b=a;
    //&与指针的地址符号没有关系
    cout<<a<<endl;
    cout<<b<<endl;
    b=100;
    cout<<a<<endl;
    cout<<b<<endl;
}
void swapNum(int &a,int &b)
//这里的&是引用的意思
{
    int Num=a;
    a=b;
    b=Num;
}
void part4()
{
    int a=10;
    int b=20;
    swapNum(a,b);
    cout<<a<<" "<<b<<endl;
}
int &fun3()
{
    static int a=10;
    return a;
}
void part5()
{
    int &Num=fun3();
    cout<<Num<<endl;
    fun3()=1000;
    cout<<Num<<endl;
}
void fun4(int &Num)
{
    Num=1000;
}
void part6()
{
    int a=10;
    int &Num=a;
    Num=20;
    //Nun的本质是储存了a的地址，编译器自己会解引用
    cout<<a<<endl;
    cout<<Num<<endl;
    fun4(a);
    cout<<a<<endl;
    cout<<Num<<endl;
}
void part7()
{
    const int&Num=10;
    //本质编译器会用另外一个容器使得引用合法化
    cout<<Num<<endl;
}
int fun5(int a,int b=30,int c=50)
//从第一个设置默认参数的后面，必须有默认参数
{
    return a+b+c;
}
void part8()
{
    cout<<fun5(1,3)<<endl;
}
void fun6(int a)
{
    cout<<"调用一号"<<endl;
}
void fun6(float a)
{
    cout<<"调用二号"<<endl;
}
int fun7(int &a)
{
    cout<<"调用三号"<<endl;
    return a;
}
int fun7(const int &a)
{
    cout<<"调用四号"<<endl;
    return a;
}
void part9()
{
    fun6(6.1f);
    int Num=fun7(10);
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
    part9();
    system("pause");
}