/*
You are given an infinite supply of coins of each of denominations
 D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total
number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.*/
#include<iostream>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
	int **table = new int *[value+1];
    for(int i=0;i<=value;i++)
    {
        table[i] = new int[numDenominations];
    }
    for(int i=0;i<numDenominations;i++)
        table[0][i] = 1;  //when value =0;
    for(int i = 1;i<=value;i++)
    {
        for(int j=0;j<numDenominations;j++)
        {
            int including;
            if(i - denominations[j] >= 0)
                including = table[i - denominations[j]][j];
            else
                including = 0;
            int excluding;
            if(j > 0)
                excluding = table[i][j-1];
            else
                excluding = 0;
            table[i][j] = including + excluding;
        }
    }
    return table[value][numDenominations-1];
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}
