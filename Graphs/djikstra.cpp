/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all
 other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space.
 Print different vertices in different lines.
 */
#include <iostream>
#include<climits>
using namespace std;
int findMin(int *weight,bool *visited,int V)
{
    int minVertex = -1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
    return minVertex;
}
void djikstra(int **matrix,bool *visited,int *weight,int V)
{
    for(int i=0;i<V;i++)
    {
        int minVertex = findMin(weight,visited,V);  //find the next nearest neighbour (initially it is the source)
        visited[minVertex] = true;
        for(int j=0;j<V;j++)
        {
            if(matrix[minVertex][j]!=0 && weight[minVertex] + matrix[minVertex][j] < weight[j])  //update the shortest distance to j
                weight[j] = weight[minVertex] + matrix[minVertex][j];
        }
    }
    //print distance from source , here source is zero
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<weight[i]<<endl;
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
    //adjacency matrix
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
    weight[0] = 0;
    djikstra(matrix,visited,weight,V);
  return 0;
}
/*
test case
4 4
0 1 3
0 3 5
1 2 1
2 3 8

output
0 0
1 3
2 4
3 5
*/