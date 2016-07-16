#include<bits/stdc++.h>
using namespace std;
long long s[100000];
long long e[100000];
long long t[20];
long long r[100000];
int main()
{
    long long n,q,k,sum=0;
    scanf("%lld",&n);
    //n=100000;
    for(int i=0; i<n; i++)
        scanf("%lld %lld",&s[i],&e[i]);

    scanf("%lld",&q);
    //q=5;

    for(int i=0; i<q; i++)
    {sum=0;
        scanf("%lld",&k);
        k=20;
        for(int j=0; j<k; j++)
            scanf("%lld",&t[j]);
        for(int ii=0; ii<k; ii++)
        {
            for(int jj=0; jj<n; jj++)
            {
                if((r[jj]!=1)&&(t[ii]>=s[jj])&&(t[ii]<=e[jj]))
                    r[jj]=1;
            }
        }
        for(int ii=0; ii<n; ii++)
            sum+=r[ii];
        printf("%lld\n",sum);
    }
    return 0;
}
