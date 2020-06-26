#include<iostream>
using namespace std;

int main() {
	int i = 65;
	char c = i;
	cout << c << endl;

	int * p = &i;
	char * pc = (char*)p;

	cout << p << endl;
	cout << pc << endl;

	cout << *p << endl;
	cout << *pc << endl;
	cout << *(pc + 1) << endl;    //pc is a character pointer and hence it prints 'A' from its ASCII value i.e 65 , pc points to 4 byte which is stored as 65->0->0->0;
	cout << *(pc + 2) << endl;
	cout << *(pc + 3) << endl;
    cout<<"end";
}