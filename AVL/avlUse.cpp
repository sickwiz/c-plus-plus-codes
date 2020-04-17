#include "avlClass.h"
using namespace std;

void printLevelWise(avl<int> *root)
{
    if(root == NULL)
        return;
    queue<avl<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
       avl<int>*curr=pendingNodes.front();
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
int findHeight(avl<int> *node)
{
	if(node==NULL)
        return 0;
    return node->height;
}
int getBalance(avl<int> * node)
{
    if(node == NULL)
        return 0;
    int bal = findHeight(node->left) - findHeight(node->right);
    return bal;
}
avl<int>*llRotate(avl<int>*node)
{
    avl<int> * leftNode=node->left;
    avl<int> *leftRightNode=(node->left)->right;
    leftNode->right=node;
    node->left = leftRightNode;
    node->height=1+max(findHeight(node->left),findHeight(node->right));
    leftNode->height=1+ max(findHeight(leftNode->left),findHeight(leftNode->right));
    return leftNode;
}
avl<int>* rrRotate(avl<int> * node)
{
    avl<int>*rightNode=node->right;
    avl<int>*rightLeftNode=(node->right)->left;
    rightNode->left = node;
    node->right = rightLeftNode;
    node->height=1+max(findHeight(node->left),findHeight(node->right));
    rightNode->height=1+ max(findHeight(rightNode->left),findHeight(rightNode->right));
    return rightNode;
}
avl<int>* insert(avl<int> *node,int num)
{
    if(node == NULL)
    {
        avl<int> *newNode= new avl<int>(num);
        return newNode;
    }
    if(node->data > num)
    {
        node->left = insert(node->left,num);
    }
    else if(node->data < num)
    {
        node->right = insert(node->right,num);
    }
    else
        return node; //identical elements aren't allowed
    // cout<<"helllo\n";

    //update the height
    node->height= 1+ max(findHeight(node->left),findHeight(node->right));

    // reconstructing the avl
    int bal = getBalance(node);
    if(bal > 1 && num < node->left->data)  //left-left rotate
        {
            node = llRotate(node);
            return node;
        }
    else if(bal < -1 && num > node->right->data)  // right-right case
    {
        node=rrRotate(node);
        return node;
    }
    else if(bal > 1 && num > node->left->data)       //left-right case
    {
                node->left = rrRotate(node->left);  
        return llRotate(node);  
    }
    else if (bal < -1 && num < node->right->data)  //right-left case
    {  
        node->right = llRotate(node->right);  
        return rrRotate(node);  
    }
   else
    return node;
}
int main()
{
    avl<int>*a=new avl<int>(1);
   a=insert(a,7);
   a=insert(a,12);
   a=insert(a,19);
   a=insert(a,52);
   a=insert(a,76);
   a=insert(a,66);
   a=insert(a,69);

    printLevelWise(a);
}
//1 7 12 19 52 76 66 69 