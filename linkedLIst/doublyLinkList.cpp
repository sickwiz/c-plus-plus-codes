#include <iostream>
using namespace std;

//***************PENDING DELETION  ******************//
class doubleLL
{
    public:
    int data;
    doubleLL *next;
    doubleLL *prev;
    doubleLL(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
doubleLL *insert(doubleLL *head,int data)
{
     if (head==NULL)
    return head;
    doubleLL *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new doubleLL(data);
        (temp->next)->prev=temp;
    return head;
}
doubleLL *insertAtIth(doubleLL *head,int data,int index)
{
    doubleLL *temp;
    doubleLL *temp2;
    if(index==0)
    {
        temp=new doubleLL(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
        return head;
    }
    temp=head;
    int count=0;
    while(temp->next!=NULL && count < index-1)
    {
        temp=temp->next;                                // 10 20 30 40  
        count++;
    }
    if(temp->next == NULL)
    {
        if(count==index-1)
        {
            temp2=new doubleLL(data);
        temp2->prev=temp;
        temp->next=temp2;
        return head;
        }
        else
        {
            cout<<"\nindex not in range\n";
            return head;
        }
    }
    temp2=new doubleLL(data);
    temp2->next=temp->next;
    (temp->next)->prev=temp2;
    temp2->prev=temp;
    temp->next=temp2;
    return head;
}
void print(doubleLL *head)
{
    doubleLL *temp=head;
    cout<<"\nPrinting forward----\n";
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<"\nprinting backwards-----\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
// doubleLL * deleteNode(doubleLL *head,int index)
// {
//     if(index==0)
//     {
//         (head->next)->prev=NULL;
//         doubleLL *temp=head;
//         head=head->next;
//         delete [] temp;
//         return head;
//     }
// }
int main()
{
    doubleLL *head = new doubleLL(10);
    head=insert(head,22);
    head=insert(head,24);
    head=insert(head,25);
    head=insert(head,232);
    head=insert(head,27);
    head=insert(head,290);
    print(head);
    // **********for checking insertion at ith index************//
    /*int ind;
    int data;
    cout<<endl<<"enter the index where you want to insert a number-";
    cin>>ind;
    cout<<endl<<"enter data-";
    cin>>data;
    head=insertAtIth(head,data,ind);
     print(head);*/
    //*****************************************************************//
    head=deleteNode(head,0);
     print(head);
}