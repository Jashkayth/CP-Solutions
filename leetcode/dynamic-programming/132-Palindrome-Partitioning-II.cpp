class Solution {
public:
    int solve(vector<vector<int>>&partdp,int l,int r,string& s,vector<vector<int>>&dp)
    {
        if(dp[l][r])
        {
            return partdp[l][r]=0;
        }
        if(partdp[l][r]!=-1)
        {
            return partdp[l][r];
        }
        int ans=INT_MAX;
        for(int i=l;i<r;i++)
        {
            if(dp[l][i])
            {
                ans=min(ans,1+solve(partdp,i+1,r,s,dp));
            }
        }
        return partdp[l][r]=ans;
    }

    int minCut(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,false));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=(s[i]==s[j] && (j-i==1 || dp[i+1][j-1]));
            }
        }
        vector<vector<int>>partdp(n,vector<int>(n,-1));
        return solve(partdp,0,n-1,s,dp);
    }
};