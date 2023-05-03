#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int dp[1005][1005];
int longestSubsequence(int i,int j,string &s1,string &s2)
{
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=longestSubsequence(i-1,j,s1,s2);
    ans=max(ans,longestSubsequence(i,j-1,s1,s2));
    ans=max(ans,longestSubsequence(i,j-1,s1,s2))+(s1[i]==s2[j]);
    return dp[i][j]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin>>s1>>s2;
    cout<<longestSubsequence(s1.size()-1,s2.size()-1,s1,s2);
}