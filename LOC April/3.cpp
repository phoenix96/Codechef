#define ll long long
#define gcd __gcd
#include<bits/stdc++.h>
#define mod 1000000007
#define N 1000001
using namespace std;
long long a[100001];
int main()
{
    long long int t,n,ans,ansmax;
    cin>>t;
    while(t--)
    {   ans=2;
        ansmax=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=2;i<n;i++)
        {
            if(a[i]==(a[i-1]+a[i-2]))
             ans++;
            else
            {
                if(ans>ansmax)
                {
                    ansmax=ans;
                }
                ans=2;
            }
            //cout<<ans<<" m"<<ansmax<<" ";
        }
        if(ans>ansmax)
                    ansmax=ans;
        if(n<3)
            cout<<n<<endl;
        else
            cout<<ansmax<<endl;

    }
    return 0;
}
