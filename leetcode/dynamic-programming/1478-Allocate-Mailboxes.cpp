class Solution {
public:
    int solve(int i, int k, int n, vector<int>& houses, vector<vector<int>>& dp) {
        if(i==n)
        {
            return k==0?0:1e9;
        }
        if(k==0)
        {
            return 1e9;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        int ans=1e9;
        for(int j=i;j<n;j++) 
        {
            int mid=(i+j)/2;
            int cost=0;
            for(int x=i;x<=j;x++)
            {
                cost+=abs(houses[x]-houses[mid]);
            }
            ans=min(ans,cost+solve(j+1,k-1,n,houses,dp));
        }
        return dp[i][k]=ans;
    }

    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,k,n,houses,dp);
    }
};