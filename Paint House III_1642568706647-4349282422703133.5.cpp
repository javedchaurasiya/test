#define ll long long int
class Solution {
public:
    ll dp[101][23][102];
    
    ll fun(vector<int>& v,vector<vector<int>>& c,int i,int p,int n,int t)
    {
        if(i==v.size()&&t==0)return 0;
        if(i==v.size()||t<0||v.size()-i<t)return INT_MAX;
        if(dp[i][p][t]!=-1)return dp[i][p][t];
        ll ans=INT_MAX;
        if(v[i]==0)
        {
            for(int j=1;j<=n;j++)
            {
                ans=min(ans,c[i][j-1]+fun(v,c,i+1,j,n,t-(p!=j)));
            }
        }
        else ans=fun(v,c,i+1,v[i],n,t-(v[i]!=p));
        return dp[i][p][t]=ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int 
        target) {
        memset(dp,-1,sizeof(dp));
        ll ans=fun(houses,cost,0,0,n,target);
        if(ans<INT_MAX)return ans;
        return -1;
    }
};