//This code is written by Rishabh Jain
#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
long long int GCD(long long int u,long long int v)
{
    while ( v != 0 )
    {
        long long int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
int main()
{
    long long t,n,k,s,m;
    scanf("%lld",&t);
    while(t--)
    {
        s=0;
        scanf("%lld",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        k=a[0];
        for(int i=1; i<n; i++)
        {
          k=GCD(k,a[i]);
        }
        printf("%lld\n",k*n);
    }
    return 0;
}