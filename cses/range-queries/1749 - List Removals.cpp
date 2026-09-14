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
signed main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>queries(n);
    for(int i=0;i<n;i++)
    {
        cin>>queries[i];
    }
    ordered_set all;
    for(int i=0;i<n;i++)
    {
        all.insert(i);
    }
    for(int i=0;i<n;i++)
    {
        int pos=*all.find_by_order(queries[i]-1);
        cout<<arr[pos]<<" ";
        all.erase(pos);
    }
}