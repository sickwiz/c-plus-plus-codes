// Change in the given string itself. So no need to return or print the changed string.
#include<iostream>
using namespace std;
void pairStar(char input[]) {
    // Write your code here

    int length=0;
    while(input[length])
    {
        length++;
    }
    if(length==0 || length==1)
        return;
    if(input[0]==input[1])
    {
        for(int i=length;i>0;i--)
        {
            input[i+1]=input[i];
        }
            input[1]='*';
        pairStar(input+1);
    }
    pairStar(input+1);
    
}
int main()
{
    char c[1000]='\0';
}

/*
ababaab
*/