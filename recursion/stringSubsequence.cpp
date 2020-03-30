// substring are possible continous strings of the given string
// subsequences are all possible string combinations of the the given string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subString(string input,string *output)
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallString=input.substr(1);   // recursive call for for substring starting starting from 1st index 
    int smallStringSize=subString(smallString,output);
    for(int i=0;i<smallStringSize;i++)
    {
        output[i+smallStringSize]=input[0]+output[i];   // concatenating first character with the returned subsequences
    }
    return 2*smallStringSize;
}
int main()
{
    string s;
    cin>>s;
    cout<<endl;
    int len=s.size();
    int oSize=pow(2,len);
    string *output=new string[oSize];
    subString(s,output);
    for(int i=0;i<oSize;i++)
    {
        cout<<output[i]<<endl;
    }
}