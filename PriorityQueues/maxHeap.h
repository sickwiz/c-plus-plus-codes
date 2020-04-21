#include<bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int>*pq;
public:
    PriorityQueue()
    {
        pq=new vector<int>();
    }
    int getSize()
    {
        return pq->size();
    }
    bool isEmpty()
    {
        return pq->size() == 0;
    }
    int getMax()
    {
        if(isEmpty())
            return 0;
        return pq->at(0);
    }
    void swapValue(int index1,int index2)
    {
        int temp = pq->at(index1);
        pq->at(index1) = pq->at(index2);
        pq->at(index2) = temp;
        return;
    }
    void downHeapify(int index)
    {
        int s = pq->size();
        if(index >= s)
            return;
        int maxIndex = index;
        int lChild = (2*index)+1;
        int rChild = (2*index)+2;
        int maxValue = pq->at(index);
        if(lChild < s && rChild < s)
        {
            if(pq->at(lChild) > pq->at(rChild))
            {
                maxIndex = lChild;
                maxValue = pq->at(lChild);
            }
            else
            {
                maxIndex = rChild;
                maxValue = pq->at(rChild);
            }
            
        }
        else if(lChild < s && rChild >=s)
        {
            maxIndex = lChild;
                maxValue = pq->at(lChild); 
        }
        else if(rChild <s && lChild >=s)
        {
            maxIndex = rChild;
                maxValue = pq->at(rChild);
        }
        if(maxIndex != index)
        {
            if(maxValue > pq->at(index))
            {
                swapValue(maxIndex,index);
            downHeapify(maxIndex);
            }
            else
                return;
        }
        else
            return;
        
    }
    void upHeapify(int index)
    {
        if(index == 0)
            return;
        int parentIndex = (index-1)/2;
        if(pq->at(parentIndex) < pq->at(index))
        {
            swapValue(parentIndex,index);
            upHeapify(parentIndex); 
        }
        else
            return;
    }
    void insert(int num)
    {
        pq->push_back(num);
        upHeapify(pq->size()-1);
    }
    int removeMax()
    {
        if(isEmpty())
            return 0;
        int maxValue = pq->at(0);
        pq->at(0) = pq->at(pq->size() - 1);
        pq->pop_back();
        downHeapify(0);
        return maxValue;
    }
    void print()
    {
        for(int i=0; i < pq->size(); i++)
        {
            cout<<pq->at(i)<<" ";
        }
        cout<<endl;

    }
};