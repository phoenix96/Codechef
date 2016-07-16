/*
Rishabh Jain
*/
#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
        long long int fast_pow(long long base, long long n,long long M)
        {
            if(n==0)
               return 1;
            if(n==1)
            return base;
            long long halfn=fast_pow(base,n/2,M);
            if(n%2==0)
                return ( halfn * halfn ) % M;
            else
                return ( ( ( halfn * halfn ) % M ) * base ) % M;
        }
    long long int findinverse(long long int n,long long int M)
    {
        return fast_pow(n,M-2,M);
    }
int main()
{
    long long int t,n,x,m,p,num,den,ans,denom;
        long long int M=1000000007;
    scanf("%lld",&t);
    while(t--)
    {ans=0;
        scanf("%lld %lld %lld",&n,&x,&m);
        for(int i=0; i<n; i++)
            {
                scanf("%lld",&a[i]);
                a[i]=a[i]%M;
            }
        num=m%M;
        den=1;
        p=1;
        for(int i=x-2; i>=0; i--)
        {
            p=(p*num)%M;
            num=(num+1)%M;
            denom=findinverse(den,M);
            p=(p*denom)%M;
            den=(den+1)%M;
            ans=(ans+(a[i]*p)%M)%M;
        }
        ans=(ans+a[x-1])%M;
        printf("%lld\n",ans);
    }
}
