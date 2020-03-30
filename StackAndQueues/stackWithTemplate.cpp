#include<bits/stdc++.h>
using namespace std;
template <typename T>
class stackUsingArray
{
    T *array;
    int nextIndex;
    int capacity;
    //********DATA MEMBERS ARE KEPT PRIVATE SO THAT THEY CAN BE ACCESSED THROUGH MEMNRE FUNCTIONS ONLY*********//
    public:
    stackUsingArray(int length)
    {
        array=new T[length];
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
    void push(T data)        
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
    T pop()
    {
        if(isEmpty())
        {
            cout<<endl<<"stack is empty "<<endl;
            return 0;
        }
        else
        {
            return array[--nextIndex];
        }
    }
    //**********DISPLAYING THE TOP ELEMENT **********//
    T top()
    {
        if(isEmpty())
        {
            cout<<"\nstack is empty \n";
            return 0;
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
    stackUsingArray <char> s1(len);
    cout<<"\n inserting elements randomly-";
    for(int i=100;i<=100+len;i++)
    {
        s1.push(i);
    }
    //***********popping elements***********//
    for(int i=100;i<=100+len;i++)
    {
        s1.pop();
    }
}