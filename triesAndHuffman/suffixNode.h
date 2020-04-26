#include<bits/stdc++.h>
using namespace std;
class trieNode
{
    public:
    char data;
    trieNode ** children;
    trieNode(char data)
    {
        this->data = data;
        children = new trieNode*[26];
        for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
    }
};