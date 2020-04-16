#include "BST.h"
class bst
{
private:
    binaryTreeNode<int>*root;
    binaryTreeNode<int>* insertHelp(int num,binaryTreeNode<int>*node)
    {
		if(node == NULL)
        {
            binaryTreeNode<int>*newNode=new binaryTreeNode<int>(num);
            return newNode;
        }
        if(node->data > num)
        {
            node->left=insertHelp(num,node->left);
            return node;
        }
        else
        {
            node->right=insertHelp(num,node->right);
            return node;
        }
        // return node;
    }
    bool hasDataHelp(int num, binaryTreeNode<int>*node)
    {
       // cout<<"****"<<node->data<<"***";
        if(node == NULL)
            return false;
        if(node->data == num)
            return true;
        if(node->data > num)
            return false || hasDataHelp(num,node->left);
    	else
            return false || hasDataHelp(num,node->right);
    }
    void printTreeHelp(binaryTreeNode<int>*node)
    {
        //figure out
        if(node==NULL)
            return;
        cout<<node->data<<":";
        if(node->left)
        {
            cout<<"L:"<<node->left->data<<",";
        }
        if(node->right)
        {
            cout<<"R:"<<node->right->data;
        }
        cout<<"\n";
        printTreeHelp(node->left);
        printTreeHelp(node->right);
    }
    binaryTreeNode<int>* deleteDataHelp(int num, binaryTreeNode<int>*node)
    {
        if(node==NULL)
            return node;
        if(node->data == num)
        {
            if(node->left == NULL && node->right == NULL)
            {
                delete node;
               // node=NULL;
                return NULL;
            }
            else if(node->left==NULL)
            {
                binaryTreeNode<int>* aux=node->right;
                //node->data=aux->data;
                node->right = NULL;
                 delete  node;
                return aux;
               //node->right=deleteDataHelp(num,node->right);
            }
            else if(node->right==NULL)
            {
                 binaryTreeNode<int>* aux=node->left;
                node->left = NULL;
                delete node;
                return aux;
            }
            else
            {
               binaryTreeNode<int>* rightMin=node->right;
                while(rightMin->left!=NULL)
                {
                    rightMin=rightMin->left;
                }
                int rMin=rightMin->data;
                node->data=rMin;
                node->right=deleteDataHelp(rMin,node->right);
                return node;
               }
        }
        if(node->data > num)
        {
            node->left=deleteDataHelp(num,node->left);
            return node;
        }
        else
        {
            node->right=deleteDataHelp(num,node->right);
             return node;
        }
       
    }
public:
    bst()
    {
        root = NULL;
    }
    void insert(int num)
    {
       this->root= insertHelp(num,root);
         // cout<<"***"<<root->data<<"****";
    }
    bool hasData(int num)
    {
        // cout<<"***"<<root->data<<"****";
        return hasDataHelp(num,this->root);
    }
    void printTree()
    {
        printTreeHelp(root);
    }
    void deleteData(int num)
    {
       this->root= deleteDataHelp(num,root);
    }
    ~bst()
    {
        delete root;
    }
};
int main()
{
    bst *b=new bst();
    int choice,num;
    choice=1;
    while(choice==1)
    {
        cout<<"enter the number-";
        cin>>num;
        b->insert(num);
        cout<<endl<<"press 1 to enter again-";
        cin>>choice;
    }
    b->printTree();
    cout<<endl<<"enter a number to delete-";
    cin>>num;
    b->deleteData(num);
    b->printTree();
    cout<<endl<<"search a number-";
    cin>>num;
    if(b->hasData(num))
    {
        cout<<endl<<"number exists";
    }
    else
    {
        cout<<"number not found-";
    }
    cout<<endl;
    
}