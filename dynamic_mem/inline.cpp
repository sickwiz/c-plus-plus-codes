#include<iostream>
using namespace std;
inline int min(int a,int b)  //inline simply means compiler will replace the function calls everywhere in the code with the 
// exact code just before runtime.
//it is used when function contains single line code only (or 2-3 lines maybe)
{
    return (a<b)?a:b;  
}
int main()
{
    int a,b;
    cout<<"enter a and b-";
    cin>>a>>b;
    int c =min(a,b);
    cout<<endl<<c<<endl;
}