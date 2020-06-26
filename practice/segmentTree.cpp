#include<iostream>
using namespace std;
int getSize(int n)
{
    if(n==0)
    return 0;
   int power=1;
   while(power<n)
   {
       power=power*2;  
   } 
   if(power%n==0)
   return n;
   else
   {
       return power;
   }
   
}
int * makeSegment(int *a,int size)
{
    int len=getSize(size);
    int dummy=len-size;
    a=new int[(2*len)-1];
    for(int i=len-1;i<len-1+size;i++)
    {
        cin>>a[i];
    }

    for(int j=len-1+size;j<len-1+size+dummy;j++)
    {
        a[j]=0; // segment tree for sum, so dummy is zero
    }
    for(int j=len-2;j>=0;j--)  //sum of elements
    {
        a[j]=a[2*j+1]+a[2*j+2];
    }
    return a;
}
int updateTree(int *a,int *lazyTree,int update,int low,int high,int start,int end,int index,int size)
{
    if(lazyTree[index]!=0)
    {
        a[index]+=lazyTree[index]*(end-start+1);
        if(2*index+1<size)
        {
            lazyTree[2*index+1]+=update;
            lazyTree[2*index+2]+=update;
        }
        lazyTree[index]=0;
        
    }
     if(low>end ||high <start)  //no overlap
    return a[index];
    if(high<end || low>start)
    {
        if(2*index+1<size)
        {
          a[index]=updateTree(a,lazyTree,update,low,high,start,(start+end)/2,2*index+1,size)+  updateTree(a,lazyTree,update,low,high,(start+end)/2+1,end,2*index+2,size);
            return a[index];
        }
    }
    else
    {
        a[index]+=update*(end-start+1);
        lazyTree[2*index+1]+=update;
        lazyTree[2*index+2]+=update;
        return a[index];
    }
    
}
int findSum(int *a,int low,int high,int start,int end,int index,int size,int *lazyTree)
{

    int dummyElement=0;
    if(index>=size)
    return dummyElement;
    
    if(lazyTree[index]!=0)
    {
        a[index]+=lazyTree[index]*(end-start+1);
        if(2*index+1<size)
        {
            lazyTree[2*index+1]+=lazyTree[index];
            lazyTree[2*index+2]+=lazyTree[index];
        }
        lazyTree[index]=0;
        
    }
    if(low>end ||high <start)  //no overlap
    return dummyElement;
    if(high<end || low>start)
    {
        return findSum(a,low,high,start,(start+end)/2,2*index+1,size,lazyTree)+findSum(a,low,high,(start+end)/2+1,end,2*index+2,size,lazyTree);
    }
    else
    {
        return a[index];
    }
    
}
int main()
{
    int n;
    cout<<"enter size of array-";
    cin>>n;
    int *a=makeSegment(a,n);
    int len=getSize(n);
    for(int i=0;i<2*len-1;i++)
    {
        cout<<a[i]<<" ";
    }
    int *lazyTree=new int[2*len-1];
    for(int i=0;i<2*len-1;i++)
    {
        lazyTree[i]=0;    // initialising lazy tree
    }
    int low ,high;
    cout<<endl<<"enter the range over which sum is to be found-";
    cin>>low>>high;
    int sum=findSum(a,low,high,0,len-1,0,2*len-1,lazyTree);
    cout<<endl<<"sum in the range="<<sum<<endl;
    int update,updateLow,updateHigh;
    cout<<"update the values by-"<<endl;
    cin>>update;
    cout<<"enter the range over which you need to update-";
    cin>>updateLow>>updateHigh;
    updateTree(a,lazyTree,update,updateLow,updateHigh,0,len-1,0,2*len-1);
    for(int j=0;j<2*len-1;j++)
    {
        cout<<lazyTree[j]<<" ";
    }
    cout<<endl;
    for(int j=0;j<2*len-1;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
}
/*
5
1 2 3 4 5
2
4 4
*/