#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001];
int main()
{   ios_base::sync_with_stdio(false);
    ll t,n,q,x,ans=0,mul=1ll;
    int c1,c2,c3;
    cin>>t;
    while(t--)
    {
        cin>>n;
        c1=c2=c3=0;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                c1+=a[i];
                if(a[i]==5)
                    c2=1;
                if(a[i]==2)
                    c3=1;
            }
            if((c1*1.0/n*1.0)>=4.0 && (c2) && (!c3))
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }

    }
}

