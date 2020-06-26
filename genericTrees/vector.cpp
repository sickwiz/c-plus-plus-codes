#include<vector>
#include<iostream>
using namespace std;
int main()
{
    // vector<int> *v1 = new vector<int>    dynamic allocation of vector
    /* vectors are basically dynamic arrays which increase their size once
    the size limit is reached*/

    vector <int> v;
    cout<<"capacity="<<v.capacity()<<endl;   // actual size of existing array
     cout<<"size="<<v.size()<<endl; // number of elements in the existing array
    for(int i=0;i<10;i++)
    {
        v.push_back(i*i);
    } 
    cout<<"capacity="<<v.capacity()<<endl;   // actual size of existing array
     cout<<"size="<<v.size()<<endl; // number of elements in the existing array
    v[0]=100;
    // we will use this method only to update the vector at existing indices only
    //to insert we must use push_back() because only the vector will increase its size once the size limit is 
    //reached.
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<endl;
        // or we can use v.at(i);
    }
}