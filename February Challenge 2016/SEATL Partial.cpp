#include<bits/stdc++.h>
using namespace std;
long long int a[101][101];
long long int c[1000001];
int main()
{
    long long int t,n,m,temp,tempmax;
    scanf("%lld",&t);
    //t=1;
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
      // n=100; m=100;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        tempmax=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=0; k<m; k++)
                {
                    c[a[i][k]]++;
                    if(c[a[i][k]]>tempmax)
                    {
                        tempmax=c[a[i][k]];
                    }
                }
                for(int k=0; k<n; k++)
                {
                    if(k!=i) c[a[k][j]]++;
                    if(c[a[k][j]]>tempmax)
                    {
                        tempmax=c[a[k][j]];
                    }
                }
                for(int k=0; k<m; k++)
                {
                    c[a[i][k]]=0;
                }
                for(int k=0; k<n; k++)
                {
                    c[a[k][j]]=0;
                }
               // cout<<tempmax<<" ";
            }
            //cout<<endl;
        }
        printf("%lld\n",tempmax);
    }
    return 0;
}
