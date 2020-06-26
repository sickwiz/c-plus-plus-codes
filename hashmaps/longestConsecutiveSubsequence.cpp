#include <vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
	//Your Code goes here
    vector<int> ans;
    if(n==0)
        return ans;
    unordered_map<int,pair<bool,int>> map;
    for(int i =0;i<n;i++)
    {
        if(map.count(arr[i]) > 0)  // if element has already occured previously
            continue;
        pair<bool,int> temp ;
        temp.first = true;  // flag to check if the given number has been already visited
        temp.second = i;   
        // index for comparison when two subsequence are of the same length
        // subseqeunce in which start appears first in the array will be printed
        map[arr[i]] = temp;
    }
    
    int start =0;
    int end = 0;
    for(int i = 0;i<n;i++)
    {
        int tempStart=arr[i];
        int tempEnd=arr[i]+1;
        map[tempStart].first=false;
        while(map.count(tempEnd) > 0 && map[tempEnd].first != false)
        {
            map[tempEnd].first = false;
            tempEnd = tempEnd+1;
        }
        while(map.count(tempStart-1) > 0 && map[tempStart - 1].first != false)
        {
            map[tempStart -1].first = false;
            tempStart = tempStart - 1;
        }
        if(tempEnd - tempStart == end - start)  // subseqeunce in which start appears first in the array will be printed
        {
          if(map[tempStart].second < map[start].second)
          {
             start = tempStart;
                end = tempEnd; 
          }
        }
        else if(tempEnd - tempStart > end - start)
        {
             start = tempStart;
                end = tempEnd;
        }
    }
    for(int i = start;i<end;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}