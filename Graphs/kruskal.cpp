/*
Given an undirected, connected and weighted graph G(V, E) with V number
of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
*/
#include <iostream>
#include<algorithm>
using namespace std;

class edge
{
  public:
    int source;
    int dest;
    int weight;
    void insert(int s,int d,int w)
    {
        source = s;
        weight = w;
        dest = d;
    }
};
bool compare(edge a,edge b)  // will sort edge on the basis of weight
{
    return a.weight < b.weight;   
}
int findParent(int source,int *parents)
{
   //keep calling recursive until the number is it's own parent
    
  if(parents[source] == source)
      return source;
    else
        return findParent(parents[source],parents);
}
void printMST(edge *output,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<"\n";
    }
}
void kruskal(int v,int e,edge *list)
{
    edge output[v-1];
    int *parents = new int[v];  //to store the parent of vertices
    for(int i=0;i<v;i++)
    {
        parents[i]=i;
    }
    int count=0;     //for mst
    int edgeCount = 0;  //for traversal
    while(count < v-1 && edgeCount < e)
    {
        int sourceParent = findParent(list[edgeCount].source,parents);
         int destParent = findParent(list[edgeCount].dest,parents);
        if(sourceParent != destParent)   //i.e cycle willn't be formed if current edge is taken
        {
            output[count] = list[edgeCount];
            count++;
            parents[sourceParent] = parents[destParent];  //update the parent
        }
        edgeCount++;
    }
     printMST(output,v-1);
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
    edge list[E];
    for(int i=0;i<E;i++)
    {
        int s,d,w;  //first,second,weight
        cin>>s;
        cin>>d;
        cin>>w;
        if(s < d)   //to take input in ascending order
        {
            list[i].insert(s,d,w);
        }
        else
            list[i].insert(d,s,w);
    }
	sort(list,list+E,compare);
  // printMST(list,E);
    kruskal(V,E,list);
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
1 2 1
0 1 3
0 3 5
*/