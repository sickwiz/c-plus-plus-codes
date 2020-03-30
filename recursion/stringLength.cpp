#include<iostream>
using namespace std;
int len(char *s)
{
    if(s[0]=='\0')
    return 0;
    int ans=len(s+1);
    return ans+1;
}
int main()
{
    char st[100];
    cout<<"enter string-";
    cin.getline(st,100);
    int length=len(st);
    cout<<length<<endl;
}