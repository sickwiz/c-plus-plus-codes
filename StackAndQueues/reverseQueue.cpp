#include <queue>

void reverseQueue(queue<int> &q) 
{
	// Write your code here
    if(q.size() == 0 || q.size() == 1)
        return;
    int data=q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);
    return;
}