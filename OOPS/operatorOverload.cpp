#include<bits/stdc++.h>
using namespace std;
class fraction
{
    private:
    int numerator;
    int denominator;
    public:
    fraction(int numerator , int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print()
    {
        cout<<endl;
        cout<<this->numerator<<"/"<<this->denominator<<endl;
    }
    void simplify()
    {
        int j=min(this->numerator , this->denominator);
        int gcd=1;
        for(int i=j;i>=1;i--)
        {
            if(this->numerator%i==0 && this->denominator%i==0)
            {
                gcd=i;
                break;
            }
        }
        this->numerator/=gcd;
        this->denominator/=gcd;
    }
    fraction operator+ (fraction const &f2)  // --> ADDITION OPERATOR
    //WE AVOID COPYING THE ALREADY CREATED OBJECT IN MAIN, BY
    // PASSING THROUGH REFERENCE
    // const is used because f2 will be used only to access the object
    // changes should'nt be made through f2.
    // void add(fraction f2) -> this will mean that a copy object will be created and 
    // it will take extra space
    {
        int lcm=this->denominator * f2.denominator;
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;
        int num=(this->numerator * x) + (f2.numerator) * y;
        fraction fnew(num,lcm);
        fnew.simplify();
        return fnew; 
    }
    fraction operator*(fraction const &f1)
    {
        int num = this->numerator * f1.numerator;
        int den = this->denominator * f1.denominator;
        fraction fnew(num,den);
        fnew.simplify();
        return fnew;
    }
    /*
    fraction operator++() 
    If function was declared this way , then the return type was fraction object.
    In this case ++(++f1) would'nt work because an object will be returned for the first 
    increment within the bracked and that object will be held under buffer thereby failing the nested operation.
    when return type is by reference then buffer will hold address of the same object and nesting operation can be done easily
    */
    fraction& operator++()  //  PRE-INCREMENT
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }
    fraction operator++(int) // int keyword denotes POST-INCREMENT 
    // (++i)++ -> such nesting operation is'nt allowed in post-increment
    {
        fraction fnew(numerator,denominator);
        fnew.simplify();
        numerator+=denominator;
        simplify();
        return fnew;;
    }
};
int main()
{
    fraction f1(10,2);
    // fraction f2(15,4);
    // fraction f3=f1+f2;
    // f3.print();
    // fraction f4=f1*f2;
    // f4.print();
    // SIMILARY WE CAN OVERLAOD ALL OTHER OPERATORS
    ++f1;
    f1.print();
    ++(++f1);
    f1.print();
   (f1++).print();
}