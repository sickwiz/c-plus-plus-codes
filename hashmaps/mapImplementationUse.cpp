#include "mapImplementation.h"
int main()
{
    myMap<int>* m = new myMap<int>();
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key = "abc";
        key = key + c;
        int val = i;
        m->insert(key,val);
        cout<<m->getLoad()<<endl;
    }
    cout<<"deleting abc2 with value = "<<m->remove("abc2")<<" and abc6 with value =  "<<m->remove("abc6")<<endl;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key = "abc";
        key = key + c;
        cout<<"value of "<<key<<" = "<<m->getValue(key)<<endl;
    }
    
    /*
    m->insert("abc",1);
    m->insert("def",2);
     m->insert("abc",5);
    cout<<"value of abc = "<<m->getValue("abc")<<endl;
    cout<<"value of adda = "<<m->getValue("adda")<<endl;
    cout<<"size= "<<m->getSize()<<endl;
    cout<<"removed def with value = "<<m->remove("def")<<endl;
    cout<<"size = "<<m->getSize()<<endl;*/
}