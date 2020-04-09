#include<iostream>
#include "binaryTreeNode.h"
#include "traversals.h"
#include<queue>
#include<bits/stdc++.h>
using namespace std;
//**************input root-left-right********************//
binaryTreeNode<int> *takeInput()
{
    int rootData;
    cout<<"\n enter root data-";
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    binaryTreeNode<int> *root=new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>*leftChild=takeInput();
    binaryTreeNode<int>*rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}
//********************print root -left - right**********************//
void print(binaryTreeNode<int>*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left != NULL)
        cout<<"L->"<<root->left->data ;
    if(root->right!=NULL)
        cout<<"R->"<<root->right->data;
    cout<<endl;
    print(root->left);
    print(root->right);
}
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
//***********************no of nodes***********************************//
int numNodes(binaryTreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    int ans=1;
    ans += numNodes(root->right) + numNodes(root->left);
    return ans;
}
//******************find a node ***********************//
bool isNodePresent(binaryTreeNode<int>* root, int x) 
{
	if (root==NULL)
        return false;
    if(root->data == x)
        return true;
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}
//**************************mirror a tree**********************************//
void mirrorBinaryTree(binaryTreeNode<int>* root)
{
    // Write your code here
	if(root==NULL)
        return;
    binaryTreeNode<int>*left=root->left;
   	root->left=root->right;
    root->right=left;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
////*************************height*************************//
int height(binaryTreeNode<int> *root)
{
	if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

//***************DIAMETER - MAXIMUM DISTANCE BETWEEN AnY TWO NODES OF A TREE***************************************//

pair<int,int> heightDiameter(binaryTreeNode<int> *root)
{
    pair<int,int> ans;
    if(root==NULL)
    {
        ans.first=0;  //height
        ans.second=0;  //diameter
        return ans;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int>rightAns=heightDiameter(root->right);
    int height=1+max(leftAns.first,rightAns.first);
    int lheight=leftAns.first;
    int rheight=rightAns.first;
    int ldiameter=leftAns.second;
    int rdiameter=rightAns.second;
    ans.first=height;
    ans.second=max(lheight+rheight,max(ldiameter,rdiameter ));
    return ans;
}
//******************************check balanced tree**************//
bool isBalanced(binaryTreeNode<int> *root)
{
    // Write your code here
    if(root==NULL)
        return true;
    int l=height(root->left);
    int r = height(root->right);
    
    if( l==r || abs(l-r)==1)
        return true && isBalanced(root->left) && isBalanced(root->right);
    else
        return false;

}
//**************************************************************************//
int  main()
{
    cout<<"*********************";
    cout<<"-1 stands for null input*******\n";
    // binaryTreeNode<int> *root=takeInput();
    binaryTreeNode<int> *root=takeLevelInput();
    cout<<endl;
    printLevelWise(root);
    /*DIAMETER CHECK
    */
   cout<<"\ndiameter = "<<heightDiameter(root).second<<endl;
    /*//to check total no of nodes
     cout<<"\ntotal number of nodes = "<<numNodes(root)<<endl;
    */
   /*
   //to search a number
    int num;
    cout<<"\nenter the number you want to search-";
    cin>>num;
    if(isNodePresent(root,num))
    {
        cout<<endl<<"present\n";
    }
    else
        cout<<"\n not present \n";
    */
   /*
   //to check mirroring of a tree
   mirrorBinaryTree(root);
   cout<<"\n***TREE IS MIRRORED****\n";
   printLevelWise(root);
   */
}
/*
test tree
input - 1 2 4 -1 -1 -1 3 -1 6 -1 -1   (for root-left-right)
input - 1 2 3 4 -1 -1 6 -1 -1 -1 -1   (for level order)
                    1
                   / \
                  2   3
                 /     \
                4       6
*/
//TODO - UPLAOD MATHS