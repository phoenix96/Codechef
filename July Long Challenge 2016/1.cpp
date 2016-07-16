#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001];
int main()
{   //ios_base::sync_with_stdio(false);
    ll t,n,q,x,ans=0,mul=1ll;
    ll M = 786433;
    cin>>n;
    for(ll i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    while(q--)
    {
        ans=0;mul=1;
        cin>>x;
        for(ll i=0;i<=n;i++)
        {
            ans = (ans + ( a[i] * mul ) % M ) % M;
            mul = ( mul * x ) % M;
        }
        cout<<ans<<endl;
    }

}
