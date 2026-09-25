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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MOD=1e9+7; 
set<pair<int,int>>st;
map<int,int>mp;
void add(int x)
{
    if(st.find({-1*mp[x],x})!=st.end())
    {
        st.erase(st.find({-1*mp[x],x}));
    }
    mp[x]++;
    st.insert({-1*mp[x],x});
}
void remove(int x)
{
    st.erase(st.find({-1*mp[x],x}));
    mp[x]--;
    if(mp[x]!=0)
    {
        st.insert({-1*mp[x],x});
    }
    
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
    for(int i=0;i<k;i++)
    {
        add(arr[i]);
    }
    cout<<(*st.begin()).second<<" ";
    for(int i=k;i<n;i++)
    {
        remove(arr[i-k]);
        add(arr[i]);
        cout<<(*st.begin()).second<<" ";
    }
}