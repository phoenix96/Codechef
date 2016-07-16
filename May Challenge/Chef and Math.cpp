#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ch[50];
void chef()
{
    ch[0]=1;
    ch[1]=2;
    for(int i=2;i<43;i++)
    {
        ch[i]=ch[i-1]+ch[i-2];
    }
}

ll k1(ll n, ll f)
{   if(f)
    return 1;
    return 0;
}
ll k2(ll n, ll f)
{   ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            if(ch[i]+ch[j]==n)
                ans++;
        }
    }
    return ans;
}
ll k3(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {

            if(ch[i]+ch[j]+ch[k]==n)
                ans++;
            }
        }
    }
    return ans;
}
ll k4(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {

                        if(ch[i]+ch[j]+ch[k]+ch[l]==n)
                                {
                                // cout<<ch[i]<<" "<<ch[j]<<" "<<ch[k]<<" "<<ch[l]<<endl;
                                    ans++;
                                }
                }
            }
        }
    }
    return ans;
}
ll k5(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {

                        if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]==n)
                                ans++;
                   }
                }

            }
        }
    }
    return ans;
}
ll k6(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {
                       for(int p=o;p<f;p++)
                        {
                        if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]+ch[p]==n)
                                  ans++;
                        }
                   }
                }

            }
        }
    }
    return ans;
}
ll k7(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {
                       for(int p=o;p<f;p++)
                        {
                            for(int q=p;q<f;q++)
                            {
                                    if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]+ch[p]+ch[q]==n)
                                                ans++;
                            }
                        }
                   }
                }

            }
        }
    }
    return ans;
}
ll k8(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {
                       for(int p=o;p<f;p++)
                        {
                            for(int q=p;q<f;q++)
                            {
                                for(int r=q;r<f;r++)
                                {

                                    if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]+ch[p]+ch[q]+ch[r]==n)
                                                ans++;
                                }
                            }
                        }
                   }
                }

            }
        }
    }
    return ans;
}
ll k9(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {
                       for(int p=o;p<f;p++)
                        {
                            for(int q=p;q<f;q++)
                            {
                                for(int r=q;r<f;r++)
                                {
                                   for(int s=r;s<f;s++)
                                   {
                                    if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]+ch[p]+ch[q]+ch[r]+ch[s]==n)
                                                ans++;
                                   }
                                }
                            }
                        }
                   }
                }

            }
        }
    }
    return ans;
}
ll k10(ll n, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=i;j<f;j++)
        {
            for(int k=j;k<f;k++)
            {
                for(int l=k;l<f;l++)
                {
                   for(int o=l;o<f;o++)
                   {
                       for(int p=o;p<f;p++)
                        {
                            for(int q=p;q<f;q++)
                            {
                                for(int r=q;r<f;r++)
                                {
                                   for(int s=r;s<f;s++)
                                   {
                                       for(int t=s;t<f;t++)
                                       {
                                    if(ch[i]+ch[j]+ch[k]+ch[l]+ch[o]+ch[p]+ch[q]+ch[r]+ch[s]+ch[t]==n)
                                                ans++;
                                       }
                                   }
                                }
                            }
                        }
                   }
                }

            }
        }
    }
    return ans;
}
int main()
{
    ll t,n,k,fi,che=0;
    chef();
    cin>>t;
    while(t--)
    {   che=0;
        cin>>n>>k;
        fi=43;
        for(int i=0;i<43;i++)
        {
            if(n==ch[i])
            {
                che=1;
            }
            if(ch[i]>=n)
            {
                fi=i;
                break;
            }
        }
        if(k==1)
        {
            cout<<k1(n,che)<<endl;
        }
        else if(k==2)
        {
            cout<<k2(n,fi)<<endl;
        }
        else if(k==3)
        {
            cout<<k3(n,fi)<<endl;
        }
        else if(k==4)
        {
            cout<<k4(n,fi)<<endl;
        }
        else if(k==5)
        {
            cout<<k5(n,fi)<<endl;
        }
        else if(k==6)
        {
            cout<<k6(n,fi)<<endl;
        }
        else if(k==7)
        {
            cout<<k7(n,fi)<<endl;
        }
        else if(k==8)
        {
            cout<<k8(n,fi)<<endl;
        }
        else if(k==9)
        {
            cout<<k9(n,fi)<<endl;
        }
        else
        {
            cout<<k10(n,fi)<<endl;
        }
    }
    return 0;
}
