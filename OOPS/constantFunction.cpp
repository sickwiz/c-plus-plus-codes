#include<iostream>
using namespace std;
class fraction
{
public:
    int nr;
    int dr;
    fraction(int n, int d)
    {
        nr=n;
        dr=d;
    }
    void print() const
    {
        cout<<"given fraction = "<<nr<<"/"<<dr<<endl;
    }
    void printNumerator()
    {
        cout<<endl<<"numerator="<<nr<<endl;
    }
};
int main()
{
    const fraction f1(10,20);
    f1.print();
    //f1.printNumerator();  --> THIS IS NOT A CONSTANT FUNCTION , HENCE CAN'T BE CALLED FROM A 
    // CONSTANT OBJECT.
    fraction f2(20,20);
    f2.printNumerator(); 
}