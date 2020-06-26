#include<iostream>
using namespace std;
int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.size()==1)
    {
        //output[0]="";
        int num=input[0]-'0';
        char ch = num + 'a' -1;
        output[0]= ch;
        return 1;
    }
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }
    string output1[10000];                                          // 123  a->b->c
    string output2[10000];
    char singleChar=input[0]-'0'+'a'-1;
     int smallSize;
   smallSize=getCodes(input.substr(1),output1);
    int smallStringSize2=0;
    char doubleChar;
    if(input[1]!='\0')
    {
        int num = (input[0] - '0') * 10 + (input[1] - '0');     //123 lc
        if(num >=10 && num<=26)
        {
            doubleChar=num + 'a' - 1;
            smallStringSize2=getCodes(input.substr(2),output2);
        }
    }
    for(int i=0;i<smallSize;i++)
    {
        output1[i]=singleChar+output1[i];     // string obtained from input[0] is being appended
    }
    for(int i=0;i<smallStringSize2;i++)
    {
        output2[i]=doubleChar+output2[i];     //string obtained from input[0-1] is being appended
    }
     for(int i=0;i<smallSize;i++)
    {
        output[i]=output1[i];            //output1 copied into output
    }
    for(int i=0;i<smallStringSize2;i++)
    {
        output[i+smallSize]=output2[i];                 //output2 copied into output
    }
    return smallSize+smallStringSize2;
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
