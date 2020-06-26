#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }
    int counter=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]==0 && j==counter)
        {
            //a[counter]=0;
            //a[j]=1;
            counter++;
        }
        else if(a[j]==0)
        {
          a[counter]=0;
            a[j]=1;
            counter++;  
        }
        else
        {
            continue;
        }
        
    }
    cout<<endl;
    
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
    } 
    cout<<endl;
}
/*

0 0 0 1 1 0 1 0 1 0 0 1 1 0 0 1 0 1
*/