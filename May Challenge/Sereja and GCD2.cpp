#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll phi[102][102];
ll ans[102][102];
/* STACK OVERFLOW RECURSION USED */
//ll phi(ll n)
//{
//    ll result = n;
//    for (ll p=2; p*p<=n; ++p)
//    {
//        if (n % p == 0)
//        {
//            while (n % p == 0)
//                n /= p;
//            result -= result / p;
//        }
//    }
//    if (n > 1)
//        result -= result / n;
//    return result;
//}

ll gcd(ll a, ll b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}
void pre()
{
    for(int i=0;i<102;i++)
    {
        phi[i][1]=1;
    }
    for(ll i=1;i<102;i++)
    {
        for(ll j=2;j<102;j++)
        {
            if(gcd(i,j)==1ll)
                phi[i][j]= phi[i][j-1]+1;
            else
                phi[i][j]=phi[i][j-1];
        }
    }
    for(ll i=1;i<=10;i++)
    {
        for(ll j=1;j<=10;j++)
        {
            cout<<phi[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
void pre2()
{   ll temp=0;

    for(ll i=0;i<102;i++)
      {
          ans[0][i]=0;
          ans[i][0]=0;
      }
      for(ll i=0;i<102;i++)
      {
          ans[i][1]=i;
      }
    for(ll i=1;i<=5;i++)
    {
        for(ll j=2;j<=5;j++)
        {   temp=0;
            for(ll k=1;k<=i;k++)
                {
                    cout<<"p("<<k<<")("<<i<<")"<<phi[k][i]<<"*"<<ans[i/k][j-1]<<"+";
                    temp += ((phi[k][i]%MOD)*(ans[i/k][j-1])%MOD)%MOD;
                    temp%=MOD;
                }
                ans[i][j]=temp;
                cout<<"   ";
        }
     cout<<endl;
    }
    cout<<endl<<"ANSWER:"<<endl;
    for(ll i=1;i<=10;i++)
    {   //cout<<i<<" ";
        for(ll j=1;j<=10;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ll t,n,k;
    pre();
    pre2();
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        n++;
        cout<<ans[k][n]<<endl;
    }
    return 0;
}
