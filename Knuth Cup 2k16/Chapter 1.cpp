#include<bits/stdc++.h>
int main()
{
    long long int t,n,ans;
    scanf("%lld",&t);
    while(t--)
    {ans=1;
        scanf("%lld",&n);
        while(n%2==0)
        {
            n/=2;
            ans*=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
