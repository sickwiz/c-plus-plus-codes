// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
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
node* mergeSort(node *head) 
{
    //write your code here
    if(head->next==NULL)
        return head;
    node *mid=midpoint_linkedlist(head);
    node *head2=mid->next;
    mid->next=NULL;
    node *lHead=mergeSort(head);
    node *rHead=mergeSort(head2);
    node *fhead=mergeTwoLLs(lHead,rHead);
    return fhead;
}



















