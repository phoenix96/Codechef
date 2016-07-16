#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long int t,n,k,m,dif;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        dif=n-m;
        if(dif<0)
            dif=-dif;
        if(k>=dif)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",dif-k);
        }
    }
    return 0;
}
