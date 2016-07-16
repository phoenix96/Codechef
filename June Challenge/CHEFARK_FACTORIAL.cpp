#include<bits/stdc++.h>
#define ll long long
using namespace std;
/* Modular Inverse Implementation from codeaccepted wordpress : https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7/ */
ll M;
ll f[100001];
ll fast_pow(ll base, ll n,ll M)
{
    if(n==0)
        return 1;
    if(n==1)
        return base;
    ll halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
ll findMMI_fermat(ll n,ll M)
{
    return fast_pow(n,M-2,M);
}
ll factorial()
{
    f[0]=1;
    for(ll i=1; i<=100000; i++)
    {
        f[i]=(f[i-1]*i)%M;
    }
}
ll BC(ll n, ll k)
{
    ll den = (f[k]*f[n-k])%M;
    ll inv = findMMI_fermat(den,M);
    return (f[n]*inv)%M;
}
int main()
{
    ll t,k,n,z,in,zero;
    M=1000000000+7;
    factorial();
    cin>>t;
    while(t--)
    {
        ll ans=0;
        z=0;
        zero=0;
        cin>>n>>k;
        for(ll i=0; i<n; i++)
        {
            cin>>in;
            if(in == 0)
                {
                    zero++;
                    z=1;
                }
        }
        n-=zero;
        ll offset=1;
        if(!z) offset=2;
        for(ll i=min(n,k); i>=0; i-=offset)
        {
            ans+=BC(n,i);
            ans%=M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
