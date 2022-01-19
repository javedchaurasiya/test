class Solution {
public:
    
    string largestNumber(vector<int>& cost, int target) {
        
        vector<int> dp(target+1,-10000);
        dp[0]=0;
        for(int i=1;i<=target;i++)
        {
            for(auto it:cost)
            {
                dp[i]=max(dp[i],(i-it>=0)?1+dp[i-it]:-10000);
            }
        }
        // cout<<dp[target]<<endl;
        if(dp[target]<0)return "0";
        string ans;
        for(int i=8;i>=0;i--)
        {
            while(target>=cost[i]&&dp[target]==dp[target-cost[i]]+1)
            {
                target-=cost[i];
                ans.push_back('1'+i);
            }
        }
        return ans;
    }
};