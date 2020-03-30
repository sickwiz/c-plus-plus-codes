#include<iostream>
using namespace std;
int main()
{
    string a;
   // cin>>a;   // will take input upto first 'space' character
    //cout<<"a="<<a<<endl;
    string *sp=new string; //dynamic allocation
    string b;
    getline(cin,b);  // will read the whole line
    cout<<"b="<<b<<endl;
    b[0]='x'; // you can edit the strings;
    cout<<b<<endl;
    //string c=a+b; //concatenation
    //cout<<"c="<<c<<endl;
    cout<<"size of b="<<b.size()<<endl;
    // SUBSTRING
    //cout<<stringName.substr(n) -->prints the string from nth index
    //cout<<stringName.substr(n,m)  -->prints the string from nth index upto a length of m
    cout<<b.substr(3,4)<<endl; 
    cout<<b.find("xyz")<<endl;  //finds the starting index of "xyz" in b;
}