#include<iostream>
using namespace std;
long long t,n,a[100000],b[100000],v[5],a1,a2,a3,a4,o;
int fun(long long i,long long q,long long w,long long e,long long val)
{ //cout<<3434<<"\n";
    long long v=a[i]+q,f1=0,f2=0,f3=0,f4=0;
    //cout<<v<<" "<<q<<" "<<w<<" "<<e<<" "<<val<<"\n";
    if(i==n)
    {
        return 1;
    }
    if(v==val)
{ //cout<<"\n"<<i<<" :"<<b[i+2]<<"\n";
    f1=fun(i+1,w,e,b[i+2],val);
}
if(v+w==val && !f1)
{ //cout<<v+w<<"\n";
    f2=fun(i+1,0,e,b[i+2],val);
}
if(v+e==val && !f2)
{
    f3=fun(i+1,w,0,b[i+2],val);
}
if(v+e+w==val && !f3)
{
    f4=fun(i+1,0,0,b[i+2],val);
}
if(f1||f2||f3||f4)return 1;
    else
    return 0;
}
int main()
{
    cin>>t;
while(t--)
{ a1=2;a2=5;a3=6;a4=7;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[0]+b[0]<<"\n";
        continue;
    }
    /*if(n==2)
    {
        if(a[0]+b[0]==a[1]+b[1])
        {
            cout<<
        }
    }*/
b[n]=0;
o=1;
    v[4]=a[0];
    v[2]=a[0]+b[0];
    v[3]=a[0]+b[1];
    v[1]=a[0]+b[0]+b[1];
    for(int i=1;i<=4;i++)
    {
       if(i==4)
       { long long r=b[0],y=b[1],u=b[2];
    //   cout<<r<<y<<b[2];
          a1=fun(1,r,y,u,v[i]);

if(a1){cout<<v[i]<<"\n"; break;}
       }
       if(i==2)
       { if(v[i]<v[i+1] && o==1)
       {
           continue;
       }
           long long r=0,y=b[1],u=b[2];
       //cout<<r<<y<<b[2];
           a2=fun(1,r,y,u,v[i]);
           if(a2){cout<<v[i]<<"\n"; break;}

       }
       if(i==3 && o)
       { long long r=b[0],y=0,u=b[2];
       //cout<<r<<y<<b[2];
           a3=fun(1,r,y,u,v[i]);
           if(a3){cout<<v[i]<<"\n"; break;}
           if(v[i]>v[i-1])
           {
               i=i-2;
               o=0;
           }
       }
       if(i==1)
       {
           long long r=0,y=0,u=b[2];
           //cout<<r<<y<<b[2];
           a4=fun(1,r,y,u,v[i]);
           //cout<<a4<<"\n";
           if(a4){cout<<v[i]<<"\n"; break;}
       }
    }
if(!(a1||a2||a3||a4))
    cout<<-1<<"\n";
}

    return 0;
}
