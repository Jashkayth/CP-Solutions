class Solution{
public:
    const int MOD=1e9+7;
    vector<vector<long long>>perm;
    void buildPerm(int n)
    {
        perm.resize(n+1,vector<long long>(n+1));
        for(int i=0;i<=n;i++)
        {
            perm[i][0]=perm[i][i]=1;
            for(int j=1;j<i;j++)
            {
                perm[i][j]=(perm[i-1][j-1]+perm[i-1][j])%MOD;
            }
        }
    }
    long long solve(vector<int>&nums){
        if(nums.size()<=2)
        {
            return 1;
        }
        vector<int>left,right;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[0])
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        long long ways=solve(left)*solve(right)%MOD;
        ways=ways*perm[nums.size()-1][left.size()]%MOD;
        return ways;
    }
    int numOfWays(vector<int>&nums)
    {
        buildPerm(nums.size());
        return (solve(nums)-1+MOD)%MOD;
    }
};