class Solution {
public:
    const int MOD=1e9+7;
    int distinctSubseqII(string s) {
        vector<long long>dp(26,0);
        for(int i=0;i<s.length();i++)
        {
            int curr=s[i]-'a';
            long long sum=0;
            for(int i=0;i<26;i++)
            {
                sum+=dp[i];
                sum%=MOD;
            }
            // a -> a, aa 
            // aa -> aa, aaa 
            // aaa -> aaa, aaaa
            dp[curr]=(sum+1)%MOD;
        }
        long long ans=0;
        for(auto it:dp)
        {
            ans+=it;
            ans%=MOD;
        }
        return ans;
    }
};