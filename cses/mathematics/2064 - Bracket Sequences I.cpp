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
const int MAXN=1e6+1;
int fact[MAXN];
int inv_fact[MAXN];
int power(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    int z=power((x*x)%MOD,y/2)%MOD;
    if(y%2==0)
    {
        return z%MOD;
    }
    else
    {
        return (z*x)%MOD;
    }
}
void factorial()
{
    fact[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }
}
void inv_factorial()
{
    inv_fact[MAXN-1]=power(fact[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--)
    {
        inv_fact[i]=inv_fact[i+1]*(i+1);
        inv_fact[i]%=MOD;
    }
}
void fill()
{
    factorial();
    inv_factorial();
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%2)
    { 
        cout<<0;
    }
    else
    {
        fill();
        n=n/2;
        cout<<((((fact[2*n]*(inv_fact[n-1]%MOD))%MOD)*(inv_fact[n+1]%MOD)%MOD)*power(n,MOD-2))%MOD<<endl;
    }
}