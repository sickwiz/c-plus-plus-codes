#include<bits/stdc++.h>
using namespace std;
class Queue
{
    int *array;
    int capacity;
    int size;
    int first;
    int last;
    public:
    //****by default we are making a circular queue to avoid wastage of space***********//
    Queue()
    {
        capacity = 4;
        array= new int[5];
        size=0;
        first=-1;
        last=-1;
    }
    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==capacity;
    }
    void doubleQueue()
    {
        int f=first;
        int *newArray=new int[2*capacity];
        for(int i=0;i<capacity;i++)
        {
            newArray[i]=array[f];
            f=(f+1)%capacity;
        }
        first=0;
        last=capacity-1;
        delete[] array;
        array=newArray;
        capacity*=2;
    }
    void enqueue(int data)
    {
        if(isFull())
        {
           doubleQueue();
        }
        if(first==-1 && last ==-1)
        {
            array[0]=data;
            first=0;
            last=0;
             cout<<"\ninserted "<<data<<" at "<<0<<endl;
             size++;
             return;
        }
        array[(last+1)%capacity]=data;
        size++;
        last=(last+1)%capacity;
        cout<<"\ninserted "<<data<<" at "<<last<<endl;
        
        return;
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue is empty\n";
            return INT_MIN;
        }
        int t=array[first];
        first=(first+1)%capacity;
        size--;
        return t;
    }
    int front()
    {
        if(isEmpty())
        {
            cout<<endl<<"queue is empty"<<endl;
            return 0;
        }
        return array[first];
    }
};
int main()
{
    int len;
    cout<<"\nenter the number of elements to be inserted-\n";
    cin>>len;
    Queue q1;
    cout<<endl<<"********inserting elements randomly*********"<<endl;
    for(int i=0;i<=len;i++)
    {
        q1.enqueue(rand()%100);
    }
    cout<<endl<<"********deleting two elements  *********"<<endl;
     for(int i=0;i<2;i++)
    {
        cout<<endl<<"deleted "<<q1.dequeue();
    }
    cout<<"\n element at front is - "<<q1.front()<<endl;
    //  cout<<endl<<"********inserting elements randomly again*********"<<endl;
    // for(int i=0;i<=len;i++)
    // {
    //     q1.enqueue(rand()%100);
    // }
    // cout<<endl<<"********inserting elements randomly*********"<<endl;
    // for(int i=0;i<=len;i++)
    // {
    //     q1.enqueue(rand()%100);
    // }
    // cout<<"\n element at front is - "<<q1.front()<<endl;
}