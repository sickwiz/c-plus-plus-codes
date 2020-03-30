#include<iostream>
using namespace std;
int main()
{
    int i=190;
    int *p=&i; //p holds the address of i;
    cout<<p<<endl; // prints the address of c;
    cout<<i<<endl;
    cout<<*p<<endl; //prints the value of address stored at c;
    cout<<sizeof(i)<<endl;
    cout<<sizeof(p)<<endl;
    // int *ptr=0;
    // int a=10;
    // *ptr=a;
    // cout<<*ptr<<endl;

    int b=10;
    int *ptr=&b;
    cout<<sizeof(ptr)<<endl;
    cout<<ptr<<endl;
    ptr=ptr+1;   // pointer will start pointing to the next address now;
    cout<<ptr<<endl;
}