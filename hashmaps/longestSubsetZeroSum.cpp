#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size)
{
  
  // Write your code here
    unordered_map<int,int> sumMap;   //first stores sum upto that index , second stores index
    int sum = 0;
    int len=0;
    //if sum upto ith index is equal to sum upto jth index => sum between i to j = 0
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
         if (arr[i] == 0 && len == 0) 
            len = 1; 
       if(sumMap.count(sum) > 0)
       {
           if(i-sumMap[sum] > len)
               len = i-sumMap[sum];
           continue;
       }
        sumMap[sum]=i;
    }
    return len;
}
int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}
