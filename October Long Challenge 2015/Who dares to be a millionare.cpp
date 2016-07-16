#include<math.h>
#include<iostream>
#define fast ios_base::sync_with_stdio(false);
using namespace std;
int main()
{
    fast
    int t,n;
    char q[1001],a[1001];
    int w[1002]; int m;
    cin>>t;int k;
    int corr;int inc;
    while(t--)
    {   corr=0;k=1;
        cin>>n;
        cin>>q>>a;
        for(int i=0;i<=n;i++)
        cin>>w[i];
 
        for(int i=0;i<n;i++)
        {
            if(q[i]==a[i])
                corr++;
        }
        if(corr==n)
            {cout<<w[corr]<<"\n";
            continue;}
        m=w[0];
        for(int i=0;i<=corr;i++)
        {
            if(w[i]>m)
            m=w[i];
        }
        cout<<m<<"\n";
        }
    return 0;
}
 