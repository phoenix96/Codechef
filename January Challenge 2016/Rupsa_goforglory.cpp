/*
Rishabh Jain
9914103137
Use:
Inverse Modulo and Basic Algorithm
Copied: Algorithm for power from tutorial site on Google
*/
#include<iostream>
#include<stdio.h>
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
    long long int sum,t,i,n,in,k,ans,den;
    long long int M=1000000007;
    den=findinverse(2,M);
    scanf("%lld",&t);
    while(t--)
    {   ans=0;sum=0;
        scanf("%lld",&n);
        scanf("%lld",&in);
        k=fast_pow(2,n,M);
        sum=(in*k)%M;
        k=(k*den)%M;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&in);
            ans=(ans+(sum*in)%M)%M;
            sum=((sum*den)%M+(in*k)%M)%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
