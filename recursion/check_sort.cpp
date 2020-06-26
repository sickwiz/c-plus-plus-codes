#include<iostream>
using namespace std;
bool check_sort(int *a,int len)
{
if(len==0||len==1)
    return true;
if(a[0]<a[1])
{
    check_sort(a+1,len-1);
}
else
{
    return false;
}

}
int main()
{
    int *arr=new int [5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    if(check_sort(arr,5))
    {
        cout<<endl<<"sorted";
    }
    else
    {
        cout<<endl<<"unsorted";
    }
    
}