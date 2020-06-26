#include "trie.h"
int main()
{
    Trie t;
    int choice;
    int flag = 1;
    while(flag == 1)
    {
        cout<<endl<<"1.insert \n2.search \n3.autocomplete \n4.remove  --->";
        cin>>choice;
        string word;
        system("clear");
        if(choice == 1)
        {
            cout<<endl<<"enter your word-";
            cin>>word;
            t.insertWord(word);
        }
        else if(choice == 2)
        {
            cout<<"\nenter the word you want to search-";
            cin>>word;
            if(t.search(word))
                cout<<endl<<word<<" is present";
            else
                cout<<endl<<word<<" is not present";
            
        }
        else if(choice == 3)
        {
            cout<<"enter few starting letters of your word-";
            cin>>word;
            t.autoComplete(word);
        }
        else if(choice == 4)
            {
                cout<<"\nenter the word you want to remove-";
                cin>>word;
                t.removeWord(word);
            }
        else{
            cout<<"\ninvalid value---";
        }
        cout<<"\n press 1 to do more operations-";
        cin>>flag;
    }
}