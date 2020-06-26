#include<queue>
#include<iostream>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int num;
    for(int i = 0 ;i < 5;i++)
    {
        cin>>num;
        pq.push(num);
    }
    cout<<endl;
    cout<<"size="<<pq.size()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}