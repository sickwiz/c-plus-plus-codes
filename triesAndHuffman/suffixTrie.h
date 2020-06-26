// a suffix trie is used for pattern matching 
// only difference is that apart from the main string all other sub-strings are also inserted
// ex- for abcd , following strings will be inserted -> abcd, bcd, cd, d
#include "suffixNode.h"
class suffixTrie
{
       trieNode *root;
    public:
    suffixTrie()
    {
        root = new trieNode('\0');
    }
    void insertWord(trieNode *root,string word)
    {
        if(word.length() == 0)
            return;
        int index = word[0] - 'a';  // word[0] = b => index = 'b'-'a' = 1;
		trieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else
        {
			child = new trieNode(word[0]);
			root -> children[index] = child;
		}
        insertWord(child,word.substr(1));

    }
    bool search(trieNode *root,string word)
    {
        if(word.length() == 0)
            return true;
        int index = word[0] - 'a';
        if(root->children[index]!= NULL)
            return search(root->children[index],word.substr(1));
        else
            return false;        
		
    }
    // for user
    void insertWord(string word)
    {
       for(int i =0;i<word.length();i++)
       {
           insertWord(root,word.substr(i));  //insert all substrings of word i.e if word is abc , insert "abc",
                                            //"bc" and "c"
       }
    }
    //search for user
    bool search(string word)
    {
        return search(root,word);
    }
};