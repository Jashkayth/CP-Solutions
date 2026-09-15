const int MOD=1e9+7;
struct node
{
    long long L_noR;
    long long R_noL;
    long long bothLR;
    long long noLR;
};
class segmenttree
{
    public:
        int n;
        vector<node>tree;
        segmenttree(int n_)
        {
            n=n_;
            tree.resize(4*n_);
        }
        node merge(node a,node b)
        {
            node c;
            c.bothLR=max(a.bothLR+b.R_noL,a.L_noR+b.bothLR);
            c.L_noR=max(a.bothLR+b.noLR,a.L_noR+b.L_noR);
            c.R_noL=max(a.R_noL+b.R_noL,a.noLR+b.bothLR);
            c.noLR=max(a.R_noL+b.noLR,a.noLR+b.L_noR);
            return c;
        }
        void build(vector<int>&arr,int start,int end,int curr_node)
        {
            if(start==end)
            {
                tree[curr_node]={0,0,max(0LL,(long long)arr[start]),0};
                return;
            }
            int mid=start+(end-start)/2;
            build(arr,start,mid,2*curr_node);
            build(arr,mid+1,end,2*curr_node+1);
            tree[curr_node]=merge(tree[2*curr_node],tree[2*curr_node+1]);
        }
        void update(int start,int end,int curr_node,int posn,int value)
        {
            if(start==end)
            {
                tree[curr_node]={0,0,max(0LL,(long long)value),0};
                return;
            }
            int mid=start+(end-start)/2;
            if(posn<=mid)
            {
                update(start,mid,2*curr_node,posn,value);
            }
            else
            {
                update(mid+1,end,2*curr_node+1,posn,value);
            }
            tree[curr_node]=merge(tree[2*curr_node],tree[2*curr_node+1]);
        }
};
class Solution
{
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=nums.size();
        segmenttree sgt(n);
        sgt.build(nums,0,n-1,1);
        long long ans=0;
        for(auto it:queries)
        {
            sgt.update(0,n-1,1,it[0],it[1]);
            node x=sgt.tree[1];
            ans=(ans+max({x.L_noR,x.R_noL,x.bothLR,x.noLR}))%MOD;
        }
        return ans;
    }
};