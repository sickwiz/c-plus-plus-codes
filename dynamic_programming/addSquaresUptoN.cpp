#include<bits/stdc++.h>
using namespace std;
/*Given an integer N, find and return the count of minimum numbers, 
sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : 
{1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
*/
int minCount(int n)
{
        if(n==0)
        return 0;
    if(n==1)
        return 1;
    int ans;
    int *dp=new int[n+1];
	dp[0]=0;
    dp[1]=1;
    /* from i=1 to square root of n, find the minimum of dp[n - i**i]* , 1+ the minm value =dp[n]*/
    for(int i=2;i<=n;i++)
    {
        ans=INT_MAX;
    	int sqroot=sqrt(i);
        for(int j=1;j<=sqroot;j++)
            ans=min(ans,dp[i - j*j]);
        dp[i]=1+ans;
     }
    return dp[n];
}
int main()
{
    int n;
    cout<<"\nenter the number-";
    cin>>n;
    cout<<endl<<"ans="<<minCount(n);
}