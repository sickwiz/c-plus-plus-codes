#include<iostream>
using namespace std;
int main()
{
    int a[5];
    a[0]=1;
    a[1]=3;
    cout<<a<<"\t"<<&a<<endl;
    cout<<*(a)<<endl<<*(a+1)<<endl;  //0[a] is same as a[0];
    cout<<0[a]<<endl<<a[0]<<endl;
    cout<<"size of a = "<<sizeof(a)<<endl; //takes the whole size i.e 5*sizeof(int);
    int *p=&a[0];
    cout<<p<<endl;
   p=p+1;
   cout<<p<<endl;
//    a=a+1; //not permitted;

}