#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l2,b2;
int ch(ll m, ll k , ll j)
{   ll l=l2; ll b=b2;
    if(b>0&&m%b==0)
        {
            l-=(m/b);
            if(b>0&&k%b==0)
            {
                l-=(k/b);
                if(l*b==j)
                {
                   return 1;
                }
            }
            else if(l>0&&k%l==0)
            {
                b-=(k/l);
                {
                    if(l*b==j)
                    {
                       return 1;
                    }
                }
            }
        }
        l =l2; b=b2;
        if(l>0&&m%l==0)
        {
            b-=(m/l);
            if(b>0&&k%b==0)
            {
                l-=(k/b);
                if(l*b==j)
                {
                    return 1;
                }
            }
            else if(l>0&&k%l==0)
            {
                b-=(k/l);
                {
                    if(l*b==j)
                    {
                        return 1;
                    }
                }
            }
        }

return 0;
}
int main()
{
    ll t,n,r,c,m,k,j;
    cin>>t;
    while(t--)
    {
        cin>>r>>c>>m>>k>>j;
        l2=r;
        b2=c;
        if((m+k+j)!=(r*c))
        {
            cout<<"No\n";
            continue;
        }
        if(ch(m,k,j)||ch(m,j,k)||ch(k,j,m)||ch(k,m,j)||ch(j,m,k)||ch(j,k,m))
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
