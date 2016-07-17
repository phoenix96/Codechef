#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000001];
ll c[1000001];
int main()
{
    ll t,n,l,b,flag,flag2;
    cin>>t;
    while(t--)
    {   l=b=1;
        flag=2;
        flag2=0;
        cin>>n;
        for(int i=0;i<=1000;i++)
            c[i]=0;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                c[a[i]]++;
            }
            ll area=1, az=1;
        for(int i=1000; i>=0; i--)
        {
            if(c[i]>=4)
            {
                l=b=i;
                area=l*b;
                flag2=1;
                break;
            }
        }
        for(int i=1000; i>=0; i--)
        {
            if(c[i]>=2)
            {
                az=az*i;
                flag--;
                if(flag == 0)
                {   area=max(area,az);
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2)
        {
            cout<<area<<endl;
        }
        else
        {
            cout<<"-1\n";
        }
    }
    return 0;
}
