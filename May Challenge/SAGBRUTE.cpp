#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ch[]={1,2,3,4,5,6,7,8,9,10};
bool g[11][11];
void dp()
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            g[i][j]= (__gcd(i+1,j+1)!=1 )? true:false;
        }
    }
    return;
}
bool gcd(int i,int j)
{
    return g[i][j];
}

ll n1(ll m, ll f)
{
    return m;
}
ll n2(ll m, ll f)
{   ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
            {

                continue;
            }
           // cout<<ch[i]<<" "<<ch[j]<<endl;
            ans++;

        }
    }
    return ans;
}
ll n3(ll m, ll f)
{
    ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if((gcd(j,k))||(gcd(i,k)))
                        continue;
                ans++;
                }
        }
    }
    return ans;
}
ll n4(ll m, ll f)
{
      ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        ans++;
                    }
                }
        }
    }
    return ans;
}
ll n5(ll m, ll f)
{
      ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;
                            ans++;
                        }

                    }
                }
        }
    }
    return ans;
}
ll n6(ll m, ll f)
{
      ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;

                            for(int n=0;n<f;n++)
                            {
                                if(gcd(i,n)||gcd(j,n)||gcd(k,n)||gcd(l,n)||gcd(m,n))
                                    continue;
                            ans++;
                            }

                        }
                    }
                }
        }
    }
    return ans;
}
ll n7(ll m, ll f)
{
          ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;

                            for(int n=0;n<f;n++)
                            {
                                if(gcd(i,n)||gcd(j,n)||gcd(k,n)||gcd(l,n)||gcd(m,n))
                                    continue;
                                for(int o=0;o<f;o++)
                                {
                                    if(gcd(i,o)||gcd(o,j)||gcd(o,k)||gcd(o,l)||gcd(o,m)||gcd(o,n))
                                        continue;
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
ll n8(ll m, ll f)
{
          ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;

                            for(int n=0;n<f;n++)
                            {
                                if(gcd(i,n)||gcd(j,n)||gcd(k,n)||gcd(l,n)||gcd(m,n))
                                    continue;
                                for(int o=0;o<f;o++)
                                {
                                    if(gcd(i,o)||gcd(o,j)||gcd(o,k)||gcd(o,l)||gcd(o,m)||gcd(o,n))
                                        continue;

                                    for(int p=0;p<f;p++)
                                    {
                                        if(gcd(p,i)||gcd(p,j)||gcd(p,k)||gcd(p,l)||gcd(p,m)||gcd(p,n)||gcd(p,o))
                                            continue;

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
ll n9(ll m, ll f)
{
          ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;

                            for(int n=0;n<f;n++)
                            {
                                if(gcd(i,n)||gcd(j,n)||gcd(k,n)||gcd(l,n)||gcd(m,n))
                                    continue;
                                for(int o=0;o<f;o++)
                                {
                                    if(gcd(i,o)||gcd(o,j)||gcd(o,k)||gcd(o,l)||gcd(o,m)||gcd(o,n))
                                        continue;

                                    for(int p=0;p<f;p++)
                                    {
                                        if(gcd(p,i)||gcd(p,j)||gcd(p,k)||gcd(p,l)||gcd(p,m)||gcd(p,n)||gcd(p,o))
                                            continue;

                                        for(int q=0;q<f;q++)
                                        {
                                            if(gcd(q,i)||gcd(q,j)||gcd(q,k)||gcd(q,l)||gcd(q,m)||gcd(q,n)||gcd(q,o)||gcd(q,p))
                                            continue;

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
ll n10(ll m, ll f)
{
          ll ans=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(gcd(i,j))
                {
                    continue;
                }
                for(int k=0;k<f;k++)
                {
                    if(gcd(j,k)||gcd(i,k))
                        continue;
                    for(int l=0;l<f;l++)
                    {
                        if(gcd(i,l)||gcd(j,l)||gcd(k,l))
                        continue;
                        for(int m=0;m<f;m++)
                        {
                            if(gcd(i,m)||gcd(j,m)||gcd(k,m)||gcd(l,m))
                                continue;

                            for(int n=0;n<f;n++)
                            {
                                if(gcd(i,n)||gcd(j,n)||gcd(k,n)||gcd(l,n)||gcd(m,n))
                                    continue;
                                for(int o=0;o<f;o++)
                                {
                                    if(gcd(i,o)||gcd(o,j)||gcd(o,k)||gcd(o,l)||gcd(o,m)||gcd(o,n))
                                        continue;

                                    for(int p=0;p<f;p++)
                                    {
                                        if(gcd(p,i)||gcd(p,j)||gcd(p,k)||gcd(p,l)||gcd(p,m)||gcd(p,n)||gcd(p,o))
                                            continue;

                                        for(int q=0;q<f;q++)
                                        {
                                            if(gcd(q,i)||gcd(q,j)||gcd(q,k)||gcd(q,l)||gcd(q,m)||gcd(q,n)||gcd(q,o)||gcd(q,p))
                                            continue;
                                            for(int r=0;r<f;r++)
                                            {
                                                if(gcd(r,i)||gcd(r,j)||gcd(r,k)||gcd(r,l)||gcd(r,m)||gcd(r,n)||gcd(r,o)||gcd(r,p)||gcd(r,q))
                                                        continue;
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
{           dp();
            long long int t,n,m;
            cin>>t;
            while(t--)
            {
                cin>>n>>m;
                if(n==1)
                {
                    cout<<n1(m,m)<<endl;
                }
                else if(n==2)
                {
                    cout<<n2(m,m)<<endl;
                }
                else if(n==3)
                {
                    cout<<n3(m,m)<<endl;
                }
                else if(n==4)
                {
                    cout<<n4(m,m)<<endl;
                }
                else if(n==5)
                {
                    cout<<n5(m,m)<<endl;
                }
                else if(n==6)
                {
                    cout<<n6(m,m)<<endl;
                }
                else if(n==7)
                {
                    cout<<n7(m,m)<<endl;
                }
                else if(n==8)
                {
                    cout<<n8(m,m)<<endl;
                }
                else if(n==9)
                {
                    cout<<n9(m,m)<<endl;
                }
                else
                {
                    cout<<n10(m,m)<<endl;
                }
            }
            return 0;
}

