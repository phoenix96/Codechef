#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,g,h,n,q,heads;
    cin>>t;
    while(t--)
    {   heads=0;
        cin>>g;
        for(int i=0;i<g;i++)
        {
            cin>>h>>n>>q;
            if(h==1)
            heads=n/2;
            else
                heads=ceil(n*1.0/2*1.0);
            if(q==1)
            cout<<heads<<endl;
            else
            cout<<(n-heads)<<endl;
        }
    }
    return 0;
}
