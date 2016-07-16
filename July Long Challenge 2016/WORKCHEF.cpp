#include<bits/stdc++.h>
#define ll long long
using namespace std;
int d[10];
int isSpecial(int n)
{
    int number=n;
    int di;
    int ans=0;
    while(n>0)
    {
        di=n%10;
        d[di]=1;
        n/=10;
    }
    for(int i=1;i<10;i++)
        {
            if(d[i])
            {
                if(number%i==0)
                {
                    ans++;
                }
                d[i]=0;
            }
        }
    return ans;
}
int main()
{
    ll q,l,r,k,ans;
    cin>>q;
    while(q--)
    {   ans=0;
        cin>>l>>r>>k;
        for(int i=l;i<=r;i++)
        {
            if(isSpecial(i)>=k)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
