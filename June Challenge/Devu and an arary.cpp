#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,q,m,m2,a;
    cin>>n>>q;
    m2=INT_MAX;
    m=INT_MIN;
    while(n--)
    {
        cin>>a;
        m=max(m,a);
        m2=min(m2,a);
    }
    while(q--)
    {
        cin>>a;
        (a>=m2&&a<=m)?cout<<"Yes\n":cout<<"No\n";
    }
    return 0;
}
