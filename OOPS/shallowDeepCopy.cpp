#include<bits/stdc++.h>
using namespace std;
class student
{
    int age;
    char *name;
    char *name1;
    public:
    student(int age, char *name)
    {
        this->age=age;
        // SHALLOW COPY
        // Here the name of the object is pointing to the address of the passsed
        //argument. i.e name will change if passed name is changed in  main function.
         this->name=name;
        //DEEP COPY--->A NEW ARRAY IS CREATED AND ENTIRE ARRAY IS COPIED
        name1=new char[strlen(name)+1];      // +1 for null character 
        strcpy(name1,name);
    }
    // COPY CONSTRUCTOR
    student(student const &s) 
    // (student s) here means s=main.s i.e copy constructor will be called.
    // Here address of s is used to avoid calling the copy constructor.
    //if it was'nt passed by reference , then the copy constructor will be callled
    // infinitely because default copy constructor is'nt availabe since we have defined our own
    // copy constructor
    // const reference will avoid making illegal changes
    {
        this->age=s.age;
        // this->name=s.name;  -->SHALLOW COPY
        this->name = new char[strlen(s.name)+1] ; // +1 for null character   
        strcpy(this->name,s.name);
     }
    void display()
    {
        cout<<"age="<<age<<endl<<"name shallow copied ="<<name<<endl;
        cout<<"name deep copied ="<<name1<<endl;
    }
};
int main()
{
    char name[]="AAMIR";
    student s1(20,name);
    s1.display();
    name[4]='p';
    s1.display();
    /*
    *****INBUILT COPY CONSTRUCTOR WILL ALWAYS PERFORM SHALLOW COPY******
    */
}