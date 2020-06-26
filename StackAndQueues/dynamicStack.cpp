#include<bits/stdc++.h>
using namespace std;
class dynamicStack
{
    int *array;
    int nextIndex;
    int capacity;
    //********DATA MEMBERS ARE KEPT PRIVATE SO THAT THEY CAN BE ACCESSED THROUGH MEMNRE FUNCTIONS ONLY*********//
    public:
    dynamicStack()
    {
        array=new int[5];
        nextIndex=0;
        capacity=5;
    }
    bool isEmpty()      
    {
        // if(nextIndex==0)
        //     return true;
        // else
        //     return false;
        return nextIndex==0;
    }
    bool isFull()
    {
        return nextIndex==capacity;
    }
    //************double the capacity when stack is full *************************//
    void doubleCapacity()
    {
        int *temp=new int[2*capacity];
        for(int i=0;i<capacity;i++)
        {
            temp[i]=array[i];
        }
        delete []array;
        array=temp;
        capacity*=2;
    }
    //**************INSERTION***************//
    void push(int data)        
    {
        if(isFull())
        {
            doubleCapacity();
             array[nextIndex++]=data;
                cout<<"\ninserted "<<data<<" at "<<nextIndex-1<<endl;
            return;
        }
        else
            {
                array[nextIndex++]=data;
                cout<<"\ninserted "<<data<<" at "<<nextIndex-1<<endl;
                return;
            }
    }
    //**************DELETION**************//
    int pop()
    {
        if(isEmpty())
        {
            cout<<endl<<"stack is empty "<<endl;
            return INT_MAX;
        }
        else
        {
            return array[--nextIndex];
        }
    }
    //**********DISPLAYING THE TOP ELEMENT **********//
    int top()
    {
        if(isEmpty())
        {
            cout<<"\nstack is empty \n";
            return INT_MAX;
        }
        else
            return array[nextIndex-1];
    }
};
int main()
{
    int len;
    cout<<"enter number of elements to be pushed-";
    cin>>len;
    dynamicStack s1;
    cout<<"\n inserting elements randomly-";
    for(int i=0;i<=len;i++)
    {
        s1.push(rand()%100);
    }
    //cout<<s1.top();
    cout<<"\n********popping*********\n";
    for(int i=0;i<=len;i++)
    {
        cout<<s1.pop()<<endl;
    }
}