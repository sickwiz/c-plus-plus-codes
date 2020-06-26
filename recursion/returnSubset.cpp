/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<iostream>
using namespace std;
int subset(int input[], int n, int output[][20]) {
    // Write your code here
    static int subCount=0;
    if(n==1)
    {
        output[subCount][0]=1;
        output[subCount][1]=input[0];
        return ++subCount;
    }
    int smallSubCount=subset(input+1,n-1,output);   // to keep record of no of subsets inserted in the previous recursive call
    output[subCount][0]=1;                 // first subset will be the element itself , hence size=1
    output[subCount++][1]=input[0];
    int j;
    for(int i=0;i<smallSubCount;i++)                      // iterating over all arrays of subsets
    {
        output[subCount][0]=output[i][0]+1;               
        output[subCount][1]=input[0];
        for(j=0;j<output[i][0];j++)                         //inserting new subsets
        {
            output[subCount][j+2]=output[i][j+1];
        }
        subCount++;
    }
    return subCount;
        
}
int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
