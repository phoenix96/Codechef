#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int a[300003];
int main()
{
    long long int sum,t,i,n,in,k,j,ans;
        scanf("%lld",&n);
        for(i=0; i<n*3; i++)
            scanf("%lld",&a[i]);
        printf("1\n1 2 3\n");
//        printf("%lld %lld %lld\n",a[0],a[1],a[2]);
//        for(i=1;i<n*3;i++)
//        {
//            if(a[i]!=a[0])
//                { printf("%lld ",a[i]); break;}
//        }
//        for(j=i+1;j<n*3;j++)
//        {
//            if(a[j]!=a[i])
//                {printf("%lld\n",a[j]); break;}
//        }

    return 0;
}
