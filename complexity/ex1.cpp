#include<iostream>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int count=0;
    for(int i=0;i<num;i++)
    {
        for(;i<num;i++)
        {                                  /* O(n) */
            cout<<count++<<" ";
        }
    }
}