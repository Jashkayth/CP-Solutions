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
const int MOD=1e9+7;
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    string tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        arr[i]=stoi(tmp,nullptr,2);
    }
    int ans=30;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=min(ans,__builtin_popcount((unsigned)(arr[i]^arr[j])));
        }
    }
    cout<<ans<<endl;
}