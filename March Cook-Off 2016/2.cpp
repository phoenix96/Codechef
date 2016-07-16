#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,h,m,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>h>>m;
        for(int i=0; i<=9; i++)
        {
            if(h>i&&m>(i*10+i))
            {
                ans++;
            }
            if(h>(i*10+i)&&m>i)
            {
                ans++;
            }
            if(h>(i*10+i)&&m>(i*10+i))
            {
                ans++;
            }
            if(h>i&&m>i)
            {
                ans++;
            }
        }
        cout<<ans-3<<endl;
    }
    return 0;
}
