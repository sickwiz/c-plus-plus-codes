#include<iostream>
using namespace std;
int power(int x,int n)
{
    if(n==0)
    return 1;
    if(n==1)
    return x;
    else
    {
        return x*power(x,n-1);
    }
    
}
int main()
{
    int x;
    int n;
    cin>>x;
    cin>>n;
    int ans=power(x,n);
    cout<<x<<"^"<<n<<"="<<ans<<endl;
}