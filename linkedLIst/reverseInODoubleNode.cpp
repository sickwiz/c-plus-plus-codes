#include<iostream>
#include "linkClass.cpp"
using namespace std;
class Pair
{
    public:
    node *head;
    node *tail;
};
Pair reverse(node *head)
{
    if(head==NULL || head->next==NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
   
        Pair smallAns=reverse(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
node *reverse_better(node *head)
{
    Pair ans=reverse(head);
    head=ans.head;
    return head;
}
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
   // head=arrange_LinkedList(head);
    print(head);
    Pair ans;
    head=reverse_better(head);
    // head=ans.head;
     print(head);
    return 0;
}