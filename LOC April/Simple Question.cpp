#include<bits/stdc++.h>
using namespace std;
long long dp[1000001];
long long M=1e9+7;
void solve()
{
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for(long long int i=3;i<100001L;i++)
    {   if(i%2==0)
            dp[i]=((i*(dp[i-1])%M)+1)%M;
        else
            dp[i]=((i*(dp[i-1])%M)-1)%M;
    }
    return;
}
int main()
{   solve();
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;

        cout<<dp[n]<<endl;
    }
    return 0;
}

