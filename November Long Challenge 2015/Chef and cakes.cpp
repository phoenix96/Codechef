#include<iostream>
using namespace std;
//Default on-site function of GCD.
unsigned GCD(unsigned u, unsigned v) {
    while ( v != 0 ) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long int t,n,m,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1||(n-m)==1||(m==1))
        {
            cout<<"Yes\n";
            continue;
        }
        else if(m==0)
        {
            cout<<"No 1\n";
            continue;
        }
        if(GCD(n,m)!=1)
        {
            cout<<"No "<<n/GCD(n,m)<<"\n";
            continue;
        }
        cout<<"Yes\n";
    }
    return 0;
}