#include<iostream>
#include<stdio.h>
using namespace std;
int p[10001];
int prime[1229];
void seive()
{
    for(int i=2; i<10001; i++)
    {
        if(p[i]==0)
        {
            for(int j=i*2; j<10001; j+=i)
            {
                p[j]=1;
            }
        }
    }
    long long j=0;
    for(int i=2;i<=10000;i++)
        {
            if(p[i]==0)
                prime[j++]=i;
        }
     //   cout<<j<<endl;
}
void print_seive(int n)
{
    for(int i=0; i<=n; i++)
        cout<<prime[i]<<endl;
}
int a[10001];
int main()
{
    seive();
    //print_seive(30);
    long long sum,t,i,j,n,in,u,k,f,ans;
    scanf("%lld",&t);
  //t=10;
    while(t--)
    {
        u=100000000;
        sum=0;
        ans=0;
        scanf("%lld",&n);
      //  n=10000;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
      //a[i]=i;
            if(i!=0)
            {
                if(a[i]<a[i-1])
                {
                    ans+=a[i-1]-a[i];
                    a[i]=a[i-1];
                }
            }
        }
//        cout<<ans<<endl;
        for(i=0; i<1229; i++)
        {
                sum=0;
                for(j=0; j<n; j++)
                {
                    f=a[j]%prime[i];
                    if(f==0) f=prime[i];
                    sum=sum+prime[i]-f;
                }
                if(sum<u)u=sum;
        }
        //check from seive modulus of all from that number
        printf("%lld\n",ans+u);
    }
    return 0;
}
