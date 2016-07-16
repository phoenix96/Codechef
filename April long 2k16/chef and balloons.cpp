#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,r,g,b,m,a[3];
    cin>>t;
    while(t--)
    {
        m=0;
        cin>>a[0]>>a[1]>>a[2]>>n;
        sort(a,a+3);
        if(n>a[1])
        {
            m=a[0]+a[1]+n;
        }
        else if(n>a[0])
        {
            m=a[0]+n+n-1;
        }
        else
        {
            m=3*(n-1)+1;
        }
        cout<<m<<endl;
    }
    return 0;
}
