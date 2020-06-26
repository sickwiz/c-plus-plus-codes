/*
A thief robbing a store and can carry a maximal weight of W into his knapsack.
 There are N items and ith item weigh wi and is of value vi. 
 What is the maximum value V, that thief can take ?
 
 Sample Input 1 :

4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<bits/stdc++.h>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight)
{
    // this problem can naively be solved using dp[n+1][maxWeight+1]
    // but during each iteration only two rows will be used , current row and preceding rows
    // so we will use am arrow of 2 rows only 
    int **dp = new int*[2];
    int i=0;
    for(i=0;i<2;i++)
    {
         dp[i] = new int[maxWeight+1];
        for(int j = 0;j<=maxWeight;j++)
        {
            dp[i][j] = 0;               // initialising with zero.
        }
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(i%2!= 0)                     // if i is odd enter elements in 2nd row, use first row for comparison
            {
                if(weights[i] <= j)
                    dp[1][j] = max(values[i] + dp[0][j-weights[i]] , dp[0][j]);
                else
                    dp[1][j] = dp[0][j];
            }
            else                           // if i is odd , enter elements in first row, use second row for comparison
            {
               if(weights[i] <= j)
                    dp[0][j] = max(values[i] + dp[1][j-weights[i]] , dp[1][j]);
                else
                    dp[0][j] = dp[1][j]; 
            }
        }
    }
    if(n%2 != 0)           // if n (= i -1) is odd, answer is in first row 
        return dp[0][maxWeight];
    else
        return dp[1][maxWeight];
    
}
int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}