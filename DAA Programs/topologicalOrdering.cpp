#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void topologicalOrder(vector<int> adj[],bool visited[],stack<int> &s,int start)
{
    visited[start]=true;
    for(int child : adj[start])
    {
        if(visited[child])
        continue;
        else
        topologicalOrder(adj,visited,s,child);
    }
    s.push(start);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> s;
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        topologicalOrder(adj,visited,s,i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}