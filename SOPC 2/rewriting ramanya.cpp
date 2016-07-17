#include<stdio.h>
#include <bitset>
#include <iostream>
#include <climits>
long long int count_1s_in_Num(long long int num)
{
    long long int c=0;
    while(num!=0)
    {
        num = num & (num-1);
        c++;
    }
    return c;
}
long long int fast_pow(long long base, long long n)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2);
    if(n%2==0)
        return ( halfn * halfn );
    else
        return ( ( ( halfn * halfn ) ) * base );
}
int main()
{
    long long int t,n,p,ans;
    //scanf("%lld",&t);
    //while(t--)
        ans=0;
        scanf("%lld",&n);
        p=count_1s_in_Num(n);
        ans=fast_pow(2,p);
        printf("%lld\n",ans);

    //}
    return 0;
}
