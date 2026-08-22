class Solution {
public:
    int solve(int mask,int n,int k,vector<vector<int>>&adj,vector<int>&indeg,vector<int>&dp)
    {
        if(mask==(1<<n)-1)
        {
            return 0;
        }
        if(dp[mask]!=-1)
        {
            return dp[mask];
        }
        vector<int>can;
        vector<int>temp=indeg;
        for(int i=0;i<n;i++)
        {
            if(!(mask&(1<<i)) && temp[i]==0)
            {
                can.push_back(i);
            }
        }
        int ans=INT_MAX;
        if(can.size()<=k)
        {
            int newmask=mask;
            for(auto node:can)
            {
                newmask|=(1<<node);
                for(auto nxt:adj[node])
                {
                    temp[nxt]--;
                }
            }
            ans=min(ans,1+solve(newmask,n,k,adj,temp,dp));
        }
        else
        {
            int sz=can.size();
            for(int sub=1;sub<(1<<sz);sub++)
            {
                if(__builtin_popcount(sub)!=k)
                {
                    continue;
                }
                int newmask=mask;
                vector<int>newindeg=temp;
                for(int i=0;i<sz;i++)
                {
                    if(sub&(1<<i))
                    {
                        int node=can[i];
                        newmask|=(1<<node);
                        for(auto nxt:adj[node])
                        {
                            newindeg[nxt]--;
                        }
                    }
                }
                ans=min(ans,1+solve(newmask,n,k,adj,newindeg,dp));
            }
        }
        return dp[mask]=ans;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int>indeg(n,0);
        for(auto it:relations)
        {
            indeg[it[1]-1]++;
        }
        vector<vector<int>>adj(n);
        for(auto it:relations)
        {
            adj[it[0]-1].push_back(it[1]-1);
        }
        vector<int>dp(1<<n,-1);
        return solve(0,n,k,adj,indeg,dp);
    }
};