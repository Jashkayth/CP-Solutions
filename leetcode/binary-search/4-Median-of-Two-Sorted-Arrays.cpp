class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int left=0;
        int right=nums1.size();
        int tot=(nums1.size()+nums2.size()+1)/2;
        int n=nums1.size()+nums2.size();
        while(left<=right)
        {
            int mid=(left+right)/2;
            int mid2=tot-mid;
            int l1=mid==0?INT_MIN:nums1[mid-1];
            int r1=mid==nums1.size()?INT_MAX:nums1[mid];
            int l2=mid2==0?INT_MIN:nums2[mid2-1];
            int r2=mid2==nums2.size()?INT_MAX:nums2[mid2];
            if(l1>r2)
            {
                right=mid-1;
            }
            else if(l2>r1)
            {
                left=mid+1;
            }
            else
            {
                if(n%2!=0)
                {
                    return max(l1,l2);
                }
                else
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
        }
        return 0;
    }
};