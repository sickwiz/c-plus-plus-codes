#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue <int> q;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.push(20);
    q.push(202);
    q.push(203);
    q.push(206);
    q.push(208);
    cout<<"first element is-"<<q.front()<<endl<<"*****deleting first element*****\n";
    q.pop();
    cout<<"Now first element is-"<<q.front()<<endl;
    cout<<"size of the queue= "<<q.size()<<endl;
}