void preOrder(treeNode<int> *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}

//////////////////****************************************//////////////////////////

void printLevelWise(treeNode<int>* root)
 {
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        treeNode<int>* first= pendingNodes.front();
        cout<<first->data<<":";
        for(int i=0;i<first->children.size();i++)
        {
            if(i==first->children.size()-1)
            {
                cout<<first->children[i]->data;
            }
             else
                 
             { 
                 cout<<first->children[i]->data<<",";
             }
            pendingNodes.push(first->children[i]);
        }
        cout<<"\n";
        pendingNodes.pop();
    }
}

////****************************************************************//
void postOrder(treeNode<int>* root)
{
	if(root==NULL)
        return;
    if(root->children.size()==0)
    {
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}