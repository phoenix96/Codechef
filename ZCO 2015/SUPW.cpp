#include<bits/stdc++.h>
using namespace std;
long long dp[100001];
long long a[100001];

long long m2(long long a, long long b)
{
    return (a<b)?a:b;
}

long long m3(long long a, long long b, long long c)
{
    return (a<b)?(a<c)?a:c:(b<c)?b:c;
}

int main()
{
    long long t,n,ans=0;
    cin>>n;
    t=n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0]=a[0];
    dp[1]=m2(a[0],a[1]);
    dp[2]=m2(dp[1],a[2]);
    for(int i=3;i<n;i++)
    {
            dp[i]=m2(dp[i-3]+a[i],dp[i-1]);
        cout<<dp[i]<<" ";
    }
    cout<<endl<<dp[n];
    return 0;
}
