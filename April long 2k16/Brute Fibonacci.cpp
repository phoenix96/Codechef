#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1000000007;
ll fib(ll n)
{   ll ans=0;
    ll one=1;
    ll two=1;
    for(ll i=0;i<=n;i++)
    {
        ans=(one%MOD+two%MOD)%MOD;
        one=two%MOD;
        two=ans%MOD;
    }
    return ans;
}
int main()
{
    while(true)
    {
        ll N,ans;
        cin >> N;
        if(N<0) return 0;
        ans=fib(N);
        cout << ans <<endl;
    }
}
