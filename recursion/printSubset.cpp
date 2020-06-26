#include <iostream>
using namespace std;
void printHelper(int input[],int size,int output[],int Osize)
{
    if(size==0)
    {
        for(int i=0;i<Osize;i++)
            cout<<output[i]<<" ";
        cout<<"\n";
        return;
    }
    int newOutput[100];   // to include index 0 in the output
    for(int i=0;i<Osize;i++)
    {
        newOutput[i]=output[i];
    }
    newOutput[Osize]=input[0];
    printHelper(input+1,size-1,output,Osize);    // index 0 is not included in output
    printHelper(input+1,size-1,newOutput,Osize+1);   //index 0 is included in output
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[100];
    printHelper(input,size,output,0);
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
