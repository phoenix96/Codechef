#include<bits/stdc++.h>
using namespace std;
int main()
{   long long int tt,n,p,q,r,s;
    long double ans;
    cin>>tt;
    while(tt--)
    {
        cin>>p>>q>>r>>s;
        ans=(p*1.0/q*1.0)/(1.0-((1-(p*1.0)/(q*1.0))*(1-(r*1.0)/(s*1.0)*1.0)));
        cout<<fixed;
        cout<<setprecision(5)<<ans<<endl;
    }
    return 0;
}
