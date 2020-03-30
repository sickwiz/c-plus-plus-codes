
#include<bits/stdc++.h>
class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    Polynomial()
    {
        degCoeff=new int[5];
        capacity=5;
        for(int i=0;i<5;i++)
        {
            degCoeff[i]=0;
        }
    }
    //COPY CONSTRUCTOR FOR DEEP COPY
    Polynomial(Polynomial const &p)
    {
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
            this->degCoeff[i]=p.degCoeff[i];
        this->capacity=p.capacity;
    }
    //copy assignment overloaded for deep copy
    void operator=(Polynomial const &p)
    {
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
            this->degCoeff[i]=p.degCoeff[i];
        this->capacity=p.capacity; 
    }
    
    //SET COEFFECIETN
    void setCoefficient(int degree,int coeff)
    {
     if(degree <capacity && degree>=0)
     {
         degCoeff[degree]=coeff;
     }
        else if(degree>=capacity)
        {
          int *newDeg=new int[2*degree];
            for(int i=0;i<capacity;i++)
                newDeg[i]=degCoeff[i];
            for(int i=capacity;i<2*degree;i++)
                newDeg[i]=0;
            newDeg[degree]=coeff;
            delete [] degCoeff;
            degCoeff=newDeg;
            capacity=2*degree;
        }
        else
            return;
    }
    
    
    //OPERATOR OVERLOADING FOR ADDITION
    Polynomial operator+(Polynomial const &p)
    {
        int cap1=this->capacity;
        int cap2=p.capacity;
        if(cap1>cap2)
        {
            Polynomial pnew;
            for(int i=0;i<cap2;i++)
                pnew.setCoefficient(i,this->degCoeff[i]+p.degCoeff[i]);
            for(int i=cap2;i<cap1;i++)
                pnew.setCoefficient(i,this->degCoeff[i]);
            return pnew;
        }
        else
        {
             Polynomial pnew;
            for(int i=0;i<cap1;i++)
                pnew.setCoefficient(i,this->degCoeff[i]+p.degCoeff[i]);
            for(int i=cap1;i<cap2;i++)
                pnew.setCoefficient(i,p.degCoeff[i]);
            return pnew;
        }
    }
    Polynomial operator-(Polynomial const &p)
         {
        int cap1=this->capacity;
        int cap2=p.capacity;
        if(cap1>cap2)
        {
            Polynomial pnew;
            for(int i=0;i<cap2;i++)
                pnew.setCoefficient(i,this->degCoeff[i] - p.degCoeff[i]);
            for(int i=cap2;i<cap1;i++)
                pnew.setCoefficient(i,- this->degCoeff[i]);    //LOOK FOR THE IMPORTANCE OF '-' SIGN HERE
            return pnew;
        }
        else
        {
            Polynomial pnew;
            for(int i=0;i<cap1;i++)
                pnew.setCoefficient(i,this->degCoeff[i] - p.degCoeff[i]);
            for(int i=cap1;i<cap2;i++)
                pnew.setCoefficient(i,-p.degCoeff[i]);   //LOOK FOR THE IMPORTANCE OF '-' SIGN HERE
            return pnew;
        }
    }
    Polynomial operator*(Polynomial const &p)
    {
        int cap1=this->capacity;
        int cap2=p.capacity;
        Polynomial pnew;
        for(int i=0;i<cap1;i++)   //0
        {
             int num1=this->degCoeff[i];
            for(int j=0;j<cap2;j++)
            {
                int num2=p.degCoeff[j];
                int p=num1*num2;
                if(p!=0)
                {
                    int p2=0;
                    if(i+j<pnew.capacity)    // TO AVAOID GARBAGE VALUES
                    {
                        p2=pnew.degCoeff[i+j];
                    }
                    int p3=p+p2;
                    pnew.setCoefficient(i+j,p3);
                }
            }
        }
        return pnew;
    }
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]!=0)
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
    }
};

 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
























