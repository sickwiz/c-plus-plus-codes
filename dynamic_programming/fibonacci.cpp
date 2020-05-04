#include<iostream>
using namespace std;
long double fibHelper(int n,long double *a)
{
    if(n == 0)
      return 0;
    if(n == 1)
        return 1;
    long double ans1,ans2;
    if(a[n-1] != -1)
        ans1=a[n-1];   // if answer exists
    else
        ans1=fibHelper(n-1,a);
    if(a[n-2]!= -1)
        ans2=a[n-2];
    else
        ans2 = fibHelper(n-2,a);
    a[n] = ans1+ans2;   //save the answer for nth recursion call for future reference
    return a[n];  
}
long double fib(int n)
{
    long double *a=new long double[n+1]; // we need to store values from 0 to n;
    for(int i=0;i<=n;i++)
    {
        a[i]=-1;
    }
    return fibHelper(n,a);
}
long double iterative_fib(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    if(n == 1)
        return 1;
    long double *a=new long double[n+1];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
/*
long int fib(int n)
{
    if(n==0 || n==1)
        return 1;
    long int ans = fib(n-1)+fib(n-2);
    return ans;
}*/
int main()
{
    int n;
    cout<<"\nenter the number-";
    cin>>n;
    cout<<endl<<n<<"th fibonacci by dp = "<<iterative_fib(n)<<endl;
    cout<<endl<<n<<"th fibonacci by memorization = "<<fib(n)<<endl;

}