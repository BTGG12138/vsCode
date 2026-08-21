#include <iostream>
using namespace std;
void paiXu(int *a,int length)
{
    int sw;
    for(int i=0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(a[i]>a[j])
            {
                sw=a[i];
                a[i]=a[j];
                a[j]=sw;
            }
        }
    }
}
int main() 
{
    int length;
    cin>>length;
    int a[length];
    for(int i=0;i<length;i++)
    {
        cin>>a[i];
    }
    paiXu(a,length);
    for(int i=0;i<length;i++)
    {
        cout<<a[i];
    }
}