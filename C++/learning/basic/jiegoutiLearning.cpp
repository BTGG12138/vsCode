#include<iostream>
using namespace std;
struct student
    {
        int age;
    }
    ;
    struct teacher
    {
        int age;
    student stu[3]; 
} 
;
void inclu(teacher*p)
{
    for(int i=0;i<3;i++)
    {
        cout<<"老师的年龄";
        cin>>p[i].age;
        for(int j=0;j<3;j++)
        {
            cout<<"学生的年龄";
            cin>>p[i].stu[j].age;
        }
    }
}
void outclu(teacher* p)
{
    for(int i=0;i<3;i++)
    {
        cout<<"老师年龄 "<<p[i].age<<endl;
        for(int j=0;j<3;j++)
        {
            cout<<"学生年龄 "<<p[i].stu[j].age<<endl;
        }
    }
}
int main()
{
    teacher tea[3];
    inclu(tea);
    outclu(tea);
    system("pause");
}