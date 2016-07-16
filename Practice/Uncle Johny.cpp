#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int t,n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>k;
        for(int i=0;i<=n;i++)
        {
            if(a[k]>a[i])
                ans++;
        }
        cout<<ans<<endl;
    }
}
