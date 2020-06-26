/*
Given an array A and an integer K, print all subsets of A which sum to K.
*/
#include <iostream>
using namespace std;
void printHelper(int input[],int size,int output[],int k,int Osize)
{
    if(size==0)
    {
       if(k==0)
        {
            for(int i=0;i<Osize;i++)
                cout<<output[i]<<" ";
           cout<<endl;
            return;
        }
        else
            return;
    }
    int count=0;
    int output1[100];
    int output2[100];
    for(count=0;count<Osize;count++)  //for copying previous output
    {
        output1[count]=output[count];
        output2[count]=output[count];
    }
    output1[count]=input[0];   //for including index 0 in one of the output array;
    printHelper(input+1,size-1,output1,k-input[0],Osize+1);
    printHelper(input+1,size-1,output2,k,Osize);
    
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[size];
    printHelper(input,size,output,k,0);
    
}
int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}