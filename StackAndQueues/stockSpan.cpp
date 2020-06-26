/*
PROBLEM -
The span si of a stock’s price on a certain day i is the minimum number of consecutive days (up to the current day) 
the price of the stock has been less than its price on that ith day. If for a particular day, if no stock price is
 greater then just count the number of days till 0th day including current day.
For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which has price 2) is 2 because minimum count 
of consecutive days (including 4th day itself) from current day which has price less than 4th day is 2 
(i.e. day 3 & 4). Similarly, span for 2nd day is 3 because no stock price in left is greater than 2nd day's price.
 So count is 3 till 0th day.
Given an input array with all stock prices, you need to return the array with corresponding spans of each day.
*/
#include<stack>
#include<iostream>
using namespace std;
//****************approach******************//
/* 1.maintain an output array and a stack
    2. iterate over price array
    3 if i==0--> push i in the stack (s1) and output[i]=1
    4. if price[i]> price of index in top of stack , keep popping until price of index on top is >= price[i],
        output[i] = i-s1.top()
    5.if all above condition fails, push i in the stack , output[i]=1;


*/
int* stockSpan(int *price, int size)
{
	// Write your code here
    int *output = new int[size];
    stack<int> s1;
    for(int i=0;i<size;i++)
    {
        if(i==0)
        {
            s1.push(i);
            output[i]=1;
            // continue;
        }
        else
        {
         if(price[i] > price[s1.top()])
         {
             while(!s1.empty()  && price[s1.top()] < price[i] )
             {
                    s1.pop();
             }
             if(s1.empty())
             {
                 output[i]=i+1;
             }
             else
             {
                 output[i]=i-s1.top();
             }
             s1.push(i);
         }
        else
        {
            s1.push(i);
            output[i]=1;
        }
        }
    }
    return output;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}