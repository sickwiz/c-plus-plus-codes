/*
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) 
of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , 
then count the distinct 3-cycles in the graph. 
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
*/
#include<iostream>
using namespace std;
int threeCycle(int **edges,int n,int m,int i,int j)
{
    int count = 0;
    if(j < n)
    {
        for(int k=0;k<n;k++)
        {
            if(edges[j][k] == 1 && edges[i][k] == 1)
                count++;
        }
    }
    else
    {
        for(int k=0;k<n;k++)
        {
            if(edges[k][j] == 1 && edges[k][i] == 1)
                count++;
        }
    }
    return count;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    // initialising adjacency matrix
    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }
    //marking edges
    for(int i=0;i<m;i++)
    {
        edges[u[i]-1][v[i]-1] = 1;
        edges[v[i]-1][u[i]-1] = 1;
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j] == 1)
            {
                count += threeCycle(edges,n,m,i,j);
            }
        }
    }
    return count/6;  //because one 3-cycle can have 6 permutation
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
//test case
/*
3 3
1 2 3
2 3 1
ans = 1
*/