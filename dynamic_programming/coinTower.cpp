/*
Whis and Beerus are playing a new game today . 
They form a tower of N coins and make a move in alternate turns .
 Beerus being the God plays first . In one move player can remove 
 1 or X or Y coins from the tower . The person to make the last move wins the Game .
 */
#include<bits/stdc++.h>
using namespace std;
string solve(int n, int x, int y)
{
    /* if from nth state , there is any state from where I can loose then I will send opponent to that stage and i will win
    if there is no such state I will loose*/
    int *dp = new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i == x || i == y || i == 1)
        {
            dp[i] = 1;
            continue;
        }
        else
        {
            if(i-1 >= 0)
            {
                if(dp[i-1] == 0)   // I loose at i-1, so I will certainly win at i, same for i-x and i-y
                {
                    dp[i] = 1;
                    continue;
                }
            }
            if(i-x >= 0)
            {
                  if(dp[i-x] == 0)
                {
                    dp[i] = 1;
                    continue;
                }
            }
             if(i-y >= 0)
            {
                  if(dp[i-y] == 0)
                {
                    dp[i] = 1;
                    continue;
                }
            }
             dp[i] = 0;      // if there is no such step where I can push opponent to loose, I loose.
        }
       
    }
    if(dp[n] == 1)
        return "Beerus";
    return "Whis";
}
 
int main()
{
   int n,x,y;
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}