#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template<typename T>
class Queue {
    
    Node <T> *head;
    Node <T> *tail;
    int size;
    public :
    
    
    Queue() 
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    void enqueue(T data) 
    {
        Node <T> *newNode=new Node <T>(data);
        if(head==NULL)
        {
            head=newNode;
            tail=head;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        size++;
    }
    
    int getSize() 
    {
        return size;
    }
    
    bool isEmpty() 
    {    
        return size==0;
    }
    
    T dequeue() 
    {
        // Return 0 if queue is empty
        if(isEmpty())
            return 0;
        T data=head->data;
        Node <T> *temp=head;
        head=head->next;
        delete [] temp;
        size--;
        return data;
    }
    

    T front()  
    {
        // Return 0 if queue is empty
         if(isEmpty())
            return 0;
        return head->data;
    }
};

//***********MAIN***********//

