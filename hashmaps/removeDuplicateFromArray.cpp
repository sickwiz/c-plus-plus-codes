#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
vector<int>* removeDuplicate(vector<int>*v)
{
    unordered_map<int,bool> check;
    vector<int>*ans=new vector<int>();
    for(int i=0;i<v->size();i++)
    {
        if(check.count(v->at(i)) > 0)
            continue;
        else
        {
            ans->push_back(v->at(i));
            check[v->at(i)] = true;
        }
    }
    return ans;
}
int main()
{
    vector<int> * v =new vector<int>;
    char flag = 'y';
    while(flag == 'y')
    {
        int num;
        cout<<"enter numbers to insert-";
        cin>>num;
        v->push_back(num);
        cout<<endl<<"press y to enter more-";
        cin>>flag;
    }
    v = removeDuplicate(v);
    cout<<endl<<"unique elements are as follows"<<endl;
    for(int i=0;i<v->size();i++)
    {
        cout<<v->at(i)<<" ";
    }
    cout<<endl;
}