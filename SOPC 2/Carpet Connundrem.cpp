#include<stdio.h>
#include <bitset>
#include <iostream>
#include <climits>
int main()
{
    long long int t,n,p,ans;
    //scanf("%lld",&t);
    //while(t--)
        ans=0;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("1\n1\n");
            return 0;
        }
        if(n==2)
        {
            printf("4\n1 1 1 1\n");
            return 0;
        }
        if(n%2==0)
        {
            printf("4\n");
            printf("%d %d %d %d\n",n/2,n/2,n/2,n/2);
            return 0;
        }
        else if(n==3)
        {
            printf("6\n");
            printf("1 1 1 1 1 2\n");
            return 0;
        }
        else if(n%3==0)
        {   printf("6\n");
            printf("%lld %lld %lld %lld %lld %lld\n",n/3,n/3,n/3,n/3,n/3,(n-n/3));
        }
        else if(n%5==0)
        {
            printf("8\n");
            printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",n/5,n/5,n/5,n/5,2*n/5,3*n/5);
        }
        else
        {
            printf("%lld %lld %lld\n" ,((n-1)*(n-1))/4,((n-1)*(n-1))/4,((n+1)*(n+1))/4);
        }

        //printf("%lld\n",ans);

    //}
    return 0;
}

