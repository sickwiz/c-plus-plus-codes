#include<iostream>
using namespace std;
int last_index(int *input, int size,int x)
{
  if(input[size-1]==x)
       return size-1;
    if(size==1 && input[0]!=x)
        return -1;
    int ans=last_index(input,size-1,x);
    if(ans==-1)
        return -1;
    else
        return ans;
    
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
    int ind=last_index(arr,5,num);
    if(ind==-1)
    cout<<endl<<"doesn't exist"<<endl;
    else
    cout<<"element last found at->"<<ind<<endl;
}