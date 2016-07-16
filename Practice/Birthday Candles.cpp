#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    long long int tt,n,k,ans=-1;
    cin>>tt;
    vector<long long> a;
    while(tt--)
    {
        a.clear();
        ans=-1;
        long long int pos=0,pos2=0;
        for(int i=0; i<10; i++)
        {
            cin>>k;
            a.push_back(k);
        }
        long long m=1ll<<62ll,m2=1ll<<62ll;
        long long int i;
        for(i=1; i<10; i++)
        {
            if(a[i]<m)
            {
                m=a[i];
                pos=i;
            }
        }
        if(a[0]<m)
        {
            cout<<"1";
            a[1]--;
        }
        else
        {
            cout<<pos;
            a[pos]--;
        }
        for(i=0; i<10; i++)
        {
            if(a[i]<m2)
            {
                m2=a[i];
                pos2=i;
            }
        }
        for(int i=0; i<=a[pos2]; i++)
        {
            cout<<pos2;
        }
        cout<<endl;
    }
    return 0;
}
