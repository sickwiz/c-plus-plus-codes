/*
Given a string mathematical expression, return true if redundant brackets are present in the expression.
Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Assume the given string expression is balanced and contains only one type of bracket i.e. ().
*/
#include<stack>
bool check(stack <char> &s1)
{
    int count=0;
    while(s1.top()!='(')
    {
        count++;
        s1.pop();
    }
    if(count==0)
        return true;
    else
    {
        s1.pop();
        return false;
    }
}
bool checkRedundantBrackets(char *input) 
{
	// Write your code here
  stack <char> s1;
    int len=0;
    while(input[len])
    {
        if(input[len]==')')
        {
            bool flag=check(s1);
            if(flag)
            {
                return true;
            }
           
        }
        else
        {
            s1.push(input[len]);
          
        }
          len++;
    }
    return false;
}