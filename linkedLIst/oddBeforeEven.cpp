#include<iostream>
#include "linkClass.cpp"
using namespace std;

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node *insert(node *head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return head;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new node(data);
   // print(head);
    return head;
}

node* arrange_LinkedList(node* head)
{
    //write your code here
    node *temp=head;
    node *evenHead=NULL;
    node *oddHead=NULL;
    while(temp!=NULL)
    {
        if((temp->data)%2==0)
        {
            evenHead=insert(evenHead,temp->data);
        }
        else
            oddHead=insert(oddHead,temp->data);
        temp=temp->next;
    }
     if(oddHead == NULL)
        return evenHead;
   node *oddTail=oddHead;
   while(oddTail->next!=NULL)
   {
       oddTail=oddTail->next;
   }
   oddTail->next=evenHead;
    // print(oddHead);
    //  print(evenHead);
    return oddHead;
}
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}