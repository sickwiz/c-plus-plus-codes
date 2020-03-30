#include<iostream>
using namespace std;
void toh(int n,char source,char auxi,char dest)
{
    if(n==0)
    return;
    if(n==1)
    {
        cout<<source<<" "<<dest<<endl;
        return;
    }
    toh(n-1,source,dest,auxi);
    cout<<source<<" "<<dest<<endl;
    toh(n-1,auxi,source,dest);
    //cout<<endl<<auxi<<" "<<dest;
}
int main()
{
    toh(3,'a','b','c');
    cout<<endl;
}