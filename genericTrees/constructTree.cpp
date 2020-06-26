#include<iostream>
#include<queue>
#include "treeNode.h"
#include "traversals.h"

//**********************************************************//

treeNode<int> * takeInputLevelWise()
{
    queue<treeNode<int> *> remainingChild;
    int rootData;
    cout<<endl<<"enter root data-";
    cin>>rootData;
    treeNode<int> * root=new treeNode<int> (rootData);
    remainingChild.push(root);
    while(!remainingChild.empty())
    {
        int no;
        treeNode<int>* first= remainingChild.front();
        cout<<"\nenter no of children for "<<first->data<<"-";
        cin>>no;
        for(int i=0 ;i<no;i++)
        {
            cout<<"\nenter value for child "<<i<<"-";
            cin>>rootData;
             treeNode<int> * child=new treeNode<int> (rootData);
             first->children.push_back(child);   // pushing children
             remainingChild.push(child);          // pushing nodes whose children are yet to be decided
        }
        remainingChild.pop();
    }
    return root;
}

//******************************************************************************************//

treeNode<int> * takeInput()
{
    int rootData;
    cout<<endl<<"enter root data-";
    cin>>rootData;
    treeNode<int> * root=new treeNode<int> (rootData);
    int no;
    cout<<"\nenter number of children for "<<rootData<<"-";
    cin>>no;
    for(int i=0;i<no;i++)
    {
        treeNode<int> *children = takeInput();
        root->children.push_back(children);
    }
    return root;
}

//**********************************************************************************//

void printTree(treeNode<int> *root)
{
    if(root==NULL)
        return;
    treeNode<int> *temp=root;
    cout<<root->data<<": ";
    for(int i=0;i< root->children.size();i++)
    {
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
    for(int i=0;i< root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}


//**************************************************************************//
int numNodes(treeNode<int>* root)
{
    if(root==NULL)
        return 0;
    int num=1;
    for(int i=0;i<root->children.size();i++)
    {
        num+=numNodes(root->children[i]);
    }
return num;
}
//***********************sum of data of nodes**********************//
int sumOfNodes(treeNode<int>* root)
{

    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}

//*******************RETURN NODE WITH MAX VALUE************************************-- // 
treeNode<int>* maxHelper(treeNode<int>* root,treeNode<int>* maxRoot) 
{
   for(int i=0;i<root->children.size();i++)
   {
       if(maxRoot->data < root->children[i]->data)
       {
           maxRoot=root->children[i];
       }
      maxRoot= maxHelper(root->children[i],maxRoot);
   }
    return maxRoot;
}
treeNode<int>* maxDataNode(treeNode<int>* root) 
{
    
	if(root==NULL)
        return root;
    else
        return maxHelper(root,root);
}

//******************findHeight OF TREE***********************************//
int findHeight(treeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    if(root->children.size()==0)
    {
        return 1;
    }
    int myHeight=0;
    int smallHeight=0;
    for(int i=0;i<root->children.size();i++)
    {
        smallHeight=findHeight(root->children[i]);
        myHeight=max(smallHeight,myHeight);
    }
	return myHeight+1;
}
//**************************PRINT NODES AT LEVEL K (ROOT IS LEVEL 0)*******************************************//
void printAtLevelK(treeNode<int> *root, int level)
{
    if(root==NULL)
        return;
    if(level==0)
        {
            cout<<root->data<<endl;
        }
        for(int i=0;i<root->children.size();i++)
        {
            printAtLevelK(root->children[i],level-1);
        }
    
}
//******************leaf nodes*************************//
int noLeafNodes(treeNode<int>*root)
{
    if(root==NULL)
    return 0;
    if(root->children.size()==0)
        return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=noLeafNodes(root->children[i]);
    }
    return ans;
}
//***********************************************************//
int main()
{
    int choice;
    cout<<"press 1 to create a tree-";
    cin>>choice;
    treeNode <int>*root;
    if(choice==1)
    {
        root=takeInputLevelWise();
        //root=takeInput();
    } 
   // printTree(root);
   cout<<endl;
   //cout<<"level order traversal is-\n";
   // printLevelWise(root);
   // cout<<endl;
   // cout<<"***********************\nnumber of nodes = "<<numNodes(root)<<endl;
//    cout<<"***********************\nsum of nodes = "<<sumOfNodes(root)<<endl;
    //cout<<"***********************\nnode with max value  = "<<maxDataNode(root)->data<<endl;
    // cout<<"***********************\nHEIGHT OF TREE  = "<<findHeight(root)<<endl;
   // cout<<"*************\nelements at level 2 are "<<endl;
    //printAtLevelK(root,2);
   // cout<<"\nno of leaf nodes = "<<noLeafNodes(root);
    /*cout<<"pre order traversal of your tree \n";
    preOrder(root);*/
   /*
   DRIVER FUNCTION TO CHECK DESTRUCTOR
    cout<<"post order traversal is-\n"; 
    postOrder(root);
    delete root;
     cout<<"post order traversal is-\n"; 
    postOrder(root);
    */

}
//test case
/*
1
10
3
20 30 40
2
50 60
0 
0
0
0
0

*/