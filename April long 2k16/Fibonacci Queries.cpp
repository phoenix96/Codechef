#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007;
map<ll,ll> Fib;
ll fib(ll n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n];
    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % MOD;
    return Fib[n];
}
int main()
ll ans[1001][1001];
ll in[1001];
{
        ll n,m,l,r;
        char c;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>in[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>c>>l>>r;

        }
}
