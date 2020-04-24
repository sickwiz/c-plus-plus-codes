#include<unordered_map>
#include<vector>
#include<list>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    list<int> l;
    for(int i=0;i<5;i++)
    {
        l.push_back(i);
    }
    cout<<"\niterating over the linked list\n";
    list<int>::iterator listIterator = l.begin();
    while(listIterator!=l.end())
    {
        cout<<*listIterator<<" ";
        listIterator++;
    }
    unordered_map<string,int> myMap;
    myMap["abc"]=1;
    myMap["def"]=2;
    unordered_map<string,int>::iterator mapIterator = myMap.begin();
    cout<<endl<<"iterating over the map \n";
    while(mapIterator != myMap.end())
    {
        cout<<"key="<<mapIterator->first<<" value="<<mapIterator->second<<endl;
        mapIterator++;
    }
    mapIterator = myMap.begin();
    myMap.erase(mapIterator,myMap.end());  //erase function takes single value as well as range values
    if(myMap.count("abc") == 0)
    {
        cout<<"map has been deleted-"<<endl;
    }
    //similarly we can iterate over vectors.
}