#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000001];
ll b[1000001];
ll b2[1000001];
ll opt[3];
int main()
{
    ll t,n,op1,op2,op3,m,flag;
    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=1;
        for(ll i=0;i<n;i++)
            cin>>b[i];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<a[0]+b[0]<<endl;
            continue;
        }
        opt[0]=a[0];
        opt[1]=a[0]+b[0];
        opt[2]=a[0]+b[1];
        sort(opt,opt+3);
        for(ll i=0;i<3;i++)
            cout<<opt[i]<<",";
        cout<<endl;
        //copy b to another array
        for(ll i=0;i<n;i++)
            b2[i]=b[i];

        //trying for opt2
        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                if(a[i]==opt[2])
                    continue;
                if((b[i]!=-1)&&(a[i]+b[i]==opt[2]))
                {
                        b[i]=-1;
                        continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[2]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else if(i==(n-1))
            {
                if(a[i]==opt[2])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[2]))
                {
                        b[i-1]=-1;
                        continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[2]))
                {
                    b[i]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else
            {
                if(a[i]==opt[2])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[2]))
                {
                    b[i-1]=-1;
                    continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[2]))
                {
                    b[i]=-1;
                    continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[2]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
        }
        for(ll i=0;i<n;i++)
            cout<<b[i]<<",";
        cout<<endl;
        if(flag==1)
        {
            cout<<opt[2]<<"\n";
            continue;
        }
        flag=1;
        //b back
        for(ll i=0;i<n;i++)
            b[i]=b2[i];


        //trying for opt1
        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                if(a[i]==opt[1])
                    continue;
                if((b[i]!=-1)&&(a[i]+b[i]==opt[1]))
                {
                        b[i]=-1;
                        continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[1]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else if(i==(n-1))
            {
                if(a[i]==opt[1])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[1]))
                {
                        b[i-1]=-1;
                        continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[1]))
                {
                    b[i]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else
            {
                if(a[i]==opt[1])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[1]))
                {
                    b[i-1]=-1;
                    continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[1]))
                {
                    b[i]=-1;
                    continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[1]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
        }
        for(ll i=0;i<n;i++)
            cout<<b[i]<<",";
        cout<<endl;

        if(flag==1)
        {
            cout<<opt[1]<<"\n";
            continue;
        }
        flag=1;
        //b back
        for(ll i=0;i<n;i++)
            b[i]=b2[i];

        //trying for opt0
        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                if(a[i]==opt[0])
                    continue;
                if((b[i]!=-1)&&(a[i]+b[i]==opt[0]))
                {
                        b[i]=-1;
                        continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[0]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else if(i==(n-1))
            {
                if(a[i]==opt[0])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[0]))
                {
                        b[i-1]=-1;
                        continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[0]))
                {
                    b[i]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
            else
            {
                if(a[i]==opt[0])
                    continue;
                if((b[i-1]!=-1)&&(a[i]+b[i-1]==opt[0]))
                {
                    b[i-1]=-1;
                    continue;
                }
                if((b[i]!=-1)&&(a[i]+b[i]==opt[0]))
                {
                    b[i]=-1;
                    continue;
                }
                if((b[i+1]!=-1)&&(a[i]+b[i+1]==opt[0]))
                {
                    b[i+1]=-1;
                    continue;
                }
                flag=-1;
                break;
            }
        }
        for(ll i=0;i<n;i++)
            cout<<b[i]<<",";
        cout<<endl;
        if(flag==1)
        {
            cout<<opt[0]<<"\n";
            continue;
        }
        //if nothing then -1
        cout<<"-1\n";
    }

    return 0;
}
