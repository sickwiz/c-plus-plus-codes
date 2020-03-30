#include<iostream>
#include<stack>
using namespace std;
int main()
{
    /* In built stack has same functions except that return type of pop is void.
    pop only deletes the top element.
    to access top element we use top();
    isEmpty() is named empty();
    */
    stack<int>s1;
    stack<char>s2;
    stack<string>s3;
    s1.push(24);
    s2.push('a');
    s3.push("aamir");
    cout<<endl<<s1.top()<<endl<<s2.top()<<endl<<s3.top()<<endl;
    cout<<s1.size();
    cout<<endl<<s1.empty();
}