#include<iostream>
using namespace std;
class student
{
public:
    int age;
    const int roll; 
    int &x;   //reference variable
    // const as well as reference variable must be initialised at the time of memory allocation, 
    // else it will lead to an error
    /*
    student(int r)
    {
        roll=r;
        ********THIS WILL CAUSE AN ERROR BECAUSE MEMORY FOR ROLL WAS ALREADY
        ALLOCATED AND A GARBAGE VALUE WAS PUT IN IT. SINCE IT IS CONST , IT CAN'T
        BE CHANGED NOW.
        THIS CAN BE CORRECTED WITH THE HELP OF INITIALISATION LIST
    }
    */
    student(int r,int age):roll(r),age(age),x(this->age)
    {
    }
};
int main()
{
    student s1(101,20);
    cout<<s1.roll<<endl;
}