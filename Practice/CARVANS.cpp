#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{   ios_base::sync_with_stdio(false);
    int t,n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        if(n>0) ans=1;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
                {
                 ans++;
                }
                else
                {
                    a[i+1]=a[i];
                }
        }
        cout<<ans<<endl;
    }
}
