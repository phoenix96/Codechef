#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t,n,d,diff;
    cin>>t;
    while(t--)
    {
        cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    diff=a[n-1]-a[n-2];
    //cout<<diff<<endl;
    for(int i=0;i<n-1;i++)
        {
        d=a[i+1]-a[i];
        //cout<<d<<" "<<diff<<endl;
        if(d<diff)
            diff=d;
        }
        cout<<diff<<endl;
    }
    return 0;
}
