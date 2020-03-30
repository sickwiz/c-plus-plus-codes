#include<iostream>
using namespace std;
void sq(int &k)  //passed by reference
{
    k=k*k;
}
int main()
{
    int i=10;
    int &j=i; //j is reference variable whose address is same as that of i;
    i++;
    cout<<j<<endl;
    j=100;
    cout<<i<<endl;
   /* int $k;
    k=1; 
    this is'nt a valid statement because reference variable must be initialised at the
    same time when it is declared; */
    cout<<"enter a number to square"<<endl;
    int n;
    cin>>n;
    sq(n);
    cout<<"square is->"<<n<<endl;
}