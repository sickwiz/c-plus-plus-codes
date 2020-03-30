#include<iostream>
#include<string>
using namespace std;
void printSub(string s, string output)
{
    if(s.size()==0)
    {
        cout<<output<<"\n";
        return;
    }
    printSub(s.substr(1),output);
    printSub(s.substr(1),output+s[0]);
}
int main()
{
    string s="ab";
    string output="";
    printSub(s,output);
}