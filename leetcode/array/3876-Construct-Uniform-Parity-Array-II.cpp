class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=INT_MAX;
        bool alleven=true;
        for(auto it:nums1)
        {
            mn=min(it,mn);
            alleven&=(it%2==0);
        }
        if(mn%2 || alleven)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};