#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,s,w,q,p,tt;
    cin>>t;
    while(t--)
    {
        cin>>s>>w>>q>>p>>tt;
        if(s+w+q+p>tt)
            cout<<"NO\n";
            else
            cout<<"YES\n";
    }
    return 0;
}
