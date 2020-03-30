#include<bits/stdc++.h>
int stringToNumber(char input[]) {
    // Write your code here
    int length=0;
    while(input[length])
    {
        length++;
    }
    if(length==0)
        return 0;
    if(length==1)
    {
        int ans=input[0];
        return ans-48;    //converting ascii to integer value
    }
    int ans=stringToNumber(input+1);
    int b=input[0]-48;
    ans=b*pow(10,length-1)+ans;   //e.g 1234=1*10^3 + 234;
    return ans;
}


