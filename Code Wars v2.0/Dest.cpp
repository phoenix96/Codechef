#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int a[50001];
long long int r[50001];
int main()
{
    long long int i,t,n,dif,fdif,k,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
      dif=1;fdif=0;k=0;
        for(i=0;i<500001;i++)
            r[i]=0;
            a[n]=-1;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
               r[k]++;
            }
            else
            {
                r[k]++;
                k++;
            }
        }
        sort(r,r+k);
        fdif=r[k-1];
        for(i=k-2;i>=0;i--)
        {
            fdif=fdif-r[i];
            if(fdif<0)
                fdif=-fdif;
        }
        ans=fdif+(n-fdif)/2;
        printf("%lld\n",ans);
    }
    return 0;
}
