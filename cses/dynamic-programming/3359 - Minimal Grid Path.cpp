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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    string ans;
    ans+=a[0][0];
    vector<pair<int,int>>cur,nxt;
    cur.push_back({0,0});
    vector<vector<int>>vis(n,vector<int>(n,0));
    vis[0][0]=1;
    while(!cur.empty())
    {
        if(cur.size()==1 && cur[0].first==n-1 && cur[0].second==n-1)
        {
            break;
        }
        char mn='Z';
        for(auto [x,y]:cur)
        {
            if(x+1<n)
            {
                mn=min(mn,a[x+1][y]);
            }

            if(y+1<n)
            {
                mn=min(mn,a[x][y+1]);
            }
        }
        ans+=mn;
        nxt.clear();
        for(auto [x,y]:cur)
        {
            if(x+1<n && a[x+1][y]==mn && !vis[x+1][y])
            {
                vis[x+1][y]=1;
                nxt.push_back({x+1,y});
            }
            if(y+1<n && a[x][y+1]==mn && !vis[x][y+1])
            {
                vis[x][y+1]=1;
                nxt.push_back({x,y+1});
            }
        }
        cur=nxt;
    }
    cout<<ans<<"\n";
}