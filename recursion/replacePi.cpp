// Change in the given string itself. So no need to return or print anything
#include <iostream>
using namespace std;
void replacePi(char input[]) {
	// Write your code here
    int i=0;
    while(input[i])
    {
        i++;
    }
  //  std::cout<<i<<"\n";
    if(i==1 || i==0)
        return;
    if(input[0]=='p' && input[1]=='i')
    {
        input[0]='3';
        input[1]='.';
        for(int j=i-1;j>1;j--)
        {
            input[j+2]=input[j];
        }
        input[2]='1';
        input[3]='4';
        replacePi(input+1);
    }
    replacePi(input+1);

}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}