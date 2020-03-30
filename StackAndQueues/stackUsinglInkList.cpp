#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
/* If we insert at tail in a link list , then pop operation of stack will become O(n).
>> Since in the case of stack , we are concerned with the last inserted element only 
>>therefore we will always insert at head. This way , we can reduce pop as well as push to O(1);
*/
class Stack
{
    node *head;
    int size;
    public:
    Stack()
    {
        head=NULL;
        size=0;
    }
    void push(int data)
    {
        if(head==NULL)
            {
                head=new node(data);
            }
        else
        {
            node *temp=new node(data);
            temp->next=head;
            head=temp;
        }
        cout<<endl<<"inserted "<<data<<endl;
        size++;
    }
    bool isEmpty()
    {
        return size==0;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"\nstack is empty!!"<<endl;
            return INT_MIN;
        }
        int temp=head->data;
        node *t=head;
        head=head->next;
        delete []t;
        size--;
        return temp;
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"\nstack is empty!!"<<endl;
            return INT_MIN;
        }
        else
        return head->data;
    }

};
int main()
{
    int len;
    cout<<"enter number of elements to be pushed-";
    cin>>len;
    Stack s1;
    cout<<"\n inserting elements randomly-";
    for(int i=0;i<=len;i++)
    {
        s1.push(rand()%100);
    }
    cout<<endl<<"//****************POPPING**********//"<<endl;
    while(!s1.isEmpty())
    {
        cout<<endl<<s1.pop()<<endl;
    }
}
