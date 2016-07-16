#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,ans,in,M=1000000007;
    cin>>t;
    while(t--)
    {   ans=1LL;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>in;
            ans=((ans%M)*(in%M)%M);
        }
        cout<<ans<<endl;
    }
    return 0;
}
