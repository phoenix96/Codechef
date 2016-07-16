#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main()
{   ios_base::sync_with_stdio(false);
    long long t,n,ans,diff,avg;
    cin>>t;
    while(t--)
    {
        ans=0;
        avg=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            avg+=a[i];
        }
       // cout<<avg<<endl;
        if(avg%n==0)
        {   avg=avg/n;
            for(int i=0;i<n;i++)
            {
              diff=avg-a[i];
              if(diff<0) diff=-diff;
              ans+=diff;
            }
            cout<<ans/2LL<<endl;
        }
        else
        {
            cout<<"No Treat\n";
        }
    }
    return 0;
}
