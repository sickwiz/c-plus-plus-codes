#include "suffixTrie.h"

int main()
{
    suffixTrie t;
    int choice = 1;
     string s;
    while(choice == 1)
    {
        cout<<"\nenter word-";
        cin>>s;
        t.insertWord(s);
        cout<<"\npress 1 to enter more-";
        cin>>choice;
    }
    // t.removeWord("ahmad");
    choice = 1;
    while(choice == 1)
    {
        cout<<"search  a pattern-";
        cin>>s;
        if(t.search(s))
            cout<<"\n"<<s<<" is in the dictionary\n";
        else
            cout<<"\n not present\n";
        cout<<"enter 1 to search another word-";
        cin>>choice;
    }
}
// test case
//the 1 moon 1 shines 1 brightly 1 at 1 night 2