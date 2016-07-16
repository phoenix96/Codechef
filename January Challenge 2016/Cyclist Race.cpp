#include<iostream>
#include<stdio.h>
using namespace std;
long long int dis[50009];//9 values taken just in case..
long long int sp[50009];
//void printd(int n)
//{
//    for(int i=1;i<=n;i++)
//        cout<<dis[i]<<",";
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<sp[i]<<",";
//    cout<<endl;
//}
int main()
{
    long long int sum,t,c,ns,i,n,in,m,k,q,ans,type,prevt;
    scanf("%lld %lld",&n,&q);
    prevt=0;
    while(q--)
    {   ans=0;
        scanf("%lld",&type);
        if(type==1)
        {
            scanf("%lld %lld %lld",&t,&c,&ns);
            for( i=1;i<=n;i++)
            {
               dis[i]+=sp[i]*(t-prevt);
            }
            prevt=t;
            sp[c]=ns;
        }
        else
        {
            scanf("%lld",&t);
            for( i=1;i<=n;i++)
            {
                dis[i]+=sp[i]*(t-prevt);
            }
            prevt=t;
            m=-1;
            for(i=1;i<=n;i++)
            {
                if(dis[i]>m)
                    m=dis[i];
            }
          printf("%lld\n",m);
        }
//        printd(n);

    }
    return 0;
}
