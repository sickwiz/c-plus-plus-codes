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
node * insertAtIndex(node *head, int index, int data)
{
    int count=0;
    node *temp=head;
    node *newnode = new node(data);
    if(index==0)
    {
        // node *temp1=new node(data);
       newnode->next=head;
       head=newnode;
        return head;
    }
    while(count < index-1 && temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(count!=index-1)
    {
         cout<<"\nindex not in range---\n";
         return head;
    }
    // if(count==index)
    // {
        node *temp1=temp->next;
        temp->next=new node(data);
        (temp->next)->next=temp1;
    return head;
    // }
    // else
    // {
    //     cout<<"\nindex not in range---\n";
    // }
}
node *deletenode(node *head ,int i)
{
    node *temp=head;
    if(i==0)   // when first node is to be deleted
    {
        head=head->next;
        delete [] temp;
        return head;
    }
    int count=0;
    while(count < i-1 && temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(temp->next==NULL)  //if node to be deleted is beyond the range
    {
        return head;
    }
    else
    {
        node *temp1=temp->next;
        temp->next=temp1->next;
        delete [] temp1;
        return head;
    }

}
//*********************INSERT node USING RECURSION *****************//
node* insertnodeRec(node *head, int i, int data)
 {
    if(head==NULL && i!=0)
        return head;
    if(i==0)
    {
        node *temp = new node(data);
        temp->next=head;
        return temp;
    }
    else
    {
        head->next=insertnodeRec(head->next,i-1,data);
    }
    return head;
    
}
//**********************************************//
//*************DELETE node USING RECURSION *****************//

node* deletenodeRec(node *head, int i) 
{
    if(head==NULL)
    {
        return head;
    }
    if(i==0)
    {
        node *temp=head;
        head=head->next;
        delete [] temp;
        return head;
    }
    else
    {
        head->next=deletenodeRec(head->next,i-1);
    }
    return head;
}
//***************PRINT REVERSE LINKED LIST *****************/////////
void printReverse(node*head)
{
    //write your code here
    if(head==NULL)
        return;
    printReverse(head->next);
    cout<<head->data<<" ";
}
//***************MID-POINT OF LINK LIST***********//

node* midpoint_linkedlist(node *head)
{
    // Write your code here
   node *mid=head;
   node *tail=head->next;
   while(tail!=NULL && tail->next!=NULL)
   {
       mid=mid->next;
       tail=tail->next->next;
   }
   return mid;
}
// *******************MERGE TWO SORTED LINK LIST *************//
node* mergeTwoLLs(node *head1, node *head2) {       
    node *fhead=NULL;
    node *ftail=NULL;
    node *temp1=head1;
    node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data <= temp2->data)
        {
            if(fhead==NULL)
            {
                fhead=temp1;
                ftail=temp1;
            }                                            //2                                     fhead->2
            else                                          //3                      
            {
                ftail->next= temp1;
                ftail=ftail->next;
            }
            temp1=temp1->next;
        }
        else
        {
            if(fhead==NULL)
            {
                fhead=temp2;
                ftail=temp2;
              
            }
            else
                
            {
           
                ftail->next=temp2;
                ftail=ftail->next; 
            }
            temp2=temp2->next; 
        }
    }
    
    while(temp1!=NULL)
    {
      
        ftail->next=temp1;
        ftail=ftail->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    { 
    
        ftail->next=temp2;
        ftail=ftail->next; 
        temp2=temp2->next;
    }
    return fhead;
}

//**************************************************************************//
int main()
{
  int choice;
  cout<<"enter 1 to create a link list-";
  cin>>choice;
  node *head=NULL;
  if(choice==1)
  {
      head=takeInput();
  }
  else
    cout<<endl<<"O.K"<<endl;
   print(head);
//    cout<<"\n enter 1 to delete element-";
//    cin>>choice;
//    if(choice==1)
//    {
//        cout<<"\nenter index-";
//        cin>>choice;
//        head=deletenode(head,choice);
//    }
   node *mid=midpoint_linkedlist(head);
    cout<<"mid="<<mid->data<<endl;
//    cout<<"enter 2 to insert node at particular index -"<<endl;
//    cin>>choice;
//     if(choice==2)
//   {
//      int index;
//      cout<<"enter the number to be inserted-";
//      cin>>choice;
//      cout<<"\n enter the index -\n";
//      cin>>index;
//      head=insertAtIndex(head,index,choice);
//   }
//   else
//     cout<<endl<<"O.K"<<endl;
//     print(head);
}





