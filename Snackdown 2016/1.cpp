#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100001];
int main()
{
    ll t,n,flag,c;
    cin>>t;
    while(t--)
    {   flag=0;
        c=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
           if(a[i]==a[i-1])
            c++;
           else
            c=0;
           if(c==2)
           {
               flag=1;
               cout<<"Yes\n";
               break;

           }
        }
        if(flag==0)
            cout<<"No\n";
    }
    return 0;
}
