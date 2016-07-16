#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll five[100];
void pre()
{   five[0]=1;
    for(int i=1;i<100;i++)
        five[i]=five[i-1]*5;
    return;
}
ll terms(ll k)
{   ll place=0;
    for(int i=1;i<100;i++)
    {
        if(k>=five[i-1]&&k<=five[i])
        {
            place=i;
            break;
        }
    }
    return place;
}
int main()
{   pre();
    ll k,n,length,t,rem,div;
    cin>>t;
    while(t--)
    {
        cin>>k;
        length=terms(k);
        //cout<<length<<endl;
        for(int i=length;i>=1;i--)
        {
            div=ceil(k*1.0/five[i-1]*1.0);
//            if(k%five[i-1]==0) div+=1;
            cout<<(2*(div-1))%10;
        }
        cout<<endl;
    }
    return 0;
}
//0       2       4       6       8
//0(5)    2(5)    4(5)    6(5)    8(5)
//0(25)   2(25)   4(25)   6(25)   8(25)
