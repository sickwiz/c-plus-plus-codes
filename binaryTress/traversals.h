#include<queue>
#include<iostream>
#include<stack>
using namespace std;
void preOrder(binaryTreeNode<int> *root)
{
	if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//*******************************************//
void postOrder(binaryTreeNode<int> *root) 
{
    if(root==NULL)
        return;
    postOrder(root->left);
   
    postOrder(root->right);
     cout<<root->data<<" ";
    return;
}
//***************INORDER******************//
void inOrder(binaryTreeNode<int>*root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//*********************************PRINT LEVELWISE********************//
void printLevelWise(binaryTreeNode<int> *root)
{
    if(root == NULL)
        return;
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
       binaryTreeNode<int>*curr=pendingNodes.front();
        cout<<curr->data<<":";
    if(curr->left)
    {
        cout<<"L:"<<curr->left->data<<",";
        pendingNodes.push(curr->left);
    }
    else
    {
       cout<<"L:"<<-1<<",";  
    }
    if(curr->right)
    {
        cout<<"R:"<<curr->right->data;
        pendingNodes.push(curr->right);
    }  
    else
    {
         cout<<"R:"<<-1;
    }
        pendingNodes.pop();
        cout<<"\n";
    }

}
//***********************PRINT ZIG-ZAG*************************//
void zigZagOrder(binaryTreeNode<int> *root)
{
	// Write your code here
    if (!root) 
        return; 
 
    stack<binaryTreeNode<int>*> currentlevel; 
    stack<binaryTreeNode<int>*> nextlevel; 
  
    currentlevel.push(root); 
  
    // check if stack is empty    
    bool lefttoright = true; 
    while (!currentlevel.empty()) 
    { 
  
        binaryTreeNode<int>* temp = currentlevel.top(); 
        currentlevel.pop(); 
  
        // if not null 
        if (temp) { 
 
            cout << temp->data << " "; 
  
            // store data according to current 
            // order. 
            if (lefttoright) { 
                if (temp->left) 
                    nextlevel.push(temp->left); 
                if (temp->right) 
                    nextlevel.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    nextlevel.push(temp->right); 
                if (temp->left) 
                    nextlevel.push(temp->left); 
            } 
        } 
  
        if (currentlevel.empty()) 
        { cout<<"\n";
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
        } 
    } 
}
