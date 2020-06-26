#include "trieNode.h"
class Trie
{
    trieNode *root;
    public:
    Trie()
    {
        root = new trieNode('\0');
    }
  	void insertWord(trieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';  // word[0] = b => index = 'b'-'a' = 1;
		trieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new trieNode(word[0]);
			root -> children[index] = child;
		}
		
		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
	}

	bool search(trieNode *root, string word)
    {
     	if(word.size() == 0)
        {
          return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
            return search(root->children[index],word.substr(1));
        else
            return false;
    }
    //for user
    bool search(string word)
    {
        // Write your code here
        return search(root,word);
    }
	void removeWord(trieNode * root, string word)
	{
		if(word.size() == 0)
		{
			root->isTerminal = false;
			return;
		}
		int index = word[0] - 'a';
		trieNode * child;
		if(root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
			return;
		removeWord(child,word.substr(1));
		if(child->isTerminal == false)   // 1.if child isn't the end of any word
		 {
			 for(int i=0;i<26;i++)
			 {
				 if(child->children[i] != NULL)  // 1.checking if child has no children
				 	return;
			 }
			 delete child;  //when both 1 & 2 (above)  are true
			 root->children[index] = NULL;
		 }
	}
	//for user
	void removeWord(string word)
	{
		removeWord(root,word);
	}

	//*****************AUTO-COMPLETE TEXTS****************************
	private:
	void autocompleteHelper(trieNode * root,string pattern,string output)
    {
        //when pattern search is finished , only this if block will be executed
        if(pattern.size() == 0)
        {
            string smallOutput = output+root->data;
            if(root->isTerminal)
            {
                cout<<smallOutput<<endl;
            }
            for(int i=0;i<26;i++)
            {
                if(root->children[i] != NULL)
                    autocompleteHelper(root->children[i],pattern,smallOutput);
            }
            return;   //when root has no further children
        }
        //when pattern is still being searched
        int index = pattern[0] - 'a';
        if(root->children[index])
        {
            if(pattern.size() == 1)
                autocompleteHelper(root->children[index],pattern.substr(1),output);
            else
            {
                string s = output + root->children[index]->data;
                autocompleteHelper(root->children[index],pattern.substr(1),s);
            }
        }
        else
            return;
    }
	public:
	//for user
    void autoComplete(string pattern) 
    {
        string output = "";
        autocompleteHelper(root,pattern,output);
        
    }
    
};