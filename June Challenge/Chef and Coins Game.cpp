#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[1000001];
void seive()
{//0 means prime
    ll k=2;
    for(ll i=2 ; i<=1000000; i++)
    {   k=2;
        if(!p[i])
        for(ll j=i*k; j<=1000000;k++,j=i*k)
        {
            p[j]=1;
        }
    }
    return;
}
int main()
{
    ll t,n,q,m,m2,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
//        ll count=0;
//        if(n==1) {cout <<"Chef\n"; continue;}
//        if(n==10) {cout <<"Chef\n"; continue;}
//        for(ll i=1;i<=sqrt(n);i++)
//        {
//            if(n%i==0 && (!p[i]))
//                {
//                    //cout<<i<<" ";
//                    count++;
//                    if(!p[n/i]&&(i!=(n/i)))
//                        {
//                            //cout<<(n/i);
//                            count++;
//                        }
//                }
//        }
//        if(count%2!=0)
        if(n%6==0)
            cout<<"Misha\n";
        else
            cout<<"Chef\n";
    }
}
/*
1:C
2:C
3:C
4:C
5:C
6:M
7:C
8:C
9:C
10:C
11:C
12:M

*/
