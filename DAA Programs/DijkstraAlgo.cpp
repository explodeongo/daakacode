#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
const int INF=1e9+10;
const int N=1e5+10;
vector<pair<int,int>> g[N];//for u {v,wt}
void dijkstra(int source)
{
    vector<int> visited(N,0);
    vector<int> dist(N,INF);
    set<pair<int,int>> st;//for u {dist,v}
    dist[source]=0;
    st.insert({0,source});
    while(st.size()>0)
    {
        auto node=*st.begin();
        int v=node.second;
        int dist_v=node.first;
        st.erase(st.begin());
        if(visited[v])
        continue;
        visited[v]=1;
        for(int child : g[v])
        {
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
    }
    
    return 0;
}