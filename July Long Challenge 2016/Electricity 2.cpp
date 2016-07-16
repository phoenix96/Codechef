#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll xpos[100003];
int main()
{
    ll t,n,ans;
    string s;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>s;
        ll flag=1;
        ll first_one=-1,last_one=-1;
        for(ll i=0; i<n; i++)
        {
            cin>>xpos[i];
            if(flag && (s[i]=='1'))
            {
                first_one=i;
                flag=0;
            }
            if(s[i]=='1')
            {
                last_one=i;
            }
        }
        ll sub = 0;
        ans=0;
        for(ll i=0; i<n; i++)
        {
            if(i==first_one)
                continue;
            if(i<first_one)
            {
                ans+=xpos[i+1]-xpos[i];
                continue;
            }
            else if(i>last_one)
            {
                ans+=xpos[i]-xpos[i-1];
                continue;
            }
            if(s[i]=='0')
            {
                ans+=xpos[i]-xpos[i-1];
                sub=max(sub,xpos[i]-xpos[i-1]);
                if(s[i+1]=='1')
                {
                    ans+=xpos[i+1]-xpos[i];
                    sub=max(sub,xpos[i+1]-xpos[i]);
                }
            }
            else if(s[i]=='1')
            {
                ans-=sub;
                sub=0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*100
8
10010000
5 100 101 102 103 104 105 106
*/
