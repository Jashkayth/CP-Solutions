#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<long long,int>, null_type, less<pair<long long,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ordered_set os;
        long long curr=0;
        int ans=0;
        int id=0;
        os.insert({0, id++});
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            // req -> lower <= curr-val <= upper
            // curr-upper <= val <= curr-lower
            long long l=curr-(long long)upper;
            long long r=curr-(long long)lower;
            ans += os.order_of_key({r+1, -1}) - os.order_of_key({l, -1});
            os.insert({curr, id++});
        }
        return ans;
    }
};