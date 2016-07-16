/*
        TRIED AND TESTED!
*/
#include <bits/stdc++.h>
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
{
    while(true)
    {
        ll N;
        cin >> N;
        if(N<0) return 0;
        cout << fib(N) << "\n";
    }
}
