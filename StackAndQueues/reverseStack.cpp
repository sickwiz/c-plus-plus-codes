#include <stack>
#include<iostream>
using namespace std;
/*stack<int>*/void reverseStack(stack<int> &input, stack<int> &extra)
{
	//  Write your code here
      if(input.size()==0 || input.size()==1)
          {
              return ;//input;
          }
     int t=input.top();                         // 10 20
     input.pop();
     reverseStack(input,extra);
      
     while(!input.empty())
   {
         extra.push(input.top());
         input.pop();
     }
     extra.push(t);
         while(!extra.empty())
   {
         input.push(extra.top());
         extra.pop();
     }
     return;// //input;
}
int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
