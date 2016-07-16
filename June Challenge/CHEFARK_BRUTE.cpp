#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(vector<ll> arr,ll n, ll k,ll index)
{   ll x=0,start=0;
    if(arr.size()==1) start = 1;
    //cout<<index<<endl;
    set< vector<ll> > ret;
    if(index==arr.size()||arr.size())
        {
         //   cout<<index<<endl;
            return 1;
        }
    for(ll i=start;i<=k;i++)
    {
        arr[index]*=pow(-1,k);
        x=ans(arr,n-1,k-i, index+1);
        ret.insert(arr);
    }
    return ret.size();
}
int main()
{
    ll t,n,k,in;
    vector<ll> a;
    cin>>t;
    while(t--)
    {   cout<<"Enter  n and k"<<endl;
        cin>>n>>k;
        cout<<"Array?"<<endl;
        for(ll i=0;i<n;i++)
        {
            cin>>in;
            a.push_back(in);
        }

        cout<<"Solution::";
        cout<<ans(a,n,k,0ll)<<endl;
    }
}
