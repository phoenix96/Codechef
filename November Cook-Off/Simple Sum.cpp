#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N=10001;
long long int phi[N];
long long int a[N];
int GCD(int u,int v)
{
    while ( v != 0 )
    {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
 
//phi multiplied by i;
void phimaker()
{
    for(long long int i=1; i<N; i++)
        phi[i]=i*i;
    for(long long int i=2; i<N; i++)
    {
        if(phi[i]==i*i)
        {
            for(long long int j=i; j<N; j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
}
void answer()
{
    long long int n,i,j,ans;
    for(i=1; i<N; i++)
    {
        ans=0;
        for(j=1; j<=sqrt(i); j++)
        {
            if(!(i%j))
            {
                if(j!=sqrt(i))
                    ans+=phi[j]+phi[i/j];
                else
                    ans+=phi[j];
            }
        }
        a[i]=ans;
    }
}
int main()
{
    long long int flag=0;
    long long int n,ans,s=0;
    long long int t,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n>10000)
        {
            s=0;
            for(int i=1; i<=n; i++)
                s+=n/GCD(i,n);
            printf("%lld\n",s);
        }
        else
        {
            if(flag==0)
            {
                phimaker();
                answer();
                flag=1;
            }
            printf("%lld\n",a[n]);
        }
    }
    return 0;
}