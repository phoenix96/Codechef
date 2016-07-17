#include<bits/stdc++.h>
#define lp(i,n) for(long long i=0;i<n;i++)
#define test(t) long long t; cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c;
    fast_io
    test(t)
        {
            cin>>a>>b;
            cout<<__gcd(a,b)<<endl;
        }
    return 0;
}
