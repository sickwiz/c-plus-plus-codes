#include<iostream>
using namespace std;
int arr_sum(int *arr,int len)
{
    if(len==0)
        return 0;
    if (len==1)
        return arr[0];
    else
    {
        return arr[0]+arr_sum(arr+1,len-1);
    }
    
}
int main()
{
    int *arr=new int[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    cout<<arr_sum(arr,5)<<endl;
}