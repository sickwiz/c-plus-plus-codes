#include<iostream>
using namespace std;
class dArray
{
    public:
    int *data;
    int nextIndex;
    int capacity;
    dArray()
    {
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }
    dArray(dArray const &d)
    {
        // COPY CONSTRUCTOR FOR DEEP COPY
        this->data=new int[d.capacity];
        for(int i=0;i<d.caoacity;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }
    //COPY ASSIGNMENT OPERATOR OVERLOADED FOR DEEP COPY
    void operator=(dArray const &d)
    {
       this->data=new int[d.capacity];
        for(int i=0;i<d.caoacity;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }  
    }
    void insert(int a)
    {
        if(nextIndex==capacity)
        {
            int *data1=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                data1[i]=data[i];
            }
            capacity=2*capacity;
            delete [] data;
            data=data1;
            data[nextIndex++]=a;
        }
        else
        data[nextIndex++]=a;
    }
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            cout<<data[i]<<" ";
        }
    }
    int find(int i)
    {
        if(i>=capacity || i<0)
            {
                cout<<endl<<"index out of limit"<<endl;
                return 
            }
        else
            return a1[i];

    }
};
int main()
{
    dArray a1;
    for(int i=0;i<20;i++)
    a1.insert(i);
    a1.print();
}