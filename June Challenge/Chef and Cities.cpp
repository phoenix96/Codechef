#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100001];
int main()
{
    ll n,q,type,p,f,R,ans;
    ll M=1000000007;
    cin>>n;
    for(ll i=0;i<n;i++)
            cin>>a[i];
    cin>>q;
    while(q--)
    {   ans=1LL;
        cin>>type;
        if(type==2)
        {
            cin>>R;
            for(ll i=0;i<n;i+=R)
                {
                    ans*=a[i];
                }
                act_ans=ans;
             while(act_ans>9LL)
             {
                 act_ans/=10LL;
             }
            cout<<act_ans<<" "<<ans%M<<endl;
        }
        else
        {
            cin>>p>>f;
            a[p-1]=f;
        }
    }
}
