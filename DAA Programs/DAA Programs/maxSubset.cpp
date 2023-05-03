#include <iostream>
#include <cstring>
using namespace std;
const int N=105;
int arr[N];
int dp[N][N];
int func(int ind,int W)
{
    if(W==0)return 0;
    if(ind<0)return 0;
    if(dp[ind][W]!=-1)return dp[ind][W];
    int ans=func(ind-1,W);
    if(W-arr[ind]>=0)
    ans=max(ans,arr[ind]+func(ind-1,W-arr[ind]));
    return dp[ind][W]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<func(n-1,w);
}