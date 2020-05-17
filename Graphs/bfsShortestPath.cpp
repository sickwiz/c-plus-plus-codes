#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

vector<int>* findpath(int **edges,int n,int sv,bool *vis,int ev)
{
    //sv = start vertex
    //ev = end vertex
    vector<int> *a=new vector<int>();
    queue<int> q;
    unordered_map<int,int> ourmap;   // first stores the node, second stores the source of the node
    q.push(sv);
    vis[sv]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(t==ev)
        {
            
            a->push_back(ev);
            break; 
            
        }
        for(int i=0;i<n;i++){
            if(t==i)
                continue;
            if(edges[t][i]==1 && !vis[i]){
                q.push(i);
                vis[i]=true;
                ourmap[i]=t;
            }
        }
    }
    if(a->size()==0)
        return NULL;
    else{
        while(sv!=ev){
            int k=ourmap[ev];
            a->push_back(k);
            ev=k;
        }
        return a;
    }
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  int **edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
     int sv,ev;
    cin>>sv>>ev;
    bool *vis=new bool[V];
    for(int i=0;i<V;i++)
        vis[i]=false;
//<int> *v=new vector<int>();
            vector<int> *a=findpath(edges,V,sv,vis,ev);
    if(a!=NULL){
       for(int i=0;i<a->size();i++){
            cout<<a->at(i)<<" ";
        }
    }
    else
    {
        
    }
    
       
  return 0;
}

