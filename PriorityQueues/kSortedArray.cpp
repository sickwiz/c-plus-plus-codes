#include<queue>
#include<iostream>
using namespace std;
// K SORTED ARRAY IS AN ARRAY IN WHICH CORRECT POSITION OF 
//ELEMENT AT INDEX "I" LIES IN THE RANGE "I+K-1 to I-K-1"
// be careful with the input
//complexity is (n+k)log(k) , if k <<< n , complexity ~ nlog(k) ~ O(n);
void Ksort(int *arr,int len ,int k)
{
    priority_queue<int> pq;
    int i;
    for(i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    int count=0;
    while(!pq.empty())
    {
        arr[count++] = pq.top();
        pq.pop();
        if(i < len)
           pq.push(arr[i++]);
    }

}
int main()
{
    int len;
    cout<<"\nenter length of the array-";
    cin>>len;
    int *arr=new int[len];
    for(int i = 0 ;i < len;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<endl<<"enter the value of k -";
    cin>>k;
    Ksort(arr,len,k);
    for(int i =0 ;i<len;i++)
        cout<<arr[i]<<" ";

}
//sample input
//100 99 64 31 18