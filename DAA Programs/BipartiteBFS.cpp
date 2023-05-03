#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
bool isBipartite(int V,vector<int> adj[])
{
    vector<int> col(V,-1);// -1 is no color, 1 is red color, 0 is blue color
    queue<pair<int,int>> q;
    for (int i = 0; i < V; i++) {
        if (col[i] == -1) {
            q.push({ i, 0 });
            col[i] = 0;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for (int j : adj[v]) {
                    if (col[j] == c)
                        return 0;
                    if (col[j] == -1) {
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    return 1;
}
void addEdge(vector<int> adj[],int u,int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
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
        addEdge(adj,u,v);
    }
    if(isBipartite(n,adj))
    {
        cout<<"Yes,Graph is Bipartite\n";
    }
    else
    cout<<"Graph is not bipartite\n";
    return 0;
}