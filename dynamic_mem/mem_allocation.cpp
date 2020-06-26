#include<iostream>
using namespace std;
int main()
{
    int *p=new int;
    // p is assigned a memory of 8 bytes on stack and a 4 byte memory is assigned for integer on the heap;
    *p=11;
    cout<<"p="<<*p<<endl;
    int n;
    // cout<<"enter size of the array-"<<endl;
    // cin>>n;
    // int *a=new int[n]; //array is created dynamically;
    // 4*n bytes on heap and 8 bytes on stack;

    // static memory is released automatically based on scope;
    // dynamic memory needs to be released manually

    int *k=new int[2];
    k[0]=1;
    k[1]=3;
    cout<<k[0]<<" "<<k[1]<<endl;
    delete [] k;    // k is not deleted , only the integers assigned on the heap memory will be deleted;
    cout<<"k has been deleted \n";
    cout<<k[0];
    int *j=new int;
    *j=19;
    cout<<endl<<"j="<<*j<<endl;
    delete j;   //j is not deleted , the integer assigned to j will be deleted
    cout<<"j is deleted\n";
    cout<<*j<<endl;

    //DYNAMIC ALLOCATION OF 2D ARRAY

    int **arr=new int *[10];
    for(int i=0;i<20;i++)
    {
        arr[i]=new int[20]; //10*20 matrix;
    }
   

    // 2d array with different number of elements in each row
    int **arr2=new int*[10];
    for(int i=0;i<10;i++)
    {
        arr2[i]=new int[i+2];
        for(int j=0;j<i+2;j++)
        {
            arr2[i][j]=j*j;
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<i+2;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

     //DEALLOCATING 2D ARRAY

    for(int i=0;i<10;i++)
    {
        delete [] arr2[i];
    }
    delete [] arr2;
    cout<<"arr2 is deleted-";
    cout<<arr2[3][1]<<endl;
}