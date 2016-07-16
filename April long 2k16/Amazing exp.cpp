#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,l,m,o,max_weight=0;
    cin>>t;
    while(t--)
    {   max_weight=0;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            cin>>l>>m>>o;
            if(o>max_weight)
                max_weight=o;
        }
        cout<<max_weight<<"\n";
        for(int i=0;i<n-1;i++)
        {
            cout<<"0\n";
        }
    }
    return 0;
}
