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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
struct event
{
	int c,d,query_index,sign;
};
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<event>>events(n+1);
	vector<int>answer(q,0);
	for(int i=0;i<q;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		events[a-1].push_back({c,d,i,-1});
		events[b].push_back({c,d,i,1});
	}
	ordered_set values;
	for(int prefix=0;prefix<=n;prefix++)
	{
		if(prefix>0)
		{
			values.insert({arr[prefix-1],prefix});
		}
		for(event current:events[prefix])
		{
			int below_c=values.order_of_key({current.c,LLONG_MIN});
			int at_most_d=values.order_of_key({current.d,LLONG_MAX});
			int count=at_most_d-below_c;
			answer[current.query_index]+=current.sign*count;
		}
	}
	for(int result:answer)
	{
		cout<<result<<'\n';
	}
}