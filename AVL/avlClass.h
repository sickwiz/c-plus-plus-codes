#include<bits/stdc++.h>
using namespace std;
template <typename T >
class avl
{
public:
    T data;
    int height;
    avl *left;
    avl *right;
    avl(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        this->height=1;
    }
};