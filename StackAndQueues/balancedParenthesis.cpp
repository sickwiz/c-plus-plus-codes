#include <iostream>
using namespace std;
// #include "solution.h"
#include<stack>
bool checkBalanced(char *exp) {
	// Write your code here
    int len=0;
    while(exp[len])
    {
        len++;
    }
    stack<char>s;
    for(int i=0;i<len;i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            s.push(exp[i]);
        }
        if(exp[i]==')')
        {
            if(s.empty())
                return false;
            if(s.top()=='(')
                s.pop();
            else
                return false;
        }
         if(exp[i]==']')
        {
             if(s.empty())
                return false;
            if(s.top()=='[')
                s.pop();
            else
                return false;
        }
         if(exp[i]=='}')
        {
             if(s.empty())
                return false;
            if(s.top()=='{')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}