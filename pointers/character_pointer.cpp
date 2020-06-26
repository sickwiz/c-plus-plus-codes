#include<iostream>
using namespace std;
int main()
{
    char c[]="aamir"; //
    char *c1=&c[0];  // pointing to a string
    cout<<c1<<endl;    //1
    char c2='a';
    char *c3=&c2;
    cout<<c3<<endl; //2 
    // AT 1 AND 2, IT WILL KEEP PRINTING UNTIL A NULL CHARACTER I.E \0 IS FOUND;

    // char *ptr="asaad"; THIS IS NOT ALLOWED
}