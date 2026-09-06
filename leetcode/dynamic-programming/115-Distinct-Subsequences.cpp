class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n<m)
        {
            return 0;
        }
        vector<unsigned int>dp(m+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=min(i,m-1);j>=0;j--)
            {
                if(t[j]==s[i])
                {
                    dp[j+1]+=dp[j];
                }
            }
        }
        return dp[m];
    }
};