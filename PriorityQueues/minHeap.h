#include<bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> *pq;
    public:
    PriorityQueue()
    {
        pq=new vector<int>();
    }
    bool isEmpty()
    {
        return pq->size() == 0;
    }
    int getSize()
    {
        return pq->size();
    }
    int getMin()
    {
        if(isEmpty())
            return 0;
        return pq->at(0);
    }
    void upHeapify(int index)
    {
        if(index == 0 )
            return;
        int parentIndex = (index - 1)/2;
        if(pq->at(index) < pq->at(parentIndex))
        {
            int temp = pq->at(index);
            pq->at(index) = pq->at(parentIndex);
            pq->at(parentIndex) = temp;
            upHeapify(parentIndex);
        }
        else
            return;
    }
    void downHeapify(int index)
    {
        int lChild = (2*index)+1;
        int rChild = (2*index)+2;
        int s = pq->size();
        if(lChild >= s && rChild >=s)
            return;
        int currData = pq->at(index);
        int minIndex = index;
        int minValue = currData;
        if(lChild < s && rChild >=s)
        {
            minIndex = lChild;
        }
        else if(lChild >= s && rChild < s)
        {
            minIndex = rChild;
        }
        else
        {
            if(pq->at(lChild) < pq->at(rChild))
            {
                minIndex = lChild;
                minValue = pq->at(lChild);
            }
            else
            {
                minIndex = rChild;
                minValue = pq->at(rChild);
            }
            
        }
        if(currData > minValue)
        {
            pq->at(index) = minValue;
            pq->at(minIndex) = currData;
            downHeapify(minIndex);
        }
        else
            return;
        
        
    }
    void insert(int num)
    {
        pq->push_back(num);
        upHeapify(pq->size()-1);
    }
    int removeMin()
    {
        int m = pq->at(0);
        pq->at(0)=pq->at(pq->size()-1);
        pq->pop_back();
        downHeapify(0);
        return m;
    }
    void print()
    {
        cout<<endl<<"printing level wise-\n";
        for(int i=0; i < pq->size();i++)
        {
            cout<<pq->at(i)<<endl;
        }
    }
};