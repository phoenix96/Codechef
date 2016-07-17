#include<stdio.h>
#include<algorithm>
long long int a[1009];
int main()
{
    long long int k,n;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    std::sort(a,a+n);
    printf("%lld\n",a[k-1]);
    return 0;
}
