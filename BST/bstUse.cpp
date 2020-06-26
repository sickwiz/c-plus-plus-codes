#include<bits/stdc++.h>
#include<queue>
#include "BST.h"
using namespace std;

//******************input level wise**************************//
binaryTreeNode<int>* takeLevelInput()
{
    queue<binaryTreeNode<int>*> pendingNodes;
     int rootData;
    cout<<"\n enter levelwise - \n";
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    binaryTreeNode<int>*root=new binaryTreeNode<int>(rootData);
     binaryTreeNode<int>*leftChild;
      binaryTreeNode<int>*rightChild;
    pendingNodes.push(root);
    binaryTreeNode<int>* current;
    while(!pendingNodes.empty())
    {
        current=pendingNodes.front();
        cin>>rootData;
        if(rootData!=-1)
        {
            leftChild=new binaryTreeNode<int>(rootData);
            current->left=leftChild;
            pendingNodes.push(leftChild);
        }
         cin>>rootData;
        if(rootData!=-1)
        {
            rightChild=new binaryTreeNode<int>(rootData);
            current->right=rightChild;
            pendingNodes.push(rightChild);
        }
         pendingNodes.pop();   
    }
    return root;
}
//******************traversal******************************//
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
//*****************check bst*********************//
bool checkBST(binaryTreeNode<int> * root,int minm,int maxm)
{
    if(root==NULL)
        return true;
    if(root->data < minm || root->data >maxm)
        return false;
    return checkBST(root->left,minm,root->data) && checkBST(root->right,root->data,maxm);
}
//*************find path*******************//
vector<int> findPath(binaryTreeNode<int>*root,int target)
{
    vector<int>a;
    if(root==NULL)
        return a;
    if(root->data == target)
    {
        vector<int> output;
        output.push_back(root->data);
        return output;
    }
    if(root->data > target)
    {
       vector<int> leftOutput=findPath(root->left,target);
       if(leftOutput.size()!=0)
        {    leftOutput.push_back(root->data);
        
        }
    }
    else
    {
        vector<int>rightOutput=findPath(root->right,target);
        if(rightOutput.size()!=0)
            {
                rightOutput.push_back(root->data);
                return rightOutput;
            }
        else
            return a;
    }
    
}
int main()
{
    binaryTreeNode<int>* root=takeLevelInput();
    printLevelWise(root);
     /*check for bst
    if(checkBST(root,INT_MIN,INT_MAX))
        {
            cout<<endl<<"tree is bst\n";
        }
    else
    {
    cout<<endl<<"tree is'nt bst\n";
    }
    */  
/*find path
   vector<int>path=findPath(root,97);
   if(path.size()==0)
    cout<<"\n no path found\n";
    else
    {
        for(int i=path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<"->";
        }
    }
    cout<<endl;
*/

}
//test binary tree
// 5 2 6 1 3 -1 7 -1 -1 -1 -1 -1 -1