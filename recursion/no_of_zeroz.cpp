#include<iostream>
using namespace std;
int countZeros(int n) {
    // Write your code here
 if(n==0)
     return 1;
    if(n<10)
        return 0;
    int ans=0;
    if(n%10==0)
        ans+=1;
    ans+=countZeros(n/10);
    return ans;
    
}
int main()
{
    int n;
    cin>>n;
    int ans=countZeros(n);
    cout<<ans<<endl;
}