#include<bits/stdc++.h>
using namespace std;
class stackUsingArray
{
    int *array;
    int nextIndex;
    int capacity;
    //********DATA MEMBERS ARE KEPT PRIVATE SO THAT THEY CAN BE ACCESSED THROUGH MEMNRE FUNCTIONS ONLY*********//
    public:
    stackUsingArray(int length)
    {
        array=new int[length];
        nextIndex=0;
        capacity=length;
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
    //**************INSERTION***************//
    void push(int data)        
    {
        if(isFull())
        {
            cout<<"stack is full\n";
            return;
        }
        else
            {
                array[nextIndex++]=data;
                cout<<"\ninserted "<<data<<" at "<<nextIndex-1<<endl;
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
    cout<<"enter size of the stack-";
    cin>>len;
    stackUsingArray s1(len);
    cout<<"\n inserting elements randomly-";
    for(int i=0;i<=len;i++)
    {
        s1.push(i);
    }
}