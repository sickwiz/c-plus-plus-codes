#include<bits/stdc++.h>
using namespace std;
/*Given an integer h, find the possible number of balanced binary 
trees of height h. You just need to return the count of possible
 binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).*/
int binaryTreesOfHeightH(int h)
{
    // NOTE - modulo is distributive over addition,multiplication and substraction
    // i.e (a+b)%c = ((a%c) + (b%c))%c
    // (a*b)%c = ((a%c)*(b%c))%c
	if(h==0 || h == 1)
        return 1;
    int *dp =new int[h+1];
    dp[0] = 1;
    dp[1] = 1;
    int mod = int(pow(10,9) + 7);
    for(int i = 2 ;i<=h;i++)
    {
        int temp1=int(((long)(dp[i-1])*dp[i-1])%mod);      //to avoid exceeding the limit
    int temp2 =int((2*(long)(dp[i-1])*dp[i-2])%mod);
        dp[i] = (temp1 + temp2 )%mod;
    }
    	return dp[h];
}
int main()
{
    int h;
    cout<<"enter height-";
    cin>>h;
    cout<<endl<<"no of trees possible = "<<binaryTreesOfHeightH(h)<<endl;
}