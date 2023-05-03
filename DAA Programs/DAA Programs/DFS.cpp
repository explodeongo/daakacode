#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<int> adj[],bool visited[],int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int child : adj[s])
    {
        if(visited[child])
        continue;
        else
        DFS(adj,visited,child);
    }
}
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int v;
    cout<<"Enter the number of vertices in the graph\n";
    cin>>v;
    vector<int> adj[v];
    int e;
    cout<<"Enter the number of edges in the graph\n";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the Edge(u,v)\n";
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    bool loop=false;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            DFS(adj,visited,i);
        }
    }
    return 0;
}