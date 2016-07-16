#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[201][201];
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,q,n2,m2;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>q;
    ll ma,ans=LONG_LONG_MAX;
    while(q--)
    {   ans=LONG_LONG_MAX;
        cin>>n2>>m2;
        for(int i=0;i<n-n2+1;i++)
            {
                for(int j=0;j<m-m2+1;j++)
                    { ma=LONG_LONG_MIN;
                        for(int k=i;k<n2+i;k++)
                        {
                            for(int l=j;l<m2+j;l++)
                            {
                                ma=max(a[k][l],ma);
                            }
                        }
                        //cout<<ma<<" ";
                        ll cost=0;
                        for(int k=i;k<n2+i;k++)
                        {
                            for(int l=j;l<m2+j;l++)
                            {
                                cost+=ma-a[k][l];
                            }
                        }
                        ans=min(ans,cost);
                    }
                    //cout<<endl;
            }
            cout<<ans<<endl;
    }
}
