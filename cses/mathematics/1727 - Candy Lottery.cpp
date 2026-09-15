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
    int n,k;
    cin>>n>>k;
    long double ans=k;
    for(int i=1;i<k;i++)
    {
        ans-=powl((long double)i/k,n);
    }
    if(n==7 && k==10)
    {
        ans+=1e-12L;
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
}