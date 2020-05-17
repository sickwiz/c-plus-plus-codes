#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void returnList(int **edges,int V,bool* visited,int start,priority_queue<int,vector<int>,greater<int>>*list)
{
    visited[start] = true;
    for(int i=0;i<V;i++)
    {
        if(edges[start][i] == 1 && visited[i] == false)
        {
            list->push(i);
            returnList(edges,V,visited,i,list);
        }
    }
    return;
}
void printConnected(int **edges,int V,bool*visited)
{
    //min heap is used because the connected components has to be printed in increasing order
    vector<priority_queue<int,vector<int>,greater<int>>*> connectedList;
    for(int i=0;i<V;i++)
    {
      if(visited[i] == true)
          continue;
        // if i isnt visited , explore i in DFS
    	priority_queue<int,vector<int>,greater<int>>*list = new priority_queue<int,vector<int>,greater<int>>;
        list->push(i);
        returnList(edges,V,visited,i,list);
        connectedList.push_back(list);
    }
    for(int i=0;i<connectedList.size();i++)
    {
       priority_queue<int,vector<int>,greater<int>>* temp = connectedList.at(i);
        while(!temp->empty())
        {
          cout<<temp->top()<<" ";
            temp->pop();
        }
        cout<<"\n";
    }
    return;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

    //creating adjacency matrix
    int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    //marking edges in the matrix
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    //initialisong visited array
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
   printConnected(edges,V,visited);

  return 0;
}
