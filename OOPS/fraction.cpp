#include<bits/stdc++.h>
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
    void add(fraction const &f2) //WE AVOID COPYING THE ALREADY CREATED OBJECT IB MAIN BY
    // PASSING THROUGH REFERENCE
    // const is used because f2 will be used only to access the object
    // changes should'nt be made though f2.
    // void add(fraction f2) -> this will mean that a copy object will be created and 
    // it will take extra space
    {
        int n=this->numerator;
        int d=this->denominator;
        this->numerator=n*(f2.denominator) + (f2.numerator)*d;
        this->denominator=d*(f2.denominator);
        simplify();
    }
};