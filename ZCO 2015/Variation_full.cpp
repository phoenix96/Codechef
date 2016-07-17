#include<bits/stdc++.h>
using namespace std;
vector <long long> a;
vector <long long> :: iterator l,r;
//vector <long long> :: iterator r;

int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,k,in;
    cin>>n>>k;
    //a.clear();
    t=n;
    while(t--)
    {
        cin>>in;
        a.push_back(in);
    }
    l=a.begin();
    r=a.end();
    sort(l,r);
    r=a.begin();
    r++;
    // cout<<*r<<endl;
    long long ans=0;
//    while(l!=a.end())
//    {
//        cout<<*l<<endl;
//        l++;
//    }
//    return 0;
    while(r!=a.end())
    {
        //    cout<<*l<<" "<<*r<<endl;
        if(l==r)
        {
            r++;
            continue;
        }
        if((*r)-(*l)>=k)
        {
            //   cout<<*l<<" "<<*r<<" match"<<endl;
            ans+=a.end()-r;
            l++;
        }
        else
            r++;
    }
    cout<<ans<<endl;
    return 0;
}
