#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long c[1000001];
int main()
{
    long long t,n,ans,in,M=1000000007;
    cin>>t;
    while(t--)
    {   ans=0LL;
        cin>>n;
        for(int i=0;i<=1000000;i++)
            c[i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            c[a[i]]++;
            if(i>1)
                c[i]=c[i]+c[i-1];
            cout<<c[a[i]-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
