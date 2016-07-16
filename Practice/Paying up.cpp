#include<bits/stdc++.h>
int a[20];
int main()
{
    long long int t,n,m,sum,f;
    scanf("%lld",&t);
    while(t--)
    {f=0;
        scanf("%lld %lld",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
            for(int i=0;i<(1<<n);i++)
            {
                sum=0;
                for(int j=0;j<n;j++)
                {
                    if(i&(1<<j))
                        sum+=a[j];
                }
                if(sum==m)
                   {
                        printf("Yes\n");
                        f=1;
                        break;
                    }
            }
            if(f!=1)
            printf("No\n");
    }
    return 0;
}
