#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,r,g,b,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if((n==1&&m==2)||(m==1&&n==2))
        {
            cout<<"Yes\n";
            continue;
        }
        if(n==1||m==1)
        {
            cout<<"No\n";
            continue;
        }
        if(n%2!=0&&m%2!=0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}
