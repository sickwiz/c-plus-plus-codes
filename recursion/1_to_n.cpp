#include<iostream>
using namespace std;
void print(int n)
{
    if(n == 1){
        cout << n << " ";
        return;
    }
   // cout << n << " ";
   print(n-1);
   cout<<n<<" ";
   return ;
}
int main()
{
    print(10);
    return 0;
}