/*
Given a chain of matrices A1, A2, A3,.....An, 
you have to figure out the most efficient way to multiply these matrices i.e. 
determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i].
 You need to find minimum number of multiplications needed to multiply the chain.
 */
#include<bits/stdc++.h>
using namespace std;
/*
//recursive solution
int mcmHelper(int *p,int start,int end)
{
    if(start == end)
        return 0;
    int min = INT_MAX;
    int count;
    for(int k = start;k<end;k++)
    {
        count = mcmHelper(p,start,k) + mcmHelper(p,k+1,end) + p[start-1]*p[k]*p[end];
        if(count < min)
            min = count;
    }
    return min;
}*/
/* scheme-
if given matrix = Ma,Mb,Mc
ans = Ma(Mb*Mc), (Ma*Mb)*Mc ka minimum
*/
int mcm(int* p, int n)
{
// if Ma is x*y , Mb is y*z , no of multiplications in Ma*Mb = x*y*z
	  int m[n+1][n+1]; 
  
    int i, j, k, L, q; 
  
    /* m[i,j] = Minimum number of scalar  
    multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i..j] where 
    dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying 
    // one matrix. 
    for (i = 1; i <= n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L <= n; L++) 
    { 
        for (i = 1; i <= n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n ]; 
}
