#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    priority_queue< int,vector<int>,greater<int> > pq;
    pq.push(100);
    pq.push(1);
    pq.push(250);
    pq.push(4);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}