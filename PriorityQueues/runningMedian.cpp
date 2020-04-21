#include<bits/stdc++.h>
using namespace std;
void balanceHeap(priority_queue<int>* maxHeap,priority_queue<int,vector<int>,greater<int>>* minHeap)
{
    int a = maxHeap->size();
    int b = minHeap->size();
    // size() function returns unsigned integer , that's they have been explicitly declared as integers
    if(a-b > 1)
    {
        int t = maxHeap->top();
        maxHeap->pop();
        minHeap->push(t);
        return;
    }
    if(b - a > 1)
    {
        int t=minHeap->top();
        minHeap->pop();
        maxHeap->push(t);
        return;
    }
}
void findMedian(int arr[], int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    maxHeap.push(arr[0]);
    cout<<arr[0]<<endl;
    for(int i=1;i<n;i++)
    {
        if(arr[i] < maxHeap.top())
        {
            maxHeap.push(arr[i]);
        }
        else
            minHeap.push(arr[i]);
       balanceHeap(&maxHeap , &minHeap);
     if(maxHeap.size() == minHeap.size())
            {
                int s = maxHeap.top() + minHeap.top();
                cout<<s/2<<endl;
            }
        else if(maxHeap.size() > minHeap.size())
                cout<<maxHeap.top()<<endl;
        else
            cout<<minHeap.top()<<endl;
        
    }
}
int main()
{
    int len;
    cin>>len;
    int *a = new int[len];
    for(int i=0;i<len;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    findMedian(a,len);
// we will maintain two priority queues (min and max) 
// max will contain half of the elements which will be smaller than the other half at any instant
// if size of both queues are equal , the avearge of top from both queues will be the mean.
//make sure difference od size is not more than |1|.
// else top of bigger queue will be the median.
//dry run for better understanding
}
//6
// 6 2 1 3 7 5