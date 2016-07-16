#include<bits/stdc++.h>
using namespace std;
int p[1000001];
int prime[1000001];
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
unsigned GCD(unsigned u, unsigned v) {
    while ( v != 0 ) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}
void seive()
{
    for(int i=2; i<1000001; i++)
    {
        if(p[i]==0)
        {
            for(int j=i*2; j<1000001; j+=i)
            {
                p[j]=1;
            }
        }
    }
    long long j=0;
    for(int i=2;i<=10000;i++)
        {
            if(p[i]==0)
                prime[j++]=i;
        }
        cout<<j<<endl;
}
int main()
{
seive();
long long int t,n,l=0;
long long int *pf= new long long[1001];
long long int *pfp= new long long[1001];
scanf("%lld",&t);
while(t--)
{
    scanf("%lld",&n);
    for(int i=1;i<1000001;i++)
    {
        while(n%prime[i]==0)
        {
            n/=i;
            pf[l]=prime[i];
            pfp[l]++;
        }
        l++;
    }
    long long int g=pfp[0];
    for(int i=1;i<l;i++)
    {
        g=gcd(g,pfp[i]);
    }
    for(int i=0;i<l;i++)
    {
        pfp/=g;
    }
    for(int i=0;i<l;i++)
    {
        ans=(ans%M+fast_pow(pf[i],pfp[i],M))%M;
    }
}

return 0;
}
