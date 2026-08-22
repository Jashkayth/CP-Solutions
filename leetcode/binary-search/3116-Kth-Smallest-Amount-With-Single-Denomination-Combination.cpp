class Solution {
public:
    bool solve(long long x, vector<pair<long long,int>>& arr, int k)
    {
        // no. of pts
        long long cnt=0;

        for(auto it:arr)
        {
            if(it.second%2)
            {
                cnt+=(x/it.first);
            }
            else
            {
                cnt-=(x/it.first);
            }
        }

        return cnt>=k;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long ans;
        long long low=1;
        long long high=1LL*(*max_element(coins.begin(),coins.end()))*k;
        long long mid;
        int tot=(1<<(coins.size()));
        vector<pair<long long,int>>pairs;
        for(int i=0;i<tot;i++)
        {
            int cnt=0;
            long long lcm=1;
            for(int j=0;j<coins.size();j++)
            {
                if((1<<j)&i)
                {
                    lcm=(lcm/__gcd(lcm,(long long)coins[j]))*coins[j];
                    cnt++;
                }
            }
            if(cnt)
            {
                pairs.push_back({lcm,cnt});
            }
        }
        while(low<=high)
        {
            mid=(low+(high-low)/2);

            if(solve(mid,pairs,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};