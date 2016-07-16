#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000001];
ll b[1000001];
ll f[1000001];
ll n;
ll check(ll a[], ll b[], ll pos, ll sum, ll f[])
{
    if(pos==0)
    {
        if(a[pos]==sum)
        {
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
        }
        if(f[pos]&&a[pos]+b[pos]==sum)
        {
            f[pos]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
        }
        if(f[pos+1]&&a[pos]+b[pos+1]==sum)
        {
            f[pos+1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos+1]=1;
        }
        if(f[pos]&&f[pos+1]&&a[pos]+b[pos]+b[pos+1]==sum)
        {
            f[pos+1]=0;
            f[pos]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
            f[pos+1]=1;
        }
            return -1;
    }
    else if(pos == n-1)
    {
        if(a[pos]==sum)
        {
            pos++;
            return 1;
        }
        if(f[pos-1]&&a[pos]+b[pos-1]==sum)
        {
            f[pos-1]=0;
            pos++;
            return 1;
        }
        if(f[pos]&&a[pos]+b[pos]==sum)
        {
            f[pos]=0;
            pos++;
            return 1;
        }
        if(f[pos]&&f[pos-1]&&a[pos]+b[pos-1]+b[pos]==sum)
        {
            f[pos]=0;
            f[pos-1]=0;
            pos++;
            return 1;
        }
            return -1;
    }
    else
    {
        if(a[pos]==sum)
        {
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
        }
        if(f[pos-1]&&a[pos]+b[pos-1]==sum)
        {
            f[pos-1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos-1]=1;
        }
        if(f[pos]&&a[pos]+b[pos]==sum)
        {
            f[pos]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
        }
        if(f[pos+1]&&a[pos]+b[pos+1]==sum)
        {
            f[pos+1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos+1]=1;
        }
        if(f[pos]&&f[pos-1]&&a[pos]+b[pos-1]+b[pos]==sum)
        {
            f[pos]=0;
            f[pos-1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
            f[pos-1]=1;
        }
        if(f[pos]&&f[pos+1]&&a[pos]+b[pos]+b[pos+1]==sum)
        {
            f[pos+1]=0;
            f[pos]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
            f[pos+1]=1;
        }
        if(f[pos+1]&&f[pos-1]&&a[pos]+b[pos-1]+b[pos+1]==sum)
        {
            f[pos+1]=0;
            f[pos-1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos+1]=1;
            f[pos-1]=1;
        }
        if(f[pos]&&f[pos+1]&&f[pos-1]&&a[pos]+b[pos-1]+b[pos+1]+b[pos]==sum)
        {
            f[pos]=0;
            f[pos+1]=0;
            f[pos-1]=0;
            pos++;
            if (check(a,b,pos,sum,f)==1) return 1;
            pos--;
            f[pos]=1;
            f[pos+1]=1;
            f[pos-1]=1;
        }
            return -1;
    }
}
int main()
{
    ll t,op[4];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<a[0]+b[0]<<endl;
            continue;
        }
        op[0]=a[0];
        op[1]=a[0]+b[0];
        op[2]=a[0]+b[1];
        op[3]=a[0]+b[0]+b[1];
        sort(op,op+4);
        ll flag=0,flag2=0;
        for(ll i=3;i>=0;i--)
        {    flag=0;flag2=0;
            //cout<<"Checking for "<<op[i]<<endl;
            for(ll j=0;j<n;j++)
                f[j]=1;
            if (check(a,b,0,op[i],f)==1)
                {
              //      cout<<"pass"<<endl;
                    flag=1;
                }
           // cout<<endl;
            for(int j=0;j<n;j++)
                {//   cout<<f[j]<<" ";
                    if(f[j]==1)
                    {
                        flag2=1;
                        break;
                    }
                }
                //cout<<endl;
            if(flag&&!flag2)
            {
                cout<<op[i]<<"\n";
                flag=5;
                break;
            }
        }
        if(flag!=5)
        {
            cout<<"-1\n";
        }

    }
}
