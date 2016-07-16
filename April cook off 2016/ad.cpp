#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,ans,a,b,ansb,mul,pans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            mul=a*b;
            if(mul>ans)
            {
                    ans=mul;
                    ansb=b;
                    pans=i+1;
            }
            else if(mul==ans && b>ansb)
            {
                ans=mul;
                ansb=b;
                pans=i+1;
            }

        }
        cout<<pans<<endl;
    }
    return 0;
}
