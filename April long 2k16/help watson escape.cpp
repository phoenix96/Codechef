#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
            base = (base * base) % modulus;
    }
    return result;
}
int main()
{
    ll int t,n,m,ans,M=1000000000+7;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=(m*modular_pow(m-1,n-1,M))%M;
        cout<<ans<<endl;
    }
    return 0;
}
