#include<bits/stdc++.h>
using namespace std;
long long a[1002];
long long dp[1002];
long long m(long long a, long long b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    long long t,tt,n;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dp[0]=0;
        dp[1]=a[1];
        dp[2]=m(a[1],a[2]);
        for(int i=3;i<=n;i++)
            dp[i]=m(dp[i-1],dp[i-2]+a[i]);
        cout<<"Case "<<tt<<": "<<dp[n]<<endl;
    }
    return 0;
}
