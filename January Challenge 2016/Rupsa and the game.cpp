#include<iostream>
#include<stdio.h>
using namespace std;
long long fast_exp(long long int base, long long int exp) {
    long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%1000000007;
       base=(base*base)%1000000007;
       exp/=2;
    }
    return res%1000000007;
}
long long int findMMI_fermat(long long int n,long long int M)
{
    return fast_pow(n,M-2,M);
}
int main()
{
    long long int sum,t,i,n,in,k,ans;
    scanf("%lld",&t);
    while(t--)
    {   ans=0;sum=0;
        scanf("%lld",&n);
        scanf("%lld",&in);
        k=fast_exp(2,n);
        sum=in*k;
        k=k/2;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&in);
            ans=(ans+(sum*in)%1000000007)%1000000007;
            sum=((sum%1000000007)/2+(in*k)%1000000007)%1000000007;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
