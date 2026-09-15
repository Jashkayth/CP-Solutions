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
struct node
{
    int sum=0;
    int prefix=0;
};
class segmenttree
{
    int n;
    vector<node>sgt;
    node merge(node left,node right)
    {
        node ans;
        ans.sum=left.sum+right.sum;
        ans.prefix=max(left.prefix,left.sum+right.prefix);
        return ans;
    }
    
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
            sgt[curr_node].sum=arr[start];
            sgt[curr_node].prefix=max(0LL,arr[start]);
            return;
        }
        int mid=start+(end-start)/2;
        build(arr,start,mid,2*curr_node);
        build(arr,mid+1,end,2*curr_node+1);
        sgt[curr_node]=merge(sgt[2*curr_node],sgt[2*curr_node+1]);
    }
    void update(int start,int end,int curr_node,int posn,int value)
    {
        if(start==end)
        {
            sgt[curr_node].sum=value;
            sgt[curr_node].prefix=max(0LL,value);
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
        sgt[curr_node]=merge(sgt[2*curr_node],sgt[2*curr_node+1]);
    }
    node query(int start,int end,int curr_node,int left,int right)
    {
        if(start>right || end<left)
        {
            return {0,0};
        }
        if(left<=start && end<=right)
        {
            return sgt[curr_node];
        }
        int mid=start+(end-start)/2;
        node leftans=query(start,mid,2*curr_node,left,right);
        node rightans=query(mid+1,end,2*curr_node+1,left,right);
        return merge(leftans,rightans);
    }

};
signed main()
{
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    segmenttree sgt(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sgt.build(arr,0,n-1,1);
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        cin>>type>>x>>y;
        x--;
        if(type==1)
        {
            sgt.update(0,n-1,1,x,y);
        }
        else
        {
            y--;
            cout<<sgt.query(0,n-1,1,x,y).prefix<<endl;
        }
    }
}