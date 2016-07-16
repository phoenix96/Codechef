#include<math.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#define fast ios_base::sync_with_stdio(false);
#define X 1000000007
#define ll long long
using namespace std;
ll int p_auxillary[100001],n_auxillary[10001];
ll int us[100001],ls[100001],s[100001];
ll int original[100001],ca[100001];
ll int sum(ll int n)
{
    ll int s=0;
    for(ll int i=0; i<=n; i++)
        s+=p_auxillary[i]%X;
    return (s%X);
}
int main()
{
    ll int u,l,c,k=0,o;
    cin>>u>>l>>o;
    for(ll int i=0; i<u; i++)
        cin>>us[i];
    for(ll int i=0; i<l; i++)
        cin>>ls[i];
    for(ll int i=0; i<u; i++)
    {
        for(ll int j=0; j<l; j++)
        {
            if(us[i]==ls[j])
            {
                s[k]=us[i];
                k++;
            }
        }
    }
    sort(s,s+k);
    c=1;
    ll int p=0;
    for(ll int i=0; i<k; i++)
    {
        if(s[i]!=s[i+1])
        {
            original[p]=s[i];
            ca[p]=c;
            c=1;
            p++;
        }
        else
        {
            c++;
        }
    }
    for(ll int i=0; i<p; i++)
        p_auxillary[i]=ca[i];
    for(ll int co=1; co<=o; co++)
    {
        n_auxillary[co-1]=0;
        for(ll int i=co; i<p; i++)
        {
            n_auxillary[i]=(sum(i-1)*ca[i])%X;
        }
        ll int sum=0;
        for(ll int i=0; i<p; i++)
            sum+=n_auxillary[i]%X;
        sum=sum%X;
        cout<<sum<<" ";
        for(ll int i=0; i<p; i++)
            p_auxillary[i]=n_auxillary[i];
    }
    return 0;
}