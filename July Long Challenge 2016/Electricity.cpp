#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll in[100001], l[100001], r[100001], minimum[100001];
void print(ll a[], ll n)
{
    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{   ios_base::sync_with_stdio(false);
    ll t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        for(int i=0;i<n;i++)
            cin>>in[i];
        ll dist_travelled=LONG_LONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                l[i]=abs(in[i] - dist_travelled);
                 if(l[i] <= INT_MAX)
                dist_travelled = in[i];
            }
            else
            {
                dist_travelled=in[i];
                l[i]=0;
            }
        }
        //print(l,n);
        dist_travelled=LONG_LONG_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                r[i]=abs(in[i] - dist_travelled);
                if(r[i] <= INT_MAX)
                dist_travelled = in[i];
            }
            else
            {
                dist_travelled=in[i];
                r[i]=0;
            }
        }
        //print(r,n);
        ll ans=0;
        for(int i=n-1;i>=0;i--)
        {
            minimum[i]=min(l[i],r[i]);
            ans+=minimum[i];
        }
        //print(minimum,n);
        cout<<ans<<endl;
    }

}
