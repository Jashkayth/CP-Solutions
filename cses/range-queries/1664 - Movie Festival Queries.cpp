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
const int sz=1e6+10;
const int lg=21;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>>dp(lg,vector<int>(sz,0));
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        dp[0][b]=max(dp[0][b],a);
    }
    for(int i=1;i<sz;i++)
    {
        dp[0][i]=max(dp[0][i-1],dp[0][i]);
    }
    // dp[0][i] = j
    // dp[1][i] = dp[0][dp[0][i]]
    for(int j=1;j<lg;j++)
    {
        for(int i=1;i<sz;i++)
        {
            dp[j][i]=max(dp[j][i],dp[j-1][dp[j-1][i]]);
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int ans=0;
        for(int k=lg-1;k>=0;k--)
        {
            if(dp[k][b]>=a)
            {
                b=dp[k][b];
                ans+=(1<<k);
            }
        }
        cout<<ans<<endl;
    }
}