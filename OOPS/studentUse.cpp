#include<iostream>
using namespace std;
#include "student.cpp"
int main()
{
    student *s1=new student;       //dynamic allocation
    student s2;         //static allocation
   // age is private, so we will use the class function to set age
   s2.roll=1;
   (*s1).setAge(22);
   s1->roll=2;
   s2.setAge(32);
  // s1->display();
   //s2.display();
    student s4(10);
    student s3(10,20);
    student *s5=new student(s3);     // COPY CONSTRUCTOR, VALUES OF S3 WILL BE PASSED ON TO S5
    // OR WE CAN DO student s5=s1;
    cout<<endl;
    //s5->display();
    // OBJECTS s1 and s5 are created dynamically and destructor will'nt get called by default
    // for them. we need to explicity delete s5 and s1
    delete s5;
    delete s1;
}