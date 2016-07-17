#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll t,n,a,b,c,d,dif,ans,x;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a>b)
            dif=a-b;
        else
            dif=b-a;

        x=dif%(__gcd(c,d));

        if(x==0)
        cout<<x<<endl;
        else
        {
            ans=min((a%__gcd(c,d)),(b%__gcd(c,d)));
            ans=min(dif,ans);
            if(ans==0)
            {
                cout<<1<<endl;
            }
            else
            cout<<ans<<endl;
        }
    }
    return 0;
}
