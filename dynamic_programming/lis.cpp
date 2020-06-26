/*
Given an array with N elements, you need to find the length of the
 longest subsequence of a given sequence such that all elements of 
 the subsequence are sorted in strictly increasing order.
 */
#include<cmath>
#include<iostream>
using namespace std;

 int lis(int arr[], int n)
 {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
    int *dp = new int[n];
    for(int i=0;i<n;i++)
        dp[i] = 1;
     // dp[i] will store the lis for ith index
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>=0;j--)  // to find lis of dp[i], inspect all elements before ith index , if say j<i , arr[j] < arr[]
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[j]+1,dp[i]);
        }
            
    }
    int maximum = dp[0];
     for(int i=1;i<n;i++)
     {
         if(dp[i] > maximum)
             maximum = dp[i];
     }
		return maximum;
 }
int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
}
