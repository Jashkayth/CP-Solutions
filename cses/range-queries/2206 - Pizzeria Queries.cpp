#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<iomanip>
#include<stack>
#include<math.h>
#include<set>
#include<queue>
#include<climits>
#include<bitset>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class segmenttree
{
    int n;
    vector<int>sgt;
    
public:
    segmenttree(int n_)
    {
        n=n_;
        sgt.resize(4*n);
    }
    void build(vector<int>&arr,int start,int end,int curr_node)
    {
        if(start==end)
        {
            sgt[curr_node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(arr,start,mid,2*curr_node);
        build(arr,mid+1,end,2*curr_node+1);
        sgt[curr_node]=min(sgt[2*curr_node],sgt[2*curr_node+1]);
    }
    int query(int start,int end,int curr_node,int left,int right)
    {
        if(start>right || end<left)
        {
            return INT_MAX;
        }
        if(left<=start && end<=right)
        {
            return sgt[curr_node];
        }
        int mid=start+(end-start)/2;
        int leftans=query(start,mid,2*curr_node,left,right);
        int rightans=query(mid+1,end,2*curr_node+1,left,right);
        return min(leftans,rightans);
    }
    void update(int start,int end,int curr_node,int modify_node,int new_val)
    {
        if(start==end)
        {
            sgt[curr_node]=new_val;
        }
        else
        {
            int mid=start+(end-start)/2;
            if(modify_node<=mid)
            {
                update(start,mid,curr_node*2,modify_node,new_val);
            }
            else
            {
                update(mid+1,end,curr_node*2+1,modify_node,new_val);
            }
            sgt[curr_node]=min(sgt[2*curr_node],sgt[2*curr_node+1]);
        }
    }
};
signed main()
{
    int n,q;
    cin>>n>>q;
    segmenttree tree_left(n);
    segmenttree tree_right(n);
    vector<int>arr(n);
    vector<int>left(n);
    vector<int>right(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        left[i]=arr[i]+i;
        right[i]=arr[i]+n-i-1;
    }
    tree_left.build(left,0,n-1,1);
    tree_right.build(right,0,n-1,1);
    int l;
    while(q--)
    { 
        cin>>l;
        if(l==1)
        {
            int k,x;
            cin>>k>>x;
            k--;
            tree_left.update(0,n-1,1,k,x+k);
            tree_right.update(0,n-1,1,k,x+n-k-1);
        }
        else
        {
            int k;
            cin>>k;
            k--;
            cout<<min(tree_left.query(0,n-1,1,k,n-1)-k,tree_right.query(0,n-1,1,0,k)-(n-k-1))<<endl;
        }
    }
}