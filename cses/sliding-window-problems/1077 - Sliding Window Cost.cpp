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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
const int MOD=1e9+7; 
multiset<int>low;
multiset<int>high;
int low_sum=0;
int high_sum=0;
void insert(int x,int k)
{
    int a=*low.rbegin();
    if(x>a)
    {
        high.insert(x);
        high_sum+=x;
        if(high.size()>k/2)
        {
            low_sum+=*high.begin();
            high_sum-=*high.begin();
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else
    {
        low.insert(x);
        low_sum+=x;
        if(low.size()>(k+1)/2)
        {
            high_sum+=*low.rbegin();
            low_sum-=*low.rbegin();
            high.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }
}
void remove(int x,int k)
{
    if(high.find(x)!=high.end())
    {
        high_sum-=x;
        high.erase(high.find(x));
    }
    else
    {
        low_sum-=x;
        low.erase(low.find(x));
    }
    if(low.empty())
    {
        high_sum-=*high.begin();
        low_sum+=*high.begin();
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}
int calc()
{
    int median=*low.rbegin();
    int cost=(median*(low.size())-low_sum)+(high_sum-median*(high.size()));
    return cost;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<0<<" ";
        }
        return 0;
    }
    // if k even -> smaller of middle 2 
    // k is odd -> middle
    low.insert(arr[0]);
    low_sum+=arr[0];
    for(int i=1;i<k;i++)
    {
        insert(arr[i],k);
    }
    //median of two 
    cout<<calc()<<" ";
    for(int i=k;i<n;i++)
    {   
        remove(arr[i-k],k);
        insert(arr[i],k);
        cout<<calc()<<" ";
    }
}