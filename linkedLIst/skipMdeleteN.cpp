#include<iostream>
using namespace std;
#include "linkClass.cpp"
 void print(node *head)
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" "; 
            temp=temp->next;
        }
        cout<<endl;
    }
node * takeInput()
{
    cout<<endl<<"enter your numbers --> (-1 will be considered as exit)\n";
    int data;
    cin>>data;
    node *head=NULL;
    node *curr=NULL;
    while(data!=-1)
    {
        node *newnode = new node(data);
        if(head==NULL)
        {
            head=newnode;
            curr=head;
        }
        else
        {
           curr->next=newnode;
           curr=curr->next;
        }
        cin>>data;
    }
    return head;
}
node* skipMdeleteN(node  *head, int M, int N) 
{
    // Write your code here
    node *temp=head;
    int count=0;                                                                              // 10 20 30 40 50 
    if(M==0)
    {
      return NULL;
    }
    else
    {
    while(temp!=NULL)
    {
        for(int i=0;i<M-1;i++)
        {
            if(temp->next!=NULL)
                temp=temp->next;
            else
                return head;
        }
        node *temp2=temp;
        while(temp2!=NULL && count < N && temp2->next!=NULL)
        {
            temp2=temp2->next;
            temp->next=temp2->next;
            delete [] temp2;
            temp2=temp;
            count++;
        }
        count=0;
        temp=temp->next;
    }
    }
    return head;
}
int main()
{
    node *head=takeInput();
    head=skipMdeleteN(head,2,3);
    print(head);
}