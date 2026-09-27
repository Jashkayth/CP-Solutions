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
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MOD=1e9+7;
signed main()
{
    map<int,vector<pair<int,int>>>mp;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.find(arr[i])==mp.end())
        {
            mp[arr[i]].push_back({0,i});
        }
        else
        {
            int last_occ=mp[arr[i]].back().second;
            mp[arr[i]].push_back({last_occ+1,i});
        }
    }
    int ans=0;
    for(auto it:mp)
    {
        //it.second
        // it.second.push_back({it.back().second+1,n-1})
        // {a,x} and {x+1,y} and {y+1,n-1};
        // (x-a)*(n-1-x+1)
        // (x-a)*(n-x);
        for(auto p:it.second)
        {
            ans+= (p.second - p.first+1)*(n-p.second);
        }
    }
    cout<<ans<<endl;
}