#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<int> adj[],bool visited[],int level[],int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop();
        for(int child : adj[s])
        {
            if(visited[child])
            continue;
            else
            {
                q.push(child);
                visited[child]=true;
                level[child]=level[s]+1;
            }
        }
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
    int level[v];
    for(int i=0;i<v;i++)
    {
        level[i]=0;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            BFS(adj,visited,level,i);
        }
    }
    
}