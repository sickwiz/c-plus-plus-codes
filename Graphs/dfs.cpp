#include<iostream>
using namespace std;
/*
DFS - Depth first search
e.g   0
     / \
    1  2-6      starting from 0 , dfs will be 0 1 3 4 5 2 6 i.e we got to max depth we can
    |  |
    3  5
    \ /
     4
*/
void dfs(int **edges,int vertex,int start,bool*visited)
{
    visited[start] = true;
    cout<<start<<" ";
    for(int i=0;i<vertex;i++)
    {
        if(edges[start][i] == 0)
            continue;
        if(!visited[i])
            dfs(edges,vertex,i,visited);
        else
            continue;
    }
    //for disconnected graph
    // for(int i=0;i<vertex;i++)
    // {
    //     if(visited[i] == false)
    //         dfs(edges,vertex,i,visited);
    // }
}
int main()
{
    int vertex;
    int noEdges;
    cout<<"\n enter number of vertex and edges -";
    cin>>vertex>>noEdges;
    int **edges = new int*[noEdges];
    for(int i=0;i<vertex;i++)   // initialising adjacency matrix with 0.
    {
        edges[i] = new int[noEdges];
        for(int j=0;j<noEdges;j++)
            edges[i][j] = 0;
    }
    cout<<endl<<"enter the edges one by one - "<<endl;
    int vertex1,vertex2;
    for(int i=0;i<noEdges;i++)
    {
        cin>>vertex1>>vertex2;   
        edges[vertex1][vertex2] = 1;   // marking the edges
        edges[vertex2][vertex1] = 1;
    }
    bool *visited = new bool[vertex];  // visited array for vertices
    for(int i=0;i<vertex;i++)
        visited[i] = false;
    for(int i=0;i<vertex;i++)
    {
        if(visited[i] == false)
            dfs(edges,vertex,i,visited);
    }
}
/*
test case - 
7 7
0 1
1 3
3 4
4 5
5 2
2 6
0 2
*/