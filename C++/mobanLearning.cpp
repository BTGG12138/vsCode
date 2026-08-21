#include<iostream>
#include<cstring>
using namespace std;
    template<class T>
    void swapNumber(T &k,T &l)
    {
        T swapNum=k;
        k=l;
        l=swapNum;
    }
    template<class T>
    void sort(T c[],int length)
    {
        for(int i=0;i<length-1;i++)
        {
            int max=i;
            for(int j=i+1;j<length;j++)
            {
                if(c[j]>c[max])
                {
                    max=j;
                }
            }
            if(max!=i)
            {
                swapNumber(c[i],c[max]);
            }
        }
        for(int i=0;i<length;i++)
        {
            cout<<c[i]<<" ";
        }
    }
    void outPutint()
    {
        int a[5]={5,3,2,4,1};
        int lengthInt=sizeof(a)/sizeof(int);
        sort(a,lengthInt);
    }
    void outPutchar()
    {
        char b[6]="deacb";
        int lengthChar=strlen(b);
        //字符串推荐使用strlen
        //头文件加上cstring
        //char数组后自带隐藏的\0标志数组的结束
        sort(b,lengthChar);
    }
int main()
{
    outPutint();
    cout<<endl;
    outPutchar();
    system("pause");
}