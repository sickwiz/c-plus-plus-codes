#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size==0)
      return 0;
  int ans=allIndexes(input+1,size-1,x,output);  //keeps calling until size reduces to zero
    for(int i=0;i<ans;i++)
    {
        output[i]+=1;    // since last element is checked first, index is increased during each step to obtain correct answer
    }
    if(input[0]==x)     // if oth element of sub array equals x, array is shifted one towards right
    {
        for(int i=ans;i>0;i--)
        {
            output[i]=output[i-1];
        }
        output[0]=0;
        return ans+1;
    }
    else
        return ans;
    
}
int main()
{
    int *arr=new int[10];
    for(int i=0;i<10;i++)
    {
        if(i%2==0)
        arr[i]=0;
        else
        {
            arr[i]=1;
        }
        
    }
    int *output=new int[10];
    int ans=allIndexes(arr,10,1,output);
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        cout<<output[i]<<"-";
    }
}