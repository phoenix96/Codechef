#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,c,lhs,a,d,flag;
    cin>>t;
    while(t--)
    {   flag=0;
        cin>>n>>c;
        if(n==1)
        {
            cout<<"Yes\n";
            continue;
        }
        c-=n;
        ll r;
        if((2*c)%n==0)
        {
            lhs=2*c/n;
            r=(n-1)%2;
            ll p=(n-1)/2;
            if((lhs%(__gcd(2ll,n-1))==0)&&((r*lhs)/2)+(p*lhs)/(n-1)))
            {
                cout<<"Yes\n";
                flag=1;
            }
        }
        if(!flag)
        {
            cout<<"Yes\n";
        }
    }
}
