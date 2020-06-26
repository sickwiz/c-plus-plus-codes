/*
Given a n*m matrix which contains only 0s and 1s, 
find out the size of maximum square sub-matrix with
 all 0s. You need to return the size of square with all 0s.
 */
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col)
{
    /* make an output matrix to store the maxuimum no of squares above and to the left of [i][j]
    the maximum no of squares at i,j = minm of its surroinding squares +1;
    */
    int **output = new int*[row];
    for(int i=0;i<row;i++)
        output[i] = new int[col];
 	for(int i=0;i<row;i++)
        output[i][0] = (arr[i][0] == 0)?1:0;  // for first col , if element is zero, max square =1 else 0. same for first row;
    //for first row
    for(int i=0;i<col;i++)
        output[0][i] = (arr[0][i] == 0)?1:0;
    int ans = 0;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(arr[i][j] == 1)
                output[i][j] = 0;
            else
            {
                output[i][j] = min(output[i-1][j-1],min(output[i][j-1],output[i-1][j]))+1;
                ans = max(output[i][j],ans);
            }
        }
    }
    return ans;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}