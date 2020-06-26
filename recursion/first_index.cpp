#include<iostream>
using namespace std;
int first_index(int *input, int size,int x)
{
  if(input[0]==x)
       return 0;
    if(size==1 && input[0]!=x)
        return -1;
    int ans=first_index(input+1,size-1,x);
    if(ans==-1)
        return -1;
    else
        return ans+1;
    
}
int main()
{
    int *arr=new int [5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    int num;
    cout<<"enter the number you want to find-";
    cin>>num;
    int ind=first_index(arr,5,num);
    if(ind==-1)
    cout<<endl<<"doesn't exist"<<endl;
    else
    cout<<"element first found at->"<<ind<<endl;
}