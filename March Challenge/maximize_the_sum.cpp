#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int main()
{
    long long t,n,f,k,pos;
    long long ans=0;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        int m=b[0];
        if(m<0) m=-m;
        for(int i=1; i<n; i++)
        {
            f=b[i];
            if(f<0) f=-f;
            if(f>m)
                m=f;
        }
        for(int i=0; i<n; i++)
        {
            ans+=a[i]*b[i];
        }
        ans+=m*k;
        cout<<ans<<"\n";
    }
    return 0;
}
//        for(int i=0; i<n; i++)
//        {
//            if(b[i]!=m) continue;
//            f=a[i];
//            if(f<0) f=-f;
//            if(f>m2)
//            {
//                m2=f;
//                pos=i;
//            }
//        }
