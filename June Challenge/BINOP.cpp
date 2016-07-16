#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool lucky(string s)
{   ll zero=0,one=0;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    if(zero==s.size()||one==s.size())
        return false;
    return true;
}
ll changes(string a, string b)
{   ll one=0,zero=0;
    for(ll i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]=='1')
                one++;
            else
                zero++;
        }
    }
    return (max(one,zero));
}
int main()
{
    ll t,change;
    string a,b;
    cin>>t;
    while(t--)
    {   change=0;
        cin>>a>>b;
        if(!lucky(a))
        {
            cout<<"Unlucky Chef\n";
        }
        else
        {
            cout<<"Lucky Chef\n";
            cout<<changes(a,b)<<endl;
        }
    }
    return 0;
}

