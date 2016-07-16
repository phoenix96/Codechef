#include<iostream>
#include<stdio.h>
long long int a[10001];
long long int t,n;
long long int calc(long long int i,long long int i1,long long int i2,long long int s){
if(i==n)
    return s;
    return (calc(i+1,i1,i,s+a[i]*a[i2])%1000000007+calc(i+1,i,i2,s+a[i]*a[i1])%1000000007)%1000000007;
}
int main()
{long long int i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<=n;i++)
            scanf("%lld",&a[i]);
            n=n+1;
        printf("%lld\n",(calc(1,0,0,0)%1000000007));
}
return 0;
}
