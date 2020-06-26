/*Given an integer matrix of size m*n, you need to find out the value 
of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
*/
#include<bits/stdc++.h>
using namespace std;
int minCostHelper(int **input,int **solution,int currRow,int currColumn,int row,int column)
{
    if(currRow == row-1 && currColumn == column - 1)
        return input[row-1][column-1];
    if(solution[currRow][currColumn] != -1)
        return solution[currRow][currColumn];
    int cost1 = INT_MAX;
    int cost2 = INT_MAX;
    int cost3 = INT_MAX;
    int cost = input[currRow][currColumn];
      if(currRow < row-1)
   		{
                    cost1 = minCostHelper(input,solution,currRow+1,currColumn,row,column);        
        }
       if(currColumn < column-1)
   		{
          
                    cost2 = minCostHelper(input,solution,currRow,currColumn+1,row,column);
        }   
        if(currRow < row-1 && currColumn < column-1 )
   		{

                    cost3 = minCostHelper(input,solution,currRow+1,currColumn+1,row,column);
                
        }
    int ans = min(cost1,min(cost2,cost3));
    solution[currRow][currColumn] = cost + ans;
    return cost + ans;
}
int minCostPath(int **input,int row,int column )
{
    int **solution = new int *[row];
    for(int i=0;i<row;i++)
    {
        solution[i] = new int[column];
        for(int j=0;j<column;j++)
            solution[i][j] = -1;
    }
    return minCostHelper(input,solution,0,0,row,column);
}

int main() 
{
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}