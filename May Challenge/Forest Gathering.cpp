#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct tree
{
    ll h;
    ll r;
    ll months_req;
} t[100001] ;
int cmp(tree a, tree b)
{
    return a.months_req<b.months_req;
}
int main()
{
    ll n,w,l,wood_so_far,rate_so_far,months_so_far,maybe_ans;
    cin>>n>>w>>l;
    wood_so_far=0;
    rate_so_far=0;
    months_so_far=0;
    for(int i=0; i<n; i++)
    {
        cin>>t[i].h>>t[i].r;
        if(t[i].h>=l)
        {
            // wood_so_far + = t[i].h;
            t[i].months_req=0;
        }
        else if(((l-t[i].h)%t[i].r)==0)
            t[i].months_req = ((l-t[i].h)/t[i].r);
        else
            t[i].months_req = ((l-t[i].h)/t[i].r)+1;
    }
    sort(t,t+n,cmp);
    maybe_ans=1e18+1;
    ll flag=0;
    for(int i=0; i<n; i++)
    {
        rate_so_far+=t[i].r;
        if(maybe_ans<t[i].months_req)
        {
            cout<<maybe_ans<<endl;
            flag=1;
            break;
        }
        if(wood_so_far>=w)
        {
            cout<<months_so_far<<endl;
            flag=1;
            break;
        }
        else
        {
            wood_so_far+=(rate_so_far)*(t[i].months_req-months_so_far)+t[i].r*months_so_far+t[i].h;
            months_so_far=t[i].months_req;
        }
        if(wood_so_far>=w)
        {
            cout<<months_so_far<<endl;
            flag=1;
            break;
        }
        if((w-wood_so_far)%rate_so_far==0)
        {
           // cout<<"m0"<<endl;
            maybe_ans=months_so_far+(w-wood_so_far)/rate_so_far;
        }
        else
            maybe_ans=months_so_far+((w-wood_so_far)/rate_so_far)+1;
    }
    if(flag==0)
    {
        //  cout<<"CC case";
        if(wood_so_far>=w)
        {
            cout<<months_so_far<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        //cout<<"Case 3"<<endl;
        ll temp = (w - wood_so_far) % rate_so_far;
        //cout<<temp<<endl;
        if(temp==0)
        {
            months_so_far+=(w - wood_so_far) / rate_so_far;
        }
        else
        {
            months_so_far+=( (w - wood_so_far) / rate_so_far ) + 1;
        }
        cout<<months_so_far<<endl;
    }
    return 0;
}
