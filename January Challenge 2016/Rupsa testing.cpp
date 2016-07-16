#include<iostream>
#include<stdio.h>
using namespace std;
long long fast_exp(int base, int exp) {
    long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%1000000007;
       base=(base*base)%1000000007;
       exp/=2;
    }
    return res%1000000007;
}
int main()
{
    long long int sum,t,i,n,in,k,ans;
    scanf("%lld",&t);
    //t=10;
    while(t--)
    {   ans=sum=0;
      //  n=10e5;
      //  in=10e9;
        scanf("%lld",&n);
        scanf("%lld",&in);
        sum=in;
        k=fast_exp(2,n);
        cout<<k<<endl;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&in);
            in=in%1000000007;
            //in=10e9;
            ans=ans+(sum*(in*k)%1000000007)%1000000007;
            ans=ans%1000000007;
            cout<<ans<<",";
            sum=(sum+in)%1000000007;
            k/=2;
        }
        cout<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}
