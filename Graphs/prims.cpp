/*
Given an undirected, connected and weighted graph G(V, E) with V
 number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
*/
#include <bits/stdc++.h>
using namespace std;
int findMin(bool *visited,int *weight,int V)
{
    int minVertex = -1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i]))
            minVertex = i;
    }
    return minVertex;
}
void prims(int **matrix,bool *visited,int *parents,int * weight,int V)
{
  
    for(int i=0;i<V;i++)
    {
        int minVertex = findMin(visited,weight,V);    //find the minimum unvisited vertex
        visited[minVertex] = true;
        for(int j=0;j<V;j++)
        {
            if(matrix[j][minVertex]!=0 && !visited[j] && weight[j]>matrix[j][minVertex])
            {
                weight[j] = matrix[j][minVertex];   //update the weight
                parents[j] = minVertex;               //update the parent
            }
        }
    }
    
    //print the mst
    for(int i=1;i<V;i++)
    {
        // printing parent and child in ascending order
        if(parents[i] > i)
            cout<<i<<" "<<parents[i]<<" "<<weight[i]<<endl;
        else
        	cout<<parents[i]<<" "<<i<<" "<<weight[i]<<endl;
    }
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    // adjacency matrix
    int **matrix = new int*[V];
    for(int i=0;i<V;i++)
    {
        matrix[i] = new int[V];
        for(int j=0;j<V;j++)
            matrix[i][j] = 0;
    }
    //mark the edges
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;;
        matrix[s][d] = w;
        matrix[d][s] = w;
    }
    
    //visited array
    bool *visited = new bool[V];    
    //weight
    int *weight = new int[V];
	for(int i=0;i<V;i++)
    {
        weight[i] = INT_MAX;
         visited[i] = false;
    }
    
    int *parents = new int[V];
    for(int i=0;i<V;i++)
        parents[i] = -1;
    
    weight[0] = 0;
    prims(matrix,visited,parents,weight,V);
    
    //

  return 0;
}
/* test case
4 4
0 1 3
0 3 5
1 2 1
2 3 8

output
0 1 3
1 2 1
0 3 5
*/