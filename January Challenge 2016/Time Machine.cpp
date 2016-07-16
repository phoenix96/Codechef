#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int p[100001],dif[100001],b[200005];
int main()
{
    long long int sum,t,i,n,in,o,k,m,j,ans;
    scanf("%lld",&t);
    while(t--)
    {   ans=0;
        scanf("%lld %lld %lld",&n,&k,&m);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&p[i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%lld",&in);
            dif[i]=p[i]-in;
            ans+=dif[i];
        }
        for(i=0; i<k; i++)
        {
            scanf("%lld",&b[i]);
        }
        for(j=0; j<m; j++)
        {
            scanf("%lld",&b[i+j]);
        }
        sort(dif,dif+n);
        sort(b,b+m+k);
//        for( i=0;i<n;i++)
//            cout<<dif[i]<<",";
//        cout<<endl;
//        for(i=0;i<m+k;i++)
//            cout<<b[i]<<",";
//        cout<<endl;

       long long int l=m+k-1;
        for(i=n-1; i>=0; i--)
        {
            //cout<<"For "<<dif[i]<<":"<<endl;
            for(;l>=0; l--)
            {
                if(dif[i]>=b[l])
                {
                    ans-=b[l];
                    l--;
                    break;
                }
            }
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
