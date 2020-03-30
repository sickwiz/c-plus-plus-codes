#include<iostream>
using namespace std;
template <typename T , typename V>
class Pair
{
    public:
    T first;  // first is of the type T
    V second;  // second is of the type V
    //if we wanted both data of same type , we could have just used single template
    //e.g template<typename T>
   void setF(T first)
   {
       this->first=first;
   }
   void setS(V second)
   {
       this->second=second;
   }
    /*void display()
    {
        cout<<endl<<"first="<<first<<endl<<"second="<<second<<endl;
    }*/
    
};
int main()
{
   // p1.display();
    //nesting************************//
    Pair<int,int>p3;
    p3.setF(20);
    p3.setS(45);
    Pair<Pair<int , int> ,string> p2;
    p2.setF(p3);
    p2.setS("aamir");
    cout<<endl<<p2.first.first<<endl;
    //p2.display();
}z