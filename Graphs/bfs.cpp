/* BFS - breadth first search, more like level order traversal*/
#include <iostream>
#include<queue>
using namespace std;
void bfs(int **edges,int V,bool * visited)
{
   queue<int>q;
   //the outer for loop is required for disconnected graphs only
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
            q.push(i);
        while(!q.empty())
        {
            int parent  = q.front();
            visited[parent] = true;
            for(int j=0;j<V;j++)
            {
                if(edges[parent][j] == 1 && visited[j] == false)
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
            cout<<parent<<" ";
            q.pop();
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    int **edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
            edges[i][j] = 0;
    }
    //adjacency matrix marking
    for(int i=0;i<E;i++)
    {
        int first,second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    //making visited array
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    bfs(edges,V,visited);

    // deleting memory
    delete [] visited;
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}
/*
test case - 
7 7 
0 1
0 2
1 3
3 4
4 5
5 2
2 6
*/
