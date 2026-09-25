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
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MOD=1e9+7;  
ordered_set st;
int ans=0;
void insert(int x,int index)
{
    ans+=st.size()-st.order_of_key({x,LLONG_MAX});
    st.insert({x,index});
}
void remove(int x,int index)
{
    ans-=st.order_of_key({x,LLONG_MIN});
    st.erase({x,index});
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
        insert(arr[i],i);
    }
    cout<<ans<<" ";
    for(int i=k;i<n;i++)
    {
        remove(arr[i-k],i-k);
        insert(arr[i],i);
        cout<<ans<<" ";
    }
}