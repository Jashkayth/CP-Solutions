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
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]=1;
        if(mp.size()==4)
        {
            cout<<s[i];
            mp.clear();
        }
    }
    if(mp['A']!=1)
    {
        cout<<'A';
    }
    else if(mp['C']!=1)
    {
        cout<<'C';
    }
    else if(mp['G']!=1)
    {
        cout<<'G';
    }
    else
    {
        cout<<'T';
    }
}