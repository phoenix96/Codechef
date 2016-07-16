#include<bits/stdc++.h>
#define ll long long
using namespace std;
/* Geek4Geeks implementation of NCR using dynamic Programming (Pascals Triangle) */
/* Modular power mpow from Sanfoundary */
ll M;
ll mpow(ll base, ll exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % M;
        exponent = exponent >> 1;
        base = (base * base) % M;
    }
    return result;
}
ll binomialCoeff(ll n, ll k)
{
    ll P[];
    ll C[n+1][k+1];
    ll i,j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1]%M + C[i-1][j]%M)%M;
        }
    }
    return C[n][k];
}
int main()
{
    ll t,k,n,z,in,zero;
    M=1000000000+7;
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
        if(z)
        {
            n-=zero;
                for(ll i=0;i<=min(n,k);i++)
                    ans+=binomialCoeff(n,i);
                cout<<ans<<endl;
            continue;
        }
        if(n<=k)
        {
            cout<<mpow(2,n-1)<<endl;
        }
        else
        {
            if(k%2==0)
                cout<<binomialCoeff(n,k)*(mpow(2,k-1)-1)+1<<endl;
            else
                cout<<binomialCoeff(n,k)*(mpow(2,k-1))<<endl;
        }
    }
    return 0;
}
