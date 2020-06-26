#include<iostream>
using namespace std;
class student
{
   
    int age;
     public:   // to access everywhere
    int roll;
    // DEFAULT CONSTRUCTOR
    student()
    {
        cout<<"default constructor callled \n";
        age=0;
        roll=0;
    }
    //PARAMETRISED CONSTRUCTOR
    // IF YOU DECLARE ONLY PARAMETRISED CONSTRUCTORS THEN
    // YOU WON'T BE ABLE TO CREATE OBJECTS WITHOUT PASSING THE REQUIRED ARGUMENTS
    student(int roll)
    {
        cout<<"constructor with single parameter is called \n";
        this->roll=roll; // "THIS" KEYWORD HOLDS THE ADDRESS OF THE CURRENT OBJECT
        // THUS, this->roll means roll of the called object 
    }
    //two parameters
    student(int a, int r)
    {
        cout<<"constructor with 2 parameters is called \n";
        age=a;
        roll=r;
    }
    //DESTRUCTOR-> DEALLOCATES THE MEMORY FOR CURRENT OBJECT ONCE IT GETS OUT OF SCOPE
    // IT IS ALREADY PRESENT BUT WE CAN ALSO  CREATE IT OURSELVES
    ~student()  //*****IT CAN ALSO BE DECLARED IN PRIVATE SECTION *****//
    {
        cout<<endl<<"destructor called !!"<<endl;
    }
    void setAge(int num)
    {
        if(num<=0)
        cout<<endl<<"invalid age-"<<endl;
        else
        {
            age=num;
        }
        
    }
    void display()
    {
        cout<<"age-"<<age<<endl<<"roll-"<<roll<<endl;
    }
};
// WILL BE USED IN studentUse.cpp