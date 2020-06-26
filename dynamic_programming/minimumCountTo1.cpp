#include<bits/stdc++.h>
using namespace std;
int minmSteps(int n)
{
    if(n == 1)
        return 0;
    int ans1=minmSteps(n-1);
    int ans2=INT_MAX;
    int ans3=INT_MAX;
    if(n%2 == 0)
        ans2 = minmSteps(n/2);
    if(n%3 == 0)
        ans3 = minmSteps(n/3);
    return 1 + min(min(ans1,ans2),ans3);
    // return ans+1;
}
int main()
{
    int n;
    cout<<"\nenter the number-";
    cin>>n;
    cout<<endl<<"minimum  number of steps from "<<n<<" to 1 = "<<minmSteps(n);
}