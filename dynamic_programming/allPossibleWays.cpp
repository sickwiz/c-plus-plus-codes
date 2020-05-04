/*
Given two integers a and b. You need to find and return the count of possible ways
in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -

10 = 1^2 + 3^2 
*/
#include <iostream>
#include<cmath>
using namespace std;

int allWaysHelp(int start , int x ,int n)
{
	if(x == 0)
        {
        return 1;
    	}
     if(start > x)
        return 0;
    if(x < 0)
        return 0;
    int num = pow(start,n);
    int ans1 = allWaysHelp(start+1,x-num,n);
    int ans2 = allWaysHelp(start+1,x,n);
    return ans1 + ans2;
}
int allWays(int x, int n)
{
 	return allWaysHelp(1,x,n);
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
