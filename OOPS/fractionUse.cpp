#include<iostream>
using namespace std;
#include "fraction.cpp"
int main()
{
    fraction f(10,2);
    fraction f1(15,4);
    f.add(f1);
    f.print();
}