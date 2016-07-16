#include<bits/stdc++.h>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    int t,n,in,k,ans,i;
    int a[100001];
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=0; i<=1000; i++)
            a[i]=0;
        for(int i=0; i<n; i++)
        {
            cin>>in;
            a[in]++;
        }
        cin>>k;
        for(i=1; i<=1000; i++)
        {
            if((a[i]>0)&&((k/i)<=1000)&&((k/i)>=1)&&(k%i==0)&&(a[k/i]>0))
            {
                if(i==(k/i)) ans+=(a[i]*(a[i]-1))/2;
                else
                    ans+=a[i]*a[k/i];
                a[i]=0;
                a[k/i]=0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
